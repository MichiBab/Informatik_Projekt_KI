/*
 * A simple libpng example program
 * http://zarb.org/~gc/html/libpng.html
 *
 * Modified by Yoshimasa Niwa to make it much simpler
 * and support all defined color_type.
 *
 * To build, use the next instruction on OS X.
 * $ brew install libpng
 * $ clang -lz -lpng16 libpng_test.c
 *
 * Copyright 2002-2010 Guillaume Cottenceau.
 *
 * This software may be freely redistributed under the terms
 * of the X11 license.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <png.h>
#include <zlib.h>

#define size(x) ((int)(sizeof(x)/sizeof(*x))) //array size for integer array

int width, height;
png_byte color_type;
png_byte bit_depth;
png_bytep *row_pointers = NULL;
png_bytep *new_row_pointers = NULL;

void read_png_file(char *filename) {
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
}

void resize_png_file(int x_start, int y_start, int x_end, int y_end) {
  int new_width = x_end-x_start +1;
  int new_height = y_end-y_start +1;
  
  //IO Operations
  FILE *fp = fopen("pictures/Resized/resized.png", "wb");
  if(!fp) abort();

  png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (!png) abort();
  png_infop info = png_create_info_struct(png);
  if (!info) abort();
  if (setjmp(png_jmpbuf(png))) abort();
  png_init_io(png, fp);

  // Output is 8bit depth, RGBA format.
  png_set_IHDR(
    png,
    info,
    new_width, new_height,
    8,
    PNG_COLOR_TYPE_RGBA,
    PNG_INTERLACE_NONE,
    PNG_COMPRESSION_TYPE_DEFAULT,
    PNG_FILTER_TYPE_DEFAULT
  );
  png_write_info(png, info);

  // Init new row pointers
  new_row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * new_height);
  for(int y = 0; y < height; y++) {
    new_row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png,info));
  }
  if (!new_row_pointers) abort();

  //resizing, copy Pixels in Scope
  for(int y = y_start; y <= y_end; y++) {
    png_bytep row = row_pointers[y];
    png_bytep new_row = new_row_pointers[y - y_start];
    for(int x = x_start; x <= x_end; x++) {
      png_bytep px = &(row[x * 4]);
      png_bytep new_px = &(new_row[(x - x_start) * 4]);
      // Do something awesome for each pixel here...
      new_px[0] = px[0];
      new_px[1] = px[1];
      new_px[2] = px[2];
      new_px[3] = px[3];
    } 
  }
  //Write
  png_write_image(png, new_row_pointers);
  png_write_end(png, NULL);
  //Clean
  /*for(int y = 0; y <= new_height; y++) {
    free(new_row_pointers[y]); //NOT WORKING?
  }*/ 
  free(new_row_pointers);

  //free(new_row_pointers);
  png_destroy_write_struct(&png, &info);
  fclose(fp);
}


void process_png_file() {

  for(int y = height-1; y >= 0; y--) {
    png_bytep row = row_pointers[y];
    for(int x = width-1; x >= 0; x--) {
      png_bytep px = &(row[x * 4]);
      //printf("%4d, %4d = RGBA(%3d, %3d, %3d, %3d)\n", x, y, px[0], px[1], px[2], px[3]);
      
      // Do something awesome for each pixel here...

    }

      
  }

}

int main(int argc, char *argv[]) {
  if(argc < 2) abort();
  read_png_file(argv[1]);
  //process_png_file();
  resize_png_file(0,0,719,719);
  return 0;
}



