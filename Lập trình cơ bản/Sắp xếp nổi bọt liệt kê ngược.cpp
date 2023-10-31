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

        for(int i=0;i<n;i++) cin >>arr[i];
        for(int i=0;i<n;i++) {
            bool check=false;
            for(int j=0;j<n-i-1;j++) {
                if(arr[j]>arr[j+1]) {
                    check=true;
                    swap(arr[j],arr[j+1]);
                }
            }
            if(check==false) break;
            vector<int> tmp;
            for(int k=0;k<n;k++) tmp.push_back(arr[k]);
            v.push_back(tmp);
        }
        for(int i=v.size()-1;i>=0;i--) {
            cout <<"Buoc " <<i+1 <<": ";
            for(auto it : v[i]) cout <<it <<" ";
            cout <<endl;
        }
    }
}