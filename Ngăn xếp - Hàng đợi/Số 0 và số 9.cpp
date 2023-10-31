// Cho số tự nhiên N. Hãy tìm số nguyên dương X nhỏ nhất được tạo bởi số 9 và số 0 chia hết cho N. Ví dụ với N = 5 ta sẽ tìm ra  X = 90.

// Input:
// Dòng đầu tiên ghi lại số lượng test T (T≤100).
// Những dòng kế tiếp mỗi dòng ghi lại một test. Mỗi test là một số tự nhiên N được ghi trên một dòng (N≤100).
// Output:
// Đưa ra theo từng dòng số X nhỏ nhất chia hết cho N tìm được .
#include <bits/stdc++.h>

using namespace std;
#define ll long long
vector<ll> v;
vector<ll> res;

void sinh() {   
    queue<string> q;
    q.push("9");
    v.push_back(9);

    while(1) {
        string top=q.front();
        if(top.size()==9) break;
        q.pop();
        q.push(top+"0");
        q.push(top+"9");
        v.push_back(stoll(top+"0"));
        v.push_back(stoll(top+"9"));
    }
    for(int i=1;i<=100;i++) {
        for(ll it : v) {
            if(it%i==0) {
                res.push_back(it);
                break;
            }
        }
    }
}
int main() {
    int t;
    cin >>t;
    sinh();

    while(t--) {
        int n;
        cin >>n;
        cout <<res[n-1] <<endl;
    }
    return 0;
}