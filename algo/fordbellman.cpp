#include "fordbellman.h"
#include <queue>

namespace graphs {

FordBellman::FordBellman() : Bfs()
{

}

FordBellman::~FordBellman()
{

}

void FordBellman::start(size_t vertexIndex)
{
    init();
    fordbellman(vertexIndex);
}

void FordBellman::init()
{
    Bfs::init();
}

void FordBellman::fordbellman(size_t vertexIndex)
{
    m_distance[vertexIndex] = 0;
    for (;;) {
        bool exit = false;
        for(const Edge& edge: graph()->edges()){
            if(m_distance[edge.getFirstVertexIndex()] < INT_MAX){
                if(m_distance[edge.getLastVertexIndex()] > m_distance[edge.getFirstVertexIndex()] + edge.getWeight()){
                    m_distance[edge.getLastVertexIndex()] = m_distance[edge.getFirstVertexIndex()] + edge.getWeight();
                    exit = true;
                }
            }
        }
        if(!exit)
            break;
    }
}

}
