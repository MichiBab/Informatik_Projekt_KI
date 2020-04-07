#ifndef Globals_h
#define Globals_h
#define TILESIZE 16
#define SKY 0
#define MARIO 1
#define BLOCK 2
#define ENEMY 3
#define INTEM 4
#define RADIUS 5 //5x5grid
#define MAPPINGDATA 4 //positions from to where
#define X_Start 0 //For Mappings Array 
#define Y_Start 1
#define X_End 2
#define Y_End 3
#define ABWEICHUNG 40 // umso kleiner umso genauer: => Abweichung von pixelwerten
//genauigkeitsformel. MATCH hängt intern noch von ABWEICHUNG ab
//zb: es kan 180 raus ==> ismatch(180) = 256/2 < 180-32 = 128<148
#define IS_A_MATCH(x) ( ((TILESIZE*TILESIZE) / 2) < x-(TILESIZE*2) )
#endif