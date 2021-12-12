CXXFLAGS := -g -std=c++17 -Wall -Wextra
LDFLAGS := -g -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

SOURCES := $(wildcard *.cc)
OBJECTS := $(patsubst %.cc,%.o,$(SOURCES))

all: game

.PHONY: clean
clean:
	rm -f game $(OBJECTS) $(DEPS)

game: $(OBJECTS)
	g++ $(CXXFLAGS) -o game $(OBJECTS) $(LDFLAGS)

$(OBJECTS): %.o: %.cc
	g++ $(CXXFLAGS) -c -o $@ $<
