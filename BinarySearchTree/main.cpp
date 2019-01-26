#include <iostream>

using namespace std;

template <typename elemType>
class binarySearchTree
{
public:
    struct node
    {
        elemType data;
        node* left, right;
        node():left(NULL), right(NULL){}
        node(const elemType x):data(x), left(NULL), right(NULL){}
        ~node(){}
    };
    node* root;
public:
    binarySearchTree()
    {
        root = NULL;
    }
    ~binarySearchTree(){}
    node* search(const elemType x) const
    {
        node* tmp = root;
        while(tmp)
        {
            if (tmp->data==x) return tmp;
            if (tmp->data < x) tmp = tmp->right;
            else tmp = tmp->left;
        }
        return NULL;
    }
    void Insert(const elemType x)// insert(node*& r, const elemType x) can be transformed to recursive form
    {
        if (!root) { root = new node(x); return;}
        node* pre = root, tmp = root;
        while(tmp)
        {
            if (tmp->data == x) return;
            if (tmp->data < x)
            {
                pre = tmp;
                tmp = tmp->right;
            }
            else
            {
                pre = tmp;
                tmp = tmp->left;
            }
        }
        tmp = new node(x);
        if (pre->data < x) pre->right = tmp;
        else pre->left = tmp;
        // Insert(x, root);
    }
    void Insert(const elemType x, node* &r)
    {
        if (!r) r = new node(x);
        if (r->data > x) Insert(x, r->left);
        else if (r->data < x) Insert(x, r->right);
        else return;
    }
    void Delete(const elemType x)
    {
        // delete a leaf node --> directly delete
        // delete a node with one child --> move child up
        // delete a node with two child --> use the max node in the left to replace
        //                              --> recursively delete the node
        Delete(x, root);
    }
    void Delete(const elemType x, node* &t)
    {
        if (!t) return;
        if (x < t->data) Delete(x, t->left);
        else if (x > t->data) Delete(x, t->right);
        else if (t->left && t->right) {
            node* tmp = t->right;
            while(tmp->left!=NULL) tmp = tmp->left;
            t->data = tmp->data;
            Delete(t->data, tmp);// whether it is tmp or t->right
        }
        else{
            node* tmp = t;
            t = (t->left!=NULL)? t->left: t->right;
            delete tmp;
        }
    }
};


int main()
{
    cout << "Hello world!" << endl;
    int i = 1;
    int *x = &i;
    return 0;
}
