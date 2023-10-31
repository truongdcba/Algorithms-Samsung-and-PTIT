#include <bits/stdc++.h>

using namespace std;

bool nt(int n) {
    for(int i=2;i<=sqrt(n);i++) {
        if(n%i==0) return false;
    }
    return n>1;
}
bool chuSoNtVaTongNt(int n) {
    int sum=0;
    while(n) {
        int tmp=n%10;
        if(!nt(tmp)) return false;
        sum+=tmp;
        n/=10;
    }
    return nt(sum);
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int a,b;
        cin >>a >>b;
        int dem=0;

        for(int i=a;i<=b;i++) {
            if(chuSoNtVaTongNt(i) && nt(i)) dem++;
        }
        cout <<dem <<endl;
    }
    return 0;
}