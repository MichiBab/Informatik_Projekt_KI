#ifndef FinderThread_h
#define FinderThread_h
#include "../../ImageTools/header/PngImage.h"
#include "../../ImageTools/header/ImageDistributor.h"
#include "../../main/header/Globals.h"
#include "../../TemplateMatching/header/GridScanner.h"
#include "../../TemplateMatching/header/Mapper.h"
class FinderThread{
    private:
        ImageDistributor distr;
        PngImage &resized;
        GridScanner gridsc;
        int modi;
        int typ;
    public:
        FinderThread(int DISTR_IMAGEES);
        ~FinderThread();
        bool search(int gridpositions[MAPPINGDATA], Mapper *mapper); //xystart xyend
};
#endif