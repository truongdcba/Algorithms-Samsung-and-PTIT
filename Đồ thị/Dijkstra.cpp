// Cho đồ thị có trọng số không âm G=<V, E> được biểu diễn dưới dạng danh sách cạnh trọng số. 
// Hãy viết chương trình tìm đường đi ngắn nhất từ đỉnh uÎV đến tất cả các đỉnh còn lại trên đồ thị.

// Input:
// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E|+1 dòng: 
// dòng đầu tiên đưa vào hai ba số |V|, |E| tương ứng với số đỉnh và uÎV là đỉnh bắt đầu; 
// |E| dòng tiếp theo mỗi dòng đưa vào bộ ba uÎV, vÎV, w tương ứng với một cạnh cùng với trọng số canh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤10^3; 1≤|E|≤|V|(|V|-1)/2;
// Output:
// Đưa ra kết quả của mỗi test theo từng dòng. Kết quả mỗi test là trọng số 
#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> d[1001];
int n,m,s;

void Dijkstra(int s) {
    vector<int> v(n+1,1e9);
    v[s]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,s});

    while(!q.empty()) {
        pair<int,int> top = q.top();
        q.pop();
        int u=top.second, kc=top.first;
        if(kc>v[u]) continue;

        for(auto it : d[u]) {
            int x=it.first, w=it.second;
            if(v[u]+w<v[x]) {
                v[x]=v[u]+w;
                q.push({v[x],x});
            }
        } 
    }
    for(int i=1;i<=n;i++) cout <<v[i] <<" ";
    cout <<endl;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(d,0,sizeof(d));
        cin >>n >>m >>s;

        for(int i=0;i<m;i++) {
            int x,y,w;
            cin >>x >>y >>w;
            d[x].push_back({y,w});
            d[y].push_back({x,w});
        }
        Dijkstra(s);
    }
    return 0;
}