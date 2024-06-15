#include "./digraph/digraph.hpp"


class TNFA{
    public:
    TNFA(std::string regexp);
    TDigraph G;
    private:
    const char *re; 
       
    size_t M;
};