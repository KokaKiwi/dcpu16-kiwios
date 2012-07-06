#ifndef HMD_H_
#define HMD_H_

#include "boot.h"

// Constants
#define QUERY_MEDIA_PRESENT         0x0000
#define QUERY_MEDIA_PARAMETERS      0x0001
#define QUERY_DEVICE_FLAGS          0x0002
#define UPDATE_DEVICE_FLAGS         0x0003
#define QUERY_INTERRUPT_TYPE        0x0004
#define SET_INTERRUPT_MESSAGE       0x0005
#define READ_SECTORS                0x0010
#define WRITE_SECTORS               0x0011
#define QUERY_MEDIA_QUALITY         0xFFFF

#define TYPE_NONE                   0x0000
#define TYPE_MEDIA_STATUS           0x0001
#define TYPE_READ_COMPLETE          0x0002
#define TYPE_WRITE_COMPLETE         0x0003

#define QUALITY_AUTHENTIC           0x7FFF
#define QUALITY_OTHER               0xFFFF

#define MEDIA_ERROR_NONE            0x0000
#define MEDIA_ERROR_NO_MEDIA        0x0001
#define MEDIA_ERROR_INVALID_SECTOR  0x0002
#define MEDIA_ERROR_PENDING         0x0003

typedef struct media Media;
struct media
{
    unsigned words_per_sector, sectors, write_locked;
};

extern void detect_drive(void);
extern unsigned media_present(void);
extern void media_params(Media *);
extern unsigned hmd_get_flag(void);
extern unsigned hmd_set_flag(unsigned);
extern unsigned hmd_set_interrupt_message(unsigned);
extern unsigned media_read_sector(void *, unsigned, unsigned);
extern unsigned media_write_sector(void *, unsigned, unsigned);

extern Device *d_hmd;

#endif
