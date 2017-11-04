#include "Tree.h"


// =================================================    Say "No!" to copy-paste!
//
// This define creates functions Addleft() and Addright(). They have similar architecture so
// it helps to avoid writing functions that are almost the same.
//

#define AddNode( side )                                     \
int Tree::Add##side (Node* app_node, Node** new_node)       \
{                                                           \
    EnterFunction();                                        \
                                                            \
    assert(app_node != nullptr);                            \
    assert(new_node != nullptr);                            \
                                                            \
    if(NodeExists(app_node-> side )){                       \
        SetColor(BLUE);                                     \
        USR_INFORM printf("Node already exist\n");          \
        SetColor(DEFAULT);                                  \
                                                            \
        *new_node = nullptr;                                \
                                                            \
        PrintVar(app_node);                                 \
        PrintVar(*new_node);                                \
        PrintVar(n_nodes);                                  \
                                                            \
        QuitFunction();                                     \
        return NODE_ALREADY_EXIST;                          \
    }                                                       \
                                                            \
    try                                                     \
    {                                                       \
        app_node-> side = new Node;                         \
        n_nodes++;                                          \
    }                                                       \
    catch(const std::bad_alloc &ex)                         \
    {                                                       \
        SetColor(RED);                                      \
        DEBUG printf("=====   Cannot create new node   =====\n");   \
        SetColor(DEFAULT);                                  \
                                                            \
        *new_node = nullptr;                                \
                                                            \
        PrintVar( app_node);                                \
        PrintVar(*new_node);                                \
        PrintVar( n_nodes);                                 \
                                                            \
        QuitFunction();                                     \
        return NODE_NOT_CREATED;                            \
    }                                                       \
                                                            \
    app_node-> side ->parent = app_node;                    \
    *new_node = app_node-> side;                            \
                                                            \
    PrintVar(app_node);                                     \
    PrintVar(*new_node);                                    \
    PrintVar(n_nodes);                                      \
                                                            \
    SetColor(GREEN);                                        \
    DEBUG printf("New side node created\n");                \
    SetColor(DEFAULT);                                      \
                                                            \
    QuitFunction();                                         \
    return OK;                                              \
}



// =================================================    Private

bool Tree::NodeExists(Node* check_ptr)
{
    return (check_ptr == nullptr)?  false : true;
}
// =================================================    Public

Tree::Tree()
{
    EnterFunction();

    try
    {
        root = new Node;
        n_nodes = 1;
    }
    catch(const std::bad_alloc &ex)
    {
        SetColor(RED);
        DEBUG printf("=====   Cannot create root node   =====\n");
        SetColor(DEFAULT);
    }

    PrintVar(root);
    PrintVar(n_nodes);

    QuitFunction();
}

/*AUTO GENERATED*/    AddNode(left);

/*AUTO GENERATED*/    AddNode(right);
