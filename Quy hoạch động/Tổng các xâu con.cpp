// Cho số nguyên dương N được biểu diễn như một xâu ký tự số. 
// Nhiệm vụ của bạn là tìm tổng của tất cả các số tạo bởi các xâu con của N. Ví dụ N=”1234” ta có kết quả là 1670 = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234.

// Input: Dòng đầu tiên đưa vào số lượng bộ test T. 
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số N.  T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤10^12.

// Output: Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;
#define ll long long
string arr[100][100];
string s;

void dp(int n) {
    for(int i=1;i<n;i++) {
        for(int j=i;j<n;j++) {
            if(i==j) arr[i][j]=s[i];
            else {
                arr[i][j]=arr[i][j-1]+s[j];
            }
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        for(int i=0;i<100;i++) {
            for(int j=0;j<100;j++) arr[i][j]="#";
        }
        cin >>s;
        s='@'+s;
        int n=s.size();
        dp(n);

        ll sum=0;
        for(int i=1;i<n;i++) {
            for(int j=i;j<n;j++) sum+=stoll(arr[i][j]);
        }
        cout <<sum <<endl;
    }
    return 0;
}