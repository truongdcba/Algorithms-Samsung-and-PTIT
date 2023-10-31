// Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy viết thuật toán duyệt theo chiều sâu bắt đầu tại đỉnh uÎV (DFS(u)=?)

// Input:
// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E| +1 dòng: 
// dòng đầu tiên đưa vào ba số |V|, |E| tương ứng với số đỉnh và số cạnh của đồ thị, và u là đỉnh xuất phát; 
// |E| dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤200; 1≤|V|≤10^3; 1≤|E|≤|V|(|V|-1)/2;
// Output:
// Đưa ra danh sách các đỉnh được duyệt theo thuật toán DFS(u) của mỗi test theo khuôn dạng của ví dụ dưới đây.
#include <bits/stdc++.h>

using namespace std;
vector<int> d[1001];
bool visited[1001];

void DFS(int u) {
    cout <<u <<" ";
    visited[u]=true;

    for(int v : d[u]) {
        if(!visited[v]) {
            DFS(v);
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(visited,false,sizeof(visited));
        memset(d,0,sizeof(d));
        
        int v,e,u;
        cin >>v >>e >>u;
        for(int i=0;i<e;i++) {
            int x,y;
            cin >>x >>y;
            d[x].push_back(y);
            d[y].push_back(x);
        }
        DFS(u);
        cout <<endl;
    }
    return 0;
}