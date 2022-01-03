namespace Utils {
    
    // Convert big endian to little endian (png format uses big endian)
    constexpr int convertBitToLittleEndian(int i) {
          unsigned char c1 = 0, c2 = 0, c3 = 0, c4 = 0;
          c1 = i & 255;
          c2 = (i >> 8) & 255;
          c3 = (i >> 16) & 255;
          c4 = (i >> 24) & 255;
          return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
    };

} // namespace Utils
