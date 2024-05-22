#include "classic_singleton.h"

Singleton& get_Singleton() {
    // if(single == nullptr)
    //     single = new Singleton();
    //Instead include like this - Initialised by the first thread that excutes this code
    static Singleton single;
    return single;
}