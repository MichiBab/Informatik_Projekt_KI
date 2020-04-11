#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include "../ImageTools/header/PngImage.h"
#include "../ImageTools/header/ImageLibrary.h"
#include "header/Environment.h"

using namespace std;

#include <zlib.h>
#include <chrono>
#include <ctime>  


    

int main () {
   
   auto start = std::chrono::system_clock::now();
   Environment fsm;
   for(int i = 0; i<1;i++){
      fsm.environment_interface("pictures/Input/input.png");
   }

   auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
   
}

