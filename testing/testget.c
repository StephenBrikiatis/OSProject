#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMKEY 666
#define SHMSIZE 500

void main()
{
  int shm_ID = 0;
  void *pointer = NULL;

  if((shm_ID = shmget(SHMKEY, SHMSIZE, 0444)) < 0)
    {
      perror("Eror getting SHM segment.");
      exit(-1);
    }
  else
    {
      printf("\nSHM segment has been found.\n");
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

  printf("Fetching message from shared memory:\n");
  printf("\n%s\n", (char*) pointer);

  if(shmdt(pointer) < 0)
    {
      perror("Error deallocating shared memory.");
      exit(-1);
    }
  else
    {
      printf("SHM has been deallcated.\n");
    }
}
