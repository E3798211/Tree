#ifndef DEBUGLIB_H_INCLUDED
#define DEBUGLIB_H_INCLUDED

#include <stdio.h>
#include <iostream>

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
const char    CYAN[] = "\x1b[96m";
const char DEFAULT[] = "\x1b[0m";

// =================================================

void SetColor(const char* color);

#define EnterFunction()                                                         \
    do{                                                                         \
        DEBUG SetColor(YELLOW);                                                 \
        DEBUG std::cout << "Entered " << __func__ << "():\n" << std::endl;      \
        DEBUG SetColor(DEFAULT);                                                \
    }while(0)

#define QuitFunction()                                                          \
    do{                                                                         \
        DEBUG SetColor(YELLOW);                                                 \
        DEBUG std::cout << "\nQuited " << __func__ << "():" << std::endl;       \
        DEBUG SetColor(DEFAULT);                                                \
    }while(0)

#define PrintVar( var )                                                         \
    do{                                                                         \
        DEBUG SetColor(CYAN);                                                   \
        DEBUG std::cout << #var    << "\t=\t" << var << std::endl;                \
        DEBUG SetColor(DEFAULT);                                                \
    }while(0)

// =================================================


#endif // DEBUGLIB_H_INCLUDED
