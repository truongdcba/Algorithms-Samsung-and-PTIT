// Cho đồ thị vô hướng G=(V, E). Hãy xây dựng một cây khung của đồ thị G với đỉnh u ∈ V là gốc của cây bằng thuật toán DFS.

// Input
// Dòng đầu tiên gồm một số nguyên T (1 ≤ T ≤ 20) là số lượng bộ test.
// Tiếp theo là T bộ test, mỗi bộ test có dạng sau:
// Dòng đầu tiên gồm 3 số nguyên N=|V|, M=|E|, u (1 ≤ N ≤ 10^3, 1 ≤ M ≤ 105, 1 ≤ u ≤ N).
// M dòng tiếp theo, mỗi dòng gồm 2 số nguyên a, b (1 ≤ a, b ≤ N, a ≠ b) tương ứng cạnh nối hai chiều từ a tới b.
// Dữ liệu đảm bảo giữa hai đỉnh chỉ tồn tại nhiều nhất một cạnh nối.
// Output
// Với mỗi bộ test, nếu tồn tại cây khung thì in ra N – 1 cạnh của cây khung với gốc là đỉnh u trên N – 1 dòng theo thứ tự duyệt của thuật toán DFS. 
// Ngược lại nếu không tồn tại cây khung thì in ra -1.
#include <bits/stdc++.h>

using namespace std;
vector<int> d[1001];
bool visited[1001];
vector<pair<int,int>> res;

void DFS(int u,int n) {
    visited[u]=true;
    if(res.size()==n-1) return;
    for(int v : d[u]) {
        if(!visited[v]) {
            res.push_back({u,v});
            DFS(v,n);
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(d,0,sizeof(d));
        memset(visited,false,sizeof(visited));
        res.clear();
        int n,m,u;
        cin >>n >>m >>u;
        
        for(int i=0;i<m;i++) {
            int x,y;
            cin >>x >>y;
            d[x].push_back(y);
            d[y].push_back(x);
        }
        DFS(u,n);
        if(res.size()==n-1) {
            for(auto it : res) cout <<it.first <<" " <<it.second <<endl;
        }
        else cout <<-1 <<endl;
    }
    return 0;
}