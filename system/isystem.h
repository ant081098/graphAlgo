#pragma once


namespace graphs {

class IGraph;

//Интерфейс ввода/вывода графа
class ISystem {

public:
    ISystem();
    virtual void printMatrix(IGraph& graph) = 0;
    virtual void printEdge(IGraph& graph) = 0;
    virtual void readMatrix(IGraph& graph) = 0;
    virtual void readEdge(IGraph& graph) = 0;
    virtual ~ISystem();
};

}
