#pragma once
#include <vector>
#include <string>

class TDigraph
{
public:
    TDigraph(size_t V);
    TDigraph(std::string filename);
    int getV();
    int getE();
    std::vector<int>& getAdj(int v);
    void addEdge(int v, int w);
    TDigraph reverse();
    void printGraph();

private:
    size_t V;
    size_t E;
    std::vector<int> *adj;
    void init (size_t v);
};