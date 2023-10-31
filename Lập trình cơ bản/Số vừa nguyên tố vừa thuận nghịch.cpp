#include <iostream>
#include <cmath>

using namespace std;
int nt[1000001];

void sang() {
    for(int i=0;i<=1000000;i++) {
        nt[i]=1;
    }
    nt[0]=nt[1]=0;
    for(int i=2;i<=sqrt(1000000);i++) {
        if(nt[i]) {
            for(int j=i*i;j<=1000000;j+=i) nt[j]=0;
        }
    }
}
bool checkTn(int n) {
    int res=0,tmp=n;
    while(n) {
        res=res*10+n%10;
        n/=10;
    }
    return res==tmp;
}
int main() {
    int t;
    cin >>t;
    sang();

    while(t--) {
        int a,b;
        cin >>a >>b;
        int dem=0;
        for(int i=a;i<=b;i++) {
            if(checkTn(i) && nt[i]) {
                dem++;
                cout <<i <<" ";
                if(dem==10) {
                    cout <<endl;
                    dem=0;
                }
            }
        }
        cout <<endl;
    }
    return 0;
}