#include <stdio.h>

#include "Tree.h"


int main()
{
    //int a = 0;
    //PrintVar(a);

    Tree b;

    Node* new_node;
    PrintVar(new_node);
    b.Addleft (b.root, &new_node);
    b.Addleft (b.root, &new_node);
    b.Addright(b.root, &new_node);
}
