// Một đồ thị N đỉnh là một cây, nếu như nó có đúng N-1 cạnh và giữa 2 đỉnh bất kì, chỉ tồn tại duy nhất 1 đường đi giữa chúng.
// Cho một đồ thị N đỉnh và N-1 cạnh, hãy kiểm tra đồ thị đã cho có phải là một cây hay không?
// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test bắt đầu bởi số nguyên N (1 ≤ N ≤ 1000).
// N-1 dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết có cạnh nối giữa đỉnh u và v.
// Output: 
// Với mỗi test, in ra “YES” nếu đồ thị đã cho là một cây, in ra “NO” trong trường hợp ngược lại.
#include <bits/stdc++.h>

using namespace std;
vector<int> d[1001];
bool visited[1001];
int way[1001];

bool BFS(int u) { // check chu trinh
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
            else if(way[top]!=v) return false;
        }
    }
    return true;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(d,0,sizeof(d));
        memset(visited,false,sizeof(visited));
        memset(way,0,sizeof(way));
        int n;
        cin >>n;

        for(int i=0;i<n-1;i++) {
            int x,y;
            cin >>x >>y;
            d[x].push_back(y);
            d[y].push_back(x);
        }
        int ok=1;
        for(int i=1;i<=n;i++) {
            if(!visited[i] && !BFS(i)) ok=0;
        }
        if(ok==1) cout <<"YES" <<endl;
        else cout <<"NO" <<endl;
    }
    return 0;
}