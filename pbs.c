#include <stdio.h>
#include <stdlib.h>

#include "superVar.h"

#define BYTES_TO_READ_IN_BOOT 512;

FILE *FILE_SYSTEM;
int BYTES_PER_SECTOR;

extern int read_sector(int sector_number, char* buffer);

typedef struct{
    int BytesPerSector;
    int SectorsPerCluster;
    int NumOfFats;
    int NumOfReservedSectors;
    int NumOfRootEntries;
    int TotalSectorCount;
    int SectorsPerFat;
    int SectorsPerTrack;
    int NumberOfHeads;
    int BootSig;
    int VolumeID;
    char VolumeLabel[12];
    char *FileSystemType[9];
    
} sectorLabels; //Easier to hold the order of the variables this way

extern SuperVar readSuperVars();
extern int read_sector();
int main()
{
    unsigned char *boot;
    
    int mostSignificantByte;
    int leastSignificantByte;
    int midVar1, midVar2, i;
    SuperVar holder;
    sectorLabels listings;
    
    holder = readSuperVars();
    
    FILE_SYSTEM = fopen(holder.floppyName, "r+");
    if(FILE_SYSTEM == NULL)
    {
        perror("File did not open.");
        exit(-1);
    }
    
    BYTES_PER_SECTOR = BYTES_TO_READ_IN_BOOT;
    
    boot = (unsigned char*) malloc(BYTES_PER_SECTOR * sizeof(unsigned char));
    
    if(read_sector(0, boot) == -1)
    {
        perror("Sector could not be read.");
        exit(0);
    }
    
    mostSignificantByte = (((int) boot[12]) << 8);
    leastSignificantByte = ((int) boot[11]);
    listings.BytesPerSector = mostSignificantByte | leastSignificantByte;
    
    mostSignificantByte = ((int) boot[13]);
    listings.SectorsPerCluster = mostSignificantByte;
    
    mostSignificantByte = (((int) boot[15]) << 8);
    leastSignificantByte = ((int) boot[14]);
    listings.NumOfReservedSectors = mostSignificantByte | leastSignificantByte;
    
    mostSignificantByte = ((int) boot[16]);
    listings.NumOfFats = mostSignificantByte;
    
    mostSignificantByte = (((int) boot[18]) << 8);
    leastSignificantByte = ((int) boot[17]);
    listings.NumOfRootEntries = mostSignificantByte | leastSignificantByte;
    
    mostSignificantByte = (((int) boot[20]) << 8);
    leastSignificantByte = ((int) boot[19]);
    listings.TotalSectorCount = mostSignificantByte | leastSignificantByte;
    
    mostSignificantByte = (((int) boot[23]) << 8);
    leastSignificantByte = ((int) boot[22]);
    listings.SectorsPerFat = mostSignificantByte | leastSignificantByte;
    
    mostSignificantByte = (((int) boot[25]) << 8);
    leastSignificantByte = ((int) boot[24]);
    listings.SectorsPerTrack = mostSignificantByte | leastSignificantByte;
    
    mostSignificantByte = (((int) boot[27]) << 8);
    leastSignificantByte = ((int) boot[26]);
    listings.NumberOfHeads = mostSignificantByte | leastSignificantByte;
    
    mostSignificantByte = ((int) boot[38]);
    listings.BootSig = mostSignificantByte;
    
    mostSignificantByte = (((int) boot[42]) << 24);
    midVar1 = (((int) boot[41]) << 16);
    midVar2 = (((int) boot[40]) << 8);
    leastSignificantByte = ((int) boot[39]);
    listings.VolumeID = (mostSignificantByte | midVar1 | midVar2 | leastSignificantByte);
    
    for(i = 0; i < 11; i++)
    {
        listings.VolumeLabel[i] = boot[43+i];
    }
    
    for(i = 0; i < 8; i++)
    {
        listings.FileSystemType[i] = boot[54+i];
    }
    
    printf("Bytes per sector = %d\n", listings.BytesPerSector);
    printf("Sectors per cluster = %d\n", listings.SectorsPerCluster);
    printf("Number of FATs = %d\n", listings.NumOfFats);
    printf("Number of reserved sectors = %d\n", listings.NumOfReservedSectors);
    printf("Number of root entries = %d\n", listings.NumOfRootEntries);
    printf("Total sector count = %d\n", listings.TotalSectorCount);
    printf("Sectors per FAT = %d\n", listings.SectorsPerTrack);
    printf("Sectors per track = %d\n", listings.SectorsPerTrack);
    printf("Number of heads = %d\n", listings.NumberOfHeads);
    printf("Boot signature = 0x%04x\n", listings.BootSig);
    printf("Volume ID = 0x%08x\n", listings.VolumeID);
    printf("Volume label = %s\n", listings.VolumeLabel);
    printf("File system type = %s\n", listings.FileSystemType);
}