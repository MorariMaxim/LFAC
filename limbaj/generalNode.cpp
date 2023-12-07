#include "generalNode.h"
using namespace std;

generalNode::generalNode(string str)
{
    content = str;
    printf("Node (%s) was created\n",content.c_str());
}

generalNode::~generalNode()
{
    printf("Node (%s) was destroyed\n",content.c_str());
}
