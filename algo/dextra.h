#pragma once

#include "bfs.h"

namespace graphs {

class Dextra : public Bfs {

public:
    Dextra();
    ~Dextra() override;
    void start(size_t vertexIndex);


protected:
    void init() override;
    void dextra(size_t vertexIndex);

};

}
