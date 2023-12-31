// Một dãy xâu ký tự G chỉ bao gồm các chữ cái A và B được gọi là dãy xâu Fibonacci nếu thỏa mãn tính chất: G(1) = A; G(2) = B; G(n) = G(n-2)+G(n-1). 
// Với phép cộng (+) là phép nối hai xâu với nhau.  Bài toán đặt ra là tìm ký tự ở vị trí thứ i (tính từ 1) của xâu Fibonacci thứ n.

// Dữ liệu vào: Dòng 1 ghi số bộ test. Mỗi bộ test ghi trên một dòng 2 số nguyên N và i (1<N<93). 
// Số i đảm bảo trong phạm vi của xâu G(N) và không quá 18 chữ số. Kết quả: Ghi ra màn hình kết quả tương ứng với từng bộ test.
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll f[100];

void sinhFibo() {
    f[1]=f[2]=1;
    for(int i=3;i<=92;i++) {
        f[i]=f[i-1]+f[i-2];
    }    
}
char find(int n,ll k) {
    if(n==1) return 'A';
    if(n==2) return 'B';
    else {
        if(k<=f[n-2]) return find(n-2,k);
        else return find(n-1,k-f[n-2]);
    }
}
int main() {
    int t;
    cin >>t;
    sinhFibo();

    while(t--) {
        int n;
        ll k;
        cin >>n >>k;
        cout <<find(n,k) <<endl;
    }
    return 0;
}