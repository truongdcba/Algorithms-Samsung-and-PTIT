#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >>n;
    int arr[n];
    vector<vector<int>> v;

    for(int i=0;i<n;i++) cin >>arr[i];
    for(int i=0;i<n;i++) {
        for(int j=i-1;j>=0;j--) {
            if(arr[j+1]<arr[j]) {
                swap(arr[j+1],arr[j]);
            }
            else break;
        }
        vector<int> tmp;
        for(int j=0;j<=i;j++) tmp.push_back(arr[j]);
        v.push_back(tmp);
    }
    for(int i=v.size()-1;i>=0;i--) {
        cout <<"Buoc " <<i <<": ";
        for(auto it : v[i]) cout <<it <<" ";
        cout <<endl;
    }
}