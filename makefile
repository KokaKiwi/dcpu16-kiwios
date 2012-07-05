CC=bin/lcc
CCFLAGS=-S -Iinclude -Wf-dcputoolchain -target=dcpu16
ASM=tools/dtasm
ASMFLAGS=-i
LD=tools/dtld
EMULATOR=java -jar tools/emu/dcpu-emu.jar
EMULATORFLAGS=
D=.dasm
O=.dobj16
A=.dlib16
E=.bin
I=include/
B=target/

all: disk$E

test:
	$(EMULATOR) $(EMULATORFLAGS) -f disk$E

# Disk
INCOBJS=$Ikernel.h $Istdlib.h $Ihardware.h $Istdio.h $Istdarg.h $Istring.h $Icolor.h $Iscreen.h $Itime.h $Iclock.h $Istdint.h $Ihmd.h
KERNOBJS=$Bkernel$O $Bstdlib$O $Bstdio$O $Bstring$O $Bscreen$O $Btime$O $Bclock$O $Bhmd$O

disk$E: $(INCOBJS) $Bboot$O $(KERNOBJS); $(LD) -o $@ $Bboot$O $(KERNOBJS)

$Bboot$O: $Bboot$D; $(ASM) $(ASMFLAGS) -o $@ $^
$Bkernel$O: $Bkernel$D; $(ASM) $(ASMFLAGS) -o $@ $^
$Bstdlib$O: $Bstdlib$D; $(ASM) $(ASMFLAGS) -o $@ $^
$Bstdio$O: $Bstdio$D; $(ASM) $(ASMFLAGS) -o $@ $^
$Bstring$O: $Bstring$D; $(ASM) $(ASMFLAGS) -o $@ $^
$Bscreen$O: $Bscreen$D; $(ASM) $(ASMFLAGS) -o $@ $^
$Btime$O: $Btime$D; $(ASM) $(ASMFLAGS) -o $@ $^
$Bclock$O: $Bclock$D; $(ASM) $(ASMFLAGS) -o $@ $^
$Bhmd$O: $Bhmd$D; $(ASM) $(ASMFLAGS) -o $@ $^

$Bboot$D: boot/boot.c; $(CC) $(CCFLAGS) -Wf-header -o $@ $^
$Bkernel$D: kernel/kernel.c; $(CC) $(CCFLAGS) -o $@ $^
$Bstdlib$D: kernel/stdlib.c; $(CC) $(CCFLAGS) -o $@ $^
$Bstdio$D: kernel/stdio.c; $(CC) $(CCFLAGS) -o $@ $^
$Bstring$D: kernel/string.c; $(CC) $(CCFLAGS) -o $@ $^
$Bscreen$D: kernel/screen.c; $(CC) $(CCFLAGS) -o $@ $^
$Btime$D: kernel/time.c; $(CC) $(CCFLAGS) -o $@ $^
$Bclock$D: kernel/clock.c; $(CC) $(CCFLAGS) -o $@ $^
$Bhmd$D: kernel/hmd.c; $(CC) $(CCFLAGS) -o $@ $^