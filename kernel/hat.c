#include <stdlib.h>
#include <hmd.h>
#include <hat.h>

void hat_format(const Media *media)
{
    // Vars
    struct section_header *header;
    struct inode *root;
    u16 *section_map;
    u16 *section_joins;
    u16 *sectors_start;
    u16 *buffer;
    unsigned i, j, k;
    
    // Init vars
    buffer = ralloc(media->words_per_sector * 2);
    
    // Write header
    header = (struct section_header *) buffer;
    header->version = 0x4001;
    header->num_sectors = media->sectors - 1;
    header->sector_size = media->words_per_sector;
    header->sectors_used = 0;
    
    // Init section map
    section_map = buffer + sizeof(struct section_header);
    header->sector_map_start[1] = sizeof(struct section_header);
    k = header->num_sectors / 16;
    if (header->num_sectors % 16)
    {
        k++;
    }
    
    // Init section joins
    section_joins = section_map + k;
    header->sector_joins_start[1] = header->sector_map_start[1] + k;
    
    // Init sectors start
    sectors_start = (u16 *) header + media->words_per_sector;
    header->sectors_start[1] = media->words_per_sector;
    
    // Init root
    root = (struct inode *) sectors_start;
    root->type = INODE_TYPE_DIRECTORY;
    section_map[0] = 0x8000;
    
    media_write_sector(buffer, 0, 2);
}
