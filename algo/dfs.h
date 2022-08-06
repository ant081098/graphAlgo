#pragma once

#include "ialgo.h"

namespace graphs {

class IGraph;

class Dfs : public IAlgo {

public:
    Dfs();
    ~Dfs() override;
    void start(size_t vertexIndex);
    std::vector<size_t> getByPass();

protected:
    void init() override;
    void dfs(size_t vertexIndex);
    std::vector<size_t> m_bypass;
};

}
