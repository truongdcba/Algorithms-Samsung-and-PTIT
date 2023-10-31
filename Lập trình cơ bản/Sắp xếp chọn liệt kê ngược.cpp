#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >>n;
    int arr[n];
    vector<vector<int>> v;

    for(int &x : arr) cin >>x;
    for(int i=0;i<n-1;i++) {
        int index=i;
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[index]) index=j;
        }
        if(index!=i) swap(arr[i],arr[index]);
        vector<int> tmp;
        for(int j=0;j<n;j++) tmp.push_back(arr[j]);
        v.push_back(tmp);
    }
    for(int i=v.size()-1;i>=0;i--) {
        cout <<"Buoc " <<i+1 <<": ";
        for(auto it : v[i]) cout <<it <<" ";
        cout <<endl;
    }
    return 0;
}