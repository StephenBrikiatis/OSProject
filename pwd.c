/*Authors: Stephen Brikiatis
Class:  CSI-385-01
Assignment: FAT12
Date Assigned: 08/30/16
Due Date: 11/2/16

Description: This code is will print the working directory of the FAT12 system.

Certification of Authenticity:
We certify that this assignment is entirely our own work.
*/
#include <stdio.h>
#include "varManip.h"

#define SECTOR_SIZE = 512;
#define SUPER_VAR_SECTOR = 2722;

extern SuperVar readSuperVars();

int main(int argc, char *argv[]){
  
    unsigned char *currentSector;
    SuperVar data;
  
  if(argc != 1)
    {
      printf("Error: to many inputs.");
      return -1;
    }
  else
    {
      currentSector = data.directoryName; 

      printf("%s", currentSector);
    }
  return 0;
}
