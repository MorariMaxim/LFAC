CC = g++
CFLAGS = -Wall -std=c++11 

target = limbaj

target_src = GeneralInfo.cpp lex.yy.c limbaj.tab.c symbolTable.cpp 
to_clean = lex.yy.c limbaj.tab.c limbaj

all: $(target)

$(target): $(target_src)
	$(CC) $(CFLAGS) -o $(target) $(target_src) $(LDFLAGS)

limbaj.tab.c: limbaj.y
	bison -d limbaj.y

lex.yy.c: limbaj.l
	lex limbaj.l

clean:
	rm -f $(to_clean) 