#ifndef templatematcher_h
#define templatematcher_h
#include "../../ImageTools/header/PngImage.h"
class TemplateMatcher{
private:
    PngImage* input_ptr;
public:
    TemplateMatcher(PngImage& input);
    int match_tilesize_on_pixel(int x_pos, int y_pos, PngImage sprite);
    ~TemplateMatcher();
};

#endif