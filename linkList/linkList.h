#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include <stddef.h>
template <typename elemType>
class List{
public:
    virtual int length() const = 0;
    virtual int search(const elemType &x) const=0;
    virtual elemType visit(int i) const=0;
    virtual void insert(int i, elemType x)=0;
    virtual void remove(int i)=0;
    virtual void clear()=0;
    virtual void traverse() const=0;
    virtual ~List(){}
};

class OutofBound{};

template <typename elemType>
class linkList{
private:
    struct node{
        elemType data;
        node *next;
        node(const elemType &x, node *p = NULL){data = x; next = p;}
        node():next(NULL){}
        ~node(){}
    };
    node *head;
public:
    linkList();
    virtual ~linkList();
    virtual int length() const;
    virtual int search(const elemType &x) const;
    virtual elemType visit(int i) const;
    virtual void insert(int i, elemType x);
    virtual void remove(int i);
    virtual void clear();
    virtual void traverse() const;
};

#endif // LINKLIST_H_INCLUDED
