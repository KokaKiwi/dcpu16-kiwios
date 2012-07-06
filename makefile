CC			:= bin/lcc
CCFLAGS		:= -S -Iinclude -Wf-dcputoolchain -target=dcpu16
ASM			:= tools/dtasm
ASMFLAGS	:= -i
LD			:= tools/dtld
D			:= .dasm
O			:= .dobj16
A			:= .dlib16
E			:= .bin
I			:= include/
B			:= target/

all: disk$E

# Disk
INCS  		:= $(wildcard $I*.h)
SRCS  		:= $(wildcard kernel/*.c)
OBJS  		:= $(subst kernel/,$B,$(SRCS:.c=$O))

disk$E		: $(INCS) $Bboot$O $(OBJS); $(LD) -o $@ $Bboot$O $(OBJS)

$B%$O		: $B%$D; $(ASM) $(ASMFLAGS) -o $@ $^

$B%$D		: kernel/%.c; $(CC) $(CCFLAGS) -o $@ $^
$Bboot$D	: boot/boot.c; $(CC) $(CCFLAGS) -Wf-header -o $@ $^