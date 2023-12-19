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
TypeNode::TypeNode(string str) : generalNode(str)
{
    int debug = 0;
    this->type = str2Type(str);
    if (debug)
        printf("\nconstructing TypeNode (%s)\n", str.c_str());
}

TypeNode::~TypeNode()
{
    if (debug)
        printf("destructing  TypeNode (%s) \n", content.c_str());
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

bool compare_types(TypeNode *t1, TypeNode *t2)
{

    if (t1->type != t2->type)
        return false;

    if (t1->type == types::USER_TYPE)
    {

        auto clas = dynamic_cast<ClassType *>(t1);

        if (!clas)
        {
            printf("error at dynamic cast \n");
            return false;
        }
        string name1 = clas->clas->name;
        clas = dynamic_cast<ClassType *>(t1);

        if (!clas)
        {
            printf("error at dynamic cast \n");
            return false;
        }
        string name2 = clas->clas->name;

        if (name1 != name2)
            return false;
    }
    return true;
}

TypeNode *ExpressionNode::type_of()
{
    if (type_node)
        return type_node;

    if (oper == OperTypes::NEG || oper == OperTypes::UMINUS)
    {
        return left->type_of();
    }
    auto t1 = left->type_of();

    auto t2 = right->type_of();

    if (!compare_types(t1, t2))
        return nullptr;

    return t1;
}

#define check_children_for_nullptr()     \
    {                                    \
        if (!left)                       \
        {                                \
            printf("left child null\n"); \
            return nullptr;              \
        }                                \
        if (!right)                      \
        {                                \
            return nullptr;              \
            printf("left child null\n"); \
        }                                \
    }

TypeNode *ExpressionNode::eval_binary_operator()
{

    auto t1 = left->eval();
    auto t2 = right->eval();

    if (!compare_types(t1, t2))
        return nullptr;

    switch (oper)
    {
    case OperTypes::SUB:
    {
        t1->sub(t2);
        break;
    }
    case OperTypes::ADD:
    {
        t1->add(t2);
        break;
    }
    case OperTypes::MUL:
    {
        t1->mul(t2);
        break;
    }
    case OperTypes::DIV:
    {
        t1->div(t2);
        break;
    }
    default:
        return nullptr;
    }

    delete t2;

    return t1;
}
TypeNode *ExpressionNode::eval_unary_operator()
{
    auto t1 = left->eval();  
    switch (oper)
    {
    case OperTypes::NEG:
    {
        t1->neg();
        break;
    }
    case OperTypes::UMINUS:
    {
        t1->uminus();
        break;
    } 
    default:
        return nullptr;
    }

    return t1;
}
TypeNode *ExpressionNode::eval()
{
    if (type_node)
    {
        auto t = new TypeNode();
        *t = *type_node;
        return t;
    }

    if (oper == OperTypes::SUB || oper == OperTypes::ADD || oper == OperTypes::MUL || oper == OperTypes::DIV)
        return eval_binary_operator();

    if (oper == OperTypes::NEG || oper == OperTypes::UMINUS)
        return eval_unary_operator();
        
    return nullptr;
}

ExpressionNode::ExpressionNode(OperTypes op, ExpressionNode *left, ExpressionNode *right, string cont) : generalNode(cont)
{
    this->oper = op;
    this->left = left;
    this->right = right;
    vector<int> v;
    string s = "213";
}

ExpressionNode::ExpressionNode(TypeNode *type_node, string cont) : generalNode(cont)
{
    this->type_node = type_node;
}

ExpressionNode::~ExpressionNode()
{
    delete right;
    delete left;
    delete this->type_node;
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
        return;
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

    auto convert = dynamic_cast<ArrayType *>(sym->typen);
    if (!convert)
    {
        printf("%s is not an ArrayType\n", arr->content.c_str());
    }
    else
        array = convert;
}
bool arrayIndexing::checkIndexes()
{
    printf("indexes : ");
    for (auto v : *values)
    {
        printf("%d ", (dynamic_cast<IntType *>(v))->value);
    }
    printf("\n");

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
        auto convert = dynamic_cast<IntType *>(rvNode);
        if (!convert)
        {
            printf("%dth indexing is not a integer value\n", it + 1);
            return false;
        }
        val = convert->value;
        indexing += "[" + to_string(val) + "]";

        if (val < 0 || val >= size)
        {
            printf("%dth indexing [%d] is out of range[%d]\n", it + 1, val, size);
            return false;
        }
        if (!temp->elements)
        {
            printf("temp->array_elements is null");
            return false;
        }
        temp = dynamic_cast<ArrayType *>((*temp->elements)[val]);
        if (!temp)
        {
            printf("error during dynamic_cast !\n");
            return false;
        }
        it++;
    }

    size = temp->size;
    rvNode = (*values)[it];
    auto convert = dynamic_cast<IntType *>(rvNode);
    if (!convert)
    {
        printf("%dth indexing is not a integer value\n", it + 1);
        return false;
    }
    val = convert->value;
    indexing += "[" + to_string(val) + "]";
    if (val < 0 || val >= size)
    {
        printf("%dth indexing [%d] is out of range[%d]\n", it + 1, val, size);
        return false;
    }
    printf("%s corect indexing of a\n", indexing.c_str());
    return true;
}

void myVectorClass::add_pointer(void *ptr)
{
    printf("pushed back %p\n", ptr);
    pointers.push_back(ptr);
}

ArrayType::ArrayType(string str, int iteration) : TypeNode(str)
{
    elements = nullptr;
    buildFromStack(iteration);
}

ArrayType::~ArrayType()
{
    for (auto el : *elements)
    {
        delete el;
    }
    delete elements;
}

ArrayType *ArrayType::arrayBuiltFromStack = nullptr;

void ArrayType::buildFromStack(int it)
{
    if (it == 0)
    {
        printf("array type = ");
        printType(arrayType);
        printf("\ndimensions : ");
        for (auto &el : arrayStack)
        {
            printf("%d,", el);
        }
        printf("\n");
    }

    int n = arrayStack.size();
    this->type = types::ARRAY;
    el_type = types::ARRAY;
    this->size = arrayStack[it];
    this->dimension = n - it;

    if (n == (it + 1))
    {
        types base_type;
        vector<TypeNode *> *bottom_elements;
        switch (arrayType)
        {
        case FLOAT:
            // printf("float\n");
            base_type = types::FLOAT;
            bottom_elements = new vector<TypeNode *>(this->size, new FloatType());
            break;
        case INT:
            base_type = types::INT;
            // printf("int\n");
            bottom_elements = new vector<TypeNode *>(this->size, new IntType("0"));
            break;
        case CHAR:
            base_type = types::CHAR;
            // printf("char\n");
            bottom_elements = new vector<TypeNode *>(this->size, new CharType());
            break;
        case STRING:
            break;
        default:
            break;
        }
        elements = bottom_elements;
        el_type = base_type;
    }
    else
    {
        elements = new vector<TypeNode *>(this->size, new ArrayType("", it + 1));
    }
    if (it == 0)
    {
        arrayStack.clear();
    }
}

IntType::IntType(string s)
{
    value = atoi(s.c_str());
}

bool IntType::add(TypeNode *other)
{

    auto t2 = dynamic_cast<IntType *>(other);

    this->value += t2->value;
    return true;
}
