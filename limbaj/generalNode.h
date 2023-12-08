#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum types
{
    INT,
    FLOAT,
    CHAR,
    STRING
};

class generalNode
{

public:
    string content;

    generalNode(string str);
    virtual ~generalNode();
};

class typeNode : public generalNode
{
public:
    types type;

    typeNode(string str, types type) ;
    ~typeNode();
};