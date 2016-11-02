all: shellOS Pwd
shellOS: shell.c varManip.c
	gcc -o shellOS shell.c varManip.c -I.
Pwd: pwd.c varManip.c
	gcc -o Pwd pwd.c varManip.c -I.
