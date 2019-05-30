#pragma once
#include "Python.h"
class ensureGILstate{
public:
    ensureGILstate(){
        _state = PyGILState_Ensure();
    }
    ~ensureGILstate(){
        PyGILState_Release(_state);
    }
private:
    PyGILState_STATE _state;
};
