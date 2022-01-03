#ifndef PNG_PARSER_HPP 
#define PNG_PARSER_HPP

#include "PngHeader.hpp"
#include "IHDRChunk.hpp"
#include "Utils.hpp"

#include <utility>
#include <fstream>

class PngParser{
    private:
        // PNG File signature 8 byte value
        #define PNG_FILE_SIGNATURE 727905341920923785

        // Parsing errors
        #define NOT_PNG_FILE std::make_pair(0,0)
        #define COULD_NOT_OPEN_FILE std::make_pair(-1,-1)
        #define INVALID_CHUNK std::make_pair(-2,-2)

        // IHDR Chunk type value
        #define IHDR_CHUNK_TYPE 1380206665

        std::pair<uint32_t, uint32_t> readIHDRChunk(std::ifstream&);

    public:
        PngParser() {};
        ~PngParser() {};
        
        std::pair<int,int> getImageDimensions(const std::string&);

        

};	
#endif
