#include "header/Mapper.h"
#include "../FinderThreads/header/MarioFinder.h"
#include "../FinderThreads/header/FinderThread.h"
#include <iostream>
#include <thread>

/*    int ErgebnisArray[GRIDRADIUS][GRIDRADIUS];
    int MappingArray[MAPPINGDATA];
    int last_mario_pos_x;
    int last_mario_pos_y;
public:
    Mapper();
    bool Map_Mario();
    int Create_Array_Around_Mario();
    int Map_Blocks_Threaded();
    int Map_Items_Threaded();
    int Map_Enemys_Threaded();
    bool check_if_free(int grid_x, int grid_y);
    bool write_to_output_array(int grid_x, int grid_y, int DISTR_IMAGES);
    ~Mapper();*/

Mapper::Mapper(): last_mario_pos_x(0), last_mario_pos_y(0){

}

Mapper::~Mapper(){

}

bool Mapper::Map_Mario(){
    MarioFinder mariofinder;
    //if(mariofinder.search_for_Mario()){
    //    std::cout << "MARIO FOUND ON X " << mariofinder.return_x_pos() << " AND Y " << mariofinder.return_y_pos() << std::endl;
    //}
    bool erg = false;
    std::thread mariofinder1(&MarioFinder::search_for_Mario_threaded,&mariofinder,0,200,0,200,&erg);
    mariofinder1.join();
    if(erg){
        std::cout << "MARIO FOUND ON X " << mariofinder.return_x_pos() << " AND Y " << mariofinder.return_y_pos() << std::endl;
    }
    
}