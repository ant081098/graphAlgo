#include "pointjoin.h"
#include <algorithm>

namespace graphs {

PointJoin::PointJoin() : Dfs()
{

}

PointJoin::~PointJoin()
{

}

void PointJoin::start()
{
    init();
    for(const Vertex& vertex : graph()->vertexes()){
        if(!checkUsedVertex(vertex.getIndex())){
            dfs(vertex.getIndex());
        }
    }

}

std::set<Vertex> PointJoin::getPointJoin()
{
    return m_pointjoin;
}

void PointJoin::init()
{
    Dfs::init();
    m_pointjoin.clear();
    m_tin.clear();
    m_fup.clear();
    for(const Vertex& vertex : graph()->vertexes()){
        m_tin[vertex.getIndex()] = m_fup[vertex.getIndex()] = 0;
    }
}

void PointJoin::dfs(size_t vertexIndex, size_t vertexIndexParent)
{
    m_usedVertex[vertexIndex] = true;
    m_tin[vertexIndex] = m_fup[vertexIndex] = m_timer;
    m_bypass.push_back(vertexIndex);
    int countChildVertex =0;
    for(Edge& edge : getAdj(vertexIndex)){
        size_t nextVertex = edge.getLastVertexIndex();
        if (nextVertex == vertexIndexParent)
            continue;
        if(m_usedVertex[nextVertex]){
            m_fup[vertexIndex] = std::min(m_fup[vertexIndex], m_fup[nextVertex]);
        } else {
            dfs(nextVertex, vertexIndex);
            m_fup[vertexIndex] = std::min(m_fup[vertexIndex], m_fup[nextVertex]);
            if (m_fup[nextVertex] >= m_tin[vertexIndex] && vertexIndexParent == 0) {
                m_pointjoin.insert(Vertex(vertexIndex));
            }
            countChildVertex++;
        }
    }
    if (vertexIndexParent == 0 && countChildVertex > 1){
        m_pointjoin.insert(Vertex(vertexIndex));
    }
}

}
