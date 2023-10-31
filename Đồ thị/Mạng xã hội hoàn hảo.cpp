// Mạng xã hội hoàn hảo khi với mọi bộ ba X, Y, Z, nếu X kết bạn với Y, Y kết bạn với Z thì X và Z cũng phải là bạn bè của nhau trên mạng xã hội.
// Hãy xác định một mạng xã hội có phải là hoàn hảo hay không? Nếu có hãy in ra “YES”, “NO” trong trường hợp ngược lại.

// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test bắt đầu bởi 2 số nguyên N và M (N, M ≤ 100 000).
// M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v (u #v) cho biết u và v là kết bạn với nhau trên mạng xã hội.
// Output: 
// Với mỗi test, in ra đáp án tìm được trên một dòng.
#include <bits/stdc++.h>

using namespace std;
vector<int> d[100001];
bool visited[100001];

void DFS(int u,int &dem) {
    dem++;
    visited[u]=true;

    for(int v : d[u]) {
        if(!visited[v]) DFS(v,dem);
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
        int canh=0;
        for(int i=1;i<=n;i++) {
            if(!visited[i]) {
                int dem=0;
                DFS(i,dem);
                canh+=dem*(dem-1)/2; //to hop chap 2 cua so dinh
            }
        }
        if(canh==m) cout <<"YES" <<endl;
        else cout <<"NO" <<endl;
    }
    return 0;
}