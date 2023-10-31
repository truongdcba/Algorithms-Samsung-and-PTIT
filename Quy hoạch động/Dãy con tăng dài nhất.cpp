// Cho một dãy số nguyên gồm N phần tử A[1], A[2], ... A[N]. 
// Biết rằng dãy con tăng là 1 dãy A[i1],... A[ik]
// thỏa mãn i1 < i2 < ... < ik và A[i1] < A[i2] < .. < A[ik].
// Hãy cho biết dãy con tăng dài nhất của dãy này có bao nhiêu phần tử? 
// Input: Dòng 1 gồm 1 số nguyên là số N (1 ≤ N ≤ 1000). Dòng thứ 2 ghi N số nguyên A[1], A[2], .. A[N] (1 ≤ A[i] ≤ 1000). 
// Output: Ghi ra độ dài của dãy con tăng dài nhất.
#include <bits/stdc++.h>

using namespace std;
int f[1001];

int main() {
    int n;
    cin >>n;
    int arr[n];

    for(int &x : arr) cin >>x;
    for(int i=0;i<n;i++) {
        f[i]=1; //dãy con tăng dài nhất có 1 phần tử là chính nó
        for(int j=0;j<i;j++) {
            if(arr[j]<arr[i]) {
                f[i]=max(f[i],f[j]+1);
            }
        }
    }
    cout <<*max_element(f,f+n);
    return 0;
}