// Cho đồ thị vô hướng có N đỉnh và M cạnh. 
// Có Q truy vấn, mỗi truy vấn yêu cầu trả lời câu hỏi giữa 2 đỉnh x và y có tồn tại đường đi tới nhau hay không?

// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test gồm 2 số nguyên N, M (1 ≤ N, M ≤ 1000).
// M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết có cạnh nối giữa đỉnh u và v.
// Dòng tiếp là số lượng truy vấn Q (1 ≤ Q ≤ 1000).
// Q dòng tiếp theo, mỗi dòng gồm 2 số nguyên x và y.
// Output:  Với mỗi truy vấn, in ra “YES” nếu có đường đi từ x tới y, in ra “NO” nếu ngược lại.
#include <bits/stdc++.h>

using namespace std;
vector<int> d[1001];
bool visited[1001];
int f[1001];

void DFS(int u,int dem) {
    visited[u]=true;
    f[u]=dem;
    
    for(int v : d[u]) {
        if(!visited[v]) {
            DFS(v,dem);
        }
    }
}
bool checkPath(int x,int y) {
    return f[x]==f[y];
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(d,0,sizeof(d));
        memset(visited,false,sizeof(visited));
        memset(f,0,sizeof(f));
        int n,m;
        cin >>n >>m;

        for(int i=0;i<m;i++) {
            int x,y;
            cin >>x >>y;
            d[x].push_back(y);
            d[y].push_back(x);
        }
        int dem=0;
        for(int i=1;i<=n;i++) {
            if(!visited[i]) {
                dem++;
                DFS(i,dem);
            }
        }

        int q;
        cin >>q;
        while(q--) {
            int x,y;
            cin >>x >>y;
            if(checkPath(x,y)) cout <<"YES" <<endl;
            else cout <<"NO" <<endl;
        }
    }    
    return 0;
}