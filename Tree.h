#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <assert.h>
#include <cstring>
#include "Errors.h"

// =================================================

// =========================    Safe mode.
//
//  In safe mode programm checks if node exists, runs verificator, etc.
//  In case you are sure that your programm will work correct and you need to
//  speed it up, turn safe-mode off.
//

// Comment next line to turn safe-mode off.
#define _SAFE
#ifdef _SAFE
    #define SAFE
#else
    #define SAFE if(0)
#endif // _USR_INFORM

// =========================    Print information for user
#define _USR_INFORM
#ifdef _USR_INFORM
    #define USR_INFORM
#else
    #define USR_INFORM if(0)
#endif // _USR_INFORM

// =========================    Print information debug information
// Comment next line to turn debug off.
#define _DEBUG
#include "DebugLib.h"

// =================================================

typedef char* data_t;

struct Node {
    /// String with data
    data_t  Data = nullptr;

    /// Pointer to the left node
    Node*   Left = nullptr;

    /// Pointer to the right node
    Node*  Right = nullptr;

    /// Pointer to the parent node
    Node* Parent = nullptr;
};

class Tree {
//private:
public:
    /// Pointer to the first node
    Node* root  = nullptr;

    /// Nodes counter
    int n_nodes = 0;

// =========================    Supporting functions
    /// Checks node existence
    /**
        Retutns TRUE if node exists

        \param [in] branch_root Pointer to te first element in branch we check
        \param [in] node        Pointer we want to check
    */
    bool NodeExists(Node* branch_root, Node* check_ptr);

public:
    /// Default constructor
    Tree();

    /// Gets root
    Node* GetRoot();

    /// Add node to the left
    /**
        Returns error code

        \param [in]  to_node    Ponter to the node you want append to
        \param [out] new_ptr    Pointer to save pointer to the new node
    */
    int AddLeft(Node* app_node, Node** new_ptr);

    /// Add node to the right
    /**
        Returns error code

        \param [in]  to_node    Ponter to the node you want append to
        \param [out] new_ptr    Pointer to save pointer to the new node
    */
    int AddRight(Node* app_node, Node** new_ptr);

    /// Set data
    /**
        Returns error code

        \param [in]  change_node    Ponter to the node you want to change
        \param [out] data           New data
    */
    int SetData(Node* change_node, data_t data);



    // Getleft(Node* app_node)              |   DEFINE  \
    // Getright(Node* app_node)             |   DEFINE   >  common define
    // Getparent(Node* app_node)            |   DEFINE  /
    // Delete() --- recursively

    // Verificator
    // Dump()
    // DOT

};

#endif // TREE_H_INCLUDED
