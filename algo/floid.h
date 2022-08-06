#pragma once

#include "ialgo.h"

namespace graphs {

class Floid : public IAlgo {

public:
    Floid();
    void start();
    std::map<size_t, std::map<size_t, int>> getMatrix();
    virtual ~Floid();

protected:
    virtual void init();
    void floid();
private:
    std::map<size_t, std::map<size_t, int>> m_matrix;

};

}
