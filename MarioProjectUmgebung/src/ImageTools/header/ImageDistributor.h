#ifndef imagedistributor_h
#define imagedistributor_h

#include "PngImage.h"
#include "ImageLibrary.h"

#define MARIOSMALL 0
#define MARIOSHROOM 1
#define MARIOFIRE 2
#define ENEMY 3
#define ITEMNONSTATIC 4
#define ITEMSTATIC 5
#define BLOCK 6

class ImageDistributor{
    private:
        ImageLibrary* ImgLib_ptr;
        int tmp_mario_Small_img_count;
        int tmp_mario_Shroom_img_count;
        int tmp_mario_Fire_img_count;
        int tmp_enemy_img_count;
        int tmp_item_Non_Static_img_count;
        int tmp_item_Static_img_count;
        int tmp_block_img_count;
        PngImage& img_grabber(int modi, int* counter, bool* done, std::vector<PngImage> *vec);
    public:
        PngImage& grab_next_mario_Small_img(bool* done);
        PngImage& grab_next_mario_Shroom_img(bool* done);
        PngImage& grab_next_mario_Fire_img(bool* done);
        PngImage& grab_next_enemy_img(bool* done);
        PngImage& grab_next_item_Non_Static_img(bool* done);
        PngImage& grab_next_item_Static_img(bool* done);
        PngImage& grab_next_block_img(bool* done);
        PngImage& grab_input_img();
        PngImage& grab_resized_img();
        ImageDistributor();
        ~ImageDistributor();
};

#endif