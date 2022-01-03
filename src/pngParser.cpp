#include "pngParser.hpp"


// Read the IHDR chunk from the png file header
inline std::pair<uint32_t, uint32_t> PngParser::readIHDRChunk(std::ifstream& imageFile) {
    uint32_t chunkLength = 0; 
    uint32_t chunkType = 0;

    imageFile.read((char*)&chunkLength,sizeof(chunkLength));
    chunkLength = Utils::convertBitToLittleEndian(chunkLength);
    
    if(chunkLength > 0) {
        imageFile.read((char*)&chunkType,sizeof(chunkType));
        if(chunkType == IHDR_CHUNK_TYPE) {
            IHDR_CHUNK chunk;
            imageFile.read((char*)&chunk, sizeof(chunk));
            int finalWidth = Utils::convertBitToLittleEndian(chunk.width);
            int finalHeight = Utils::convertBitToLittleEndian(chunk.height);
        
            return std::make_pair(finalWidth, finalHeight);
        }
    } 
    return INVALID_CHUNK;
}

// Get the image dimenstions from given .png file
std::pair<int,int> PngParser::getImageDimensions(const std::string& imageFilePath) {
    std::ifstream imageFile(imageFilePath); 
    PNG_HEADER pngHeader;

    if(imageFile.is_open()) {
        imageFile.read((char*)&pngHeader.fileSignature, sizeof(pngHeader.fileSignature));
        if(pngHeader.fileSignature == PNG_FILE_SIGNATURE) {
            return readIHDRChunk(imageFile); // Get IHDR chunk from .png file                 
        }             
        return NOT_PNG_FILE; // Not a png file
    } 
    return COULD_NOT_OPEN_FILE; // Could not open file
}
