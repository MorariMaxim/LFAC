#ifndef commonIncludes_H
#define commonIncludes_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <string.h>
class SymbolTable;
class Expression;
class FunctionDetails;
class Vector;
class TypeNode;
class ValueNode;
class ArrayType;
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
    OTHER,
    ARRAY,
    USER_TYPE
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
extern SymbolTable *rootSymbolTable;
extern SymbolTable *currentSymbolTable;
extern vector<int> arrayStack;
extern TypeNode* arrayType;
extern TypeNode*  gReturnType;
extern Expression* return_expression;
extern visibilityType currentVisibility;
extern bool ignore_after_return_statement;

class GeneralInfo;

#define notify(message, ...)                                                                                \
    do                                                                                                      \
    {                                                                                                       \
        int debug_option = 1;                                                                               \
        if (!debug_option)                                                                                  \
            continue;                                                                                       \
        char buffer_x[300];                                                                                 \
        snprintf(buffer_x, sizeof(buffer_x), "NOTIFY : ");                                                  \
        snprintf(buffer_x + strlen(buffer_x), sizeof(buffer_x) - strlen(buffer_x), message, ##__VA_ARGS__); \
        printf("%s", buffer_x);                                                                             \
    } while (0)
#endif
