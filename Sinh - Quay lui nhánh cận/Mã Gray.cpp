// Số nhị phân được xem là cách mặc định biểu diễn các số. Tuy nhiên, trong nhiều ứng dụng của điện tử và truyền thông lại dùng một biến thể của mã nhị phân đó là mã Gray. Mã Gray độ dài n có mã đầu tiên là n số 0, mã kế tiếp của nó là một xâu nhị phân độ dài n khác biệt với xâu trước đó một bít. Ví dụ với n=3 ta có 23 mã Gray như sau: 000, 001, 011, 010, 110, 111, 101, 100. Hãy viết chương trình liệt kê các mã Gray có độ dài n.

// Input: Dòng đầu tiên là số lượng test T. T dòng kế tiếp ghi lại mỗi dòng một test. Mỗi test là một số tự nhiên n. T, n thỏa mãn ràng buộc: 1≤T, n≤10.

// Output: Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;
int n,arr[20];

void khoiTao() {
    for(int i=1;i<=n;i++) arr[i]=0;
}
void sinhNhiPhan(int &ok) {
    int i=n;
    while(i>=1 && arr[i]==1) {
        arr[i]=0;
        i--;
    }
    if(i==0) ok=0;
    else arr[i]=1;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        cin >>n;
        int f[20],ok=1;
        khoiTao();

        while(ok) {
            f[1]=arr[1];
            cout <<f[1];
            for(int i=2;i<=n;i++) {
                f[i]=arr[i-1]^arr[i];
                cout <<f[i];
            }
            cout <<" ";
            sinhNhiPhan(ok);
        }
        cout <<endl;
    }
    return 0;
}