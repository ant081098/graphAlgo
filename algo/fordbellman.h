#pragma once

#include "bfs.h"

namespace graphs {

class FordBellman : public Bfs {

public:
    FordBellman();
    ~FordBellman() override;
    void start(size_t vertexIndex);

protected:
    void init() override;
    void fordbellman(size_t vertexIndex);

};

}
