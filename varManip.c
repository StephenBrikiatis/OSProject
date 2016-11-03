/*Authors: Stephen Brikiatis
Class:  CSI-385-01
Assignment: FAT12
Date Assigned: 08/30/16
Due Date: 11/2/16

Description: This code is the main code for variables manipulation of the ones to be held outside of 
the main systems since all will need access.

Certification of Authenticity:
We certify that this assignment is entirely our own work.
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "superVar.h"

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
	
	memcpy(&data, pointer, sizeof(pointer));
	
	if(shmdt(pointer) < 0)
	{
		perror("Error deallocating shared memory.");
	}
	
	return data;
}

void writeSuperVars(SuperVar data)
{
	
	
}

void startSuperVars() //This should only be run with the shell
{
    SuperVar data;
    int shm_ID = 0;
    void *pointer = NULL;
    
    data.sector = 19;
    data.floppyName = "floppy1";
    data.directoryName = "/";

    if((shm_ID = shmget(SHMKEY, SHMSIZE, IPC_CREAT | 0666)) < 0)
    {
        perror("Shell was unable to create SuperVars");
        exit(-1);
    }
    
    if((pointer = shmat(shm_ID, NULL, 0)) < 0)
    {
        perror("Unable to put SuperVars into memory");
        exit(0);
    }
    
    memcpy(pointer, &data, sizeof(data));
    
    if(shmdt(pointer) < 0)
    {
        perror("Couldn't deallocate SuperVars.");
        exit(0);
    }
}