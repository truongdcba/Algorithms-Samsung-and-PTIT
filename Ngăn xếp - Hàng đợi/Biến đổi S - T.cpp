// Cho hai số nguyên dương S và T (S, T<10000) và hai thao tác (a), (b) dưới đây:

// Thao tác (a): Trừ S đi 1  (S = S-1) ;                   

// Thao tác (b): Nhân S với 2 ( S = S*2);

// Hãy dịch chuyển S thành T sao cho số lần thực hiện các thao tác (a), (b) là ít nhất. Ví dụ với    S =2, T=5 thì số các bước ít nhất để dịch chuyển S thành T thông qua 4 thao tác sau:

// Thao tác (a): 2*2 = 4;

// Thao tác (b): 4-1 = 3;

// Thao tác (a): 3*2 = 6;

// Thao tác (b): 6-1 = 5;

// Input:
// Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test;
// T dòng kế tiếp mỗi dòng ghi lại một bộ Test. Mỗi test là một bộ đôi S và T.
// Output: Đưa ra kết quả mỗi test theo từng dòng.

#include <bits/stdc++.h>

using namespace std;
bool visited[100000]; // su dung mang danh dau co the bi RTE (Hoac doi sang dung set)

int BFS(int s,int t) {
    queue<pair<int,int>> q;
    q.push({s,0});
    visited[s]=true;

    while(!q.empty()) {
        pair<int,int> top=q.front();
        q.pop();
        if(top.first==t) return top.second;

        if(!visited[top.first-1] && top.first>1) {
            q.push({top.first-1,top.second+1});
            visited[top.first-1]=true;
        }
        if(!visited[top.first*2] && top.first<t) {
            q.push({top.first*2,top.second+1});
            visited[top.first*2]=true;
        }
    }
}
int main() {
    int q;
    cin >>q;

    while(q--) {
        memset(visited,false,sizeof(visited));
        int s,t;
        cin >>s >>t;
        cout <<BFS(s,t) <<endl;
    }
    return 0;
}