#ifndef AKINATOR_H_INCLUDED
#define AKINATOR_H_INCLUDED

#include <stdio.h>
#include "Tree.h"

// =================================================

const char DEFAULT_INPUT[] = "datadef.txt";

// =================================================

class Akinator {
private:
public:
    /// Main tree
    Tree tree;

    /// Reads file
    /**
        Returns nullptr if something has gone wrong

        \param [in] input        Data file
    */
    char* FileRead(FILE* input);

    /// Appends node with data from file
    /**
        \param [in] data            String with data
        \param [in] app_node        Ppointer to the node to be appended
        \param [in] place_in_data     Place in data where to look for data
    */
    int AppendNode(char* data, int* place_in_data, Node* app_node);

    /// Loads data from database and creates tree
    /**
        \param [in] filename        Name of the data file
    */
    int LoadData(const char* filename);

    // Unloading data
    // AskForDiff()

public:
    /// Default constructor
    Akinator();                                         //  Calls Load data

    ~Akinator();

    // AddElem()
    // Compare


};

#endif // AKINATOR_H_INCLUDED
