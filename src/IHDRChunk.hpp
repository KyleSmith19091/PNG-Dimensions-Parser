#ifndef IHDR_CHUNK_HPP 
#define IHDR_CHUNK_HPP

#include <cstdint>

typedef struct __attribute__ ((packed)) IHDR_DATA {
    uint32_t width;
    uint32_t height;
    uint8_t bitDepth;
    uint8_t colorType;
    uint8_t compressionMethod;
    uint8_t filterMethod;
    uint8_t interlaceMethod;
} IHDR_CHUNK;

#endif
