#include "bfs.h"
#include <queue>

namespace graphs {

Bfs::Bfs() : IAlgo()
{

}

void Bfs::start(size_t vertexIndex)
{
    init();
    bfs(vertexIndex);
}

std::vector<size_t> Bfs::getByPass()
{
    return m_bypass;
}

std::map<size_t, int> Bfs::getDistance()
{
    return m_distance;
}

std::map<size_t, size_t> Bfs::getParent()
{
    return m_parent;
}

Bfs::~Bfs()
{

}

void Bfs::init()
{
    IAlgo::init();
    m_bypass.clear();
    m_distance.clear();
    m_parent.clear();
    for(const Vertex& vertex : graph()->vertexes()){
        m_distance[vertex.getIndex()] = INT_MAX; //Максимальное значение расстояния
        m_parent[vertex.getIndex()] = 0;
    }
}

void Bfs::bfs(size_t vertexIndex)
{
    std::queue<size_t> queueVertexes;
    queueVertexes.push(vertexIndex);
    m_usedVertex[vertexIndex] = true;
    m_distance[vertexIndex] = 0;
    while(!queueVertexes.empty()) {
        size_t currentVertex = queueVertexes.front();
        m_bypass.push_back(currentVertex);
        queueVertexes.pop();
        for(Edge& edge : getAdj(currentVertex)){
            size_t nextVertex = edge.getLastVertexIndex();
            if(!m_usedVertex[nextVertex]){
                m_usedVertex[nextVertex];
                m_parent[nextVertex] = currentVertex;
                m_distance[nextVertex] = m_distance[currentVertex] + 1;
                queueVertexes.push(nextVertex);
            }
        }
    }

}

}
