#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <assert.h>
#include "Errors.h"

// =================================================

// =========================    Print information for user
#define _USR_INFORM
#ifdef _USR_INFORM
    #define USR_INFORM
#else
    #define USR_INFORM if(0)
#endif // _USR_INFORM

// =========================    Print information debug information
#define _DEBUG
#include "DebugLib.h"

// =================================================

struct Node {
    /// String with data
    char* data  = nullptr;

    /// Pointer to the left node
    Node* left  = nullptr;

    /// Pointer to the right node
    Node* right = nullptr;

    /// Pointer to the parent node
    Node* parent = nullptr;
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

        \param [in] node    Pointer we want to check
    */
    bool NodeExists(Node* check_ptr);

public:
    /// Default constructor
    Tree();

    /// Add node to the left
    /**
        Returns error code

        \param [in]  to_node    Ponter to the node you want append to
        \param [out] new_ptr    Pointer to save pointer to the new node
    */
    int Addleft(Node* app_node, Node** new_ptr);

    /// Add node to the right
    /**
        Returns error code

        \param [in]  to_node    Ponter to the node you want append to
        \param [out] new_ptr    Pointer to save pointer to the new node
    */
    int Addright(Node* app_node, Node** new_ptr);

    // SetData()
    // GetRoot()
    // Getleft(Node* app_node)              |   DEFINE  \
    // Getright(Node* app_node)             |   DEFINE   >  common define
    // Getparent(Node* app_node)            |   DEFINE  /
    // Delete() --- recursively

    // Verificator
    // Dump()
    // DOT

};

#endif // TREE_H_INCLUDED
