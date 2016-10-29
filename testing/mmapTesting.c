#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  int fp;
  int fileSize = 0;
  char *addr;
  struct stat st;
  
  fp = open("test.txt", O_RDWR);
  stat("test.txt", &st);
  fileSize = st.st_size;
  
  addr = mmap(0x1234, fileSize, PROT_WRITE, MAP_SHARED, fp, 0);
  if(addr == MAP_FAILED)
    {
      printf("mmap failed.");
    }

  printf("%d\n%s\n%d", fileSize, addr, *addr);
  
  close(fp);

  return 0;
}
