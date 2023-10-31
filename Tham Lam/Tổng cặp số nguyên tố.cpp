// Cho số tự nhiên N. Hãy tìm cặp số nguyên tố đầu tiên có tổng là N. Nếu không tồn tại cặp số nguyên tố có tổng bằng N, hãy đưa ra -1.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm là một số N được ghi trên một dòng.
// T, N thỏa mãn ràng buộc: 1≤T≤100; 1≤ N ≤10^6.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;
int f[1000001];
set<int> se;

void sang() {
    for(int i=0;i<=1000000;i++) {
        f[i]=1;
    }
    f[0]=f[1]=0;
    for(int i=2;i<=sqrt(1000000);i++) {
        if(f[i]) {
            for(int j=i*i;j<=1000000;j+=i) f[j]=0;
        }
    }
    for(int i=2;i<=1000000;i++) {
        if(f[i]) se.insert(i);
    }
}
void find(int n) {
    int check=0;
    for(int it : se) {
        if(se.find(n-it)!=se.end()) {
            cout <<it <<" " <<n-it <<endl;
            check=1;
            break;
        }
        if(it>n) break;
    }
    if(check==0) cout <<-1 <<endl;
}
int main() {
    int t;
    cin >>t;
    sang();

    while(t--) {
        int n;
        cin >>n;
        find(n);
    }
    return 0;
}