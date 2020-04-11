#ifndef Globals_h
#define Globals_h
#define TILESIZE 16
#define SKY 0
#define MARIO 1
#define BLOCK 2
#define ENEMY 3
#define ITEM 4
#define GRIDRADIUS 5 //5x5grid
#define MAPPINGDATA 4 //positions from to where
#define X_Start 0 //For Mappings Array 
#define Y_Start 1
#define X_End 2
#define Y_End 3
#define STATIC 0
#define NONSTATIC 1
#define ABWEICHUNG 30 // umso kleiner umso genauer: => Abweichung von pixelwerten //bei 50 wird mario richtig detektiert mit momentaner lib
#define tilesize_mario_big_x 9
#define tilesize_mario_big_y 8
#define tilesize_mario_x 7
#define tilesize_mario_y 5
//genauigkeitsformel. MATCH hängt intern noch von ABWEICHUNG ab
//zb: es kan 180 raus ==> ismatch(180) = 256/2 < 180-32 = 128<148
//#define IS_A_MATCH(x) ( ((TILESIZE*TILESIZE) / 2) < x-(TILESIZE*2) )
#define MAX_FEHLER 4
#define MAX_FEHLER_BLOECKE 10//34//wegen Pipe
//#define IS_A_MATCH(x) ( ((TILESIZE*TILESIZE) - MAX_FEHLER_BLOECKE <= x ))
#define IS_A_MATCH(x) ( ((TILESIZE*TILESIZE) - MAX_FEHLER_BLOECKE <= x ))
#define IS_A_MARIO_MATCH(x) ( (tilesize_mario_x*tilesize_mario_y)-MAX_FEHLER<=x )
#define IS_A_BIG_MARIO_MATCH(x) ((tilesize_mario_big_x*tilesize_mario_big_y)-MAX_FEHLER<=x  )
//THREADCOUNTS
#define MARIOFINDERTHREADS 14 //darf nicht größer sein als 15, sonst wird das bild zu sehr geteilt und out of bounds folgt
#define FINDERTHREADS GRIDRADIUS //threads pro FINDER
#endif