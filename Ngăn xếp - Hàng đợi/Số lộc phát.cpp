// Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. Cho số tự nhiên N. Hãy liệt kê các số lộc phát có không quá N chữ số.
// Input:
// Dòng đầu tiên ghi lại số tự nhiên T là số lượng bộ test (T<10);
// T dòng kế tiếp mỗi dòng ghi số N (1<N<15).
// Output:
// Dòng đầu tiên là số lượng số lộc phát tìm được. Dòng thứ hai in ra đáp án theo thứ tự giảm dần.

#include <bits/stdc++.h>

using namespace std;
vector<string> v;

void sinh(int n) {
    queue<string> q;
    q.push("6");
    q.push("8");
    v.push_back("6");
    v.push_back("8");

    while(!q.empty()) {
        string top=q.front();
        if(top.size()==n) break;
        q.pop();
        q.push(top+"6");
        q.push(top+"8");
        v.push_back(top+"6");
        v.push_back(top+"8");
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        v.clear();
        int n;
        cin >>n;
        sinh(n);

        cout <<v.size() <<endl;
        for(int i=v.size()-1;i>=0;i--) {
            cout <<v[i] <<" ";
        }
        cout <<endl;
    }
    return 0;
}