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
/*
    Tree c;
    Node* left;
    Node* right;
    c.AddLeft(c.GetRoot(), &left);
    c.AddRight(c.GetRoot(), &right);

    c.SetData(c.GetRoot(), "root");
    c.SetData(left, "left_first");
    c.SetData(right,"right_first");

    Node* tmp;
    c.AddLeft(left, &tmp);
    c.SetData(tmp, "leftleft");
    c.AddRight(left, &tmp);
    c.SetData(tmp, "leftright");

    c.AddLeft(right, &tmp);
    c.SetData(tmp, "rightleft");
    c.AddRight(right, &tmp);
    c.SetData(tmp, "rightright");


    tmp = c.FindNode(c.GetRoot(), "sleft_first");

    c.CallGraph();
*/

    //Akinator a("save.txt");
    Akinator a("outdef.txt");
    //a.LoadData("save.txt");
    //a.LoadData("save.txt");

    //a.Action();

    a.CompareAnswers("QQQQ", "Mooshroom");
    //a.tree.CallGraph();

    //PrintVar(a.UserAnswer("qwe"));

    //PrintVar(a);


}
