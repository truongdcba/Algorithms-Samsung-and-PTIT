// Cho đồ thị có hướng G= được biểu diễn dưới dạng danh sách cạnh. Hãy viết thuật toán duyệt theo chiều rộng bắt đầu tại đỉnh uÎV (BFS(u)=?)

// Input:
// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: 
// Dòng đầu tiên đưa vào ba số |V|, |E|, uÎV tương ứng với số đỉnh, số cạnh và đỉnh bắt đầu duyệt; 
// Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤200; 1≤|V|≤10^3; 1≤|E|≤|V|(|V|-1)/2;
// Output:
// Đưa ra danh sách các đỉnh được duyệt theo thuật toán BFS(u) của mỗi test theo khuôn dạng của ví dụ dưới đây.
#include <bits/stdc++.h>

using namespace std;
vector<int> d[1001];
bool visited[1001];

void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u]=true;

    while(!q.empty()) {
        int top=q.front();
        q.pop();
        cout <<top <<" ";
        for(int v : d[top]) {
            if(!visited[v]) {
                q.push(v);
                visited[v]=true;
            }
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(d,0,sizeof(d));
        memset(visited,false,sizeof(visited));
        int n,m,u;
        cin >>n >>m >>u;
        for(int i=0;i<m;i++) {
            int x,y;
            cin >>x >>y;
            d[x].push_back(y);
        }
        BFS(u);
        cout <<endl;
    }
    return 0;
}