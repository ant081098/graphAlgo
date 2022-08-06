#include "bridges.h"
#include <algorithm>

namespace graphs {

Bridges::Bridges() : Dfs()
{

}

Bridges::~Bridges()
{

}

void Bridges::start()
{
    init();
    for(const Vertex& vertex : graph()->vertexes()){
        if(!checkUsedVertex(vertex.getIndex())){
            dfs(vertex.getIndex());
        }
    }

}

void Bridges::init()
{
    Dfs::init();
    m_timer = 0;
    m_bridges.clear();
    m_tin.clear();
    m_fup.clear();
    for(const Vertex& vertex : graph()->vertexes()){
        m_tin[vertex.getIndex()] = m_fup[vertex.getIndex()] = 0;
    }
}

void Bridges::dfs(size_t vertexIndex, size_t vertexIndexParent)
{
    m_usedVertex[vertexIndex] = true;
    m_tin[vertexIndex] = m_fup[vertexIndex] = m_timer;
    m_bypass.push_back(vertexIndex);

    for(Edge& edge : getAdj(vertexIndex)){
        size_t nextVertex = edge.getLastVertexIndex();
        if (nextVertex == vertexIndexParent)
            continue;
        if(m_usedVertex[nextVertex]){
            m_fup[vertexIndex] = std::min(m_fup[vertexIndex], m_fup[nextVertex]);
        } else {
            dfs(nextVertex, vertexIndex);
            m_fup[vertexIndex] = std::min(m_fup[vertexIndex], m_fup[nextVertex]);
            if (m_fup[nextVertex] > m_tin[vertexIndex]) {
                m_bridges.insert(Edge(vertexIndex, nextVertex));
            }
        }
    }

}

std::set<Edge> Bridges::getBridges()
{
    return m_bridges;
}

}
