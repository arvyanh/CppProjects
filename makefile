# makefile for text.c

CC=g++
CFLAGS=-Wall -Werror -g
OBJS=text.o page.o line.o prompt.o
HEADERS=$(subst .o,.h,$(OBJS)) # text.h page.h ...
LIBS=-lncurses

edit: $(OBJS)
	$(CC) $(CFLAGS) -o edit $(OBJS) $(LIBS)

# '$<' expands to first prerequisite file
# NOTE: this rule is already implicit
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@ 

.PHONY: clean

clean:
	rm -f $(OBJS) *.txt edit

