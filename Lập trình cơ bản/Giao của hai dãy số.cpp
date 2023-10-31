#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    cin >>n >>m;
    set<int> s1,s2;

    for(int i=0;i<n;i++) {
        int x;
        cin >>x;
        s1.insert(x);
    }
    for(int j=0;j<m;j++) {
        int x;
        cin >>x;
        s2.insert(x);
    }
    for(int it : s1) {
        if(s2.find(it)!=s2.end()) cout <<it <<" ";
    }
    return 0;
}