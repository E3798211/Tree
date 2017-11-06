#ifndef AKINATOR_H_INCLUDED
#define AKINATOR_H_INCLUDED

#include <stdio.h>
#include "Tree.h"

// =================================================

const char  DEFAULT_INPUT[] = "datadef.txt";
const char DEFAULT_OUTPUT[] = "outdef.txt";

// =================================================

class Akinator {
private:
public:
    /// Main tree
    Tree tree;

// =========================    Supporting functions
    /// Creates align
    /**
        Returns amount of tabs

        \param [in] output      Output file
        \param [in] depth       Amount of tabs :)
    */
    int Align(FILE* output, int depth);

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

    /// Prints branch to the file recurcively to the file
    /**
        \param [in] output          Output file
        \param [in] root_node       Root of the branch
        \param [in] recursion_depth Depth of the recursion
    */
    int PrintBranch(FILE* output, Node* root_node, int recursion_depth = 0);

    /// Loads data to the file
    /**
        \param [in] filename        Name of the file to be created
    */
    int UnloadData(const char* filename);

// =========================    Supporting functions about action
    /// Asks user
    /**
        Returns true if answer is positive, false otherwise

        \param [in] question        String with the question
    */
    bool UserAnswer(const char* question);

    // AskForDiff()
    // AddNode()

public:
    /// Default constructor
    /**
        Put nullptr as argument to load default database

        \param [in] filename        Name of the database
    */
    Akinator(const char* filename = nullptr);

    /// Default destructor
    ~Akinator();


    // ACT() or GO() or START() etc


    // AddElem()
    // Compare


};

#endif // AKINATOR_H_INCLUDED
