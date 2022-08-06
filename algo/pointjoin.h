#pragma once

#include "dfs.h"

namespace graphs {

class PointJoin : public Dfs {

public:
    PointJoin();
    ~PointJoin() override;
    void start();
    std::set<Vertex> getPointJoin();

protected:
    void init() override;
    void dfs(size_t vertexIndex, size_t vertexIndexParent = 0);
private:
    int m_timer;
    std::map<size_t, int> m_tin, m_fup;
    std::set<Vertex> m_pointjoin;
};

}
