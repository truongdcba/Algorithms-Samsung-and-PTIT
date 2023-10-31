// Cho một quân mã trên bàn cờ vua tại vị trí ST. Nhiệm vụ của bạn là hãy tìm số bước di chuyển ít nhất để đưa quân mã tới vị trí EN.

// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test gồm 2 xâu dạng “xy” và “uv”, trong đó x, u là kí tự trong “abcdefgh” còn y, v là số thuộc 1, 2, 3, 4, 5, 6, 7, 8.
// Output: 
// Với mỗi test, in ra đáp án tìm được trên một dòng.
#include <bits/stdc++.h>

using namespace std;
string path="abcdefgh";
int f[10][10];
bool visited[10][10];
pair<int,int> d[8]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};

void convert(string &a,string &b) {
    for(int i=0;i<path.size();i++) {
        if(a[0]==path[i]) {
            a[0]=(i+1+'0');
            break;
        }
    }
    for(int i=0;i<path.size();i++) {
        if(b[0]==path[i]) {
            b[0]=(i+1+'0');
            break;
        }
    }
}
void find(int x,int y,int u,int v) {
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y]=true;

    while(!q.empty()) {
        if(visited[u][v]) return;
        
        pair<int,int> top=q.front();
        q.pop();
        for(int i=0;i<8;i++) {
            int i1=top.first+d[i].first, j1=top.second+d[i].second;
            if(i1>=1 && i1<=8 && j1>=1 && j1<=8 && !visited[i1][j1]) {
                q.push({i1,j1});
                visited[i1][j1]=true;
                f[i1][j1]=f[top.first][top.second]+1;
            }
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(f,0,sizeof(f));
        memset(visited,0,sizeof(visited));
        string st,en;
        cin >>st >>en;
        convert(st,en);
        int x=stoi(string(1,st[0]));
        int y=stoi(string(1,st[1]));
        int u=stoi(string(1,en[0]));
        int v=stoi(string(1,en[1]));

        find(x,y,u,v);
        cout <<f[u][v] <<endl;
    }
    return 0;
}