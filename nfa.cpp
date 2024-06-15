#include "nfa.hpp"
#include <stack>
template <typename T>
auto pop_value(T &stack)
{
    auto v = std::move(stack.top());
    stack.pop();
    return v;
}

TNFA::TNFA(std::string regexp) : G{regexp.length()}, re{regexp.c_str()}, M{regexp.length()}
{
    std::stack<int> ops; // operation stack
    for (int i = 0; i < M; i++)
    {        
        if (re[i] == '(' || re[i] == '|')
        {
            ops.push(i);            
        }
        else if (re[i] == ')')
        {
            int stack0 = pop_value(ops);
            if (re[stack0] == '|')
            {
                int stack1= pop_value(ops);
                G.addEdge(stack1, stack0 + 1);
                G.addEdge(stack0, i);
            }
            if (re[stack0] == '(' && i < M - 1 && re[i + 1] == '*')
            {
                G.addEdge(stack0, i + 1);
                G.addEdge(i + 1, stack0);
            }
        }
        else if (i < M - 1 && re[i + 1] == '*')
        {
            G.addEdge(i, i + 1);
            G.addEdge(i + 1, i);
        }
        if (re[i] == '(' || re[i] == '*' || re[i] == ')')
        {
            G.addEdge(i, i + 1);
        }
    }
}