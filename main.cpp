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
    b.AddRight(b.GetRoot()->Left, &tmp);
    b.AddRight(b.GetRoot()->Left->Right, &tmp);
    b.AddLeft(b.GetRoot()->Left->Right, &tmp);

    //b.DeleteBranch(nullptr);
    new_node = b.GetRoot();
    //b.DeleteBranch(new_node);

    b.CallGraph();

}
