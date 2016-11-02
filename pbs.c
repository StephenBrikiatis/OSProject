#include <stdio.h>

#define BYTES_TO_READ_IN_BOOT 512;

FILE *FILE_SYSTEM;
int BYTES_PER_SECTOR;

extern int read_sector(int sector_number, char* buffer);

typedef struct{
    int BytesPerSector;
    int SectorsPerCluster;
    int NumOfFats;
    int NumOfReservedSectors;
} sectorLabels;

int main()
{
    unsigned char *boot;
    
}