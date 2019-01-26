#include <iostream>

using namespace std;

template <typename edgeType>
class graph
{
public:
    virtual bool Insert(int u, int v, edgeType w) = 0;
    virtual bool Remove(int u, int v) = 0;
    virtual bool exist(int u, int v) = 0;
    virtual int getVerNumber() const {return Vers;}
    virtual int getEdgeNumber() const {return Edges;}
protected:
    int Vers; int Edges;
};

template <typename verType, typename edgeType>
class adjListGraph:public graph<edgeType>
{
private:
    struct edgeNode
    {
        int end;
        edgeType weight;
        edgeNode *next;
        edgeNode(int e, edgeType w, edgeNode* t=NULL)
        {
            end = e;
            weight = w;
            t = next;
        }
    };
    struct verNode
    {
        verType ver;
        edgeNode *head;
        verNode(edgeNode *h=NULL){head = h;}
    };
    verNode* verList;
public:
    adjListGraph(int vSize, const verType d[])
    {
        this.Vers = vSize;
        this.Edges = 0;

        verList = new verNode[vSize];
        for (int i=0; i<vSize; i++) verList[i].ver = d[i];
    }
    int Find(verType x)
    {
        for (int i=0; i<this.Vers; i++)
        {
            if (verList[i].ver == x) return i;
        }
        return -1;
    }
    bool Insert(int u, int v, edgeType w)
    {
        if (u==-1 || v == -1) return false;
        verList[u].head = new edgeNode(v, w, verList[u].head);
        // ����ͼ
        verList[v].head = new edgeNode(u, w, verList[v].head);
        this.Edges ++ ;
        return true;
    }
    bool Remove(int u, int v)
    {
        if (u == -1 || v == -1) return false;
        edgeNode *p = verList[v].head;
        edgeNode *q = verList[v].head;
        if (!p) return false;
        if (p->end == u)
        {
            verList[v].head = p->next;
            delete p;
        }
        else
        {
            while(p!=NULL && p->end == u)
            {
                q = p; p = p->next;
            }
            if (p==NULL) return false;
            else
            {
                q->next = p->next;
                delete p;
            }
        }

        // ����ͼ
        p = verList[u].head;
        q = verList[u].head;
        if (!p) return false;
        if (p->end == u)
        {
            verList[v].head = p->next;
            delete p;
        }
        else
        {
            while(p!=NULL && p->end == v)
            {
                q = p; p = p->next;
            }
            if (p==NULL) return false;
            else
            {
                q->next = p->next;
                delete p;
            }
        }

        this.Edges --;
        return true;
    }
    bool exist(int u, int v)
    {
        edgeNode *p = verList[u].head;
        while (p!=NULL && p->end!=v) p = p->next;
        if (p!=NULL) return true;
        return false;
    }
    // ɾ������
    // ��������: BFS DFS

    void findEulerCircuit()
    {
    // ŷ����·
        //�ж�����ŷ����·
        for(int i=0; i<Vers; i++)
        {
            edgeNode *node = verList[i].head;
        }

        //��Ҫ��edge�ϼ�¼�Ƿ���ʹ�

        //��������߲�ͨ������һ������չ����
    }

    // ��������
    void topSort()
    {

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
