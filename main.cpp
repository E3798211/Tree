#include <stdio.h>

//#include "Tree.h"
#include "Akinator.h"

#include "DebugLib.h"

int main()
{
    Akinator a("outdef.txt");
    //a.Action();

    //a.CompareAnswers("QQQQ", "Mooshroom");
    //a.CreateDefinition("WALL-E");
    //a.CreateDefinition("Berezka");
    //a.tree.CallGraph();
    a.CompareAnswers("Kolobok", "Smesharik");
    a.CreateDefinition("Smesharik");

}
