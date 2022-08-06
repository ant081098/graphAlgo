#include "igraph.h"

namespace graphs {

IGraph::IGraph(bool oriented) : m_oriented(oriented)
{

}

bool IGraph::createVertex(size_t vertexIndex, int vertexWeight)
{
    return m_vertexes.insert(Vertex(vertexIndex, vertexWeight)).second;
}

bool IGraph::removeVertex(size_t vertexIndex)
{
    vertexIterator vertex = getVertex(vertexIndex);
    if (vertex == m_vertexes.end()){    //Если вершина не существует
        return false;
    }
    m_vertexes.erase(vertex);
    return true;
}

vertexIterator IGraph::getVertex(size_t vertexIndex)
{
    return m_vertexes.find(Vertex(vertexIndex));
}

size_t IGraph::countVertexes() const
{
    return m_vertexes.size();
}

std::set<Vertex> &IGraph::vertexes()
{
    return m_vertexes;
}

std::map<size_t, std::vector<Edge> > IGraph::adjacency()
{
    std::map<size_t, std::vector<Edge> > listAdj;
    decltype (edges()) listEdges = edges();
    for(const Edge& e : listEdges){
        listAdj[e.getFirstVertexIndex()].push_back(e);
    }
    return listAdj;
}

IGraph::~IGraph()
{

}

}
