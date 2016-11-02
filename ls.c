/*Authors: Stephen Brikiatis and Kelly Morrissey
Class:  CSI-385-01
Assignment: FAT12
Date Assigned: 08/30/16
Due Date: 11/2/16

Description: This code holds the control of the ls command in relation to the FAT12.

Certification of Authenticity:
We certify that this assignment is entirely our own work.

*/
#include <stdio.h>

void listDirectory(*char directoryName, *char currentDir, int location)
{

}

void listFile(*char filename, *char currentDir, int location)
{
  char name[11];
  int nameLength = 0;
  char holder;
  int fileType = 0;
  int fileSize = 0;
  int flc = 0;
  int i;
  
  for(i = 0; i < 8; i++)
    {
      holder = currentDir[location+i];
      if(holder != ' ')
	{
	  name[i] = holder;
	  nameLength++;
	}
    }
  name[nameLength] = '.';

  for(i = 0; i < 3; i++)
    {
      holder = currentDir[0x08+location+i];
      if(holder != ' ')
	{
	  nameLength++;
	  name[nameLength] = holder;
	}
    }

  fileType = currentDir[location+0x0B];

  //file size require the concataination of 4 variables

  
}

void listSingleItem(*char filename)
{
  //need to open the current section here or pass it in
  char fileSelection[11];
  int position = 0x00;
  int i;
  char fileType;
  int condition = 0 ; //1 is found 0 is no such file -1 is doesn't exist
  
  do
    {
      for(i = 0; i < 11; i++)
	{
	  fileSelection[i] = currentDir[position + i];
	}

      if(fileSelection == filename)
	{
	  fileType = currentDir[position + 0x0B];
	  if(fileType == 0x10)
	    {
	      listDirectory(filename);
	    }
	  else
	    {
	      listFile(filename);
	    }
	  condition = 1;
	}
      else if(fileSelection[0] == 0x00 | fileSelection[0] == 0xF6)
	{
	  condition = -1;
	}
      else
	{
	  position = postion + 0x20;
	}
    }while(condition == 0);
  
}

void listAllFiles()
{
  //need to open the current section here or pass it in
  char fileName[11];
  int position = 0x00;
  int FCN;
  int type;
  int size;

  do
    {
      
    }while(fileName[0] != 0x00 | fileName[0] != 0xF6);
}


int main(int argc, char *argv[])
{
  
  if(argc > 2)
    {
      printf("Too many elements.");
    }
  else if(argc == 2)
    {
      listSingleFile(argv[1]);
    }
  else
    {
      listAllFiles();
    }

  return 0;
}
