// Cho một mê cung bao gồm các khối được biểu diễn như một ma trận nhị phân A[N][N]. 
// Một con chuột đi từ ô đầu tiên góc trái (A[0][0]) đến ô cuối cùng góc phải (A[N-1][N-1]) theo nguyên tắc:

// Down (D): Chuột được phép xuống dưới nếu ô dưới nó có giá trị 1.
// Right (R): Chuột được phép sang phải dưới nếu ô bên phải nó có giá trị 1.
// Left (L): Chuột được phép sang trái dưới nếu ô bên trái nó có giá trị 1.
// Up (U): Chuột được phép lên trên nếu ô trên nó có giá trị 1.
// Hãy đưa ra tất cả các hành trình của con chuột trên mê cung. Đưa ra -1 nếu chuột không thể đi đến đích.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là kích cỡ của mê cung; dòng tiếp theo đưa vào ma trận nhị phân A[N][N].
// T, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 2≤N≤8; 0≤A[i][j] ≤1.
// Output:
// Đưa ra các xâu ký tự được sắp xếp, trong đó mỗi xâu là một đường đi của con chuột trong mê cung. 
//In ra đáp án theo thứ tự từ điển. Đưa ra -1 nếu chuột không đi được đến đích.
#include <bits/stdc++.h>

using namespace std;
int n,arr[10][10];
pair<int,int> d[4]={{1,0},{0,-1},{0,1},{-1,0}};
vector<string> v;
string tmp="",s="DLRU";

void Try(int i,int j) {
    for(int k=0;k<4;k++) {
        int i1=i+d[k].first, j1=j+d[k].second;
        if(i1>=1 && i1<=n && j1>=1 && j1<=n && arr[i1][j1]) {
            tmp+=s[k];
            arr[i1][j1]=0;
            if(i1==n && j1==n) v.push_back(tmp);
            else Try(i1,j1);
            tmp.pop_back();
            arr[i1][j1]=1;
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        v.clear();
        cin >>n;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) cin >>arr[i][j];
        }
        arr[1][1]=0;
        Try(1,1);
        
        if(v.empty()) cout <<-1;
        else {
            for(auto it : v) cout <<it <<" ";
        }
        cout <<endl;
    }
}