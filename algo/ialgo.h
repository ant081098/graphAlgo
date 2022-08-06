#pragma once

#include "../graph/igraph.h"

namespace graphs {

class IAlgo {

public:
    IAlgo();
    void setGraph(IGraph *igraph);
    IGraph *graph();
    virtual ~IAlgo();

protected:
    virtual void init();
    bool checkUsedVertex(size_t vertexIndex) const;
    void setUsedVertex(size_t vertexIndex);
    std::vector<Edge> &getAdj(size_t vertexIndex);
    std::map<size_t, bool> m_usedVertex;
private:
    std::map<size_t, std::vector<Edge>> m_adjacency;

    IGraph *m_graph;
};

}
