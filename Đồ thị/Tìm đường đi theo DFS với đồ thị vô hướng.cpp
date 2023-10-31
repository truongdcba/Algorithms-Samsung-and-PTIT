// Cho đồ thị vô hướng G= được biểu diễn dưới dạng danh sách cạnh. Hãy tìm đường đi từ đỉnh s đến đỉnh t trên đồ thị bằng thuật toán DFS.

// Input:
// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: 
// dòng đầu tiên đưa vào bốn số |V|, |E|, s, t tương ứng với số đỉnh, số cạnh,  đỉnh u, đỉnh v; 
// Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤10^3; 1≤|E|≤|V|(|V|-1)/2;
// Output:
// Đưa ra đường đi từ đỉnh s đến đỉnh t của mỗi test theo thuật toán DFS của mỗi test theo khuôn dạng của ví dụ dưới đây. Nếu không có đáp án, in ra -1.
#include <bits/stdc++.h>

using namespace std;
vector<int> d[1001];
bool visited[1001];
int way[1001];

void DFS(int u) {
    visited[u]=true;
    for(int v : d[u]) {
        if(!visited[v]) {
            way[v]=u;
            DFS(v);
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(d,0,sizeof(d));
        memset(visited,false,sizeof(visited));
        memset(way,0,sizeof(way));
        int n,m,s,t;
        cin >>n >>m >>s >>t;
        for(int i=0;i<m;i++) {
            int x,y;
            cin >>x >>y;
            d[x].push_back(y);
            d[y].push_back(x);
        }
        DFS(s);
        if(!visited[t]) cout <<-1 <<endl;
        else {
            vector<int> res;
            while(t!=s) {
                res.push_back(t);
                t=way[t];
            }
            res.push_back(s);
            reverse(res.begin(),res.end());
            for(int it : res) cout <<it <<" ";
            cout <<endl;
        }
    }
    return 0;
}