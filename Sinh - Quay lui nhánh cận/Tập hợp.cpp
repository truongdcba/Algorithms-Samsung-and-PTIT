// Xét tất cả các tập hợp các số nguyên dương có các phần tử khác nhau và không lớn hơn số n cho trước. 
// Nhiệm vụ của bạn là hãy đếm xem có tất cả bao nhiêu tập hợp có số lượng phần tử bằng k và tổng của tất cả các phần tử trong tập hợp bằng s?

// Các tập hợp là hoán vị của nhau chỉ được tính là một.
// Ví dụ với n = 9, k = 3, s = 23, {6, 8, 9} là tập hợp duy nhất thỏa mãn.
// Input:  Gồm nhiều bộ test (không quá 100 test).
// Mỗi bộ test gồm 3 số nguyên n, k, s với 1 ≤ n ≤ 20, 1 ≤ k ≤ 10 và 1 ≤ s ≤ 155. Input kết thúc bởi 3 số 0.
// Output:  Với mỗi test in ra số lượng các tập hợp thỏa mãn điều kiện đề bài.

#include <bits/stdc++.h>

using namespace std;
int n,k,s;
int sum=0,dem=0;

void Try(int i,int index) {
    for(int j=index;j<=n;j++) {
        sum+=j;
        if(i==k && sum==s) dem++;
        else if(i<k && sum<s) Try(i+1,j+1);
        sum-=j;
    }
}
int main() {
    while(cin >>n >>k >>s) {
        if(n==0 && k==0 && s==0) break;
        dem=0;
        Try(1,1);
        cout <<dem <<endl;
    }
    return 0;
}