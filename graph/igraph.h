#pragma once
#include "../part/vertex.h"
#include "../part/edge.h"

#include <set>
#include <map>
#include <vector>


namespace graphs {

typedef std::set<Vertex>::iterator vertexIterator;

//Граф без ребер
class IGraph {

public:
    IGraph(bool oriented = false);

    //Создать вершину
    bool createVertex(size_t vertexIndex, int vertexWeight = 0);

    //Удалить вершину
    bool removeVertex(size_t vertexIndex);

    //Получить количество вершин
    size_t countVertexes() const;

    //Получить множество вершин
    std::set<Vertex> &vertexes();

    //Создать ребро
    virtual bool createEdge(size_t firstVertexIndex, size_t lastVertexIndex, int edgeWeight = 0) = 0;

    //Удалить ребро
    virtual bool removeEdge(size_t firstVertexIndex, size_t lastVertexIndex) = 0;

    //Получить количество ребер
    virtual size_t countEdges() const = 0;

    //Получить множество ребер
    virtual std::set<Edge> &edges() = 0;

    //Получить список смежности
    std::map<size_t, std::vector<Edge>> adjacency();

    virtual ~IGraph();

protected:
    //Получить вершину
    vertexIterator getVertex(size_t vertexIndex);

    //Ориентированный граф
    bool m_oriented;

    //Множество вершин
    std::set<Vertex> m_vertexes;
};

}
