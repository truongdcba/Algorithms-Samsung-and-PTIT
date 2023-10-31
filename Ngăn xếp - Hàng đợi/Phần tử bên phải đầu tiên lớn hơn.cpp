// Cho dãy số A[] gồm N phần tử. Với mỗi A[i], bạn cần tìm phần tử bên phải đầu tiên lớn hơn nó. Nếu không tồn tại, in ra -1.
// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test bắt đầu bởi số nguyên N (1 ≤ N ≤ 100000).
// Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 109).
// Output: 
// Với mỗi test, in ra trên một dòng N số R[i], với R[i] là giá trị phần tử đầu tiên lớn hơn A[i].
#include <bits/stdc++.h>

using namespace std;
int f[100001];

void find(int n,int arr[]) {
    stack<int> st;

    for(int i=0;i<n;i++) {
        if(st.empty()) st.push(i);
        else {
            while(!st.empty() && arr[i]>arr[st.top()]) {
                f[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()) {
        f[st.top()]=-1;
        st.pop();
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(f,0,sizeof(f));
        int n;
        cin >>n;
        int arr[n];

        for(int &x : arr) cin >>x;
        find(n,arr);
        for(int i=0;i<n;i++) cout <<f[i] <<" ";
        cout <<endl;
    }
    return 0;
}