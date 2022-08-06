#pragma once
#include "igraph.h"

namespace graphs {

typedef std::set<Edge>::iterator edgeIterator;

//Граф без кратных ребер
class Graph : public IGraph {

public:
    Graph(bool oriented = false);

    bool createEdge(size_t firstVertexIndex, size_t lastVertexIndex, int edgeWeight = 0) override;

    bool removeEdge(size_t firstVertexIndex, size_t lastVertexIndex) override;

    size_t countEdges() const override;

    std::set<Edge> &edges() override;

    ~Graph() override;

protected:
    //Получить ребро
    edgeIterator getEdge(size_t firstVertexIndex, size_t lastVertexIndex);

    //Список ребер
    std::set<Edge> m_edges;
};

}
