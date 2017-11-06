#ifndef DEBUGLIB_H_INCLUDED
#define DEBUGLIB_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <iomanip>

// =================================================
// Debug mode

#ifdef _DEBUG
    #define DEBUG
#else
    #define DEBUG if(0)
#endif

// =================================================
// Colors

const char    BLUE[] = "\x1b[34m";
const char     RED[] = "\x1b[91m";
const char   GREEN[] = "\x1b[92m";
const char  YELLOW[] = "\x1b[93m";
const char MAGENTA[] = "\x1b[95m";

const char    CYAN[] = "\x1b[96m";
const char DEFAULT[] = "\x1b[0m";

// =================================================

extern bool IN;

void SetColor(const char* color);

#define EnterFunction()                                                         \
    do{                                                                         \
    DEBUG {                                                                     \
        SetColor(YELLOW);                                                       \
        std::cout << "\nEntered " << __func__ << "():\n" << std::endl;          \
        SetColor(DEFAULT);                                                      \
        IN = true;                                                              \
    }                                                                           \
    }while(0)                                                                                                                                              \

#define QuitFunction()                                                          \
    do{                                                                         \
    DEBUG {                                                                     \
        SetColor(YELLOW);                                                       \
        std::cout << "\nQuited " << __func__ << "():" << std::endl;             \
        SetColor(DEFAULT);                                                      \
        IN = false;                                                             \
    }                                                                           \
    }while(0)

#define PrintVar( var )                                                         \
    do{                                                                         \
    DEBUG{                                                                      \
        SetColor(CYAN);                                                         \
        if(IN)    std::cout << ">>\t";                                          \
        std::cout << std::setw(25) << #var << " = " << var << std::endl;        \
        SetColor(DEFAULT);                                                      \
    }                                                                           \
    }while(0)

// =================================================




/*


    Add Execute( param ): prints debug info and places param in source text


*/











#endif // DEBUGLIB_H_INCLUDED
