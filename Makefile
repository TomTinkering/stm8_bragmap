#  Project Settings
PROJECT=stm8_bragmap
# target is STM8S003F3P6
TARGET_FAM = STM8S

SDCC=sdcc
SDLD=sdld
REMOVE = rm -f

# list all include directories here
INCLUDE_DIRS = include/
INCLUDE_DIRS += ./

# list all c and c++ source directories here

SRC_DIRS = src/
SRC_DIRS += ./

# list all assembly source directories here
#ASM_DIRS = src/

# current makefile directory
MAKE_DIR = $(notdir $(shell pwd))

#generate lists of source files based on directory listings
C_SRC = $(wildcard $(addsuffix *.c,$(SRC_DIRS))) 
#CPP_SRC = $(wildcard $(addsuffix *.cpp,$(SRC_DIRS)))
#ASM_SRC = $(wildcard $(addsuffix *.s,$(ASM_DIRS)))

# define the output directory for the object files
OBJ_OUTPUT_DIR = build/

# define the C object filenames to generate
OBJECT_NAMES = $(notdir $(C_SRC:.c=.ihx))
#OBJECT_NAMES += $(notdir $(CPP_SRC:.cpp=.ihx))
#OBJECT_NAMES += $(notdir $(ASM_SRC:.s=.ihx))

# add the output path to all the object names
OBJECTS = $(patsubst %.ihx, $(OBJ_OUTPUT_DIR)%.ihx, $(OBJECT_NAMES))

# build a search list for make dependencies
vpath %.c $(SRC_DIRS)
#vpath %.cpp $(SRC_DIRS)
#vpath %.s $(ASM_DIRS)
vpath %.h $(INCLUDE_DIRS)
vpath %.ihx

# define any directories containing header files other than /usr/include
INCLUDES = $(addprefix -I,$(INCLUDE_DIRS)) 

#########################################################################

all:: begin sdcc_version printvar $(OBJECT_NAMES) end

.PHONY: clean
clean:
	$(REMOVE) $(OBJ_OUTPUT_DIR)*.ihx
	$(REMOVE) $(OBJ_OUTPUT_DIR)*.lst
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
	
#flash: $(OBJECT).ihx
#stm8flash -cstlink -pstm8l150 -w $(OBJECT).ihx	
	
#########################################################################
#  Default rules to compile .c and .cpp file to .o
#  and assemble .s files to .o

# General Rule for compiling C source files
%.ihx: %.c
	$(SDCC) -lstm8 -mstm8 --out-fmt-ihx -D__SDCC__ $(CFLAGS) $(LDFLAGS) $(INCLUDES) -c $< -o $(OBJ_OUTPUT_DIR)$(notdir $@)

#########################################################################	