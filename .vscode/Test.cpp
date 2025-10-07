#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int *ptr = &a;

    cout << "Address of a = " << ptr << endl;
    return 0;
}