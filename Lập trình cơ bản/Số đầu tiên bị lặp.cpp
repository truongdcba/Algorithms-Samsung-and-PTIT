#include <iostream>
#include <map>

using namespace std;

int main() {
    int t;
    cin >>t;

    while(t--) {
        int n,ok=0;
        cin >>n;
        int arr[n];
        map<int,int> mp;

        for(int i=0;i<n;i++) {
            cin >>arr[i];
            mp[arr[i]]++;
        }
        for(int it : arr) {
            if(mp[it]!=1) {
                cout <<it <<endl;
                ok=1;
                break;
            }
        }
        if(ok==0) cout <<"NO" <<endl;
    }
    return 0;
}