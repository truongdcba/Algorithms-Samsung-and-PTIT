// Cho đồ thị vô hướng có trọng số G=<V, E, W>. Nhiệm vụ của bạn là hãy xây dựng một cây khung nhỏ nhất của đồ thị bằng thuật toán Kruskal.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: 
// phần thứ nhất đưa vào hai số V, E tương ứng với số đỉnh và số cạnh của đồ thị; 
// phần thứ 2 đưa vào E cạnh của đồ thị, mỗi cạnh là một bộ 3: đỉnh đầu, đỉnh cuối và trọng số của cạnh.
// T, S, D thỏa mãn ràng buộc: 1≤T≤100;  1≤V≤100; 1≤E, W≤10000.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;
int way[101],sz[101];

struct edge {
    int x,y,w;
};
vector<edge> v;

bool cmp(edge a,edge b) {
    return a.w < b.w;
}
void khoiTao(int n) {
    for(int i=1;i<=n;i++) {
        way[i]=i;
        sz[i]=1;
    }
}
int Find(int u) {
    if(u==way[u]) return u;
    else return way[u]=Find(way[u]);
}
bool Union(int u,int v) {
    u=Find(u);
    v=Find(v);

    if(u==v) return false;
    if(sz[u]<sz[v]) {
        swap(u,v);
    }
    sz[u]+=sz[v];
    way[v]=u;
    return true;
}
int Kruskal(int n) {
    int value=0;
    vector<edge> MST;

    for(auto it : v) {
        if(MST.size()==n-1) break;
        edge e=it;
        if(Union(e.x,e.y)) {
            value+=it.w;
            MST.push_back(e);
        }
    }
    return value;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        v.clear();
        memset(way,0,sizeof(way));
        memset(sz,0,sizeof(sz));
        int n,m;
        cin >>n >>m;
        for(int i=0;i<m;i++) {
            int x,y,w;
            cin >>x >>y >>w;
            v.push_back((edge){x,y,w});
        }
        sort(v.begin(),v.end(),cmp);
        khoiTao(n);
        cout <<Kruskal(n) <<endl;
    }
    return 0;
}