#pragma once

namespace graphs {

class Vertex {

public:
    Vertex(unsigned int index, int weight = 0);

    unsigned int getIndex() const;
    int getWeight() const;

    void setIndex(const unsigned int index);
    void setWeight(const int weight);

    bool operator<(const Vertex& vertex) const;

private:
    //Индекс вершины
    unsigned int m_index;
    //Вес вершины
    int m_weight;

};

}
