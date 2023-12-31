// Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các hoán vị của 1, 2, .., N theo thứ tự ngược. Ví dụ với N = 3 ta có kết quả: 321, 312, 231, 213, 132, 123.
// Input:
// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
// T, n thỏa mãn ràng buộc: 1≤T, N≤10.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;
int n,x[20];
bool visited[20];

void Try(int i) {
    for(int j=n;j>=1;j--) {
        if(!visited[j]) {
            x[i]=j;
            visited[j]=true;
            if(i==n) {
                for(int j=1;j<=n;j++) cout <<x[j];
                cout <<" ";
            }
            else Try(i+1);
            visited[j]=false;
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        cin >>n;
        Try(1);
        cout <<endl;
    }
    return 0;
}