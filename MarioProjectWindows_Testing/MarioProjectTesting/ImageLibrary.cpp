#include "ImageLibrary.h"
#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

ImageLibrary* ImageLibrary::m_pInstance = NULL;  

ImageLibrary* ImageLibrary::getInstance(){
   if (!m_pInstance)   // Only allow one instance of class to be generated.
      m_pInstance = new ImageLibrary;
   return m_pInstance;
}

ImageLibrary::ImageLibrary() : mario_Small_img_count(0), mario_Shroom_img_count(0), mario_Fire_img_count(0),
                enemy_img_count(0), item_Non_Static_img_count(0),item_Static_img_count(0), block_img_count(0){
    
    //Init Input
    std::cout << "Current path is " << fs::current_path() << '\n';

    const char *path_to_input = "pictures/Input/input.png";
    Input_Img = PngImage(path_to_input);

    //init deathscreen
    const char *path_to_deathscreen = "pictures/Deathscreen/deathscreen.png";
    Deathscreen_Img = PngImage(path_to_deathscreen);

    //init enemys
    init_vector("pictures/Enemys",&enemy_img_count,&Enemy_Images);

    //init mario
    init_vector("pictures/Mario/MarioSmall",&mario_Small_img_count,&Mario_Small_Images);
    init_vector("pictures/Mario/MarioBig/MarioNormal",&mario_Shroom_img_count,&Mario_Shroom_Images);
    init_vector("pictures/Mario/MarioBig/MarioFire",&mario_Fire_img_count,&Mario_Fire_Images);

    //init items
    init_vector("pictures/Items/Items_Non_Static",&item_Non_Static_img_count,&Item_Non_Static_Images);
    init_vector("pictures/Items/Items_Static",&item_Static_img_count,&Item_Static_Images);

    //init blocks
    init_vector("pictures/Ground/bloecke",&block_img_count,&Ground_Images);
    init_vector("pictures/Ground/pipes",&pipes_img_count,&Pipe_Images);

    

}

int ImageLibrary::return_mario_Small_img_count(){
    return mario_Small_img_count;
}
int ImageLibrary::return_mario_Shroom_img_count(){
    return mario_Shroom_img_count;
}
int ImageLibrary::return_mario_Fire_img_count(){
    return mario_Fire_img_count;
}
int ImageLibrary::return_enemy_img_count(){
    return enemy_img_count;
}
int ImageLibrary::return_item_Static_img_count(){
    return item_Static_img_count;
}
int ImageLibrary::return_item_Non_Static_img_count(){
    return item_Non_Static_img_count;
}
int ImageLibrary::return_block_img_count(){
    return block_img_count;
}

int ImageLibrary::return_pipe_img_count(){
    return pipes_img_count;
}

int ImageLibrary::set_input_image(PngImage input){
    Input_Img=input;
    return 0;
}

int ImageLibrary::set_resized_image(PngImage resized){
    Resized_Img=resized;
    return 0;
}

int ImageLibrary::init_vector(const char* pathchar, int* imgcounter, 
                        std::vector<PngImage> *vec){
    int count;
    std::string path = pathchar;
    count=0;
    for (const auto & entry : fs::directory_iterator(path)){
        std::string pat = entry.path().string();
        const char *c = pat.c_str();
        PngImage tmp(c);
        vec->push_back(PngImage(c));
        count++;
    }
    *imgcounter=count;
    return 0;
}

ImageLibrary::~ImageLibrary()=default;