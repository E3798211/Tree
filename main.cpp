#include <stdio.h>

//#include "Tree.h"
#include "Akinator.h"

#include "DebugLib.h"

int main()
{
/*
    Tree b;

    Node* new_node;
    Node* tmp;
    PrintVar(new_node);
    b.AddLeft (b.GetRoot(), &new_node);
    b.AddLeft (b.GetRoot(), &new_node);
    b.AddRight(b.GetRoot(), &new_node);
    b.AddLeft (new_node, &tmp);

    b.SetData(b.GetRoot(), "datataatat");
    b.AddRight(b.GetRoot()->Left, &tmp);
    b.AddRight(b.GetRoot()->Left->Right, &tmp);
    b.AddLeft(b.GetRoot()->Left->Right, &tmp);

    //b.DeleteBranch(nullptr);
    new_node = b.GetRoot();
    //b.DeleteBranch(new_node);

    b.CallGraph();

    //b.DeleteBranch(b.GetRoot());
*/

    Akinator a("save.txt");
    //Akinator a("outdef.txt");
    //a.LoadData("save.txt");
    //a.LoadData("save.txt");

    a.tree.CallGraph();

    a.UnloadData(DEFAULT_OUTPUT);

    int b = 7;
    PrintVar(b);

    EnterFunction();
    //Execute(int a = 0;);
    QuitFunction();

    Execute(int c = 0);

    //PrintVar(a);


}
