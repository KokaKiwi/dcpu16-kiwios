#ifndef HAT_H_
#define HAT_H_

#include <types.h>

#define INODE_TYPE_UNUSED      0
#define INODE_TYPE_DIRECTORY   1
#define INODE_TYPE_FILE        2

struct section_header
{
    u16 version;               // Default: 0x4001
    u16 num_sectors;           // total number of sectors in the filesystem.
    u16 sector_map_start[2];   // address of the start of the sector map.
    u16 sector_joins_start[2]; // address of the start of the array of sector joins.
    u16 sectors_start[2];      // address of the first sector on disk.
    u16 sector_size;           // size of each sector in the filesystem.
    u16 sectors_used;          // number of sectors that are currently in use.
};

struct inode
{
    u16 type;
    u16 num_links;
    u16 content_size[2];
};

struct link
{
    u16 strip_start_sector;
    char filename[15];
};

extern void hat_format(const Media *);

#endif
