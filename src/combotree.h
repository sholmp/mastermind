#ifndef COMBOTREE_H
#define COMBOTREE_H


#include <list>
#include <string>
#include <vector>

struct Node
{
    Node(){}
    Node(char ch): ch(ch){}

    std::vector<Node*> children;
    char ch;
};

class ComboTree
{
public:
    ComboTree(std::string colors, int depth);
    std::list<std::string> getCombinations();
    ~ComboTree();

private:
    void generateTree(Node* node, int depth);
    void getCombinations(Node* n, std::string prev_string, std::list<std::string>& combos);

    Node* root;
    std::vector<Node*> nodes;
    std::string colors;
};


#endif // COMBOTREE_H
