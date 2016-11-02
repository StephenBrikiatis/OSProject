CC=gcc
DEPS = ../varManip/superVar.h ../varManip/varManip.h

%.c $(DEPS)
	$(CC) -c -o $@ $<

shell: main.c
	gcc -o shell main.c 
