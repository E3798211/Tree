#ifndef DEBUGLIB_H_INCLUDED
#define DEBUGLIB_H_INCLUDED

#include <stdio.h>
#include <cstring>
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

const char    BLUE[] = "\x1b[34m";      // Info for user. This color is not under DEBUG
const char     RED[] = "\x1b[91m";      // Errors
const char   GREEN[] = "\x1b[92m";      // Succseffuly executed operation
const char  YELLOW[] = "\x1b[93m";      // Enterings and quits of functions
const char  PURPLE[] = "\x1b[200m";     // FREE
const char    CYAN[] = "\x1b[96m";      // Printing varriables
const char DEFAULT[] = "\x1b[0m";       // Default
const char MAGENTA[] = "\x1b[95m";      // Notes. If nothing else fits

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
        std::cout << std::setfill ('_') << std::setw(20);                       \
        if(IN){                                                                 \
            std::cout << __func__ << "():";                                     \
            std::cout << std::setw(30);                                         \
        }                                                                       \
        std::cout << #var << " = " << var << std::endl;                         \
        SetColor(DEFAULT);                                                      \
    }                                                                           \
    }while(0)

#define Execute( statement )                                                    \
    DEBUG{                                                                      \
        SetColor(MAGENTA);                                                      \
        if(IN){                                                                 \
            std::cout << __func__ << "(): ";                                    \
            std::cout << std::setw(20);                                         \
        }                                                                       \
        std::cout << "Executing:\t" << #statement << std::endl;                 \
        SetColor(DEFAULT);                                                      \
    }                                                                           \
    statement ;

#define MARK                                                                    \
    DEBUG {                                                                     \
        SetColor(MAGENTA);                                                      \
        if(IN){                                                                 \
            std::cout << "=====   Mark in " << __func__ << "()   =====" << std::endl;   \
        }else{                                                                  \
            std::cout << "=====   Mark   =====" << std::endl;                   \
        }                                                                       \
        SetColor(DEFAULT);                                                      \
    }

// =================================================




/*


    Add Execute( param ): prints debug info and places param in source text

    Initing functions: initializating spec global varriables with info - do we need to print bdg info in a file,
        stderr, as html, etc


*/











#endif // DEBUGLIB_H_INCLUDED
