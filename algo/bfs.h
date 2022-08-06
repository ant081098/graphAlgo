#pragma once

#include "ialgo.h"

namespace graphs {

class IGraph;

class Bfs : public IAlgo {

public:
    Bfs();
    void start(size_t vertexIndex);
    std::vector<size_t> getByPass();
    std::map<size_t, int> getDistance();
    std::map<size_t, size_t> getParent();
    ~Bfs() override;

protected:
    void init() override;
    void bfs(size_t vertexIndex);

    std::map<size_t, int> m_distance;
    std::map<size_t, size_t> m_parent;
    std::vector<size_t> m_bypass;

};

}
