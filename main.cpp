#include <stdio.h>

#include "Tree.h"

#include "DebugLib.h"

int main()
{
    //int a = 0;
    //PrintVar(a);

    Tree b;

    Node* new_node;
    PrintVar(new_node);
    b.AddLeft (b.root, &new_node);
    b.AddLeft (b.root, &new_node);
    b.AddRight(b.root, &new_node);
    b.AddRight(b.root, &new_node);

    b.SetData(b.root->Left, "qwe");
    std::cout << b.root->Left->Data;

}
