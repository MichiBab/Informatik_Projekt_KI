#ifndef environment_h
#define environment_h
#include "../../ImageTools/header/PngImage.h"
#include "../../ImageTools/header/ImageResizer.h"
#include "../../TemplateMatching/header/Mapper.h"
#include "../../main/header/Globals.h"
class Environment{
private:
    ImageLibrary* image_library; // = ImageLibrary::getInstance()
    ImageResizer resize;
    Mapper mapper;
public:
    Environment();
    int give_Input(PngImage& new_input, int arr[GRIDRADIUS][GRIDRADIUS]);
    int environment_interface(const char* filename, int arr[GRIDRADIUS][GRIDRADIUS]);
    ~Environment();
};  
#endif 