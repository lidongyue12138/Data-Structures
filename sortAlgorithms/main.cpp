#include <iostream>

using namespace std;

template<typename elemType>
void insertSort(elemType *elemList, int n)
{
    for(int i=0; i<n; i++)
    {
        int minIndex = i;
        for (int j=i; j<n; j++)
        {
            if (elemList[j]<elemList[minIndex]) minIndex = j;
        }
        elemType tmp = elemList[i];
        elemList[i] = elemList[minIndex];
        elemList[minIndex] = tmp;
    }
}

template<typename elemType>
void bubbleSort(elemType *elemList, int n)
{
    for (int i=n-1; i>=0; i--)
    {
        bool flag = true;
        for (int j = 0; j<=i; j++)
        {
            if (elemList[j]>elemList[j+1])
            {
                elemType tmp = elemList[j];
                elemList[j] = elemList[j+1];
                elemList[j+1] = tmp;
                flag = false;
            }
        }
        if (flag) break;
    }
}

template <typename elemType>
void shellSort(elemType *elemList, int n)
{
    for (int step=n/2; step > 0; step /=2 )
    {
        for (int i=step; i<n; i++)
        {
            elemType tmp = elemList[i];
            int j;
            for (j=i-step; j>=0&&elemList[j]>tmp; j-=step)
            {
                elemList[j+step] = elemList[j];
            }
            elemList[j+step] = tmp;
        }
    }
}

template<typename elemType>
void quickSort(elemType *elemList, int n, int startIndex, int endIndex)
{
    if (startIndex >= endIndex) return;
    elemType compare = elemList[startIndex];
    int left = startIndex+1, right = endIndex;
    int index = left;

    for (int i=left; i<=right; i++)
    {
        if (elemList[i]<compare)
        {
            elemType tmp = elemList[i];
            elemList[i] = elemList[index];
            elemList[index] = tmp;
            index ++ ;
        }
    }
    elemList[startIndex] = elemList[index-1];
    elemList[index-1] = compare;
    quickSort(elemList, n, startIndex, index-2);
    quickSort(elemList, n, index, endIndex);
}

int main()
{
    int testList[9] = {2, 3, 5, 1, 8, 4, 9, 7, 6};
    //quickSort<int>(testList, 9, 0, 8);
    shellSort<int>(testList, 9);
    for (int i=0; i<9; i++) cout << testList[i] << " ";
    cout << endl;
    return 0;
}
