all: shellOS Pwd pbs
shellOS: shell.c varManip.c
	gcc -o shellOS shell.c varManip.c -I.
Pwd: pwd.c varManip.c
	gcc -o Pwd pwd.c varManip.c -I.
pbs: pbs.c varManip.c fatSupport.c
	gcc -o pbs pbs.c varManip.c fatSupport.c -I.
