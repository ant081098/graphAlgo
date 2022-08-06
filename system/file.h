#pragma once

#include "isystem.h"
#include <fstream>
#include <string>

namespace graphs {

class File : public ISystem {
public:
    File(std::string filename);
    void printMatrix(IGraph& graph) override;
    void printEdge(IGraph& graph) override;

    void readMatrix(IGraph& graph) override;
    void readEdge(IGraph& graph) override;
    ~File() override;
private:
    std::fstream m_file;
};

}
