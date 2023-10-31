// Cho đồ thị có hướng G= được biểu diễn dưới dạng danh sách cạnh. Hãy kiểm tra xem đồ thị có liên thông mạnh hay không?

// Input:
// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: 
// dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤10^3; 1≤|E|≤|V|(|V|-1)/2;
// Output:
// Đưa ra “YES”, hoặc “NO” theo từng dòng tương ứng với test là liên thông mạnh hoặc không liên thông mạnh.
#include <bits/stdc++.h>

using namespace std;
vector<int> d[1001],transpose[1001];
bool visited[1001];
stack<int> topo;

void DFS1(int u) {
    visited[u]=true;

    for(int v : d[u]) {
        if(!visited[v]) DFS1(v);
    }
    topo.push(u);
}
void DFS2(int u) {
    visited[u]=true;

    for(int v : transpose[u]) {
        if(!visited[v]) DFS2(v);
    }
}
bool Kosaraju() {
    int dem=0;
    while(!topo.empty()) {
        if(!visited[topo.top()]) {
            dem++;
            DFS2(topo.top());
        }
        topo.pop();
    }
    return dem==1;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(d,0,sizeof(d));
        memset(transpose,0,sizeof(transpose));
        memset(visited,false,sizeof(visited));
        int n,m;
        cin >>n >>m;

        for(int i=0;i<m;i++) {
            int x,y;
            cin >>x >>y;
            d[x].push_back(y);
            transpose[y].push_back(x);
        }
        for(int i=1;i<=n;i++) {
            if(!visited[i]) DFS1(i);
        }
        memset(visited,false,sizeof(visited));
        if(Kosaraju()) cout <<"YES" <<endl;
        else cout <<"NO" <<endl;
    }
    return 0;
}