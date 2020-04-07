#ifndef fsmenv_h
#define fsmenv_h
#include "../../ImageTools/header/PngImage.h"
class FSM_env{
private:
    int state_machine(); //mit einer condition variable, 
                         //die ausgelößt wird, wenn ein neues inputbild steht.
                         //fährt dann mit resizing mapping von vorne fort.
    int resizing_state();
    int mapping_state();
public:
    FSM_env();
    int get_new_Input(PngImage new_input);
    ~FSM_env();
};  
#endif 
