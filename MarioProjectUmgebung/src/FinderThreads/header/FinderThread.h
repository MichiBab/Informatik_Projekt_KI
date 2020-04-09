#ifndef FinderThread_h
#define FinderThread_h
#include "../../ImageTools/header/PngImage.h"
#include "../../ImageTools/header/ImageDistributor.h"
class FinderThread{
    private:
        ImageDistributor distr;
    public:
        FinderThread(PngImage &resized, int MODUS, int DISTR_IMAGEES);
        ~FinderThread();
        bool search(int *gridpositions);
};
#endif