// Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh.

// Hãy tìm đường đi từ đỉnh u đến đỉnh v trên đồ thị bằng thuật toán BFS.

// Input:
// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E|+1 dòng: 
// dòng đầu tiên đưa vào bốn số |V|, |E|, u, v tương ứng với số đỉnh, số cạnh,  đỉnh xuất phát u, đỉnh kết thúc v;
// |E| dòng tiếp theo mỗi dòng đưa vào bộ đôi x, y tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤10^3; 1≤|E|≤|V|(|V|-1)/2;
// Output:
// Đưa ra đường đi từ đỉnh s đến đỉnh t của mỗi test theo thuật toán BFS của mỗi test theo khuôn dạng của ví dụ dưới đây. 
//Nếu không có đáp án, in ra -1.
#include <bits/stdc++.h>

using namespace std;
vector<int> d[1001];
bool visited[1001];
int way[1001];

void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u]=true;

    while(!q.empty()) {
        int top=q.front();
        q.pop();
        for(int v : d[top]) {
            if(!visited[v]) {
                q.push(v);
                visited[v]=true;
                way[v]=top;
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
        memset(way,0,sizeof(way));

        int n,m,u,v;
        cin >>n >>m >>u >>v;
        for(int i=0;i<m;i++) {
            int x,y;
            cin >>x >>y;
            d[x].push_back(y);
        }
        BFS(u);
        if(!visited[v]) cout <<-1 <<endl;
        else {
            vector<int> res;
            while(v!=u) {
                res.push_back(v);
                v=way[v];
            }
            res.push_back(u);
            reverse(res.begin(),res.end());
            for(int i=0;i<res.size();i++) {
                if(i!=res.size()-1) cout <<res[i] <<" -> ";
                else cout <<res[i] <<endl;
            }
        }
    }
    return 0;
}