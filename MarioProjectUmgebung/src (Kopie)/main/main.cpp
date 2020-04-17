#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include "../ImageTools/header/PngImage.h"
#include "../ImageTools/header/ImageLibrary.h"
#include "header/Environment.h"
#include "header/Globals.h"
using namespace std;

#include <zlib.h>
#include <chrono>
#include <ctime>  


    

int main () {
   
  // auto start = std::chrono::system_clock::now();
   Environment fsm;
   int ergArray[GRIDRADIUS][GRIDRADIUS];

   fsm.environment_interface("pictures/Input/input.png",ergArray);
/* //PRINTING ARRAY
   printf("\n");
   for(int y = 0; y<GRIDRADIUS;y++){
      for(int x= 0; x<GRIDRADIUS;x++){
         printf("%d ",ergArray[x][y]);
         }
      printf("\n");
      }
   printf("\n");
   //}
*/
  // auto end = std::chrono::system_clock::now();
   // std::chrono::duration<double> elapsed_seconds = end-start;
  //  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  //  std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
   
}

