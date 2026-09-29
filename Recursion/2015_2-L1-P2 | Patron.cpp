#include <iostream>
using namespace std;

bool esPotenciaDeDos(int num) {
    if (num==0) return false;
    while (num%2==0) {
        num=num/2;
    }
    if (num==1) return true;
    return false;
}

void patron(int n,int i) {
    if (n<=0 or not esPotenciaDeDos(n)) return;

    patron(n/2,i);
    for(int j=0;j<i;j++) {
        cout<<"  ";
    }
    for(int j=0;j<n;j++) {
        cout<<"* ";
    }
    cout<<endl;
    patron(n/2,i+n/2);
}

int main() {
    patron(8,0);
    return 0;
}
