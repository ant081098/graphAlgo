#include "ialgo.h"

namespace graphs {

IAlgo::IAlgo() : m_graph(nullptr)
{

}

void IAlgo::setGraph(IGraph *igraph)
{
    m_graph = igraph;
}

IGraph *IAlgo::graph()
{
    return m_graph;
}

IAlgo::~IAlgo()
{

}

void IAlgo::init()
{
    m_adjacency = m_graph->adjacency();

    m_usedVertex.clear();
    for(const Vertex& vertex : graph()->vertexes()){
        m_usedVertex[vertex.getIndex()] = false;
    }
}

bool IAlgo::checkUsedVertex(size_t vertexIndex) const
{
    return m_usedVertex.at(vertexIndex);
}

void IAlgo::setUsedVertex(size_t vertexIndex)
{
    m_usedVertex[vertexIndex] = true;
}

std::vector<Edge> &IAlgo::getAdj(size_t vertexIndex)
{
    return m_adjacency.at(vertexIndex);
}

}
