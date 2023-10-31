// Cho cặp số S và T là các số nguyên tố có 4 chữ số (Ví dụ S = 1033, T = 8197 là các số nguyên tố có 4 chữ số). Hãy viết chương trình tìm cách dịch chuyển S thành T thỏa mãn đồng thời những điều kiện dưới đây:
// Mỗi phép dịch chuyển chỉ được phép thay đổi một chữ số của số ở bước trước đó (ví dụ nếu S=1033 thì phép dịch chuyển S thành 1733 là hợp lệ);
// Số nhận được cũng là một số nguyên tố có 4 chữ số (ví dụ nếu S=1033 thì phép dịch chuyển S thành 1833 là không hợp lệ, và S dịch chuyển thành 1733 là hợp lệ);
// Số các bước dịch chuyển là ít nhất.
// Ví dụ số các phép dịch chuyển ít nhất để S = 1033 thành  T = 8179 là 6 bao gồm các phép dịch chuyển như sau:       
// 8179 8779 3779 3739 3733 1733 1033.
// Input:
// Dòng đầu tiên đưa vào số lượng test T (T≤100)
// Những dòng kế tiếp mỗi dòng đưa vào một test. Mỗi test là một bộ đôi S, T.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;
int f[10000];
set<int> se;
bool visited[10000];

void sang() {
    for(int i=0;i<=10000;i++) f[i]=1;
    f[0]=f[1]=0;
    for(int i=2;i<=sqrt(10000);i++) {
        if(f[i]) {
            for(int j=i*i;j<=10000;j+=i) f[j]=0;
        }
    }
    for(int i=1000;i<=9999;i++) {
        if(f[i]) se.insert(i);
    }
}
bool check(int a,int b) {
    int dem=0;
    while(a) {
        if(a%10!=b%10) dem++;
        a/=10;
        b/=10;
        if(dem>1) return false;
    }
    return true;
}
int convert_s_to_t(int s,int t) {
    queue<pair<int,int>> q;
    q.push({s,0});
    visited[s]=true;
    
    while(!q.empty()) {
        pair<int,int> top=q.front();
        q.pop();

        if(top.first==t) return top.second;
        for(int it : se) {
            if(check(top.first,it) && !visited[it]) {
                q.push({it,top.second+1});
                visited[it]=true;
            }
        }
    }
}
int main() {
    int q;
    cin >>q;
    sang();

    while(q--) {
        memset(visited,0,sizeof(visited));
        int s,t;
        cin >>s >>t;
        cout <<convert_s_to_t(s,t) <<endl;
    }
    return 0;
}