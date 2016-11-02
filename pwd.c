#include <stdio.h>
#include <fatSupport.h>
#include "varManip.h"

#define SECTOR_SIZE = 512;
#define SUPER_VAR_SECTOR = 2722;

extern SuperVar readSuperVars();

int main(int argc, char *argv[]){
  
    unsigned char *currentSector;
    SuperVar 
    
  
  if(argc != 1)
    {
      printf("Error: to many inputs.");
      return -1;
    }
  else
    {
      

      printf("%s", currentSector);
    }
  return 0;
}
