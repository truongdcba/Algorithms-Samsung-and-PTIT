#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll find(ll n) {
    for(int i=2;i<=sqrt(n);i++) {
        while(n%i==0) {
            n/=i;
        }
        if(n==1) return i;
    }
    if(n!=1) return n;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        ll n;
        cin >>n;
        cout <<find(n) <<endl;
    }
    return 0;
}