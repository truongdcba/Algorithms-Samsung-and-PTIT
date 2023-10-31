// Cho hai mảng đã được sắp xếp A[], B[] gồm M, N phần tử theo thứ tự và số K. 
// Nhiệm vụ của bạn là tìm phần tử ở vị trí số K sau khi trộn hai mảng để nhận được một mảng được sắp xếp.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào số M, N, K; 
// dòng tiếp theo đưa vào M số của mảng A[];dòng tiếp theo đưa vào N số của mảng B[];các số được viết cách nhau một vài khoảng trống.
// T, M,N, A[i], B[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N, A[i], B[i]≤10^6; 1≤ K≤N+M.
// Output:
// Đưa ra giá trị phần tử thứ K của mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;
vector<int> v;

void merge(int n,int m,int a1[],int a2[]) {
    int i=0,j=0;
    while(i<n && j<m) {
        if(a1[i]<=a2[j]) {
            v.push_back(a1[i]);
            i++;
        }
        else {
            v.push_back(a2[j]);
            j++;
        }
    }
    while(i<n) {
        v.push_back(a1[i]);
        i++;
    }
    while(j<m) {
        v.push_back(a2[j]);
        j++;
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        v.clear();
        int n,m,k;
        cin >>n >>m >>k;
        int a1[n],a2[m];

        for(int &x : a1) cin >>x;
        for(int &x : a2) cin >>x;
        merge(n,m,a1,a2);

        cout <<v[k-1] <<endl;
    }
    return 0;
}