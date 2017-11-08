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
        \param [in] question        String with the question
    */
    bool UserAnswer(const char* question);

    /// Ask about new element
    /**
        \param [in] user_answer     Array to place user's answer
    */
    int AskAboutNewName(char* user_answer);

    /// Ask about definition of new element
    /**
        Returns amount of varriables read from stdin

        \param [in] old_answer      Old answer
        \param [in] new_answer      New answer
        \param [in] user_answer     Array to place user's answer
    */
    int AskAboutNewDiff(const char* old_answer, const char* new_answer, char* user_answer);

    /// Adds new answer
    /**
        \param [in] current_node    Node we want to replace with question
        \param [in] difference      String with difference between NEW and OLD data
        \param [in] new_node_data   String with data for new node
    */
    int AddNewAnswer(Node* current_node, char* difference, char* new_node_data);

    /// Finds path to element
    /**
        \param [in] start           Pointer to the start node
        \param [in] destination     Pointer to the destination node
    */
    int* BuildPath(Node* start, Node* destination);

    /// Prints difference between elements ans_1 and ans_2
    /**
        \param [in] ans_1           Name of the first element
        \param [in] ans_2           Name of the second element
        \param [in] path_1          Path to the first element
        \param [in] path_2          Path to the second element
    */
    int PrintDiff(const char* ans_1, const char* ans_2, int* path_1, int* path_2);

public:
    /// Default constructor
    /**
        Put nullptr as argument to load default database

        \param [in] filename        Name of the database
    */
    Akinator(const char* filename = nullptr);

    /// Default destructor
    ~Akinator();

    /// Action
    int Action();

    /// Compares two answers
    /**
        \param [in] ans_1           First answer
        \param [in] ans_2           Second answer
    */
    int CompareAnswers(const char* ans_1, const char* ans_2);

};

#endif // AKINATOR_H_INCLUDED
