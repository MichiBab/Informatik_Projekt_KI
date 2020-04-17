#ifndef gridscanner_h
#define gridscanner_h

#include "../../ImageTools/header/ImageDistributor.h"
#include "../../ImageTools/header/PngImage.h"
#include "../../TemplateMatching/header/TemplateMatcher.h"
#include "../../main/header/Globals.h"
class GridScanner{
private:
    ImageDistributor distr;
    PngImage& resized;
    TemplateMatcher matcher;
public:
    GridScanner();
    ~GridScanner();
    bool grid_matching_static(int grid_x, int grid_y, PngImage &matchingImg, int untere_flanke, int obere_flanke);
    bool grid_matching_non_static(int grid_x, int grid_y, PngImage &matchingImg, int untere_flanke, int obere_flanke);
};

#endif