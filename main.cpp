#include <stdio.h>

#include "Tree.h"

#include "DebugLib.h"

int main()
{
    Tree b;

    Node* new_node;
    Node* tmp;
    PrintVar(new_node);
    b.AddLeft (b.GetRoot(), &new_node);
    b.AddLeft (b.GetRoot(), &new_node);
    b.AddRight(b.GetRoot(), &new_node);
    b.AddLeft (new_node, &tmp);

    b.SetData(b.root, "datataatat");

    PrintVar(b.GetRoot());
    //b.DeleteBranch(nullptr);
    new_node = b.GetRoot();
    b.DeleteBranch(new_node);

    PrintVar(new_node);
    PrintVar(b.n_nodes);
    PrintVar(b.GetRoot());
    //PrintVar(b.GetRoot());

}
