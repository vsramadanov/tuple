OLEVEL=-O0
CXXSTD=-std=c++14
CXXFLAGS=$(CXXSTD) -Wall -Wpedantic -Wextra $(OLEVEL)
DIR=bin

all: naive apply reverse transform index

naive: $(DIR)/naive
apply: $(DIR)/apply
reverse: $(DIR)/reverse
transform: $(DIR)/transform
index: $(DIR)/index

$(DIR)/%: %.cpp
	mkdir -p $(DIR)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: clean all

clean:
	rm -rf $(DIR)

.SUFFIXES:

