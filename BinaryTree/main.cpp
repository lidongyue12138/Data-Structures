#include <iostream>
using namespace std;


template <typename elemType>
class Queue
{
public:
    virtual bool isEmpty() const =0;
    virtual void enQueue(const elemType &x) = 0;
    virtual elemType deQueue()=0;
    virtual elemType& getHead() const =0;
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
    virtual elemType& getHead() const;
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
elemType& seqQueue<elemType>::getHead() const
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
class BinaryTree
{
private:
    struct node
    {
        elemType data;
        node* left;
        node* right;
        node():left(NULL),right(NULL){}
        node(elemType d, node* l = NULL, node *r = NULL):data(d),left(l),right(r){}
        ~node(){}
    };
    node *root;
public:
    BinaryTree():root(NULL){}
    BinaryTree(const elemType& val)
    {
        root = new node(val);
    }
    BinaryTree(node *p){root = p;}
    ~BinaryTree(){clear();}

    elemType getRoot() const {return root->data;}
    elemType getLeft() const {return root->left->data;} // check the left
    elemType getRight() const {return root->right->data;} // check the right
    void makeTree(const elemType &x, BinaryTree<elemType> &lt, BinaryTree<elemType> &rt)
    {
        root = new node(x, lt.root, rt.root);
        lt.root = NULL; rt.root = NULL;
    }
    void defLeft()
    {
        BinaryTree<elemType> tmp = root->left;
        root->left = NULL;
    }
    void delRight()
    {
        BinaryTree<elemType> tmp = root->right;
        root->right = NULL;
    }
    bool isEmpty(){return root == NULL;}
    void clear()
    {
        if (!root) return;
        clear(root);
        root = NULL;
    }

    int height() const {return height(root);}
    int size() const {return size(root);}
    void preOrder() const {preOrder(root); cout << endl;}
    void inOrder() const {inOrder(root); cout << endl;}
    void postOrder() const {postOrder(root); cout << endl;}

    void createTree(elemType flag)
    {
        seqQueue<node*> inputQueue;
        node *tmp;
        elemType x, ldata, rdata;
        cin >> x;
        root = new node(x);

        inputQueue.enQueue(root);
        while(!inputQueue.isEmpty())
        {
            tmp = inputQueue.deQueue();
            cin >> ldata >> rdata;
            if (ldata!=flag){inputQueue.enQueue(tmp->left = new node(ldata));}
            if (rdata!=flag){inputQueue.enQueue(tmp->right = new node(rdata));}
        }
    }
private:
    void clear(node *t)
    {
        if (!t) return;
        clear(t->left);
        clear(t->right);
        delete t;
    }
    int height(node *t) const
    {
        if (!t) return 0;
        return max(height(t->left),height(t->right))+1;
    }
    int size(node *t) const
    {
        if (!t) return 0;
        return size(t->left)+size(t->right)+1;
    }
    void preOrder(node *t) const
    {
        if (!t) return;
        cout << t->data << " ";
        preOrder(t->left);
        preOrder(t->right);
    }
    void inOrder(node *t) const
    {
        if (!t) return;
        inOrder(t->left);
        cout << t->data << " ";
        inOrder(t->right);
    }
    void postOrder(node *t) const
    {
        if (!t) return;
        postOrder(t->left);
        postOrder(t->right);
        cout << t->data << " ";
    }
};

int main()
{
    BinaryTree<int> testTree;
    testTree.createTree(-1);
    cout << testTree.isEmpty() << endl;
    testTree.preOrder();
    testTree.inOrder();
    testTree.postOrder();
    return 0;
}
