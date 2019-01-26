#include <iostream>

using namespace std;

class DisjointSet
{
private:
    int Size;
    int *parent;
public:
    DisjointSet(int s)
    {
        Size = s;
        parent = new int[s];
        for (int i=0; i<s; i++) parent[i] = -1;
    }
    ~DisjointSet()
    {
        delete []parent;
    }
    void Union(int root1, int root2)
    {
        if (root1 == root2) return;
        if (parent[root1] > parent[root2])
        {
            parent[root2] += parent[root1];
            parent[root1] = root2;
        }
        else
        {
            parent[root1] += parent[root2];
            parent[root2] = root1;
        }
    }
    int Find(int x)
    {
        int *recordPath = new int[Size];

        int tmp = x;
        int index = 0;
        while(tmp>=0)
        {
            recordPath[index++] = tmp;
            tmp = parent[tmp];
        }

        index --;

        for (int i=0; i<index; i++)
        {
            parent[recordPath[i]] = recordPath[index];
        }

        int res = recordPath[index];
        delete recordPath;
        return res;
    }
};

int main()
{
    DisjointSet s(6);
    s.Union(s.Find(0), s.Find(1));
    s.Union(s.Find(0), s.Find(2));
    s.Union(s.Find(0), s.Find(3));
    s.Union(s.Find(4), s.Find(5));
    cout << s.Find(4) << endl;
    cout << s.Find(3) << endl;
}
