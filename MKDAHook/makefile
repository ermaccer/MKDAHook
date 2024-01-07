EE_BIN = ../scripts/MKDAHook.elf
EE_OBJS = main.o mips.o ps2mem.o inf.o\
mkda/core.o \
mkda/script.o \
mkda/camera.o \
mkda/object.o \
fatality/quanchi.o \
pcsx2\rini.o \
pcsx2\inireader.o \
settings.o \
mkdahook.o \

BASE_ADDRESS = 0x02020000
EE_LINKFILE = linkfile

EE_LDFLAGS = -Wl,--entry=init -Wl,-Map,../scripts/MKDAHook.map -Wl,'--defsym=BASE_ADDRESS=$(BASE_ADDRESS)'

all: $(EE_BIN)

PS2SDK = ../external/ps2sdk/ps2sdk
include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
