#include "generalNode.h"

typeNode::typeNode(string str, types type) : generalNode(str)
{
    this->type = type;
    printf("constructing typeNode (%s)\n",content.c_str());
}

typeNode::~typeNode()
{
    printf("destructing  typeNode (%s)\n",content.c_str());
}

generalNode::generalNode(string str) : content(str)
{
    printf("constructing generalNode (%s)\n",content.c_str());
}

generalNode::~generalNode()
{
    printf("destructing  generalNode (%s)\n",content.c_str());
}
