#include <iostream>
#include "linkList.h"

using namespace std;
template <typename elemType>
linkList<elemType>::linkList()
{
    head = new node;
}

template <typename elemType>
linkList<elemType>::~linkList()
{
    clear();
    delete head;
}

template <typename elemType>
int linkList<elemType>::length() const
{
    int count=0;
    node *p = head->next;
    while(p!=NULL) {p = p->next; count++;}
    return count;
}

template <typename elemType>
int linkList<elemType>::search(const elemType &x) const
{
    int count=0;
    node *p = head->next;
    while(p!=NULL)
    {
        if (p->data==x) {return count;}
        p = p->next;
        count++;
    }
    return -1;
}

template <typename elemType>
elemType linkList<elemType>::visit(int i) const
{
    if (i<0) throw OutofBound();
    int count=0;
    node *p = p->next;
    while(p!=NULL && count!=i)
    {
        p = p->next;
        count++;
    }
    if (!p) throw OutofBound();
    return p->data;
}

template <typename elemType>
void linkList<elemType>::insert(int i, elemType x)
{
    if (i<0) throw OutofBound();
    node *p = head;
    for (int j=0; j<i&&p!=NULL; j++) p = p->next;
    if (!p) throw OutofBound();
    node *tmp = new node(x);
    tmp->next = p->next;
    p->next = tmp;
}

template <typename elemType>
void linkList<elemType>::remove(int i)
{
    if (i<0) throw OutofBound();
    node *p=head;
    for (int j=0; j<i&&p!=NULL; j++) p = p->next;
    if (!p || !p->next) throw OutofBound();
    node *tmp = p->next;
    p->next = p->next->next;
    delete tmp;
}

template <typename elemType>
void linkList<elemType>::clear()
{
    node *p = head;
    while(!p->next){
        node *tmp = p->next;
        p->next = p->next->next;
        delete tmp;
    }
}

template <typename elemType>
void linkList<elemType>::traverse() const
{
    node *p = head->next;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
