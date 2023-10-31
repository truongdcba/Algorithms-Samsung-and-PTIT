// Một xâu nhị phân được gọi là xen kẽ nếu giá trị 0 ở ngay bên cạnh giá trị 1 và không có hai giá trị nào bằng nhau ở cạnh nhau. 
// Hãy viết chương trình liệt kê các xâu nhị phân xen kẽ có độ dài N.

// Input
// Chỉ có một dòng ghi số N (2 ≤ N ≤ 1000)
// Output
// Ghi ra các xâu nhị phân xen kẽ, mỗi xâu trên một dòng.
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >>n;

    for(int i=1;i<=n;i++) {
        if(i%2!=0) cout <<0 <<" ";
        else cout <<1 <<" ";
    }
    cout <<endl;
    for(int i=1;i<=n;i++) {
        if(i%2!=0) cout <<1 <<" ";
        else cout <<0 <<" ";
    }
}