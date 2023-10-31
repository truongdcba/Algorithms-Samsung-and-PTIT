#include <bits/stdc++.h>

using namespace std;
int f[100001];

bool cmp(int a,int b) {
    if(f[a]!=f[b]) {
        if(f[a]>f[b]) return true;
        return false;
    }
    return a<b;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        int arr[n];
        memset(f,0,sizeof(f));
      
        for(int i=0;i<n;i++) {
            cin >>arr[i];
            f[arr[i]]++;
        }
        sort(arr,arr+n,cmp);
        for(int i=0;i<n;i++) cout <<arr[i] <<" ";
        cout <<endl;
    }
    return 0;
}