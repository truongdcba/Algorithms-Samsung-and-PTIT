// Cho đồ thị vô hướng G có N đỉnh, M cạnh. 
// Hãy liệt kê các đỉnh không cùng thành phần liên thông với đỉnh 1.
// Input
// Dòng đầu ghi 2 số N và M (0 < N < 300; 1 <= M <= N*(N-1)/2)).
// Tiếp theo là M dòng, mỗi dòng ghi một cạnh của đồ thị. Các cạnh được liệt kê với thứ tự bất kỳ.
// Output
// Ghi ra các đỉnh không liên thông với đỉnh 1 theo thứ tự tăng dần, mỗi dòng ghi một đỉnh. Nếu không có đỉnh nào thì
#include <bits/stdc++.h>

using namespace std;
vector<int> d[301];
bool visited[301];

void DFS(int u) {
    visited[u]=true;
    for(int v : d[u]) {
        if(!visited[v]) DFS(v);
    }
}
int main() {
    int n,m;
    cin >>n >>m;
    for(int i=0;i<m;i++) {
        int x,y;
        cin >>x >>y;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    DFS(1);

    int ok=0;
    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            ok=1;
            cout <<i <<endl;
        }
    }
    if(ok==0) cout <<0;
    return 0;
}