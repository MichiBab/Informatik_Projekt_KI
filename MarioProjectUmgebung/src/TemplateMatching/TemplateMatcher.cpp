#include "header/TemplateMatcher.h"
#include "../main/header/Globals.h"


TemplateMatcher::~TemplateMatcher(){
    
}

/*
VON UNTEN RECHTS BIS OBEN LINKS:
for(int y = height-1; y >= 0; y--) {
    png_bytep row = row_pointers[y];
    for(int x = width-1; x >= 0; x--) {
      png_bytep px = &(row[x * 4]);*/

/*  
VON OBEN LINKS BIS UNTEN RECHTS
for(int y = 0; y <height ; y++) {
    png_bytep row = row_pointers[y];
    for(int x = 0; x <width; x++) {
      png_bytep px = &(row[x * 4]);*/
//printf("%4d, %4d = RGBA(%3d, %3d, %3d, %3d)\n", x, y, px[0], px[1], px[2], px[3]);

// px+offset < sppx > px-offset

//Fehlerbehandlungen von außerhalb? für geschwindigkeit
int TemplateMatcher::match_tilesize_on_pixel(int x_pos, int y_pos, PngImage sprite){
    int matchings = 0;
    for(int y = 0; y < TILESIZE; y++){
        png_bytep img_row = input_ptr->row_pointers[y_pos+y];
        png_bytep sprite_row = sprite.row_pointers[y];
        for(int x = 0; x<TILESIZE;x++){
            png_bytep impx = &(img_row[(x_pos+x) * 4]);
            png_bytep sppx = &(sprite_row[x * 4]);
            //Compare
            printf("TO COMPARE: %4d, %4d = RGBA(%3d, %3d, %3d, %3d)\n", x_pos+x, y_pos+y, impx[0], impx[1], impx[2], impx[3]);
            printf("WITH: %4d, %4d = RGBA(%3d, %3d, %3d, %3d)\n", x, y, sppx[0], sppx[1], sppx[2], sppx[3]);
            if( ((impx[0])+ABWEICHUNG) >= sppx[0] && sppx[0] >= ((impx[0])-ABWEICHUNG) ){
                if( ((impx[1])+ABWEICHUNG) >= sppx[1] && sppx[1] >= ((impx[1])-ABWEICHUNG) ){
                    if(((impx[2])+ABWEICHUNG) >= sppx[2] && sppx[2] >= ((impx[2])-ABWEICHUNG)){
                        //printf("\nTRUE\n");
                        matchings++;
                    }
                }
            }

        }
    }
    return matchings;
}

TemplateMatcher::TemplateMatcher(PngImage& input){
    input_ptr = &input;
}