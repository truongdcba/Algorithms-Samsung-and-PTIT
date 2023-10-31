// Cho mảng A[] gồm n số nguyên khác nhau. Hãy đưa ra các phần tử của mảng theo khuôn dạng lớn nhất, nhỏ nhất, lớn thứ hai, nhỏ thứ 2, … 
// Ví dụ với A[] = {9, 7, 12, 8, 6, 5} ta đưa ra : 12, 5, 9, 6, 8, 7.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên là số phần tử của mảng n; 
// dòng tiếp theo là n số A [i] của mảng A [];các số được viết cách nhau một vài khoảng trống.
// T, n thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤10^3.
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

        int l=0,r=n-1;
        while(l<r) {
            cout <<arr[r] <<" " <<arr[l] <<" ";
            l++;
            r--;
        }
        if(n%2!=0) cout <<arr[l];
        cout <<endl;
    }
}