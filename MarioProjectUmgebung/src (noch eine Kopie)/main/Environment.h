#ifndef environment_h
#define environment_h
#include "PngImage.h"
#include "ImageResizer.h"
#include "Mapper.h"
#include "Globals.h"
class Environment{
private:
    ImageLibrary* image_library; // = ImageLibrary::getInstance()
    ImageResizer resize;
    Mapper mapper;
public:
    Environment();
    int give_Input(PngImage& new_input, int arr[GRIDRADIUS][GRIDRADIUS], int* status);
    int environment_interface(const char* filename, int arr[GRIDRADIUS][GRIDRADIUS], int* status);
    ~Environment();
};  
#endif 