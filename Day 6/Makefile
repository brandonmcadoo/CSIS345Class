CFILES=number.cpp constructor.cpp
OFILES=$(CFILES:.c=.o)
CC=clang -g -Wall

constructor:	$(OFILES)
	$(CC) -o constructor $(OFILES)

clean::
	/bin/rm -f constructor $(OFILES)
