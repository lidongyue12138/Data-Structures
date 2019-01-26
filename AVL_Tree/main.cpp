#include <iostream>

using namespace std;

template <typename elemType>
class AVL_Tree
{
private:
    struct node
    {
        elemType data;
        node* left;
        node* right;
        int height;
        node(const elemType x): data(x){left = NULL; right = NULL; height = 0;}
        node(): left(NULL), right(NULL), height(0){}
        ~node(){}
    };
    int height(node* t)
    {
        if (t!=NULL) return t->height;
        return 0;
    }
    node* root;
public:
    AVL_Tree(){root = NULL;}
    ~AVL_Tree(){}
    int height(){return height(root);}
    bool Find(const elemType x) const
    {
        node* tmp = root;
        while(tmp)
        {
            if (tmp->data==x) return true;
            if (tmp->data<x) tmp = tmp->right;
            else tmp = tmp->left;
        }
        return false;
    }
    void Insert(const elemType x)
    {
        //LL or RR
        //balance turn to 0
        //LR or RL
        Insert(x, root);
    }
    void Delete(const elemType x)
    {
        Delete(x, root);
    }
    void Insert(const elemType x, node* &t)
    {
        if (t == NULL) t = new node(x);
        else if (t->data > x)
        {
            Insert(x, t->left);
            if (height(t->left) - height(t->right) == 2)
            {
                if (x < t->left->data) LL(t);
                else LR(t);
            }
        }
        else if (t->data < x)
        {
            Insert(x, t->right);
            if (height(t->right) - height(t->left) == 2)
            {
                if (x < t->right->data) RL(t);
                else RR(t);
            }
        }

        t->height = max(height(t->left), height(t->right)) + 1;
    }
    void Delete(const elemType x, node* &t)
    {
        int deleteTree = 0;

        if (t == NULL) return;
        else if (x < t->data) {Delete(x, t->left); deleteTree = 1;}
        else if (x > t->data) {Delete(x, t->right); deleteTree = 2;}
        else
        {
            if (t->left != NULL && t->right != NULL)
            {
                node *tmp = t->right;
                while (tmp ->left) tmp = tmp->left;
                t->data = tmp->data;
                Delete(tmp->data, t->right);
                deleteTree = 2;
            }
            else
            {
                node *tmp = t;
                t = (t->left!=NULL)? t->left:t->right;
                delete tmp;
                return;
            }
        }

        int bf;
        switch(deleteTree)
        {
        case 1:
            bf = height(t->left) + 1 - height(t->right);
            if (bf==0) return;
            if (bf==+1) return;
            if (bf==-1)
            {
                int bfr = height(t->right->left) - height(t->right->right);
                switch (bfr)
                {
                case 0: RR(t); return;
                case -1: RR(t); return;
                case 1: RL(t); return;
                }
            }
            break;
        case 2:
            bf = height(t->left) - height(t->right)-1;
            if (bf==0) return;
            if (bf==-1) return;
            if (bf==+1)
            {
                int bfl = height(t->left->left) - height(t->left->right);
                switch (bfl)
                {
                case 0: LL(t); return;
                case 1: LL(t); return;
                case -1: LR(t); return;
                }
            }
            break;
        }
    }
    void LL(node*& t)
    {
        node* tmp = t->left;
        t->left = t->left->right;
        tmp->right = t;
        t->height = max(height(t->left), height(t->right))+1;
        tmp->height = max(height(tmp->left), height(t)) + 1;
        t = tmp;
    }
    void LR(node* &r)
    {
        RR(r->left);
        LL(r);
    }
    void RL(node* &r)
    {
        LL(r->right);
        RR(r);
    }
    void RR(node* &t)
    {
        node* tmp = t->right;
        t->right = t->right->left;
        tmp->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        tmp->height = max(height(tmp->right), height(t))+1;
        t = tmp;
    }
};

int main()
{
    AVL_Tree<int> testTree;
    for (int i=0; i<10; i++) testTree.Insert(i);
    int op;
    cout << testTree.height() << endl;
    cin >> op;
    while (op!=0)
    {
        cout << testTree.Find(op) << endl;
        testTree.Delete(op);
        cin >> op;
    }
}
