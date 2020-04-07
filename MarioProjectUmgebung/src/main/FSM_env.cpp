#include "header/FSM_env.h"
#include "../ImageTools/header/PngImage.h"
#include "../ImageTools/header/ImageLibrary.h"
#include "../ImageTools/header/ImageDistributor.h"
#include <iostream>
#include "../TemplateMatching/header/TemplateMatcher.h"

int FSM_env::state_machine(){
    
    //Create Image Library:
    ImageLibrary* image_library = ImageLibrary::getInstance(); 
    //initialisiert alle images

    //TODO: mit cond var durch get new input den ablauf resizing und mapping wiederholen lassen
    //while(condvar_no_new_pic:sleep){....} //Alles hier sollte nun im loop sein:

    resizing_state(); 

    mapping_state();

    //testing
    PngImage a = image_library->Ground_Images[0];
    PngImage b = image_library->Ground_Images[5];
    TemplateMatcher test(a);
    int x = test.match_tilesize_on_pixel(0,0,b);
    std::cout<<x<<std::endl;
}

int FSM_env::resizing_state(){

}

int FSM_env::mapping_state(){

}

FSM_env::FSM_env(){
    state_machine();
}

FSM_env::~FSM_env(){

}

//für später mit cond var die state machine wiederholen lassen.
int FSM_env::get_new_Input(PngImage new_input){

}
