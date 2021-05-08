#include "stdlib.h"
#include "singleton.h"

Singleton *singleton = NULL;

Singleton* getSingletonInstance() {
    if (singleton == NULL) {
        singleton = (Singleton*)malloc(sizeof(Singleton));
    }
    singleton->michael = 'M';
    return singleton;
}