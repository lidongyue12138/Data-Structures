#include <iostream>

using namespace std;

template<typename elemType>
class BernoulliQueue
{
private:
    struct node
    {
        elemType data;
        node* left; node* right;
        node(){left = NULL; right = NULL;}
        node(const elemType x){data=x; left=NULL; right=NULL;}
        ~node(){}
    };
    node** rootList;
    int listSize;
    int* flagList;

    void doubleSpace()
    {
        node** tmp = rootList;
        rootList = new node*[listSize*2];
        for (int i=0; i<listSize; i++) rootList[i] = tmp[i];
        delete tmp;

        int* newFlag = flagList;
        flagList = new int[listSize*2];
        for (int i=0; i<listSize; i++) flagList[i] = newFlag[i];
        for (int i=listSize; i<listSize*2; i++) flagList[i] = 0;
        delete newFlag;
        listSize*=2;
    }
    node* copyTree(node* treeRoot)
    {
        node* tmpRoot;
        //copy the whole tree
        return treeRoot;
    }
    node* mergeTree(node* tree1, node* tree2)
    {
        node *tmp = tree1;
        if (!tmp->left) {tmp->left = tree2; return tree1;}
        tmp = tmp->left;
        while(tmp->right) tmp = tmp->right;
        tmp->right = tree2;
        return tree1;
    }
    void destroyTree(node* root)
    {
        //delete the whole tree
    }
public:
    BernoulliQueue(int size=10)
    {
        listSize = size;
        rootList = new node*[listSize];
        flagList = new int[listSize];
        for (int i=0; i<listSize; i++) flagList[i] = 0;
    }
    ~BernoulliQueue(){}
    void mergeFromTree(node *treeRoot, int i)
    {
        if (flagList[i]==0) {rootList[i] = copyTree(treeRoot); flagList[i] = 1;}
        else
        {
                if (rootList[i]->data < treeRoot->data) rootList[i] = mergeTree(rootList[i], treeRoot);
                else rootList[i] = mergeTree(treeRoot, rootList[i]);
                int tmp = i;
                while(true)
                {
                    if (tmp+2>listSize) {doubleSpace(); continue;}
                    if (flagList[tmp+1]==0)
                    {
                        rootList[tmp+1] = copyTree(rootList[tmp]);
                        destroyTree(rootList[tmp]);
                        flagList[tmp] = 0;
                        flagList[tmp+1] = 1;
                        break;
                    }
                    else
                    {
                        if (rootList[tmp]->data<rootList[tmp+1]->data)
                            rootList[tmp+1] = mergeTree(rootList[tmp], rootList[tmp+1]);
                        else
                            rootList[tmp+1] = mergeTree(rootList[tmp+1], rootList[tmp]);
                        destroyTree(rootList[tmp]);
                        flagList[tmp] = 0;
                        tmp ++;
                    }
                }
            }
    }
    void mergeBerQueue(const BernoulliQueue<elemType>* que)
    {
        for(int i=0; i<que.listSize; i++)
        {
            if (que.flagList[i]==0) continue;
            mergeFromTree(que.rootList[i], i);
        }
    }
    elemType deQueue()
    {
        int minIndex = -1;
        elemType minData;
        for (int i=0; i<listSize; i++)
        {
            if (!flagList[i]) continue;
            minData = rootList[i]->data;
            minIndex = i;
            break;
        }
        for (int i=minIndex+1; i<listSize; i++)
        {
            if (!flagList[i]) continue;
            if (rootList[i]->data<minData)
            {
                minIndex = i;
                minData = rootList[i]->data;
            }
        }
        flagList[minIndex] = 0;
        // delete and merge

        node** mergeList = new node*[minIndex];
        node* target = rootList[minIndex]->left;
        node* tmp = target;
        for (int i=0; i<minIndex; i++)
        {
            mergeList[i] = target;
            target = target->right;
            tmp->right = NULL;
            tmp = target;
        }
        for (int i=0; i<minIndex; i++) mergeFromTree(mergeList[i], i);
        return minData;
    }
    void enQueue(const elemType x)
    {
        node* tmp = new node(x);
        mergeFromTree(tmp, 0);
    }
    elemType getHead()
    {
        int minIndex = -1;
        elemType minData;
        for (int i=0; i<listSize; i++)
        {
            if (!flagList[i]) continue;
            minData = rootList[i]->data;
            minIndex = i;
            break;
        }
        for (int i=minIndex+1; i<listSize; i++)
        {
            if (!flagList[i]) continue;
            if (rootList[i]->data<minData)
            {
                minIndex = i;
                minData = rootList[i]->data;
            }
        }
        return minData;
    }
};

int main()
{
    BernoulliQueue<int> que;
    for (int i=5; i>0; i--) que.enQueue(i);
    cout << que.getHead() << endl;
    for (int i=0; i<5; i++) cout << que.deQueue() << endl;
    return 0;
}
