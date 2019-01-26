#include <iostream>
#include <string>
using namespace std;

class hfTree
{
private:
    struct node
    {
        char data;
        double weight;
        int left, right, parent;
        node()
        {
            data = '/';
            left = right = parent = 0;
        }
    };
    node* elem;
    int length;

public:
    hfTree(char* x, double *w, int size)
    {
        const int MAX_INT = 32767;
        double minW1 =MAX_INT, minW2 = MAX_INT;
        int minIn1, minIn2;

        length = 2*size;
        elem = new node[length];
        for (int i=size; i<length; i++)
        {
            elem[i].weight = w[i-size];
            elem[i].data = x[i-size];
            elem[i].left = elem[i].right = elem[i].parent = 0;
        }

        for (int i = size-1; i>0; i--)
        {
            minW1 = minW2 = MAX_INT;
            minIn1 = minIn2 = 0;
            for (int j=i+1; j<length; j++)
            {
                if (elem[j].parent==0)
                {
                    if (elem[j].weight<minW1)
                    {
                        minW2 = minW1;
                        minW1 = elem[j].weight;
                        minIn2 = minIn1;
                        minIn1 = j;
                    }
                    else if (elem[j].weight<minW2)
                    {
                        minW2 = elem[j].weight;
                        minIn2 = j;
                    }
                }
            }
                elem[i].weight = minW1 + minW2;
                elem[i].left = minIn1;
                elem[i].right = minIn2;
                elem[i].parent = 0;
                elem[minIn1].parent = i; elem[minIn2].parent = i;
        }
    }
    void getCode(char x)
    {
        string resCode;
        int cur = length/2, p;
        while(elem[cur].data!=x) cur++;
        p = elem[cur].parent;
        while(p)
        {
            if (elem[p].left==cur) resCode = "0"+resCode;
            else resCode = "1" + resCode;
            cur = p;
            p = elem[cur].parent;
        }
        cout << resCode << endl;;
    }
    ~hfTree(){delete []elem;}
};

int main()
{
    char ch[7] = {'a', 'e', 'i', 'd', 's', 't', 'd'};
    double w[7] = {10, 15, 12, 3, 4, 13, 1};
    hfTree myTree(ch, w, 7);
    for (int i=0; i<7; i++)
    {
        myTree.getCode(ch[i]);
    }
    return 0;
}
