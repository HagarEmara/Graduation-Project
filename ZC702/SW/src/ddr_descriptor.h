#ifndef _DDR_DESCRIPTOR_H_
#define _DDR_DESCRIPTOR_H_

#include <stdint.h>

#define DDR_DESCRIPTOR_BASE       0x0C800000
#define DDR_DESCRIPTOR_MAGIC      0x5A544131
#define DDR_DESCRIPTOR_VERSION    1
#define DDR_DESCRIPTOR_MAX_FILES  16
#define DDR_DESCRIPTOR_NAME_LEN   64
#define DDR_MODEL_BASE            0x0C900000

typedef struct {
    char     name[DDR_DESCRIPTOR_NAME_LEN];
    uint32_t ddr_addr;
    uint32_t size;
    uint32_t crc32;
    uint32_t reserved;
} DdrFileEntry;

typedef struct {
    uint32_t     magic;
    uint32_t     version;
    uint32_t     num_files;
    uint32_t     reserved;
    DdrFileEntry files[DDR_DESCRIPTOR_MAX_FILES];
} DdrDescriptor;

#endif
