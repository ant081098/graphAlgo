#include "graph.h"
#include <algorithm>

namespace graphs {

Graph::Graph(bool oriented) : IGraph(oriented)
{

}

bool Graph::createEdge(size_t firstVertexIndex, size_t lastVertexIndex, int edgeWeight)
{

    //Проверить что вершины существуют
    if(getVertex(firstVertexIndex) == m_vertexes.end() || getVertex(lastVertexIndex) == m_vertexes.end()){
        return false;
    }
    Edge edge = Edge(firstVertexIndex, lastVertexIndex, edgeWeight);
    bool successInsert = m_edges.insert(edge).second;   //Создать ребро
    if(successInsert && !m_oriented){   //Если неориентированный
        Edge backEdge = Edge(lastVertexIndex, firstVertexIndex, edgeWeight);
        m_edges.insert(backEdge);
    }

    return successInsert;
}

bool Graph::removeEdge(size_t firstVertexIndex, size_t lastVertexIndex)
{
    edgeIterator edge = getEdge(firstVertexIndex, lastVertexIndex);

    if(edge == m_edges.end()) { //Если ребро не существует
        return false;
    }
    m_edges.erase(edge);
    if (!m_oriented){   //Если неориентированный
        edgeIterator backEdge = getEdge(lastVertexIndex, firstVertexIndex);
        m_edges.erase(backEdge);
    }
    return true;
}

size_t Graph::countEdges() const
{
    return m_edges.size();
}

edgeIterator Graph::getEdge(size_t firstVertexIndex, size_t lastVertexIndex)
{
    return m_edges.find(Edge(firstVertexIndex, lastVertexIndex));
}

std::set<Edge> &Graph::edges()
{
    return m_edges;
}


Graph::~Graph()
{

}

}
