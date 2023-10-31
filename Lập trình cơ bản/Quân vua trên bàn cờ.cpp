// Trên bàn cờ vua kích thước 8*8 thì quân vua được phép di chuyển đến cả 8 ô liền kề theo cả đường dọc và đường chéo. 
// Tất nhiên quân vua sẽ không thể di chuyển được ra ngoài bàn cờ.

// Cho 2 ô trên bàn cờ gọi là ô bắt đầu và ô kết thúc. Hãy tính xem quân vua cần ít nhất bao nhiêu bước để di chuyển từ ô bắt đầu đến ô kết thúc.
// Input
// Có 2 cặp số nguyên s1,s2 và f1,f2 lần lượt và vị trí ô bắt đầu và ô kết thúc. Các vị trí đảm bảo nằm trong phạm vi bàn cờ.
// Output
// Số bước đi ít nhất của quân vua
#include <bits/stdc++.h>

using namespace std;
int s,t,u,v;
pair<int,int> d[8]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
int f[100][100];
bool visited[100][100];

void loang(int i,int j) {
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j]=true;

    while(!q.empty()) {
        pair<int,int> top=q.front();
        q.pop();
        for(int k=0;k<8;k++) {
            int i1=top.first+d[k].first, j1=top.second+d[k].second;
            if(i1>=1 && i1<=8 && j1>=1 && j1<=8 && !visited[i1][j1]) {
                q.push({i1,j1});
                visited[i1][j1]=true;
                f[i1][j1]=f[top.first][top.second]+1;
            }
        }
    }
}
int main() {
    cin >>s >>t >>u >>v;    
    loang(s,t);

    cout <<f[u][v];
    return 0;
}