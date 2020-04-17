CC      := g++
LD	:= g++

LFLAGS := -g -pthread -lpng -lstdc++fs 
CFLAGS := -g -pthread -MD -MMD -lstdc++fs

MODULES := main
SRC_DIR := $(addprefix src/,$(MODULES))
BUILD_DIR := $(addprefix bin/,$(MODULES))

SRC := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.cpp))
OBJ := $(patsubst src/%.cpp,bin/%.o,$(SRC))
INCLUDES := $(addprefix -I,$(SRC_DIR))

INCLUDEDIRS:=$(foreach x, $(wildcard $(BUILD_DIR)), $x)

vpath %.cpp $(SRC_DIR)

define make-goal
$1/%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c -MMD $$< -o $$@ 
endef

.PHONY: all checkdirs clean

all: checkdirs bin/MarioProj.exe 

-include $(foreach x, $(INCLUDEDIRS),$x/*d)

bin/MarioProj.exe: $(OBJ)
	$(LD) $^ $(LFLAGS) -o $@ 

checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)
$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal,$(bdir))))

