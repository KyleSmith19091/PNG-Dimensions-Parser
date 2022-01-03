#ifndef PNG_HEADER_HPP 
#define PNG_HEADER_HPP

#include <cstdint>

// PNG Format Signature
typedef struct __attribute__ ((packed)) PNG_HEADER {
    uint32_t chunkSize;
    uint32_t chunkType;
    uint32_t CRC;
    uint64_t fileSignature;
} PNG_HEADER;

#endif
