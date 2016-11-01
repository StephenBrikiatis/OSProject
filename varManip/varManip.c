#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMKEY 1234
#define SHMSIZE 1024

SuperVar readSuperVars()
{
	int shm_ID = 0;
	void *pointer = NULL;
	SuperVar data;
	
	if((shm_ID = shmget(SHMKEY, SHMSIZE, 0444)) < 0)
	{
		perror("Error creating SHM segment.");
		exit(-1);
	}
	
	if((pointer = shmat(shm_ID, NULL, 0)) == NULL)
	{
		perror("Error including SHM address space.");
		exit(0);
	}
	
	data = (SuperVar) pointer;
	
	if(shmdt(pointer) < 0)
	{
		perror("Error deallocating shared memory.")
	}
	
	return data;
}

void writeSuperVars(SuperVar data)
{
	
	
}