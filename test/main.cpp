#include <iostream>

using namespace std;

int main()
{
    int *i;
    cout << i << endl;
    i = new int(10);
    cout << i << endl;
    i = new int[20];
    cout << i << endl;
    cout << "Hello world!" << endl;
    return 0;
}
