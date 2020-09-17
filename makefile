OLEVEL=-O0
CXXSTD=-std=c++14
CXXFLAGS=$(CXXSTD) -Wall -Wpedantic -Wextra $(OLEVEL)
DIR=bin

all: $(DIR)/apply $(DIR)/index $(DIR)/reverse

$(DIR)/%: %.cpp
	mkdir -p $(DIR)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: clean all

clean:
	rm -rf $(DIR)

