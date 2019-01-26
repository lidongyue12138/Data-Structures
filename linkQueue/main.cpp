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
class linkQueue
{
private:
    struct node
    {
        elemType data;
        node *next;
        node(const elemType &x, node *N=NULL){data=x; next=N;}
        node():next(NULL){}
        ~node(){}
    };
    node *head;
    node *rear;
public:
    linkQueue();
    ~linkQueue();
    virtual void enQueue(const elemType &x);
    virtual elemType deQueue();
    virtual elemType getHead() const;
    virtual bool isEmpty() const;
};

template <typename elemType>
linkQueue<elemType>::linkQueue()
{
    head = NULL;
    rear = NULL;
}

template <typename elemType>
linkQueue<elemType>::~linkQueue()
{
    while(head!=NULL)
    {
        node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

template <typename elemType>
void linkQueue<elemType>::enQueue(const elemType &x)
{
    node *tmp = new node(x);
    if (rear == NULL) head = rear = tmp;
    else rear->next = tmp;
    rear = tmp;
}

template <typename elemType>
bool linkQueue<elemType>::isEmpty() const
{
    return head == NULL;
}

template <typename elemType>
elemType linkQueue<elemType>::deQueue()
{
    if (isEmpty()) throw queueIsEmpty();
    elemType data = head->data;
    node *tmp = head;
    head = head->next;
    delete tmp;
    return data;
}

template <typename elemType>
elemType linkQueue<elemType>::getHead() const
{
    if (isEmpty()) throw queueIsEmpty();
    return head->data;
}


int main()
{
    linkQueue<int> testQueue;
    for (int i=0; i<200; i++) testQueue.enQueue(i);
    while(!testQueue.isEmpty()) {cout << testQueue.deQueue() << " ";}
    cout << "Hello world!" << endl;
    return 0;
}
