#pragma once

#include "dfs.h"

namespace graphs {

class TopSort : public Dfs {

public:
    TopSort();
    ~TopSort() override;
    void start();
    std::vector<size_t> getTopSort();

protected:
    void init() override;
    void dfs(size_t vertexIndex);
private:
    std::vector<size_t> m_topsort;
};

}
