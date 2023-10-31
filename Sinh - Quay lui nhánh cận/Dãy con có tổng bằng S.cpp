// Cho dãy số A[] có n phần tử và số nguyên dương S. Hãy tìm dãy con có ít phần tử nhất của A[] có tổng các phần tử đúng bằng S.

// Input
// Dòng đầu ghi hai số n và S. (n ≤ 30; S  ≤  10^9).
// Dòng thứ 2 ghi n số của dãy A[], các số đều nguyên dương và không quá 9 chữ số.
// Output
// Ghi ra độ dài của dãy con ngắn nhất có tổng bằng S.
// Nếu không có kết quả đúng thì ghi ra -1

#include <bits/stdc++.h>

using namespace std;
int n,s,arr[50];
int sum=0,length=1e9;

void Try(int i,int index) {
    for(int j=index;j<=n;j++) {
        sum+=arr[j];
        if(sum==s) length=min(length,i);
        else if(i<length && sum<s) Try(i+1,j+1);
        sum-=arr[j];
    }
}
int main() {
    cin >>n >>s;
    for(int i=1;i<=n;i++) {
        cin >>arr[i];
    }
    Try(1,1);
    if(length==1e9) cout <<-1;
    else cout <<length;
    return 0;
}