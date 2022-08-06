#include "floid.h"

namespace graphs {

Floid::Floid() : IAlgo()
{

}

Floid::~Floid()
{

}

void Floid::start()
{
    init();
    floid();
}

std::map<size_t, std::map<size_t, int> > Floid::getMatrix()
{
    return m_matrix;
}

void Floid::init()
{
    IAlgo::init();
    m_matrix.clear();
    for(const Vertex& vertex : graph()->vertexes()){
        for(const Vertex& vertex2 : graph()->vertexes()){
            m_matrix[vertex.getIndex()][vertex2.getIndex()] = INT_MAX;
        }
    }
    for(const Edge& edge : graph()->edges()){
        m_matrix[edge.getFirstVertexIndex()][edge.getLastVertexIndex()] = edge.getWeight();
    }
}

void Floid::floid()
{
    for(const Vertex& vertexMiddle : graph()->vertexes()){
        for(const Vertex& vertexLeft : graph()->vertexes()){
            for(const Vertex& vertexRight : graph()->vertexes()){
                m_matrix[vertexLeft.getIndex()][vertexRight.getIndex()] = std::min(
                            m_matrix[vertexLeft.getIndex()][vertexRight.getIndex()],
                        m_matrix[vertexLeft.getIndex()][vertexMiddle.getIndex()]
                        + m_matrix[vertexMiddle.getIndex()][vertexRight.getIndex()]
                        );
            }
        }
    }
}

}
