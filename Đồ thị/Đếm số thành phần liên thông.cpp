// Cho đồ thị vô hướng G= được biểu diễn dưới dạng danh sách cạnh. Hãy tìm số thành phần liên thông của đồ thị..

// Input:
// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: 
// dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh; Dòng tiếp theo đưa vào các bộ đôi u, v tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤10^3; 1≤|E|≤|V|(|V|-1)/2;
// Output:
// Đưa ra số thành phần liên thông của đồ thị bằng thuật toán DFS.
#include <bits/stdc++.h>

using namespace std;
vector<int> d[1001];
bool visited[1001];

void DFS(int u) {
    visited[u]=true;
    for(int v : d[u]) {
        if(!visited[v]) DFS(v);
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(d,0,sizeof(d));
        memset(visited,false,sizeof(visited));
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
                DFS(i);
            }
        }
        cout <<dem <<endl;
    }
    return 0;
}