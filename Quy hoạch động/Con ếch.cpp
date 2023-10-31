// Một con ếch có thể nhảy 1, 2, 3 bước để có thể lên đến một đỉnh cần đến. Hãy đếm số các cách con ếch có thể nhảy đến đỉnh.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là số n là số bước con ếch có thể lên được đỉnh.
// T, n thỏa mãn ràng buộc: 1≤T≤100;  1≤n ≤50.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;
long long f[100];

void sinh() {
    f[0]=1;
    for(int i=1;i<=50;i++) {
        for(int j=1;j<=3;j++) {
            if(i>=j) f[i]+=f[i-j];
        }
    }
}
int main() {
    int t;
    cin >>t;
    sinh();
    
    while(t--) {
        int n;
        cin >>n;

        cout <<f[n] <<endl;
    }
    return 0;
}