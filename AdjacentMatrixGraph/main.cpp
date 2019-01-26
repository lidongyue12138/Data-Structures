#include <iostream>

using namespace std;


template <typename elemType>
class Queue
{
public:
    virtual bool isEmpty() const =0;
    virtual void enQueue(const elemType &x) = 0;
    virtual elemType deQueue()=0;
    virtual elemType getHead() const =0;
    virtual ~Queue(){};
};

class queueIsEmpty{};

template <typename elemType>
class seqQueue
{
private:
    elemType *data;
    int head;
    int rear;
    int maxSize;

    void doubleSpace();
public:
    seqQueue(int initSize=100);
    ~seqQueue();
    virtual bool isEmpty() const;
    virtual void enQueue(const elemType &x);
    virtual elemType deQueue();
    virtual elemType getHead() const;
};

template <typename elemType>
void seqQueue<elemType>::doubleSpace()
{
    elemType *tmp = new elemType[maxSize*2];
    for (int i=1; i<maxSize; i++) tmp[i] = data[(head+i)%maxSize];
    head = 0; rear = maxSize - 1;
    maxSize *= 2;
    delete []data;
    data = tmp;
}

template <typename elemType>
seqQueue<elemType>::seqQueue(int initSize)
{
    data = new elemType[initSize];
    head = rear = 0;
    maxSize = initSize;
}

template <typename elemType>
seqQueue<elemType>::~seqQueue()
{
    delete []data;
}

template <typename elemType>
void seqQueue<elemType>::enQueue(const elemType &x)
{
    if (head==(rear+1)%maxSize) doubleSpace();
    rear = (rear+1)%maxSize;
    data[rear] = x;
}

template <typename elemType>
elemType seqQueue<elemType>::deQueue()
{
    if (head == rear) throw queueIsEmpty();
    head = (head+1)%maxSize;
    return data[head];
}

template <typename elemType>
elemType seqQueue<elemType>::getHead() const
{
    if (head == rear) throw queueIsEmpty();
    return data[head+1];
}

template <typename elemType>
bool seqQueue<elemType>::isEmpty() const
{
    return head == rear;
}

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


template<typename TypeOfVer, typename TypeOfEdge>
class graph
{
protected:
    int Vers, Edges;
public:
    virtual void Insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w) = 0;
    virtual void Remove(TypeOfVer x, TypeOfVer y) = 0;
    virtual bool exist(TypeOfVer x, TypeOfVer y) const = 0;
    int getVers() const {return Vers;}
    int getEdges() const {return Edges;}
};

template<typename TypeOfVer, typename TypeOfEdge>
class adjMatrixGraph: public graph<TypeOfVer, TypeOfEdge>
{
private:
    TypeOfEdge **edge;
    TypeOfVer *ver;
    TypeOfEdge noEdge;
    int Find(TypeOfVer v) const
    {
        for (int i=0; i<this->Vers; i++)
            if (ver[i] == v) return i;
    }
public:
    adjMatrixGraph(int verSize,const TypeOfVer *verList, const TypeOfEdge noEdgeFlag)
    {
        this->Vers = verSize;
        this->Edges = 0;
        noEdge = noEdgeFlag;

        edge = new TypeOfEdge*[verSize];
        ver = new TypeOfVer[verSize];
        for (int i=0; i<verSize; i++)
        {
            ver[i] = verList[i];
            edge[i] = new TypeOfEdge[verSize];
        }

        for (int i=0; i<verSize; i++)
        {
            for (int j=0; j<verSize; j++)
            {
                edge[i][j] = noEdge;
            }
        }

    }
    ~adjMatrixGraph()
    {
        delete ver;
        for (int i=0; i<this->Vers; i++) delete edge[i];
        delete edge;
    }
    virtual void Insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w)
    {
        int indexX = Find(x); int indexY = Find(y);
        edge[indexX][indexY] = w;
        edge[indexY][indexX] = w;// undirected graph
        this->Edges++;
    }
    virtual void Remove(TypeOfVer x, TypeOfVer y)
    {
        int indexX = Find(x); int indexY = Find(y);
        edge[indexX][indexY] = noEdge;
        edge[indexY][indexX] = noEdge;// undirected graph
        this->Edges--;
    }
    virtual bool exist(TypeOfVer x, TypeOfVer y) const
    {
        int indexX = Find(x); int indexY = Find(y);
        return (edge[indexX][indexY]==noEdge);
    }
    void depthFristSearch(TypeOfVer start) const
    {
        int beg = Find(start);
        int label[this->Vers] = {0};// check if it is visited;
        seqStack<int> tmpStack;
        tmpStack.push(beg);
        label[beg] = 1;

        while(!tmpStack.isEmpty())
        {
            int tmp = tmpStack.pop();
            cout << ver[tmp] << " ";
            for (int i=0; i<this->Vers; i++)
            {
                if (edge[tmp][i]!=noEdge && label[i]!=1)
                {
                    tmpStack.push(i);
                    label[i] = 1;
                }
            }
        }
        cout << endl;
    }
    void breadthFristSearch(TypeOfVer start) const
    {
        int beg = Find(start);
        int label[this->Vers] = {0};// check if it is visited

        seqQueue<int> tmpQue;
        tmpQue.enQueue(beg);
        label[beg] = 1;
        while(!tmpQue.isEmpty())
        {
            int tmp = tmpQue.deQueue();
            cout << ver[tmp] << " ";
            for (int i=0; i<this->Vers; i++)
            {
                if (edge[tmp][i]!=noEdge && label[i]!=1)
                {
                    tmpQue.enQueue(i);
                    label[i] = 1;
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    int vers[7] = {1, 2, 3, 4, 5, 6, 7};
    adjMatrixGraph<int, int> testGraph(7, vers, -1);
    testGraph.Insert(5, 6, 1);
    testGraph.Insert(5, 7, 1);
    testGraph.Insert(7, 6, 1);
    testGraph.Insert(7, 4, 1);
    testGraph.Insert(6, 2, 1);
    testGraph.Insert(2, 4, 1);
    testGraph.Insert(2, 3, 1);
    testGraph.Insert(4, 1, 1);
    testGraph.Insert(4, 3, 1);
    testGraph.Insert(1, 2, 1);
    testGraph.Insert(3, 1, 1);
    testGraph.breadthFristSearch(5);
    testGraph.depthFristSearch(5);
    return 0;
}
