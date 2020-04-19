CXX = g++
LEX = flex
YACC = bison

CXXFLAGS = -W -Wall  -g -std=c++11
LDFLAGS = 

HEADERS = driver.h ast.h parser.h position.hh \
	scanner.h stack.hh tinyContext.h location.hh 

all: tiny

parser.cc: parser.y
	$(YACC) -o parser.cc --defines=parser.h parser.y

scanner.cc: scanner.l
	$(LEX) -o scanner.cc scanner.l

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

tiny: main.o parser.o scanner.o driver.o
	$(CXX) $(LDFLAGS) -o $@ main.o parser.o scanner.o driver.o

clean: 
	rm -f tiny *.o 

extraclean: clean
	rm -f parser.cc parser.h scanner.cc
