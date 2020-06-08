CXX = g++
LEX = flex
YACC = bison

CXXFLAGS = -W -Wall  -g

HEADERS = driver.h tokens.h ast.h parser.hh position.hh \
	scanner.h stack.hh tinyContext.h location.hh 

parser.cc: parser.y
	$(YACC) -o parser.cc --defines=parser.hh parser.y

scanner.cc: scanner.l
	$(LEX) -o scanner.cc scanner.l

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

minic: parser.o scanner.o driver.o main.o 
	$(CXX) $(LDFLAGS) -o $@ parser.o scanner.o driver.o main.o 

clean: 
	$(CXX)  -c $(shell llvm-config --cxxflags) -fexceptions  -o $@ $<

minic: parser.o scanner.o driver.o main.o 
	$(CXX) -o $@ parser.o scanner.o driver.o main.o  $(shell llvm-config --ldflags --libs) -lpthread

clean:
	rm -f minic *.o 

debug:
	$(YACC) -o parser.cc --graph=graph.out --report=solved --report-file=report.output  parser.y

clean_debug:
	rm -f graph.out 
	rm -f graph.out report.output
extraclean: clean
	rm -f parser.cc parser.hh scanner.cc

