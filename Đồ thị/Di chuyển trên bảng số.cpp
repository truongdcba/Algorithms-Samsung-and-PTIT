// Cho một bảng số kích thước N x M. Chi phí khi đi qua ô (i,j) bằng A[i][j]. 
// Nhiệm vụ của bạn là hãy tìm một đường đi từ ô (1, 1) tới ô (N, M) sao cho chi phí là nhỏ nhất. 
// Tại mỗi ô, bạn được phép đi sang trái, sang phải, đi lên trên và xuống dưới.

// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test bắt đầu bởi hai số nguyên N và M (1 ≤ N, M ≤ 500).
// N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j] (0 ≤ A[i][j] ≤ 9).
// Output: 
// Với mỗi test, in ra một số nguyên là chi phí nhỏ nhất cho đường đi tìm được.
#include <bits/stdc++.h>

using namespace std;
#define ii pair<int,pair<int,int>>  
pair<int,int> d[4] = {{-1,0},{0,1},{1,0},{0,-1}};
int n,m,arr[501][501],f[501][501];

void Init() {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) f[i][j]=1e9;
    }
}
void Dijkstra(int s,int t) {
    Init();
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0,{s,t}});
    f[s][t]=arr[s][t];

    while(!q.empty()) {
        ii top = q.top();
        q.pop();
        pair<int,int> tmp = top.second;
        int i = tmp.first, j = tmp.second;

        for(int k=0;k<4;k++) {
            int i1=i+d[k].first, j1=j+d[k].second;
            if(i1>=1 && i1<=n && j1>=1 && j1<=m && f[i1][j1]>f[i][j]+arr[i1][j1]) {
                f[i1][j1]=f[i][j]+arr[i1][j1];
                q.push({f[i1][j1],{i1,j1}});
            }
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        cin >>n >>m;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) cin >>arr[i][j];
        }
        Dijkstra(1,1);
        cout <<f[n][m] <<endl;        
    }
    return 0;
}