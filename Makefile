#  Project Settings
PROJECT=stm8_bragmap
# target is STM8S003F3P6
TARGET_FAM = STM8S

SDCC=sdcc
SDLD=sdld
REMOVE = rm -f

# list all include directories here
INCLUDE_DIRS = include/ 
INCLUDE_DIRS += ./ STM8S_StdPeriph_Driver/inc/

# list all c and c++ source directories here

SRC_DIRS = src/
SRC_DIRS += ./ 

# list all assembly source directories here
#ASM_DIRS = src/

# current makefile directory
MAKE_DIR = $(notdir $(shell pwd))

#generate lists of source files based on directory listings
C_SRC = $(wildcard $(addsuffix *.c,$(SRC_DIRS)))
#add specific c_files
C_SRC += STM8S_StdPeriph_Driver/src/stm8s_uart1.c
C_SRC += STM8S_StdPeriph_Driver/src/stm8s_i2c.c
C_SRC += STM8S_StdPeriph_Driver/src/stm8s_tim1.c
C_SRC += STM8S_StdPeriph_Driver/src/stm8s_tim2.c
C_SRC += STM8S_StdPeriph_Driver/src/stm8s_clk.c
#CPP_SRC = $(wildcard $(addsuffix *.cpp,$(SRC_DIRS)))
#ASM_SRC = $(wildcard $(addsuffix *.s,$(ASM_DIRS)))

# define the output directory for the object files
OBJ_OUTPUT_DIR = build/

# define the C object filenames to generate
OBJECT_NAMES = $(notdir $(C_SRC:.c=.rel))
PREPROC_NAMES = $(notdir $(C_SRC:.c=.ppc))
#OBJECT_NAMES += $(notdir $(CPP_SRC:.cpp=.rel))
#OBJECT_NAMES += $(notdir $(ASM_SRC:.s=.rel))

# add the output path to all the object names
OBJECTS = $(patsubst %.rel, $(OBJ_OUTPUT_DIR)%.rel, $(OBJECT_NAMES))
PREPROCS = $(patsubst %.ppc, $(OBJ_OUTPUT_DIR)%.ppc, $(PREPROC_NAMES))

# build a search list for make dependencies
vpath %.c $(SRC_DIRS)
vpath %.c STM8S_StdPeriph_Driver/src/
#vpath %.cpp $(SRC_DIRS)
#vpath %.s $(ASM_DIRS)
vpath %.h $(INCLUDE_DIRS)
vpath %.rel

# define any directories containing header files other than /usr/include
INCLUDES = $(addprefix -I,$(INCLUDE_DIRS)) 

CFLAGS = -mstm8 --out-fmt-ihx -D__SDCC__ --std-c99 
#--opt-code-size for slightly smaller code size
LIBS   = -lstm8
LDFLAGS = 

# code / ram size checks
LD_SIZE_FLAGS = --code-size 0x1400 --iram-size 0x400 

#########################################################################

all:: begin sdcc_version printvar $(PROJECT).hex sizes end

pre:: begin sdcc_version printvar preproc end

$(PROJECT).hex:$(notdir $(OBJECTS))
	$(SDCC) $(LIBS) $(CFLAGS) $(LDFLAGS) $(LD_SIZE_FLAGS) $(OBJECTS) -o $(OBJ_OUTPUT_DIR)/bin/$(notdir $@)

flash: $(OBJ_OUTPUT_DIR)/bin/$(PROJECT).hex
	stm8flash -cstlink -pstm8s003 -w $(OBJ_OUTPUT_DIR)/bin/$(PROJECT).hex

preproc : $(notdir $(PREPROCS))
	echo "Preprocessing done.."
	
.PHONY: sizes
sizes:
	echo "\n------------section sizes------------------\n"
	objdump -x $(OBJ_OUTPUT_DIR)/bin/$(PROJECT).hex	

.PHONY: clean
clean:
	$(REMOVE) $(OBJ_OUTPUT_DIR)*.*
	
# Eye Candy
.PHONY begin: 
begin: 
	@echo
	@echo "---------- begin ----------"

.PHONY end:
end:
	@echo
	@echo "----------- end -----------"

.PHONY sdcc_version: 
sdcc_version: 
	@echo
	@$(SDCC) --version
	
.PHONY:printvar
printvar: 
	@echo $(OBJECTS)
	

#########################################################################
#  Default rules to compile .c and .cpp file to .rel
#  and assemble .s files to .rel

# General Rule for compiling C source files
%.rel: %.c
	$(SDCC) $(CFLAGS) $(INCLUDES) -c $< -o $(OBJ_OUTPUT_DIR)$(notdir $@)

# Show preprocessor output (don't build object)
%.ppc: %.c
	$(SDCC) $(CFLAGS) $(INCLUDES) -E -c $< -o $(OBJ_OUTPUT_DIR)$(notdir $@)

#########################################################################	
