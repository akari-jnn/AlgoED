#include <iostream>
using namespace std;

int main() {
    int numAmigs;
    int amigos[367]{},amigas[367]{};
    cin>>numAmigs;
    int genero,a,b;
    for(int i=0;i<numAmigs;i++) {
        cin>>genero>>a>>b;
        if (1<=a and a<=b and b<=366) {
            if (genero==1) {
                //Amigas
                amigas[a]++;
                amigas[b+1]--;
            }else if (genero==2) {
                //Amigos
                amigos[a]++;
                amigos[b+1]--;
            }else {
                break;
            }
        }else {
            break;
        }
    }

    int mayorNumAmigs=-1;
    for(int i=1;i<367;i++) {
        amigas[i]=amigas[i]+amigas[i-1];
        amigos[i]=amigos[i]+amigos[i-1];
        if (amigas[i]==amigos[i] and (amigas[i]*2)>=mayorNumAmigs) {
            mayorNumAmigs=amigas[i]*2;
        }
    }

    cout<<mayorNumAmigs<<endl;

    return 0;
}
