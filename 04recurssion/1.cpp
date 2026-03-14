#include <iostream>
using namespace std;

void printName(int i, int n) {
    if(i>n) return;
    while(i<=n) {
        cout << "Hello" << endl;
        i++;
    }
}

int main() {
    int i=1,n=6;
    printName(i,n);
}
