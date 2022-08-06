#include "vertex.h"

namespace graphs {

Vertex::Vertex(unsigned int index, int weight) : m_index(index), m_weight(weight)
{

}

unsigned int Vertex::getIndex() const
{
    return m_index;
}

void Vertex::setIndex(const unsigned int index)
{
    m_index = index;
}

int Vertex::getWeight() const
{
    return m_weight;
}

void Vertex::setWeight(const int weight)
{
    m_weight = weight;
}

bool Vertex::operator<(const Vertex &vertex) const
{
    return this->getIndex() < vertex.getIndex();
}

}
