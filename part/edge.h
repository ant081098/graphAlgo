#pragma once
namespace graphs {

class Edge {

public:
    Edge(unsigned int firstVertexIndex, unsigned int lastVertexIndex, int weight = 0);

    int getWeight() const;
    void setWeight(const int weight);

    unsigned int getFirstVertexIndex() const;
    unsigned int getLastVertexIndex() const;

    bool operator<(const Edge& edge) const;


private:
    //Вес ребра
    int m_weight;
    //Вершины ребра
    unsigned int m_firstVertexIndex, m_lastVertexIndex;
};

}
