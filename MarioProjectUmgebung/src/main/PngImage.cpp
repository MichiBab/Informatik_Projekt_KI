#include "PngImage.h"
#include <stdlib.h>
#include <cstring>
//Reads in the Image and fills in the row_pointers and data
bool PngImage::read_png_file(const char* filename){
    FILE *fp = fopen(filename, "rb");

    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if(!png) abort();

    png_infop info = png_create_info_struct(png);
    if(!info) abort();

    if(setjmp(png_jmpbuf(png))) abort();

    png_init_io(png, fp);

    png_read_info(png, info);

    width      = png_get_image_width(png, info);
    height     = png_get_image_height(png, info);
    color_type = png_get_color_type(png, info);
    bit_depth  = png_get_bit_depth(png, info);

    // Read any color_type into 8bit depth, RGBA format.
    // See http://www.libpng.org/pub/png/libpng-manual.txt

    if(bit_depth == 16)
        png_set_strip_16(png);

    if(color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_palette_to_rgb(png);

    // PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16bit depth.
    if(color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
        png_set_expand_gray_1_2_4_to_8(png);

    if(png_get_valid(png, info, PNG_INFO_tRNS))
        png_set_tRNS_to_alpha(png);

    // These color_type don't have an alpha channel then fill it with 0xff.
    if(color_type == PNG_COLOR_TYPE_RGB ||
     color_type == PNG_COLOR_TYPE_GRAY ||
     color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

    if(color_type == PNG_COLOR_TYPE_GRAY ||
     color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
        png_set_gray_to_rgb(png);

    png_read_update_info(png, info);

    if (row_pointers) abort();

    row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * height);
    for(int y = 0; y < height; y++) {
        row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png,info));
    }

    png_read_image(png, row_pointers);
    fclose(fp);
    png_destroy_read_struct(&png, &info, NULL);
    created_flag=true;
    return true;
}

PngImage::PngImage(const char* filename){
    read_png_file(filename);
  //  myname = filename;
}

PngImage::PngImage(){
    //for img library
}

int PngImage::return_height(){
    return PngImage::height;
}

int PngImage::return_width(){
    return PngImage::width;
}

/*
PngImage::PngImage(const PngImage& img): row_pointers((png_bytep*)malloc(sizeof(*row_pointers))){
    std::memcpy(row_pointers, img.row_pointers, sizeof(*row_pointers));
    width = img.width;
    height = img.height;
    color_type = img.color_type;
    bit_depth = img.bit_depth;
    filename = img.filename;
    created_flag = img.created_flag;
}*/

PngImage::~PngImage(){
    //Check if Image was created, to free the mallocated row pointers
    if(created_flag){
        for(int y = 0; y < height; y++) {
            free(row_pointers[y]);
        }
        free(row_pointers);
    }
}