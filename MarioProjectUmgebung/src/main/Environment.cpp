#include "header/Environment.h"
#include "../ImageTools/header/PngImage.h"
#include "../ImageTools/header/ImageLibrary.h"
#include "../ImageTools/header/ImageDistributor.h"
#include "../ImageTools/header/ImageResizer.h"
#include "../TemplateMatching/header/Mapper.h"
#include "../TemplateMatching/header/TemplateMatcher.h"
#include "../FinderThreads/header/MarioFinder.h"
#include <iostream>



int Environment::environment_interface(const char* filename, int arr[GRIDRADIUS][GRIDRADIUS]){
    PngImage inp(filename);
    give_Input(inp,arr);
}

//constructor
Environment::Environment(){
    image_library = ImageLibrary::getInstance(); 
}

Environment::~Environment(){

}

int Environment::give_Input(PngImage& new_input,int arr[GRIDRADIUS][GRIDRADIUS]){
    image_library->set_input_image(new_input);
    if(resize.resize()){
        if(mapper.Map_Mario()){
            //printf("mario found\n");
            mapper.Map_Enemys_Threaded();
            mapper.Map_Blocks_Threaded();
            mapper.Map_Items_Threaded();
            //mapper.print_erg_radius();

            //return array test
            mapper.return_erg_array(arr);
            printf("\n");
            for(int y = 0; y<GRIDRADIUS;y++){
                for(int x= 0; x<GRIDRADIUS;x++){
                    printf("%d ",arr[x][y]);
                }
                printf("\n");
            }
            printf("\n");
        }
        else{
            return -1;
        }
    
    }
    return -1;
}
