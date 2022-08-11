#include <iostream>

#include "graphAlgo.h"

using namespace std;

int main()
{
    graphs::Graph graph;
    graphs::Console console;
    console.readMatrix(graph);
    graphs::Dextra algo;
    algo.setGraph(&graph);
    algo.start(1);
    for (auto v : algo.getDistance()){
        cout<<v.first<<" "<<v.second<<"\n";
    }

    return 0;
}
