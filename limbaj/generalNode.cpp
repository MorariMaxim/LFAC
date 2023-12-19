#include "generalNode.h"
inline types str2Type(string str)
{

    if (str.compare("float") == 0)
    {
        return types::FLOAT;
    }
    else if (str.compare("string") == 0)
    {
        return types::STRING;
    }
    else if (str.compare("int") == 0)
    {
        return types::INT;
    }
    else if (str.compare("char") == 0)
    {
        return types::CHAR;
    }
    else if (str.compare("void") == 0)
    {
        return types::VOID;
    }
    return types::OTHER;
}

static int debug = 0;
typeNode::typeNode(string str) : generalNode(str)
{
    int debug = 0;
    this->type = str2Type(str);
    if (debug)
        printf("\nconstructing typeNode (%s)\n", str.c_str());
}

typeNode::~typeNode()
{
    if (debug)
        printf("destructing  typeNode (%s) \n", content.c_str());
    string s = "1";
}

generalNode::generalNode(string str) : content(str)
{
    if (debug)
        printf("constructing generalNode (%s) at (%d,%d)\n", content.c_str(), row, col);
}

generalNode::generalNode()
{
    content = "";
}

generalNode::generalNode(string str, int row, int col) : generalNode(str)
{
    this->row = row;
    this->col = col;
}

void generalNode::print()
{
    printf("%s", content.c_str());
}

generalNode::~generalNode()
{
    if (debug)
        printf("destructing  generalNode (%s)\n", content.c_str());
}

void printx(string str)
{
    static int debug = 1, delay = 0;
    if (debug)
    {
        printf("%s", str.c_str());
        fflush(stdin);
    }
    if (delay)
        this_thread::sleep_for(std::chrono::milliseconds(100));
}

expressionNode::expressionNode(operTypes op, expressionNode *left, expressionNode *right, string cont) : generalNode(cont)
{
    this->oper = op;
    this->left = left;
    this->right = right;
    vector<int> v;
    string s = "213";
}

expressionNode::expressionNode(value *val, string cont) : generalNode(cont)
{
    this->val = val;
}

expressionNode::~expressionNode()
{
    delete right;
    delete left;
    delete this->val;
}

value::~value()
{
}

parameterList::parameterList()
{
    parameters = new vector<Symbol *>();
}

void parameterList::addParameter(Symbol *parameter)
{
    (*parameters).push_back(parameter);
}

functionNode::functionNode(string name, types retType, vector<Symbol *> *pars) : generalNode("")
{
    parameters = pars;
    returnType = retType;
    this->name = name;
}

functionNode::~functionNode()
{
    if (parameters == nullptr)
        return;
    for (auto &par : *parameters)
    {
        delete par;
    }
    delete parameters;
}

Symbol *functionNode::hasParemeter(string name)
{
    if (!parameters)
        return nullptr;
    for (auto &par : *parameters)
    {
        if (par->name == name)
            return par;
    }
    return nullptr;
}

void functionNode::printParameters()
{
    if (parameters == nullptr)
        return;

    for (auto par : *parameters)
    {
        par->printSymbol();
    }
}

void functionNode::setSignature()
{

    string temp = "fn " + name + "(";
    if (parameters)
    {
        for (auto par : *parameters)
        {
            temp += par->getSymbolAsString() + ", ";
        }
        temp.erase(temp.size() - 2, 2);
    }
    temp += ") -> ";
    temp += getTypeAsStr(this->returnType);
    signature = temp;
    printf("%s\n", signature.c_str());
}

bool functionCall::checkCall()
{
    if (functionName == nullptr)
    {
        printf("name == nulptr\n");
        return false;
    }

    auto parameters = functionName->parameters;

    if (((parameters == nullptr) && (args->size() != 0)) ||
        ((parameters != nullptr) && (args->size() != parameters->size())))
    {
        printf("((parameters == nullptr) && (args->size() != 0)) || ((parameters != nullptr) && (args->size() != parameters->size()))\n");
        return false;
    }

    int size = args->size();
    for (int i = 0; i < size; i++)
    {
        if ((*args)[i]->type != (*parameters)[i]->type)
        {
            printf("args[%d].type (%s) != pars[%d].type (%s)\n", i, getTypeAsStr((*args)[i]->type).c_str(), i, getTypeAsStr((*parameters)[i]->type).c_str());
            return false;
        }
    }
    return true;
}

functionCall::functionCall(generalNode *scope_id, myVectorClass *rest)
{
    symbolTalbeNode *scope = currentSymbolTable;

    Symbol *sym = nullptr;
    if (scope_id)
    {
        sym = scope->is_user_symbol_defined(scope_id);
    }

    if (!sym)
        return;

    if (!rest)
    {
        printf("for some reason rest is null");
        return;
    }

    generalNode *id = (generalNode *)(rest->pointers[0]);

    scope = sym->classType;

    if (!id)
        return;

    auto funcnode = scope->isFuncDefined(id->content);

    if (funcnode == nullptr)
    {
        printf("found no such function\n");
        return ;
    }
        
    else
        printf("found such function\n");

    functionName = funcnode;
    
    args = new vector<rvalueNode *>();

    if (rest->pointers.size() > 1)
    {
        this->setArgs((rValueNodes *)(rest->pointers[1]));
    }
}

void functionCall::setArgs(rValueNodes *rvals)
{
    args = rvals->values;
}

void functionCall::addRvalue(rvalueNode *rval)
{
    args->push_back(rval);
}

rvalueNode::rvalueNode(string cont) : generalNode(cont)
{
    type = OTHER;
}

rvalueNode::rvalueNode(string cont, types type) : generalNode(cont)
{
    this->type = type;
}

rValueNodes::rValueNodes()
{
    values = new vector<rvalueNode *>();
}

void rValueNodes::addRvalue(rvalueNode *rval)
{
    values->push_back(rval);
}

#define checkSymbol(x)                                                                        \
    {                                                                                         \
        if (currentSymbolTable->isSymbolDefinedInPath(x->content) == nullptr)                 \
            printf("\nsymbol not defined %s at %d:%d\n", x->content.c_str(), x->row, x->col); \
    }
#define getSymbol(x) currentSymbolTable->isSymbolDefinedInPath(x->content)

arrayIndexing::arrayIndexing(generalNode *arr)
{
    checkSymbol(arr);
    auto sym = getSymbol(arr);

    if (sym == nullptr)
    {
        array = nullptr;
        return;
    }

    auto convert = dynamic_cast<arraySymbol *>(sym);
    if (convert == nullptr)
    {
        printf("%s is a symbol but not an arraySymbol\n", arr->content.c_str());
    }
    else
        array = convert;
}
inline intValueNode *convertIntValNode(rvalueNode *rvNode, int it)
{

    return nullptr;
}
bool arrayIndexing::checkIndexes()
{
    if (!values)
    {
        printf("rvalues of array_indexing is null");
        return false;
    }
    int dim = array->dimension;
    int n = values->size();
    int size;
    auto temp = array;
    if (dim < n)
    {
        printf("too many indexations\n");
    }
    int min = n - 1;

    int it = 0;
    int val;
    string indexing = "";
    rvalueNode *rvNode;
    while (it != min)
    {
        size = temp->size;
        // printf("size = %d\n",size);
        rvNode = (*values)[it];
        auto convert = dynamic_cast<intValueNode *>(rvNode);
        if (!convert)
        {
            printf("%dth indexing is not a integer value\n", it + 1);
            return false;
        }
        val = convert->value;
        indexing += "[" + to_string(val) + "]";

        if (val < 0 || val >= size)
        {
            printf("%dth indexing [%d] is out of range\n", it + 1, val);
            return false;
        }
        if (!temp->array_elements)
        {
            printf("temp->array_elements is null");
            return false;
        }
        temp = (*temp->array_elements)[val];
        it++;
    }

    size = temp->size;
    rvNode = (*values)[it];
    auto convert = dynamic_cast<intValueNode *>(rvNode);
    if (!convert)
    {
        printf("%dth indexing is not a integer value\n", it + 1);
        return false;
    }
    val = convert->value;
    indexing += "[" + to_string(val) + "]";
    if (val < 0 || val >= size)
    {
        printf("%dth indexing [%d] is out of range\n", it + 1, val);
        return false;
    }
    printf("%s corect indexing of a\n", indexing.c_str());
    return true;
}

intValueNode::intValueNode(string cont) : rvalueNode(cont, INT)
{
    value = atoi(cont.c_str());
}

void myVectorClass::add_pointer(void *ptr)
{
    printf("pushed back %p\n", ptr);
    pointers.push_back(ptr);
}
