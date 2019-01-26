#include <iostream>

using namespace std;

template <typename elemType>
class priorityQueue
{
private:
    elemType *Array;
    int curSize, maxSize;

    void doubleSpace()
    {
        elemType *tmp;
        tmp = new elemType[2*maxSize];
        for (int i=0; i<=curSize; i++) tmp[i] = Array[i];
        delete []Array; maxSize*=2;
        Array = tmp;
    }
    void buildHeap()
    {
        for (int i=curSize/2; i>0; i--) percolateDown(i);
    }
    void percolateDown(int hole)
    {
        int child;
        elemType tmp = Array[hole];
        while(2*hole<=curSize)
        {
            child = 2*hole;
            if(child+1<=curSize && Array[child]>Array[child+1]) child ++;
            if (Array[child]<tmp) Array[hole] = Array[child];
            else break;
            hole = child;
        }
        Array[hole] = tmp;
    }
public:
    priorityQueue(int Size=100)
    {
        Array = new elemType[Size];
        maxSize = Size;
        curSize = 0;
    }
    priorityQueue(elemType *data, int dataSize):maxSize(dataSize+10), curSize(dataSize)
    {
        Array == new elemType[maxSize];
        for (int i=0; i<dataSize; i++) Array[i+1] = data[i];
        buildHeap();
    }
    ~priorityQueue(){delete []Array;}
    void enQueue(const elemType x)
    {
        if (curSize==maxSize) doubleSpace();
        Array[++curSize] = x;
        int i = curSize;
        while(i>1)
        {
            if (x<Array[i/2])
            {
                Array[i] = Array[i/2];
                i = i/2;
            }
            else break;
        }
        Array[i] = x;
    }
    elemType deQueue()
    {
        elemType res = Array[1];
        Array[1] = Array[curSize--];
        percolateDown(1);
        return res;
    }
};

int main()
{
    int data[5] = {4, 5, 3, 1, 2};
    priorityQueue<int> que(data, 5);
    for (int i=0; i<5; i++) cout << que.deQueue() << endl;
    return 0;
}
