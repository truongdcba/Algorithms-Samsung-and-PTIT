// Cho một bảng kích thước N x N, trong đó có các ô trống ‘.’ và vật cản ‘X’. Các hàng và các cột được đánh số từ 0.
// Mỗi bước di chuyển, bạn có thể đi từ ô (x, y) tới ô (u, v) nếu như 2 ô này nằm trên cùng một hàng hoặc một cột, và không có vật cản nào ở giữa.
// Cho điểm xuất phát và điểm đích. Bạn hãy tính số bước di chuyển ít nhất?

// Input:
// Dòng đầu ghi số bộ test (không quá 10). Mỗi test gồm:
// Dòng đầu tiên là số nguyên dương N (1 ≤ N ≤ 100).
// N dòng tiếp theo, mỗi dòng gồm N kí tự mô tả bảng.
// Cuối cùng là 4 số nguyên a, b, c, d với (a, b) là tọa độ điểm xuất phát, (c, d) là tọa độ đích. Dữ liệu đảm bảo hai vị trí này không phải là ô có vật cản.
 
// Output: 
// Với mỗi test, in ra một số nguyên là đáp số của bài toán.
#include <bits/stdc++.h>

using namespace std;
char arr[105][105];
bool visited[105][105];
int f[105][105];

void BFS(int n,int a,int b,int c,int d) {
    queue<pair<int,int>> q;
    q.push({a,b});
    visited[a][b]=true;

    while(!q.empty()) {
        pair<int,int> top=q.front();
        q.pop();
        if(visited[c][d]) return;

        // 4 vòng for này là để loang từ 1 ô ra 4 hướng theo hàng và cột
        for(int i=top.first-1;i>=0;i--) {
            if(arr[i][top.second]=='X') break;
            else if(!visited[i][top.second]) {
                q.push({i,top.second});
                visited[i][top.second]=true;
                f[i][top.second]=f[top.first][top.second]+1;
            }
        }
        for(int i=top.first+1;i<n;i++) {
            if(arr[i][top.second]=='X') break;
            else if(!visited[i][top.second]) {
                q.push({i,top.second});
                visited[i][top.second]=true;
                f[i][top.second]=f[top.first][top.second]+1;
            }
        }
        for(int i=top.second-1;i>=0;i--) {
            if(arr[top.first][i]=='X') break;
            else if(!visited[top.first][i]) {
                q.push({top.first,i});
                visited[top.first][i]=true;
                f[top.first][i]=f[top.first][top.second]+1;
            }
        }
        for(int i=top.second+1;i<n;i++) {
            if(arr[top.first][i]=='X') break;
            else if(!visited[top.first][i]) {
                q.push({top.first,i});
                visited[top.first][i]=true;
                f[top.first][i]=f[top.first][top.second]+1;
            }
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(visited,false,sizeof(visited));
        memset(f,0,sizeof(f));
        int n;
        cin >>n;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) cin >>arr[i][j];
        }
        int a,b,c,d;
        cin >>a >>b >>c >>d;
        BFS(n,a,b,c,d);
        cout <<f[c][d] <<endl;
    }
    return 0;
}