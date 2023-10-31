// Cho mảng A[] gồm N số nguyên dương phân biệt và số X. Nhiệm vụ của bạn là tìm phép tổ hợp các số trong mảng A[] có tổng bằng X. Các số trong mảng A[] có thể được sử dụng nhiều lần. 
// Mỗi tổ hợp các số của mảng A[] được in ra theo thứ tự không giảm các số. 
// Ví dụ với A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số như sau:
// [2, 2, 2, 2], [2, 2, 4], [2, 6], [4, 4], [8].
// Input:
// · Dòng đầu tiên đưa vào số lượng bộ test T.
// · Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số N và X; dòng tiếp theo đưa vào N số của mmảng A[]; các số được viết cách nhau một vài khoảng trống.
// · T, N, X, A[i] thỏa mãn ràng buộc: 1≤T ≤10; 1≤X, A[i]≤100. N ≤ 20.
// Output:
// · Đưa ra kết quả mỗi test theo từng dòng. Mỗi đường tổ hợp được bao bởi cặp ký tự [, ]. Đưa ra -1 nếu không có tổ hợp nào thỏa mãn yêu cầu bài toán.
#include <bits/stdc++.h>

using namespace std;
int n,x,arr[30];
vector<vector<int>> v;
vector<int> tmp;
int sum=0;

void Try(int i,int index) {
    for(int j=index;j<=n;j++) {
        sum+=arr[j];
        tmp.push_back(arr[j]);
        if(sum==x) {
            v.push_back(tmp);
        }
        else if(sum<x) Try(i+1,j);
        sum-=arr[j];
        tmp.pop_back();
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        v.clear();
        cin >>n >>x;
        for(int i=1;i<=n;i++) cin >>arr[i];     
        sort(arr+1,arr+n+1);   
        Try(1,1);

        if(v.empty()) cout <<-1;
        else {
            for(auto it : v) {
                cout <<"[";
                for(int i=0;i<it.size();i++) {
                    if(i!=it.size()-1) cout <<it[i] <<" ";
                    else cout <<it[i];
                }
                cout <<"]";
            }
        }
        cout <<endl;
    }
    return 0;
}