OLEVEL=-O0
CXXSTANDART=-std=c++14
CXXFLAGS=$(CXXSTANDART) -Wall -Wpedantic -Wextra $(OLEVEL)
DIR=bin

APPLY_SRC=apply.cpp
APPLY_OBJ=$(addprefix $(DIR)/, $(APPLY_SRC:.cpp=.o))

INDEX_SRC=index.cpp
INDEX_OBJ=$(addprefix $(DIR)/, $(INDEX_SRC:.cpp=.o))

all: $(DIR)/apply $(DIR)/index

$(DIR)/apply: $(APPLY_OBJ)
	$(CXX) $(LDFLAGS) $(APPLY_OBJ) -o $@ $(LDLIBS)

$(DIR)/index: $(INDEX_OBJ)
	$(CXX) $(LDFLAGS) $(INDEX_OBJ) -o $@ $(LDLIBS)

$(DIR)/%.o: %.cpp
	mkdir -p $(DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $^

.PHONY: clean all

clean:
	rm -rf $(DIR)	

