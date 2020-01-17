require("build/lua/rom_info")

local arg = { ... }

local rom = gru.n64rom_load(arg[1])
local rom_info = roms[rom:crc32()]

if rom_info == nil then
    error("invalid rom", 0)
    return 1
end

local kb_version = "kb-" .. rom_info.rom_id
print("Building ".. kb_version)

local _,_,res = os.execute("make " .. kb_version)
if res ~= 0 then
    error("could not build kb", 0)
end

print("assembling rom")
local prev_ldr = rom:copy(0x1000, 0x50)
local kb = gru.blob_load("bin/" .. kb_version .. "/kb.bin")
local payload_rom = rom:size()
local ram = 0x80400000
local _,_,res = os.execute(string.format("make CPPFLAGS='-DROM=0x%08x -DRAM=0x%08x -DSIZE=0x%08x' " ..
                                         "ldr-" .. kb_version,
                                        rom:size(),
                                        ram,
                                        kb:size() + 0x60))

if(res ~= 0) then
    error("could not build loader", 0)
end

local ldr = gru.blob_load("bin/ldr-" .. kb_version .. "/ldr.bin")
print("inserting payload")
rom:write(0x1000, ldr)
rom:write(payload_rom, prev_ldr)
rom:write(payload_rom + 0x60, kb)
rom:crc_update()

return rom, rom_info, kb_version