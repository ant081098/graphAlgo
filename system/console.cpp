#include "console.h"
#include "../graph/igraph.h"

#include <set>
#include <map>
#include <iostream>

namespace graphs {

Console::Console() : ISystem()
{

}

void Console::printMatrix(IGraph &graph)
{
    std::cout<<"Vertex count: "<<graph.countVertexes()<<"\n";
    std::cout<<"Edge count: "<<graph.countEdges()<<"\n\n";
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

    std::cout<<" +\t";
    for(const Vertex& v: vertexes){
        std::cout<<"[" <<v.getIndex()<<"]\t";
    }
    std::cout<<"\n";

    for(const Vertex& v: vertexes){
        std::cout<<"[" <<v.getIndex()<<"]\t";
        for(const Vertex& v2: vertexes){
            std::cout<<""<<matrix[v.getIndex()][v2.getIndex()]<<"\t";
        }
        std::cout<<"\n";
    }
}

void Console::printEdge(IGraph &graph)
{
    std::cout<<"Vertex count: "<<graph.countVertexes()<<"\n";
    std::cout<<"Edge count: "<<graph.countEdges()<<"\n\n";
    decltype (graph.edges()) edges = graph.edges();
    for(const Edge& e : edges){
        std::cout<<"["<<e.getFirstVertexIndex()<<"] -> ["
                <<e.getLastVertexIndex()<<"] = "<<e.getWeight()<<"\n";
    }
}

void Console::readMatrix(IGraph &graph)
{
    size_t n;
    std::cin>>n;
    for(size_t i=0;i<n;i++) {
        graph.createVertex(i+1);
    }

    for(size_t i = 0; i<n ;i++){
        for(size_t j = 0; j<n ;j++){
            int w;
            std::cin>>w;
            if(w) {
                graph.createEdge(i+1,j+1,w);
            }
        }
    }

}

void Console::readEdge(IGraph &graph)
{
    size_t n, m;
    std::cin>>n >> m;
    for(size_t i=0;i<n;i++) {
        graph.createVertex(i+1);
    }

    for(size_t i=0;i<m;i++) {
        size_t a,b;
        int w;
        std::cin>>a>>b>>w;
        graph.createEdge(a, b, w);
    }


}

Console::~Console()
{

}

}
