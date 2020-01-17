local args = { ... }
local in_rom
local opt_out_rom

while(args[1]) do
    if args[1] == "-o" then
        opt_out_rom = args[2]
        table.remove(args, 1)
        table.remove(args, 1)
    else
        in_rom = args[1]
        table.remove(args, 1)
    end
end

local make = loadfile("build/lua/make.lua")

local rom, rom_info, kb_version = make(in_rom)

if(opt_out_rom ~= nil) then
    print("saving " .. opt_out_rom)
    rom:save(opt_out_rom)
else
    print("Saving build/" .. kb_version .. ".z64")
    rom:save("build/" .. kb_version .. ".z64")
end