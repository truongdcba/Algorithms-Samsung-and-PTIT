// Cho một bảng kích thước NxM, được chia thành lưới ô vuông đơn vị N dòng M cột. 
// Trên các ô của bảng ghi số 0 hoặc 1. 
// Các dòng của bảng được đánh số 1, 2... N theo thứ tự từ trên xuống dưới và các cột của bảng được đánh số 1, 2..., M theo thứ tự từ trái qua phải

// Yêu cầu: Hãy tìm một hình chữ nhật gồm các ô của bảng thoả mãn các điều kiện sau:
// 1 - Hình chữ nhật đó chỉ gồm các số 1
// 2 - Cạnh hình chữ nhật song song với cạnh bảng
// 3 - Diện tích hình chữ nhật là lớn nhất có thể
// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test bắt đầu bởi hai số nguyên N và M (1 ≤ M, N ≤ 500).
// N dòng tiếp theo, mỗi dòng gồm M số nguyên 0 hoặc 1.
// Output: 
// Với mỗi test, in ra diện tích hình chữ nhật lớn nhất tìm được.
#include <bits/stdc++.h>

using namespace std;
int arr[505][505];
int height[505],L[505],R[505];

void left(int m);
void right(int n,int m);
int findMax(int n,int m);

int main() {
    int t;
    cin >>t;

    while(t--) {
        memset(height,0,sizeof(height));
        int n,m;
        cin >>n >>m;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) cin >>arr[i][j];
        }
        cout <<findMax(n,m) <<endl;
    }
    return 0;
}
int findMax(int n,int m) {
    int maxValue=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(arr[i][j]) height[j]++;
            else height[j]=0;
        }
        left(m);
        right(n,m);
        for(int j=1;j<=m;j++) {
            if(height[j]) {
                int width=R[j]-L[j]-1;
                maxValue=max(maxValue,width*height[j]);
            }
        }
    }
    return maxValue;
}
void left(int m) {
    stack<int> st;
    for(int i=m;i>=1;i--) {
        while(!st.empty() && height[i]<height[st.top()]) {
            L[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        L[st.top()]=0;
        st.pop();
    }
}
void right(int n,int m) {
    stack<int> st;
    for(int i=1;i<=m;i++) {
        while(!st.empty() && height[i]<height[st.top()]) {
            R[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        R[st.top()]=m+1;
        st.pop();
    }
}