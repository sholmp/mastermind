#include "combotree.h"

ComboTree::ComboTree(std::string colors, int depth): colors(colors)
{
    root = new Node;
    generateTree(root, depth);
}

std::list<std::string> ComboTree::getCombinations()
{
    std::list<std::string> combos;
    for(Node* child : root->children)
        getCombinations(child, "", combos);

    return combos;
}

ComboTree::~ComboTree()
{
    for(auto ptr : nodes)
        delete ptr;
}


void ComboTree::generateTree(Node* node, int depth)
{
    if(depth == 0)
        return;

    for(char ch : colors)
    {
        Node* nn = new Node(ch);
        nodes.push_back(nn);
        node->children.push_back(nn);
        generateTree(nn, depth - 1);
    }
}

void ComboTree::getCombinations(Node* n, std::string prev_string, std::list<std::string>& combos)
{
    if(n->children.size() == 0) //leaf
    {
        combos.push_back(prev_string + n->ch);
        return;
    }
    for(Node* child : n->children)
    {
        getCombinations(child, prev_string + n->ch, combos);
    }
}

