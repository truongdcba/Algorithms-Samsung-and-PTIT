#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >>n;
    long long res=0,tmp=1;

    for(int i=1;i<=n;i++) {
        tmp*=i;
        res+=tmp;
    }
    cout <<res;
    return 0;
}