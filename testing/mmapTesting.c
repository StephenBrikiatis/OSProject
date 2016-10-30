#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
  int fp;
  int fileSize = 0;
  char *addr;
  struct stat st;
  int error;
  
  fp = shm_open("/test.txt", O_RDWR, 0777);
  if(fp == -1)
    {
      fprintf(stderr, "Open failed:%s\n", strerror(errno));
      exit(0);
    }
  error = stat("test.txt", &st);
  if(error == -1)
    {
      printf("stat is failing");
      exit(0);
    }
  fileSize = st.st_size;
  
  addr = mmap(NULL, fileSize, PROT_WRITE, MAP_SHARED, fp, 0);
  if(addr == MAP_FAILED)
    {
      printf("mmap failed.");
    }

  printf("%d\n%s\n%d", fileSize, addr, *addr);

  write(*addr, "Goodbye", 7);
  
  printf("%d\n%s%d\n", fileSize+7, addr, *addr);
  
  munmap(addr, fileSize+7);
  //close(fp);

  return 0;
}
