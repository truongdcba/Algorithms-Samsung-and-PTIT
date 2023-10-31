// Cho hai số nguyên dương N và K. Nhiệm vụ của bạn là hãy liệt kê tất cả các tập con K phần tử của 1, 2, .., N. 
//Ví dụ với N=5, K=3 ta có 10 tập con của 1, 2, 3, 4, 5 như sau: {1, 2, 3}, {1, 2, 4},{1, 2, 5},{1, 3, 4},{1, 3, 5},{1, 4, 5},{2, 3, 4},{2, 3, 5},{2, 4, 5},{3, 4, 5}.

// Input:
// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một cặp số tự nhiên N, K được viết trên một dòng.
// T, n thỏa mãn ràng buộc: 1≤T≤100; 1≤k ≤ n≤15.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <iostream>

using namespace std;
int x[20];

void Try(int i,int n,int k) {
    for(int j=x[i-1]+1;j<=n-k+i;j++) {
        x[i]=j;
        if(i==k) {
            for(int j=1;j<=k;j++) cout <<x[j];
            cout <<" ";
        }
        else Try(i+1,n,k);
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n,k;
        cin >>n >>k;
        Try(1,n,k);
        cout <<endl;
    }
    return 0;
}