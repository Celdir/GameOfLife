CXX = g++ -std=c++14
OPTS = -g -O2 -lsfml-graphics -lsfml-window -lsfml-system
DEPS = -MMD -MF $*.d 
SOURCES = cell.cpp grid.cpp

OBJS = game.o

default: $(OBJS)

clean:
	rm -rf Dependencies $(OBJS)

%.o: %.cpp $(SOURCES)
	$(CXX) $(OPTS) $(DEPS) $(SOURCES) $< -o $@
	cat $*.d >> Dependencies
	rm -f $*.d

-include Dependencies
