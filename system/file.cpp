#include "file.h"
#include "../graph/igraph.h"

#include <set>
#include <map>
#include <iostream>

namespace graphs {

File::File(std::string filename) : ISystem()
{
    m_file.open(filename);
}

void File::printMatrix(IGraph &graph)
{
    if (!m_file.is_open()) return;

    m_file<<"Vertex count: "<<graph.countVertexes()<<"\n";
    m_file<<"Edge count: "<<graph.countEdges()<<"\n\n";
    std::map<size_t, std::map<size_t, int>> matrix;
    decltype (graph.vertexes()) vertexes = graph.vertexes();
    for(const Vertex& v: vertexes){
        for(const Vertex& v2: vertexes){
            matrix[v.getIndex()][v2.getIndex()] = 0;
        }
    }
    decltype (graph.edges()) edges = graph.edges();
    for(const Edge& e : edges){
        matrix[e.getFirstVertexIndex()][e.getLastVertexIndex()] = e.getWeight();
    }

    m_file<<" +\t";
    for(const Vertex& v: vertexes){
        m_file<<"[" <<v.getIndex()<<"]\t";
    }
    m_file<<"\n";

    for(const Vertex& v: vertexes){
        m_file<<"[" <<v.getIndex()<<"]\t";
        for(const Vertex& v2: vertexes){
            m_file<<""<<matrix[v.getIndex()][v2.getIndex()]<<"\t";
        }
        m_file<<"\n";
    }
}

void File::printEdge(IGraph &graph)
{
    if (!m_file.is_open()) return;

    m_file<<"Vertex count: "<<graph.countVertexes()<<"\n";
    m_file<<"Edge count: "<<graph.countEdges()<<"\n\n";
    decltype (graph.edges()) edges = graph.edges();
    for(const Edge& e : edges){
        m_file<<"["<<e.getFirstVertexIndex()<<"] -> ["
                <<e.getLastVertexIndex()<<"] = "<<e.getWeight()<<"\n";
    }
}

void File::readMatrix(IGraph &graph)
{
    if (!m_file.is_open()) return;

    size_t n;
    m_file>>n;
    for(size_t i=0;i<n;i++) {
        graph.createVertex(i+1);
    }

    for(size_t i = 0; i<n ;i++){
        for(size_t j = 0; j<n ;j++){
            int w;
            m_file>>w;
            if(w) {
                graph.createEdge(i+1,j+1,w);
            }
        }
    }

}

void File::readEdge(IGraph &graph)
{
    if (!m_file.is_open()) return;

    size_t n, m;
    m_file>>n >> m;
    for(size_t i=0;i<n;i++) {
        graph.createVertex(i+1);
    }

    for(size_t i=0;i<m;i++) {
        size_t a,b;
        int w;
        m_file>>a>>b>>w;
        graph.createEdge(a, b, w);
    }


}

File::~File()
{
    m_file.close();
}

}
