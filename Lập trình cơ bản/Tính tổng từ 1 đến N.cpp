#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        ll res=1ll*n*(n+1)/2;
        cout <<res <<endl;
    }
    return 0;
}