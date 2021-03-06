CXX = g++
LEX = flex
YACC = bison

CXXFLAGS = -W -Wall  -g

HEADERS = driver.h tokens.h ast.h context.h  code_gen_ctx.h parser.hh position.hh \
	scanner.h stack.hh  location.hh 

all: minic
parser.cc: parser.y
	$(YACC) -o parser.cc --defines=parser.hh parser.y

scanner.cc: scanner.l
	$(LEX) -o scanner.cc scanner.l

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

minic: parser.o scanner.o driver.o main.o code_gen.o code_gen_ctx.o
	$(CXX) -o $@ $^

clean:
	rm -f minic *.o 

debug:
	$(YACC) -o parser.cc --graph=graph.out --report=solved --report-file=report.output  parser.y

clean_debug:
	rm -f graph.out 
	rm -f graph.out report.output
extraclean: clean
	rm -f parser.cc parser.hh scanner.cc
