#include "header/FSM_env.h"
#include "../ImageTools/header/PngImage.h"
#include "../ImageTools/header/ImageLibrary.h"
#include "../ImageTools/header/ImageDistributor.h"
#include "../ImageTools/header/ImageResizer.h"
#include "../TemplateMatching/header/Mapper.h"
#include "../TemplateMatching/header/TemplateMatcher.h"
#include "../FinderThreads/header/MarioFinder.h"
#include <iostream>

#include <chrono>
#include <ctime>  

int FSM_env::state_machine(){
    
    //Create Image Library:
    ImageLibrary* image_library = ImageLibrary::getInstance(); 
    //initialisiert alle images

    //TODO: mit cond var durch get new input den ablauf resizing und mapping wiederholen lassen
    //while(condvar_no_new_pic:sleep){....} //Alles hier sollte nun im loop sein:

    resizing_state(); 

    mapping_state();

    //testing
    auto start = std::chrono::system_clock::now();
    
    ImageResizer resize;
    if(resize.resize()){
        Mapper mapper;
        mapper.Map_Mario();
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";


    
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
