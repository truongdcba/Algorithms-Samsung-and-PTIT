// Ma trận kề A của một đồ thị vô hướng là một ma trận chỉ có các số 0 hoặc 1 trong đó A[i][j] = 1 có ý nghĩa là đỉnh i kề với đỉnh j (chỉ số tính từ 1).

// Danh sách kề thì liệt kê các đỉnh kề với đỉnh đó theo thứ tự tăng dần.
// Hãy chuyển biểu diễn đồ thị từ dạng ma trận kề sang dạng danh sách kề.
// Input: Dòng đầu tiên chứa số nguyên n – số đỉnh của đồ thị (1 < n ≤ 1000). n dòng tiếp theo, mỗi dòng có n số nguyên có giá trị 0 và 1 mô tả ma trận kề của đồ thị.
// Output:  Gồm n dòng, dòng thứ i chứa các số nguyên là đỉnh có nối với đỉnh i và được sắp xếp tăng dần. Dữ liệu đảm bảo mỗi đỉnh có kết nối với ít nhất 1 đỉnh khác.
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >>n;
    int arr[n+1][n+1];

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) cin >>arr[i][j];
    }
    vector<int> d[1001];
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++) {
            if(arr[i][j]) {
                d[i].push_back(j);
                d[j].push_back(i);
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(auto it : d[i]) cout <<it <<" ";
        cout <<endl;
    }
}