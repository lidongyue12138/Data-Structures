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
class seqStack:public Stack<elemType>
{
private:
    elemType *data;
    int topNum;
    int maxSize;
    void doubleSpace()
    {
        maxSize *= 2;
        elemType *tmp = new elemType[maxSize];
        for (int i=0; i<topNum+1; i++)
        {
            tmp[i] = data[i];
        }
        delete []data;
        data = tmp;
    }
public:
    seqStack(int initSize=10000);
    virtual ~seqStack(){delete []data ;}
    virtual bool isEmpty() const;
    virtual void push(const elemType &x);
    virtual elemType pop();
    virtual elemType top() const;
};

template <typename elemType>
seqStack<elemType>::seqStack(int initSize)
{
    data = new elemType[initSize];
    maxSize = initSize;
    topNum = -1;
}


template <typename elemType>
bool seqStack<elemType>::isEmpty() const {return topNum==-1;}

template <typename elemType>
void seqStack<elemType>::push(const elemType &x)
{
    if (topNum==maxSize-1) doubleSpace();
    data[++topNum] = x;
}

template <typename elemType>
elemType seqStack<elemType>::pop()
{
    if (topNum == -1) throw OutofBound();
    return data[topNum--];
}

template <typename elemType>
elemType seqStack<elemType>::top() const
{
    if (topNum == -1) throw OutofBound();
    return data[topNum];
}


int main()
{
    seqStack<int> testStack;
    for (int i=0; i<10; i++){testStack.push(i);cout<<testStack.top()<<endl;}
    while(!testStack.isEmpty()){cout << testStack.pop() << " " <<testStack.pop() << endl;}
}
