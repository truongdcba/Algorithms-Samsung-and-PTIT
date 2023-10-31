// Cho mảng A[] gồm các số từ 0 đến 9. Nhiệm vụ của bạn là tìm tổng nhỏ nhất của hai số được tạo bởi các số trong mảng A[]. 
// Chú ý, tất cả các số trong mảng A[] đều được sử dụng để tạo nên hai số.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số phần tử của mảng N; dòng tiếp theo đưa vào N số A[i] tương ứng với các phần tử của mảng A[]; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤20; 0≤A[i]≤9.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        int arr[n];
        for(int &x : arr) cin >>x;
        sort(arr,arr+n);

        long long num1=0,num2=0;
        for(int i=0;i<n;i++) {
            if(i%2==0) num1=num1*10+arr[i];
            else num2=num2*10+arr[i];
        }
        cout <<num1+num2 <<endl;
    }
    return 0;
}