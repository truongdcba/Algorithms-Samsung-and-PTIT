#include <bits/stdc++.h>

using namespace std;
int f[1000001];
set<int> s;

void sang() {
    for(int i=0;i<=1000000;i++) f[i]=1;
    f[0]=f[1]=0;
    for(int i=2;i<=sqrt(1000000);i++) {
        if(f[i]) {
            for(int j=i*i;j<=1000000;j+=i) f[j]=0;
        }
    }
    for(int i=2;i<=1000000;i++) {
        if(f[i]) s.insert(i);
    }
}
int main() {
    int t;
    cin >>t;
    sang();

    while(t--) {
        int n;
        cin >>n;
        int ok=0;

        for(auto it : s) {
            if(it<n && s.find(n-it)!=s.end()) {
                ok=1;
                cout <<it <<" " <<n-it <<endl;
                break;
            }
            else if(it>=n) break;
        }
        if(ok==0) cout <<-1 <<endl;
    }
    return 0;
}