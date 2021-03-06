#ifndef pngimage_h
#define pngimage_h

#include <png.h>
#include <zlib.h>
class PngImage{
    private:
        int width;
        int height;
        png_byte color_type;
        png_byte bit_depth;
        char* filename;
        bool read_png_file(const char* filename);  
    public:
        png_bytep *row_pointers = NULL;
        PngImage(const char *filename);
        PngImage();//? ist das ok?
        ~PngImage();
        int return_height();
        int return_width();
};

#endif