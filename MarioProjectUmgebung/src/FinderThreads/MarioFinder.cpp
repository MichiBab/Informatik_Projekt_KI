#include "header/MarioFinder.h"
#include "../TemplateMatching/header/TemplateMatcher.h"
#include "../main/header/Globals.h"
/*class MarioFinder{
    private:
        ImageDistributor distr;
        PngImage& resized;
        int x_pos;
        int y_pos;
    public:
        MarioFinder();
        ~MarioFinder();
        bool search_for_Mario();
        bool search_for_Mario(int x_start, int x_end, int y_start, int y_end);
};*/

int MarioFinder::return_x_pos(){
    return x_pos;
}
int MarioFinder::return_y_pos(){
    return y_pos;
}

MarioFinder::MarioFinder(): x_pos(0), y_pos(0), resized(distr.grab_resized_img() ){
    //resized = distr.grab_resized_img();
}

MarioFinder::~MarioFinder(){

}


bool MarioFinder::search_for_Mario(){
    return (search_for_Mario(0,resized.return_width()-TILESIZE, 0,  resized.return_height()-TILESIZE ));
}

void MarioFinder::search_for_Mario_threaded(int x_start, int x_end, int y_start, int y_end, bool *boolean){
    *boolean = search_for_Mario(x_start, x_end, y_start, y_end);
}

bool MarioFinder::search_for_Mario(int x_start, int x_end, int y_start, int y_end){
    TemplateMatcher matcher(resized);
    bool am_i_done = false;
    int erg = 0;
    while(true){
        PngImage& rBlock = distr.grab_next_mario_Small_img(&am_i_done);
        if(am_i_done){break;}
        for(int y = y_start; y < y_end;y++){
            for(int x = x_start; x < x_end;x++){
                erg = matcher.match_tilesize_on_pixel(x,y,rBlock, tilesize_mario_x, tilesize_mario_y);
                if(IS_A_MARIO_MATCH(erg)){
                    x_pos=x;
                    y_pos=y;
                   // printf("mario found on: x = %d y = %d",x,y);
                    return true;
                }
            }
        }
    }
    //BigMario
    while(true){
        PngImage& rBlock = distr.grab_next_mario_Shroom_img(&am_i_done);
        if(am_i_done){break;}
        for(int y = y_start; y < y_end;y++){
            for(int x = x_start; x < x_end;x++){
                erg = matcher.match_tilesize_on_pixel(x,y,rBlock, tilesize_mario_big_x, tilesize_mario_big_y);
                if(IS_A_MARIO_MATCH(erg)){
                    x_pos=x;
                    y_pos=y;
                    return true;
                }
            }
        }
    }
    while(true){
        PngImage& rBlock = distr.grab_next_mario_Fire_img(&am_i_done);
        if(am_i_done){break;}
        for(int y = y_start; y < y_end;y++){
            for(int x = x_start; x < x_end;x++){
                erg = matcher.match_tilesize_on_pixel(x,y,rBlock, tilesize_mario_big_x, tilesize_mario_big_y);
                if(IS_A_MARIO_MATCH(erg)){
                    x_pos=x;
                    y_pos=y;
                    return true;
                }
            }
        }
    }
    return false;
}
