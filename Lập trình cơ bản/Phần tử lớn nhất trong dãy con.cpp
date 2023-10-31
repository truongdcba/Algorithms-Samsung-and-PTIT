#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >>t;

    while(t--) {
        int n,k;
        cin >>n >>k;
        int arr[n];
        multiset<int> se;

        for(int &x : arr) cin >>x;
        //khoi tao cua so dau tien
        for(int i=0;i<k;i++) se.insert(arr[i]);
        cout <<*(se.rbegin()) <<" ";
        for(int i=k;i<n;i++) {
            auto it=se.find(arr[i-k]);
            se.erase(it);
            se.insert(arr[i]);
            cout <<*(se.rbegin()) <<" ";
        }
        cout <<endl;
    }
    return 0;
}