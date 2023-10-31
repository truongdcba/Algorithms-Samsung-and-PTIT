// Vua Titan và các hiệp sĩ bàn tròn thường gặp nhau vào đầu năm mới để ăn mừng tình bạn của họ. 
// Để tưởng nhớ sự kiện này, chúng ta xem xét một trò chơi, trong đó có một quân vua và một vài quân mã được đặt ngẫu nhiên trên các ô riêng biệt. 
// Bàn cờ có kích thước N×N, trên bàn cờ có một số ô cấm những ô còn lại là những ô tự do – ô có thể di chuyển vào được. 
// Các ô đặt quân mã và quân vua đang đứng ở các ô tự do.

// Tại mỗi bước tất cả các quân đều phải di chuyển theo quy tắc và không được đi vào ô cấm, hãy tìm cách di chuyển để chúng gặp nhau nhanh nhất.
// Input:
// Dòng đầu tiên là số nguyên N (N ≤ 100).
// N dòng tiếp theo, mỗi dòng gồm 1 xâu có N ký tự, mô tả bàn cờ. 
// “.” Thể hiện ô trống, “#” thể hiện ô cấm, “T” thể hiện vị trí vua đang đứng và “M” thể hiện vị trí quân mã đang đứng.
// Output: 
// In ra đáp án là số bước ít nhất để các quân gặp nhau. Nếu không thể gặp nhau, in ra -1.
#include <bits/stdc++.h>

using namespace std;
pair<int,int> d1[8]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
pair<int,int> d2[8]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
char a1[105][105];
int f1[105][105],f2[105][105];
int x1,y,x2,y2;
bool visited[105][105];

int find(int n) {
    queue<pair<int,int>> qT;
    qT.push({x1,y});

    while(!qT.empty()) {
        pair<int,int> top=qT.front();
        qT.pop();
        for(int i=0;i<8;i++) {
            int i1=top.first+d1[i].first, j1=top.second+d1[i].second;
            if(i1>=1 && i1<=n && j1>=1 && j1<=n && !visited[i1][j1] && a1[i1][j1]=='.') {
                qT.push({i1,j1});
                visited[i1][j1]=true;
                f1[i1][j1]=f1[top.first][top.second]+1;
            }
        }
    }
    memset(visited,false,sizeof(visited));
    queue<pair<int,int>> qM;
    qM.push({x2,y2});

    while(!qM.empty()) {
        pair<int,int> top=qM.front();
        qM.pop();
        for(int i=0;i<8;i++) {
            int i1=top.first+d2[i].first, j1=top.second+d2[i].second;
            if(i1>=1 && i1<=n && j1>=1 && j1<=n && !visited[i1][j1] && a1[i1][j1]=='.') {
                qM.push({i1,j1});
                visited[i1][j1]=true;
                f2[i1][j1]=f2[top.first][top.second]+1;
                if(f1[i1][j1]==f2[i1][j1]) { 
                    return f1[i1][j1];
                }
            } 
        }
    }
    return -1;
}
int main() {
    int n;
    cin >>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >>a1[i][j];
            if(a1[i][j]=='T') {
                x1=i;
                y=j;
            }
            else if(a1[i][j]=='M') {
                x2=i;
                y2=j;
            }
        }
    }
    cout <<find(n);
    return 0;
}