#include <bits/stdc++.h>

using namespace std;
int n,arr[20],x[20];
bool visited[10001];

void Try(int i) {
    for(int j=1;j<=n;j++) {
        if(!visited[arr[j]]) {
            x[i]=arr[j];
            visited[arr[j]]=true;
            if(i==n) {
                for(int j=1;j<=n;j++) cout <<x[j] <<" ";
                cout <<endl;
            }
            else Try(i+1);
            visited[arr[j]]=false;
        }
    }
}
int main() {
    cin >>n;
    for(int i=1;i<=n;i++) cin >>arr[i];
    sort(arr+1,arr+n+1);
    Try(1);
    return 0;
}