#include "edge.h"
#include "vertex.h"

namespace graphs {

Edge::Edge(unsigned int firstVertexIndex, unsigned int lastVertexIndex, int weight) :
    m_weight(weight),
    m_firstVertexIndex(firstVertexIndex),
    m_lastVertexIndex(lastVertexIndex)
{

}

int Edge::getWeight() const
{
    return m_weight;
}

void Edge::setWeight(const int weight)
{
    m_weight = weight;
}

unsigned int Edge::getFirstVertexIndex() const
{
    return m_firstVertexIndex;
}

unsigned int Edge::getLastVertexIndex() const
{
    return m_lastVertexIndex;
}

bool Edge::operator<(const Edge &edge) const
{
    if (this->getFirstVertexIndex() == edge.getFirstVertexIndex())
        return this->getLastVertexIndex() < edge.getLastVertexIndex();

    return this->getFirstVertexIndex() < edge.getFirstVertexIndex();
}

}
