CC				:= bin/lcc
CCFLAGS			:= -S -Iinclude -Wf-dcputoolchain -target=dcpu16
ASM				:= tools/dtasm
ASMFLAGS		:= -i
LD				:= tools/dtld
D				:= .dasm
O				:= .dobj16
A				:= .dlib16
E				:= .bin
I				:= include/
B				:= target/
S				:= $Bsource/

all: disk$E

# Disk
INCS  			:= $(wildcard $I*.h)
DIRS			:= boot kernel
SRCS  			:= $(foreach dir,$(DIRS),$(wildcard $(dir)/*.c))
OBJS  			:= $(addprefix $B,$(notdir $(SRCS:.c=$O)))

disk$E			: $(INCS) $(OBJS)
	@echo 	"Creating boot disk..."
	$(LD) -o $@ $(OBJS)

$B%$O			: $B%$D
	$(ASM) $(ASMFLAGS) -o $@ $^
	cp $^ $(addprefix $S,$(notdir $^))
	rm $^

$B%$D			: kernel/%.c
	$(CC) $(CCFLAGS) -o $@ $^
$Bboot$D		: boot/boot.c; $(CC) $(CCFLAGS) -Wf-header -o $@ $^