#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        int arr[n];
        vector<vector<int>> v;

        for(int &x : arr) cin >>x;
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                if(arr[j]<arr[i]) swap(arr[i],arr[j]);
            }
            vector<int> tmp;
            for(int k=0;k<n;k++) {
                tmp.push_back(arr[k]);
            }
            v.push_back(tmp);
        }
        for(int i=v.size()-1;i>=0;i--) {
            cout <<"Buoc " <<i+1 <<": ";
            for(auto it : v[i]) cout <<it <<" ";
            cout <<endl;
        }
    }
    return 0;
}