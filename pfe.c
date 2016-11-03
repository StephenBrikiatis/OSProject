/*
 *Author: Stephen Brikiatis, Kelly Morrissey
 *Class: CSI-385-01
 *Assignment: FAT 12
 *Date Assigned: 08/30/16
 *Due Date: 11/02/16
 *
 * Description: This code locates FAT entries and prints them out to the user
 * 
 * Certification of Authenticity: I certify that this assignment is entirely my own work.  
 */
#include <stdio.h>
#include <stdlib.h>

extern get_fat_entry(int fat_entry_number, unsigned char* fat);

FILE* FILE_SYSTEM_ID;
int BYTES_PER_SECTOR;

int main(int argc, char *argv[])
{
    
    if(argc > 3)
    {
        printf("Too many items.");
        exit(-1);
    }
    else if(argc < 3)
    {
        printf("Too few items.");
        exit(-1);
    }
    
    if(argv[2] > argv[3])
    {
        printf("The first entry cannot be smaller than the second.");
        exit(-1);
    }
    else if(argv[2] < 2)
    {
        printf("Cannot access this entry.");
    }
    
    
    return 0;
}