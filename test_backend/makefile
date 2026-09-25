TARGET      := server
BUILD_DIR   := output
BIN_DIR     := $(BUILD_DIR)/bin
OBJ_DIR     := $(BUILD_DIR)/obj

CXX         := g++
CXXSTD      := -std=c++17
CXXFLAGS    := $(CXXSTD) -Wall -Wextra -O2 -g
CPPFLAGS    := -Iincludes -Ihelpers -Icontroller -Ifilters -IHTTP_methods
LDLIBS      := -Wl,--no-as-needed -ldrogon -ltrantor -ljsoncpp -lssl -lcrypto -lz -lpthread -Wl,--as-needed

SRC_DIRS    := server controller filters HTTP_methods helpers utils
SRCS        := $(foreach d,$(SRC_DIRS),$(wildcard $(d)/*.cc))
OBJS        := $(patsubst %.cc,$(OBJ_DIR)/%.o,$(SRCS))
DEPS        := $(OBJS:.o=.d)

.PHONY: all dirs run clean

all: dirs $(BIN_DIR)/$(TARGET)

dirs:
	@mkdir -p $(BIN_DIR) $(OBJ_DIR) json uploads

$(BIN_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDLIBS)
	@echo "Готово: $@"

$(OBJ_DIR)/%.o: %.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -MMD -MP -c $< -o $@

run: all
	./$(BIN_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS) 
