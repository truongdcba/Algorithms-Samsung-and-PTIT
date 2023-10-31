// Cho đồ thị vô hướng liên thông G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy đưa ra tất cả các cạnh cầu của đồ thị?

// Input:
// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E| + 1 dòng: 
// dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh; 
// |E| dòng tiếp theo đưa vào các bộ đôi u, v tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤10^3; 1≤|E|≤|V|(|V|-1)/2;
// Output:
// Đưa ra danh sách các cạch cầu của mỗi test theo từng dòng. In ra đáp án theo thứ tự từ điển, theo dạng “a b …” với a < b.
#include <bits/stdc++.h>

using namespace std;
set<int> d[1001];  // luu danh sach ke
vector<pair<int,int>> v; // luu danh sach canh
bool visited[1001];

void Delete(int n) {
    for(int i=1;i<=n;i++) d[i].clear();
}
void DFS(int u) {
    visited[u]=true;
    for(int v : d[u]) {
        if(!visited[v]) DFS(v);
    }
}
int tplt(int n) {
    int dem=0;
    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            dem++;
            DFS(i);
        }
    }
    return dem;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n,m;
        cin >>n >>m;
        Delete(n);
        v.clear();

        for(int i=0;i<m;i++) {
            int x,y;
            cin >>x >>y;
            v.push_back({x,y});
            d[x].insert(y);
            d[y].insert(x);
        }
        for(auto it : v) {
            d[it.first].erase(it.second);
            d[it.second].erase(it.first);
            if(tplt(n)>1) { // do đề bài cho đồ thị liên thông nên số thành phần liên thông ban đầu là 1
                cout <<it.first <<" " <<it.second <<" ";
            }
            d[it.first].insert(it.second);
            d[it.second].insert(it.first);
            memset(visited,false,sizeof(visited));
        }
        cout <<endl;
    }
    return 0;
}