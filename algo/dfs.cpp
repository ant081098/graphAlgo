#include "dfs.h"

namespace graphs {

Dfs::Dfs() : IAlgo()
{

}

Dfs::~Dfs()
{

}

void Dfs::start(size_t vertexIndex)
{
    init();
    dfs(vertexIndex);
}

std::vector<size_t> Dfs::getByPass()
{
    return m_bypass;
}

void Dfs::init()
{
    IAlgo::init();
    m_bypass.clear();
}

void Dfs::dfs(size_t vertexIndex)
{
    if(m_usedVertex[vertexIndex]){
        return;
    }
    m_usedVertex[vertexIndex] = true;
    m_bypass.push_back(vertexIndex);
    for(Edge& edge : getAdj(vertexIndex)){
        size_t nextVertex = edge.getLastVertexIndex();
        dfs(nextVertex);
    }

}

}
