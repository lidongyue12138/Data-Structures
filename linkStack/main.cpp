#include <iostream>

using namespace std;

template <typename elemType>
class Stack
{
public:
    virtual bool isEmpty() const = 0;
    virtual void push(const elemType &x) = 0;
    virtual elemType pop() = 0;
    virtual elemType top() const = 0;
    virtual ~Stack(){};
};

class OutofBound{};

template <typename elemType>
class linkStack
{
private:
    struct node
    {
        elemType data;
        node *next;
        node(const elemType &x, node* p=NULL){data = x; next=p;}
        node(){next = NULL;}
        ~node() {}
    };
    node *topNode;
public:
    linkStack(){topNode = NULL;}
    virtual bool isEmpty() const{return topNode==NULL;}
    virtual void push(const elemType &x)
    {
        node *tmp = new node(x,topNode);
        topNode = tmp;
    }
    virtual elemType pop()
    {
        if (!topNode) throw OutofBound();
        node *tmp = topNode;
        topNode = topNode->next;
        elemType data = tmp->data;
        delete tmp;
        return data;
    }
    virtual elemType top() const
    {
        if (!topNode) throw OutofBound();
        return topNode->data;
    }
    virtual ~linkStack()
    {
        node *tmp;
        while(topNode)
        {
            tmp = topNode;
            topNode = tmp->next;
            delete tmp;
        }
    }
};

int main()
{
    linkStack<int> testStack;
    for (int i=0; i<10; i++){testStack.push(i);}
    while(!testStack.isEmpty())
    {cout << testStack.top();
        cout << " " << testStack.pop() << endl;}
}
