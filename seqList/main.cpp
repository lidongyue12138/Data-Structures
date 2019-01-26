#include <iostream>
#include <string>

using namespace std;

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

class OutOfBound{};
class IllegalSize{};
template <typename elemType>
class seqList: public List<elemType>
{
private:
    elemType *data;
    long curLength;
    long maxLength;
    void doubleSpace();
public:
    seqList(int initSize=1000);
    ~seqList(){delete [] data;}
    virtual int length() const;
    virtual int search(const elemType &x) const;
    virtual elemType visit(int i) const;
    virtual void insert(int i, elemType x);
    virtual void remove(int i);
    virtual void clear();
    virtual void traverse() const;
    // reload plus
    // in the class
    seqList<elemType> operator+(const seqList<elemType> &obj) const
    {
        seqList<elemType> temp;
        for (int i=0; i<length(); i++) temp.insert(temp.length(),visit(i));
        for (int i=0; i<obj.length(); i++) temp.insert(temp.length(),obj.visit(i));
        return temp;
    }
    void operator=(const seqList<elemType> &obj){
        if(&obj==this) return
        clear();
        for (int i=0; i<obj.length(); i++) insert(i, obj.visit(i));
    }
};
using namespace std;

template <typename elemType>
void seqList<elemType>::doubleSpace(){
    maxLength *= 2;
    elemType *tmp = new elemType[maxLength];
    for (int i=0; i<curLength; i++){
        tmp[i] = data[i];
    }
    delete []data;
    data = tmp;
}

template <typename elemType>
seqList<elemType>::seqList(int initSize){
    maxLength = initSize;
    curLength = 0;
    data = new elemType[maxLength];
    if (!data) throw IllegalSize();
}

template <typename elemType>
int seqList<elemType>::length() const{
    return curLength;
}

template <typename elemType>
int seqList<elemType>::search(const elemType &x) const{
    for (int i=0; i<curLength; i++){
        if (data[i] == x) return i;
    }
    return -1;
}

template <typename elemType>
elemType seqList<elemType>::visit(int i) const{
    if (i<0 || i>=curLength) throw OutOfBound();
    return data[i];
}

template <typename elemType>
void seqList<elemType>::insert(int i, elemType x){
    if (i<0 || i>curLength) throw OutOfBound();
    if (curLength == maxLength) doubleSpace();
    for (int j=curLength; j>i; j--){
        data[j] = data[j-1];
    }
    data[i] = x; curLength++;
}

template <typename elemType>
void seqList<elemType>::remove(int i){
    if (i<0 || i>=curLength) throw OutOfBound();
    for(int j=i; j<curLength-1; j++){
        data[j] = data[j+1];
    }
    curLength--;
}

template <typename elemType>
void seqList<elemType>::clear(){
    curLength = 0;
}

template <typename elemType>
void seqList<elemType>::traverse() const{
    if (curLength<1) {cout << endl;return;}
    for (int i=0; i<curLength-1; i++) cout << data[i] << " " ;
    cout << data[curLength-1] << endl;
}

int main()
{
    seqList<int> testList;
    int x = 1;
    for (int i=0; i<20; i++) testList.insert(0,i);
    testList.remove(0);
    cout << testList.length() << endl;
    testList.traverse();
    cout << "Hello world!" << endl;
    return 0;
}
