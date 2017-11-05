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
    PrintVar(app_node);                                     \
    PrintVar(*new_node);                                    \
    PrintVar(n_nodes);                                      \
                                                            \
    assert(app_node != nullptr);                            \
    assert(new_node != nullptr);                            \
                                                            \
    SAFE {                                                  \
    if(NodeExists(root, app_node-> side )){                 \
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
    }                                                       \
                                                            \
                                                            \
                                                            \
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
    app_node-> side ->Parent = app_node;                    \
    *new_node = app_node-> side;                            \
                                                            \
    if      (!strcmp(#side, "Right"))                       \
        app_node->side->Is_right = true;                    \
    else if (!strcmp(#side, "Left"))                        \
        app_node->side->Is_right = false;                   \
    else{                                                   \
        SetColor(RED);                                      \
        DEBUG printf("=====   Invalid argument. Expected \"Left\" or \"Right\"   =====\n");   \
        SetColor(DEFAULT);                                  \
                                                            \
        *new_node = nullptr;                                \
                                                            \
        PrintVar( app_node);                                \
        PrintVar(*new_node);                                \
        PrintVar( n_nodes);                                 \
                                                            \
        QuitFunction();                                     \
        return INVALID_ARGUMENT;                            \
    }                                                       \
                                                            \
                                                            \
                                                            \
                                                            \
                                                            \
                                                            \
    PrintVar(app_node);                                     \
    PrintVar(*new_node);                                    \
    PrintVar(n_nodes);                                      \
                                                            \
    SetColor(GREEN);                                        \
    DEBUG printf("New ");                                   \
    DEBUG printf(#side);                                    \
    DEBUG printf(" node created\n");                        \
    SetColor(DEFAULT);                                      \
                                                            \
    QuitFunction();                                         \
    return OK;                                              \
}



// =================================================    Private

bool Tree::NodeExists(const Node* branch_root, const Node* check_ptr)
{
    if(check_ptr == nullptr)                return false;

    if(branch_root == nullptr)              return false;
    if(branch_root == check_ptr)            return true;

    return (NodeExists(branch_root->Left,  check_ptr) ||
            NodeExists(branch_root->Right, check_ptr))?    true : false;
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

    root->Is_right = true;

    PrintVar(root);
    PrintVar(n_nodes);

    QuitFunction();
}

Node* Tree::GetRoot()
{
    return root;
}

/*AUTO GENERATED*/    AddNode(Left);

/*AUTO GENERATED*/    AddNode(Right);

int Tree::SetData(Node* change_node, data_t data)
{
    EnterFunction();

    PrintVar(change_node);
    PrintVar(data);

    assert(change_node != nullptr);
    assert(data != nullptr);

    SAFE {

    // Verificator

    if(!NodeExists(root, change_node)){
        SetColor(BLUE);
        USR_INFORM printf("Node does not exist\n");
        SetColor(DEFAULT);

        PrintVar(change_node);
        PrintVar(data);

        QuitFunction();
        return NODE_DOES_NOT_EXIST;
    }
    }

    // =============================

    size_t data_len = strlen(data);
    PrintVar(data_len);

    data_t tmp = change_node->Data;
    try
    {
        change_node->Data = new char [data_len + 1];
    }
    catch(const std::bad_alloc &ex)
    {
        SetColor(RED);
        printf("=====   Cannot allocate %d bytes for Data   =====\n", data_len + 1);
        SetColor(DEFAULT);

        PrintVar(change_node);
        PrintVar(data);

        QuitFunction();
        return DATA_NOT_CREATED;
    }

    delete [] tmp;
    strcpy(change_node->Data, data);

    // =============================

    PrintVar(change_node);
    PrintVar(change_node->Data);
    PrintVar(data);

    QuitFunction();
    return OK;
}

int Tree::DeleteBranch(Node* branch_root, int rec_depth, bool right)
{
    assert(branch_root != nullptr);

    SetColor(MAGENTA);
    DEBUG printf("\tIn:   recursion depth = %d, right = %s\n", rec_depth, right? "true" : "false");
    SetColor(DEFAULT);

    PrintVar(branch_root);
    PrintVar(branch_root->Left);
    PrintVar(branch_root->Right);

    if(!NodeExists(root, branch_root)){
        SetColor(BLUE);
        USR_INFORM printf("Node does not exist\n");
        SetColor(DEFAULT);

        return NODE_DOES_NOT_EXIST;
    }

    if((branch_root)->Left != nullptr)
        DeleteBranch(branch_root->Left,    rec_depth + 1, false);
    if((branch_root)->Right != nullptr)
        DeleteBranch((branch_root)->Right, rec_depth + 1, true);

    delete [] (branch_root)->Data;

    if(branch_root != root){
        if(branch_root->Is_right)
            branch_root->Parent->Right = nullptr;
        else
            branch_root->Parent->Left  = nullptr;
    }
    else{
        root = nullptr;
    }

    delete branch_root;
    n_nodes--;

    SetColor(MAGENTA);
    DEBUG printf("\tQuit: recursion depth = %d, right = %s\n", rec_depth, right? "true" : "false");
    SetColor(DEFAULT);
    return OK;
}
