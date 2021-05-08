#ifndef SINGLETON_H
#define SINGLETON_H

typedef struct Singleton {
    char michael;
    char gabriel;
    char raphael;
    char uriel;
} Singleton;

Singleton* getSingletonInstance();

#endif