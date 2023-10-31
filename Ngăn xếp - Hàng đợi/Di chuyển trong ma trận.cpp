// Cho ma trận A[M][N]. Nhiệm vụ của bạn hãy tìm số bước đi ít nhất dịch chuyển từ vị trí A[1][1] đến vị trí A[M][N]. Biết mỗi bước đi ta chỉ được phép dịch chuyển đến vị trí A[i][j+A[i][j]] hoặc vị trí A[i+A[i][j]][j] bên trong ma trận.
// Input:
// Dòng đầu tiên đưa vào số lượng test T.
// Dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số M, N; phần thứ hai là các phần tử của ma trận A[][]; các số được viết cách nhau một vài khoảng trống.
// T, M, N, A[i][j] thỏa mãn ràng buộc: 1≤T≤100; 1≤M, N, A[i][j]≤103.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng. In ra -1 nếu không tìm được đáp án.
#include <bits/stdc++.h>

using namespace std;
#define fi top.first
#define se top.second
int f[1005][1005],arr[1005][1005];
bool visited[1005][1005];

void find(int n,int m) {
    queue<pair<int,int>> q;
    q.push({1,1});

    while(!q.empty()) {
        pair<int,int> top=q.front();
        q.pop();

        if(fi+arr[fi][se]<=m && !visited[fi+arr[fi][se]][se]) {
            q.push({fi+arr[fi][se],se});
            visited[fi+arr[fi][se]][se]=true;
            f[fi+arr[fi][se]][se]=f[fi][se]+1;
        }
        if(se+arr[fi][se]<=n && !visited[fi][se+arr[fi][se]]) {
            q.push({fi,se+arr[fi][se]});
            visited[fi][se+arr[fi][se]]=true;
            f[fi][se+arr[fi][se]]=f[fi][se]+1;
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(f,0,sizeof(f));
        memset(visited,0,sizeof(visited));
        int m,n;
        cin >>m >>n;

        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                cin >>arr[i][j];
            }
        }
        find(n,m);
        if(f[m][n]==0) cout <<-1 <<endl;
        else cout <<f[m][n] <<endl;
    }
    return 0;
}