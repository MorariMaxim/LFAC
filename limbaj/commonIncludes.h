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
class ArrayIndexing;
using namespace std;

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

enum AssignResult
{
    DIFTYPE,
    OK,
    ISCONST,
    OTHERAR
};

enum Colours
{
    IDCOL,
    TYPECOL,
    DEFAULTCOL,
    CFCOL,
    VALCOL
};

string col_2_ansi(Colours col);
void printType(types type);
string getTypeAsStr(types type);

extern int row;
extern int col;
extern SymbolTable *rootSymbolTable;
extern SymbolTable *currentSymbolTable;
extern vector<int> arrayStack;
extern TypeNode *arrayType;
extern TypeNode *gReturnType;
extern Expression *return_expression;
extern visibilityType currentVisibility;
extern bool ignore_after_return_statement;

class GeneralInfo;

#define semantic_error(message, ...)                                                                        \
    do                                                                                                      \
    {                                                                                                       \
        int debug_option = 1;                                                                               \
        if (!debug_option)                                                                                  \
            continue;                                                                                       \
        char buffer_x[300];                                                                                 \
        snprintf(buffer_x, sizeof(buffer_x), "SEMANTIC ERROR : ");                                          \
        snprintf(buffer_x + strlen(buffer_x), sizeof(buffer_x) - strlen(buffer_x), message, ##__VA_ARGS__); \
        printf("\033[38;5;196m%s\033[0m\n", buffer_x);                                                        \
    } while (0)
#endif
