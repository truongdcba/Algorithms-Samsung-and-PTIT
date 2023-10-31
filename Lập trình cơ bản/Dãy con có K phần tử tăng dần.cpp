#include <bits/stdc++.h>

using namespace std;
int x[20];
vector<vector<int>> v;
vector<int> tmp;

void Try(int i,int n,int k,int arr[]) {
    for(int j=1;j<=n;j++) {
        if(arr[j]>x[i-1]) {
            x[i]=arr[j];
            tmp.push_back(x[i]);
            if(i==k) {
                v.push_back(tmp);
            }
            else Try(i+1,n,k,arr);
            tmp.pop_back();
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(x,0,sizeof(x));
        v.clear();

        int n,k;
        cin >>n >>k;
        int arr[n+1];

        for(int i=1;i<=n;i++) cin >>arr[i];
        Try(1,n,k,arr);
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++) {
            for(auto it : v[i]) cout <<it <<" ";
            cout <<endl;
        }
    }
    return 0;
}