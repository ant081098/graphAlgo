#include "dextra.h"
#include <queue>

namespace graphs {

Dextra::Dextra() : Bfs()
{

}

Dextra::~Dextra()
{

}

void Dextra::start(size_t vertexIndex)
{
    init();
    dextra(vertexIndex);
}

void Dextra::init()
{
    Bfs::init();
}

void Dextra::dextra(size_t vertexIndex)
{
    m_distance[vertexIndex] = 0;
    std::priority_queue<std::pair<int, size_t>> queueVertexes;
    queueVertexes.push(std::make_pair(-m_distance[vertexIndex], vertexIndex));
    while(!queueVertexes.empty()){
        size_t currentVertex = queueVertexes.top().second;
        int distanceVertex = -queueVertexes.top().first;
        queueVertexes.pop();
        if(distanceVertex > m_distance[currentVertex])
            continue;
        for(Edge& edge : getAdj(currentVertex)){
            size_t nextVertex = edge.getLastVertexIndex();
            int nextVertexWeight = edge.getWeight();
            if(m_distance[currentVertex] + nextVertexWeight < m_distance[nextVertex]) {
                m_distance[nextVertex] = m_distance[currentVertex] + nextVertexWeight;
                m_parent[nextVertex] = currentVertex;
                queueVertexes.push(std::make_pair(-m_distance[nextVertex], nextVertex));
            }
        }


    }
}

}
