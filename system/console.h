#pragma once

#include "isystem.h"

namespace graphs {

class Console : public ISystem {
public:
    Console();
    void printMatrix(IGraph& graph) override;
    void printEdge(IGraph& graph) override;

    void readMatrix(IGraph& graph) override;
    void readEdge(IGraph& graph) override;
    ~Console() override;
};

}
