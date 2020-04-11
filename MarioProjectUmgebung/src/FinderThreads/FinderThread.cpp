#include "header/FinderThread.h"
#include "../TemplateMatching/header/GridScanner.h"
/*class FinderThread{
    private:
        ImageDistributor distr;
        PngImage &resized;
    public:
        FinderThread(PngImage &resized, int MODUS, int DISTR_IMAGEES);
        ~FinderThread();
        bool search(int gridpositions[MAPPINGDATA]); //xystart xyend
};
*/

FinderThread::FinderThread(int TYP): resized(distr.grab_resized_img()) , gridsc(){
  this->typ = TYP;
}

FinderThread::~FinderThread(){

}

bool FinderThread::search(int gridpositions[MAPPINGDATA], Mapper *mapper){
  bool am_i_done = false;
  int erg = 0;
  switch(typ){
    case ENEMY:
      while(true){
        PngImage& img = distr.grab_next_enemy_img(&am_i_done);
        if(am_i_done){break;}
        for(int x = gridpositions[X_Start]; x<= gridpositions[X_End];x++){
          for(int y = gridpositions[Y_Start]; y<=gridpositions[Y_End];y++){
            if(mapper->check_if_free(x-gridpositions[X_Start],y-gridpositions[Y_Start])){
              if(gridsc.grid_matching_non_static(x,y,img)){
                mapper->write_to_output_array(x-gridpositions[X_Start], y-gridpositions[Y_Start], ENEMY);
              }
            }
          }
        }
      }
    break;
    case ITEM:
      while(true){
        PngImage& img = distr.grab_next_item_Non_Static_img(&am_i_done);
        if(am_i_done){break;}
        for(int x = gridpositions[X_Start]; x<= gridpositions[X_End];x++){
          for(int y = gridpositions[Y_Start]; y<=gridpositions[Y_End];y++){
            if(mapper->check_if_free(x,y)){
              if(gridsc.grid_matching_non_static(x,y,img)){
                mapper->write_to_output_array(x-gridpositions[X_Start], y-gridpositions[Y_Start], ITEM);
              }
            }
          }
        }
      }
      while(true){
        PngImage& img = distr.grab_next_item_Static_img(&am_i_done);
        if(am_i_done){break;}
        for(int x = gridpositions[X_Start]; x<= gridpositions[X_End];x++){
          for(int y = gridpositions[Y_Start]; y<=gridpositions[Y_End];y++){
            if(mapper->check_if_free(x,y)){
              if(gridsc.grid_matching_static(x,y,img)){
                mapper->write_to_output_array(x-gridpositions[X_Start], y-gridpositions[Y_Start], ITEM);
              }
            }
          }
        }
      }
    break;
    case BLOCK:
      while(true){
        PngImage& img = distr.grab_next_block_img(&am_i_done);
        if(am_i_done)break;
        for(int x = gridpositions[X_Start]; x<= gridpositions[X_End];x++){
          for(int y = gridpositions[Y_Start]; y<= gridpositions[Y_End];y++){
            if(mapper->check_if_free(x-gridpositions[X_Start],y-gridpositions[Y_Start])){
              if(gridsc.grid_matching_static(x,y,img)){
                mapper->write_to_output_array(x-gridpositions[X_Start], y-gridpositions[Y_Start], BLOCK);
              }
            }
          }
        }
      }
    break;
    }
}



//TODO: entfernen // Working code example from block grabbing for finder threads!
/*//test image distributor
    ImageDistributor imdist;
    bool am_i_done = false;
    int tmpcount=0;
    while(true){
      PngImage& rBlock = imdist.grab_next_block_img(&am_i_done);
      if(am_i_done){break;}
      std::cout << "block number: "<<tmpcount<<std::endl;
      print_different_rgbs_for_testing(rBlock.return_height(),rBlock.return_width(),rBlock.row_pointers);
      tmpcount++;
    }*/

/*
static int  print_different_rgbs_for_testing(int height, int width, png_bytep* row_pointers){
  int wertsize = 10000;
  int werte[wertsize][3];
  for(int i = 0; i<wertsize;i++){
    for(int y = 0; y<3;y++){
      werte[i][y]=0;
    }
  }
  for(int y = height-1; y >= 0; y--) {
    png_bytep row = row_pointers[y];
    for(int x = width-1; x >= 0; x--) {
      png_bytep px = &(row[x * 4]);
      //printf("%4d, %4d = RGBA(%3d, %3d, %3d, %3d)\n", x, y, px[0], px[1], px[2], px[3]);
      // Do something awesome for each pixel here...
      for(int i = 0; i<wertsize;i++){
        if(werte[i][0] == px[0] && werte[i][1] == px[1] && werte[i][2] == px[2]){
          i=wertsize;
        }
        else if(werte[i][0] == 0 && werte[i][1] == 0 && werte[i][2] == 0){
          werte[i][0]=px[0];
          werte[i][1]=px[1];
          werte[i][2]=px[2];
          i=wertsize;
          }
     
        }
      }
  }

  //ausgabe:
  for(int i = 0; i<wertsize;i++){
        if(werte[i][0] == 0 && werte[i][1] == 0 && werte[i][2] == 0){
          i=wertsize;//break
        }
        else{
          printf("RGB(%3d, %3d, %3d)\n", werte[i][0], werte[i][1], werte[i][2]);
        }
    }

}
*/


