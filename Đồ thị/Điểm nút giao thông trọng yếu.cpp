// Một thành phố có N điểm nút giao thông. Các tuyến đường hai chiều được thiết kế giúp cho người dân có thể đi từ một nút bất kỳ đến tất cả các nút còn lại.

// Những nút giao thông trọng yếu được định nghĩa là nút giao thông mà nếu các con đường đến nó đều bị chặn thì thành phố sẽ bị chia cắt, 
// tức là khi đó sẽ có những cặp điểm nút không thể đi đến nhau được nữa.
// Giả sử các điểm nút giao thông được đánh số từ 1 đến N. Hãy liệt kê các nút giao thông trọng yếu theo thứ tự tăng dần.

// Input
// Dòng đầu là số bộ test (không quá 100)
// Mỗi bộ test bắt đầu với số nút giao thông N (không quá 1000) và số tuyến đường M.
// Tiếp theo là một dòng có M cặp số mô tả các tuyến đường hai chiều trong thành phố.
// Output
// Dòng đầu ghi ra số lượng điểm nút giao thông trọng yếu
// Dòng thứ 2 lần lượt liệt kê các nút giao thông trọng yếu theo thứ tự tăng dần
#include <bits/stdc++.h>

using namespace std;
int n,m;
vector<int> d[1001];
bool visited[1001];

void DFS(int u) {
    visited[u]=true;
    for(int v : d[u]) {
        if(!visited[v]) DFS(v);
    }
}
int tplt() {
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
        memset(d,0,sizeof(d));

        cin >>n >>m;
        for(int i=0;i<m;i++) {
            int x,y;
            cin >>x >>y;
            d[x].push_back(y);
            d[y].push_back(x);
        }
        vector<int> res;
        for(int i=1;i<=n;i++) {
            visited[i]=true;
            if(tplt()>1) { // do đề bài cho đồ thị liên thông nên số thành phần liên thông ban đầu là 1
                res.push_back(i);
            }
            memset(visited,false,sizeof(visited));
        }
        cout <<res.size() <<endl;
        for(int it : res) cout <<it <<" ";
        cout <<endl;
    }
    return 0;
}