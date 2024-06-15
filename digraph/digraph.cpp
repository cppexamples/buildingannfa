#include "digraph.hpp"
#include <iostream>
#include <fstream>
#include <ios>

void TDigraph::init(size_t v)
{
    V = v;
    E = 0;
    adj = new std::vector<int>[V];
}

TDigraph::TDigraph(size_t v)
{
    init(v);
}

TDigraph::TDigraph(std::string filename)
{
    std::fstream fin(filename, std::fstream::in);
    if (!fin.is_open())
    {
        std::cerr << "Failed to open the file." << std::endl;
    }

    fin >> std::skipws >> V;
    init(V);
    fin >> std::skipws >> E;

    int v;
    int w;
    while (true)
    {
        if (!(fin >> std::skipws >> v))
            break;
        fin >> std::skipws >> w;
        addEdge(v, w);
    }
}

void TDigraph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    E++;
}

TDigraph TDigraph::reverse()
{
    TDigraph R{V};
    for (int v = 0; v < V; v++)
        for (int w : getAdj(v))
            R.addEdge(w, v);
    return R;
}

std::vector<int>& TDigraph::getAdj(int v){
    return adj[v];
}

void TDigraph::printGraph()
{
    for (int i = 0; i < V; i++)
    {
        std::cout << i<< "= ";
        for(const int &i:adj[i]){
            std::cout << " " << i;
        }
        std::cout<< std::endl;               
    }
};

int TDigraph::getV(){
    return V;
}