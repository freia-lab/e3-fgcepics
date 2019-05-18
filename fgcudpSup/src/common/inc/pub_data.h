// ../../sw/lib/fgceth/fgcepics/fgcudpSup/src/common/inc/pub_data.h - This file is automatically generated by `parser/Output/EPICS/asynDriver/pub_data.pm`  DO NOT EDIT
#ifndef PUB_DATA_H
#define PUB_DATA_H

#include <cstdint>

#include "classes/62/62_stat.h"
#include "classes/63/63_stat.h"

#define FGCD_MAX_DEVS 65

#define FGC_DEVICE_IN_DB    0x01
#define FGC_DATA_VALID      0x02
#define FGC_CLASS_VALID     0x04



/*----- UDP Data_header -----*/

struct fgc_udp_header
{
    uint32_t    id;                 // Context dependent ID
    uint32_t    sequence;           // Sequence number
    int32_t     send_time_sec;      // Timestamp of data send (sec)
    int32_t     send_time_usec;     // Timestamp of data send (usec)
};

/*----- Boot structure (40 bytes) -----*/

struct boot_stat
{
    uint8_t     reserved0[10];                  // Union with fgc50_stat
    uint8_t     reserved1[2];
    uint32_t    code_request;                   // Code slot requests (slots 0-31)
    uint8_t     reserved2[2];
    char        rterm[21];                      // Remote terminal data
    uint8_t     reserved3;
};

/*----- Common structure (40 bytes) -----*/

struct common_stat
{
    uint16_t    st_faults;                      // Faults
    uint16_t    st_warnings;                    // Warnings
    uint16_t    st_latched;                     // Latched status
    uint16_t    st_unlatched;                   // Unlatched status
};

/*----- Class specific data (40 bytes) -----*/

union fgc_pub_class_data
{
    uint32_t            alarms;
    struct boot_stat    boot;
    struct common_stat  common;
    struct fgc62_stat   c62;
    struct fgc63_stat   c63;
    uint8_t             reserved[40];
};

/*----- Published status structure declaration -----*/

struct fgc_stat
{
    uint8_t     data_status;                    // [0x00] Class data status
    uint8_t     class_id;                       // [0x01] Class ID for the device
    uint8_t     reserved0;                      // [0x02] FGC command status byte
    uint8_t     runlog;                         // [0x03] FGC runlog data byte

    uint8_t     reserved1[12];                  // [0x04] Padding

    union fgc_pub_class_data class_data;        // [0x10] Class specific data
};

/*----- Published data structure -----*/

struct Pub_data
{
    struct fgc_udp_header   header;
    uint32_t                time_sec;
    uint32_t                time_usec;
    struct fgc_stat         status[FGCD_MAX_DEVS];
};



#endif
// End of file: ../../sw/lib/fgceth/fgcepics/fgcudpSup/src/common/inc/pub_data.h
