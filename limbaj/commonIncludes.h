#ifndef commonIncludes_H
#define commonIncludes_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
class symbolTalbeNode;
class expressionNode;
class functionNode;
using namespace std;

#define checkInsertion(...)                                                                      \
    {                                                                                            \
        int debug = 0;                                                                           \
        auto result = __VA_ARGS__;                                                               \
        if (result.second)                                                                       \
        {                                                                                        \
            if (debug)                                                                           \
                cout << "Insertion successful. Value: " << result.first->second << std::endl;    \
        }                                                                                        \
        else                                                                                     \
        {                                                                                        \
            if (debug)                                                                           \
                cout << "Element already existed. Value: " << result.first->second << std::endl; \
        }                                                                                        \
    }

enum types
{
    INT,
    FLOAT,
    CHAR,
    STRING,
    VOID,
    OTHER
};

enum visibilityType
{
    PRIVATE,
    PUBLIC
};
enum scopeType
{
    OTHER_SCOPE,
    CLASS_SCOPE,
    FUNC_SCOPE,
};
void printType(types type);
string getTypeAsStr(types type);

extern int row;
extern int col;
extern symbolTalbeNode *rootSymbolTable;
extern symbolTalbeNode *currentSymbolTable;
extern vector<int> arrayStack;
extern types arrayType;
extern types returnType;
extern visibilityType currentVisibility;

class generalNode;
#endif
