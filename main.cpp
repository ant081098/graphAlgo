#include <iostream>

#include "graphAlgo.h"

using namespace std;
using namespace graphs;

int main()
{
    Graph graph;
    Console console;
    console.readMatrix(graph);
    Dextra algo;
    algo.setGraph(&graph);
    algo.start(1);
    for (auto v : algo.getDistance()){
        cout<<v.first<<" "<<v.second<<"\n";
    }

    return 0;
}
