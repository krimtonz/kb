PACKAGE		?= $(NAME)
URL			?= github.com/krimtonz/kb
CC			= mips64-gcc
LD			= mips64-g++
AS			= mips64-gcc -x assembler-with-cpp
OBJCOPY		= mips64-objcopy
GRC 		= grc
CFILES		= *.c
SFILES		= *.S
RESFILES	= *.png
SRCDIR		= src
OBJDIR		= obj
BINDIR		= bin 
LIBDIR		= lib
KB_VERSIONS	= NBKJ
RESDESC		= res.json

ADDRESS	= 0x80400060
ADDRESS_LDR = 0x80000400
ALL_CPPFLAGS	= $(CPPFLAGS)
ALL_CFLAGS	= -g -c -MMD -MP -std=gnu11 -Wall -ffunction-sections -fdata-sections -O3 -flto -ffat-lto-objects
ALL_LDFLAGS = -T gl-n64.ld -L$(LIBDIR) -nostartfiles -specs=nosys.specs -Wl,--gc-sections -O3 -flto $(LDFLAGS)
ALL_LIBS	= $(LIBS)

KB	= $(foreach v,$(KB_VERSIONS),kb-$(v))
LDR = $(foreach v,$(KB_VERSIONS),ldr-kb-$(v))

KB-NBKJ = $(OBJ-kb-NBKJ) $(ELF-kb-NBKJ)

all	: $(KB)
clean :
	rm -rf $(OBJDIR) $(BINDIR)
distclean : clean
	rm -rf build/*.z64 build/*.wad

.PHONY : all clean distclean

define bin_template
SRCDIR-$(1)	= $(5)
OBJDIR-$(1)	= obj/$(1)
BINDIR-$(1) = bin/$(1)
RESDIR-$(1)	= $(6)
NAME-$(1)	= $(1)
ADDRESS-$(1)	= $(4)
CSRC-$(1)       := $$(foreach s,$$(CFILES),$$(wildcard $$(SRCDIR-$(1))/$$(s)))
COBJ-$(1)        = $$(patsubst $$(SRCDIR-$(1))/%,$$(OBJDIR-$(1))/%.o,$$(CSRC-$(1)))
SSRC-$(1)       := $$(foreach s,$$(SFILES),$$(wildcard $$(SRCDIR-$(1))/$$(s)))
SOBJ-$(1)		 = $$(patsubst $$(SRCDIR-$(1))/%,$$(OBJDIR-$(1))/%.o,$$(SSRC-$(1)))
RESSRC-$(1)		:= $$(wildcard $$(RESDIR-$(1))/*)
RESOBJ-$(1)	     = $$(patsubst $$(RESDIR-$(1))/%,$$(OBJDIR-$(1))/%.o,$$(RESSRC-$(1)))
OBJ-$(1)		 = $$(COBJ-$(1)) $$(SOBJ-$(1)) $$(RESOBJ-$(1))
ELF-$(1)         = $$(BINDIR-$(1))/$(3).elf
BIN-$(1)         = $$(BINDIR-$(1))/$(3).bin
OUTDIR-$(1)      = $$(OBJDIR-$(1)) $$(BINDIR-$(1))
BUILD-$(1)		 = $(1)
CLEAN-$(1)		 = clean-$(1)
$$(ELF-$(1))		 : LDFLAGS += -Wl,--defsym,start=$$(ADDRESS-$(1))
$$(BUILD-$(1))       : $$(BIN-$(1))
$$(CLEAN-$(1))       :
	rm -rf $$(OUTDIR-$(1))
$$(COBJ-$(1))     : $$(OBJDIR-$(1))/%.o: $$(SRCDIR-$(1))/% | $$(OBJDIR-$(1))
	$(CC) $$(ALL_CPPFLAGS) $$(ALL_CFLAGS) $$< -o $$@
$$(SOBJ-$(1))		: $$(OBJDIR-$(1))/%.o: $$(SRCDIR-$(1))/% | $$(OBJDIR-$(1))
	$(AS) -c -MMD -MP $$(ALL_CPPFLAGS) $$< -o $$@
$$(RESOBJ-$(1))		: $$(OBJDIR-$(1))/%.o: $$(RESDIR-$(1))/% | $$(OBJDIR-$(1))
	$(GRC) $$< -d $(RESDESC) -o $$@
$$(ELF-$(1))      : $$(OBJ-$(1)) | $$(BINDIR-$(1))
	$(LD) $$(ALL_LDFLAGS) $$^ $$(ALL_LIBS) -o $$@
$$(BIN-$(1))      : $$(ELF-$(1)) | $$(BINDIR-$(1))
	$(OBJCOPY) -S -O binary $$< $$@
$$(OUTDIR-$(1))   :
	mkdir -p $$@
endef

$(foreach v,$(KB_VERSIONS),$(eval $(call bin_template,kb-$(v),$(v),kb,$(ADDRESS),src/kb,res)))
$(foreach v,$(KB_VERSIONS),$(eval $(call bin_template,ldr-kb-$(v),$(v),ldr,$(ADDRESS_LDR),src/ldr,res/ldr)))

$(KB-NBKJ)	: ALL_LIBS := -lnbkj