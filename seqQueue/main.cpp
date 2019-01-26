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

int main()
{
    seqQueue<int> testQueue;
    for (int i=0; i<200; i++) testQueue.enQueue(i);
    while(!testQueue.isEmpty()) {cout << testQueue.deQueue() << " ";}
    cout << "Hello world!" << endl;
    return 0;
}
