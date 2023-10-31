// Cho N cột, mỗi cột có chiều cao bằng H[i]. Bạn hãy tìm hình chữ nhật lớn nhất bị che phủ bởi các cột?

// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test bắt đầu bởi số nguyên N (N ≤ 100 000).
// Dòng tiếp theo gồm N số nguyên H[i] (1 ≤ H[i] ≤ 109).

// Output: 
// Với mỗi test, in ra diện tích hình chữ nhật lớn nhất tìm được.
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void leftElement(int n,int arr[],int left[]) {
    stack<int> st;

    for(int i=n-1;i>=0;i--) {
        while(!st.empty() && arr[i]<arr[st.top()]) {
            left[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        left[st.top()]=-1;
        st.pop();
    }
}
void rightElement(int n,int arr[],int right[]) {
    stack<int> st;

    for(int i=0;i<n;i++) {
        while(!st.empty() && arr[i]<arr[st.top()]) {
            right[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        right[st.top()]=n;
        st.pop();
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        int arr[n];

        for(int &x : arr) cin >>x;
        int left[n], right[n];
        leftElement(n,arr,left);
        rightElement(n,arr,right);

        ll res=-1;
        for(int i=0;i<n;i++) {
            int width=right[i]-left[i]-1;
            ll tmp=1ll*arr[i]*width;
            res=max(res,tmp);
        }
        cout <<res <<endl;
    }
    return 0;
}