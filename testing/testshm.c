#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMKEY 666
#define SHMSIZE 500


void main(int argc, char *argv[])
{
  int shm_ID =0;
  void *pointer = NULL;

  if(argc < 2)
    {
      printf("Usage: ./shmA textmessage\n\n");
      exit(-1);
    }

  if((shm_ID = shmget(SHMKEY, SHMSIZE, IPC_CREAT | 0666)) < 0)
    {
      perror("Error creating SHM segment.");
      exit(-1);
    }
  else
    {
      printf("\nSHM segment has been created. \n");
    }

  if((pointer = shmat(shm_ID, NULL, 0)) == NULL)
    {
      perror("Error including SHM address space.");
      exit(0);
    }
  else
    {
      printf("Allocating SHM to my address space.\n");
    }

  printf("Copying message into shared memory...\n");
  memcpy(pointer, argv[1], strlen(argv[1]) +1);

  if(shmdt(pointer) < 0)
    {
      perror("Error deallocating shared memory.");
      exit(-1);
    }
  else
    {
      printf("SHM has been deallovated.\n");
    }
}
