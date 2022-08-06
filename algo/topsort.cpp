#include "topsort.h"
#include <algorithm>

namespace graphs {

TopSort::TopSort() : Dfs()
{

}

TopSort::~TopSort()
{

}

void TopSort::start()
{
    init();
    for(const Vertex& vertex : graph()->vertexes()){
        if(!checkUsedVertex(vertex.getIndex())){
            dfs(vertex.getIndex());
        }
    }
    std::reverse(begin(m_topsort), end(m_topsort));
}

std::vector<size_t> TopSort::getTopSort()
{
    return m_topsort;
}

void TopSort::init()
{
    Dfs::init();
    m_topsort.clear();
}

void TopSort::dfs(size_t vertexIndex)
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
    m_topsort.push_back(vertexIndex);
}

}
