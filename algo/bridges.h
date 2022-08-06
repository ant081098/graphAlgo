#pragma once

#include "dfs.h"

namespace graphs {

class Bridges : public Dfs {

public:
    Bridges();
    ~Bridges() override;
    void start();
    std::set<Edge> getBridges();

protected:
    void init() override;
    void dfs(size_t vertexIndex, size_t vertexIndexparent = 0);
private:
    int m_timer;
    std::set<Edge> m_bridges;
    std::map<size_t, int> m_tin, m_fup;
};

}
