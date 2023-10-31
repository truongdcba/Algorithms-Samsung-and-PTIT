// Ta gọi số nguyên dương K là một số BDN nếu các chữ số trong K chỉ bao gồm các 0 hoặc 1 có nghĩa. Ví dụ số K = 1, 10, 101. Cho số tự nhiên N (N<231). Hãy cho biết có bao nhiêu số BDN không lớn hơn N. Ví dụ N=100 ta có 4 số BDN bao gồm các số: 1, 10, 11, 100.
// Dữ liệu vào: Dòng đầu tiên ghi lại số tự nhiên T (T ≤ 50) là số lượng bộ test.
// T dòng kế tiếp mỗi dòng là một số tự nhiên N (1 ≤ N ≤ 231).
// Kết quả: Với mỗi số N in ra kết quả trên một dòng là số các số BDN không lớn hơn N.
#include <bits/stdc++.h>

using namespace std;
#define ll long long
vector<ll> v;

void sinh() {
    queue<string> q;
    q.push("1");
    v.push_back(1);

    while(!q.empty()) {
        string top=q.front();
        q.pop();
        if(top.size()==11) break;
        q.push(top+"0");
        q.push(top+"1");
        v.push_back(stoll(top+"0"));
        v.push_back(stoll(top+"1"));
    }
}
int main() {
    int t;
    cin >>t;
    sinh();

    while(t--) {
        ll n;
        cin >>n;

        auto it=upper_bound(v.begin(),v.end(),n);
        cout <<it-v.begin() <<endl;
    }
    return 0;
}