#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define SECTOR_SIZE 512

typedef struct {
    char magic[4];          // "MYCD"
    uint8_t version;        // 1
    uint16_t sector_size;   // 512
    uint32_t num_sectors;   // total sectors
    char volume_name[16];   // volume label
} CDHeader;

// Create an empty .cd disk
void create_disk(const char *disk_name, uint32_t sectors, const char *volume) {
    FILE *f = fopen(disk_name, "wb");
    if (!f) { perror("fopen"); exit(1); }

    // Prepare header
    CDHeader header = {0};
    memcpy(header.magic, "MYCD", 4);
    header.version = 1;
    header.sector_size = SECTOR_SIZE;
    header.num_sectors = sectors;
    strncpy(header.volume_name, volume, 16);

    fwrite(&header, sizeof(CDHeader), 1, f);

    // Pre-allocate remaining disk (pad to exact sectors)
    fseek(f, sectors * SECTOR_SIZE - 1, SEEK_SET);
    fputc(0, f);

    fclose(f);
    printf("Created disk '%s' with %d sectors (%d bytes).\n",
           disk_name, sectors, sectors * SECTOR_SIZE);
}

int main() {
    // Example: create a 1000-sector floppy-style disk
    create_disk("test.cd", 1000, "MYDISK");

    return 0;
}
