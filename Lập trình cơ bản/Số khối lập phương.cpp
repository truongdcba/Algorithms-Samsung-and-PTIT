// Một số X được gọi là số khối lập phương nếu X là lũy thừa bậc 3 của số Y (X= Y^3). 
//Cho số nguyên dương N, nhiệm vụ của bạn là tìm số khối lập phương lớn nhất bằng cách loại bỏ đi các chữ số của N. 
//Ví dụ số 4125 ta có kết quả là 125 = 5^3.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
// T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤10^18.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng. Nếu không tìm được đáp án in ra -1.
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
set<ll> se;
string s;
ll tmp=0,maxValue=-1;
int x[20];

void sang() {
    for(int i=1;i<=1000000;i++) {
        se.insert(1ll*i*i*i);
    }
}
void Try(int i) {
    for(int j=0;j<=1;j++) {
        x[i]=j;
        if(i==s.size()-1) {
            for(int j=0;j<=i;j++) {
                if(x[j]) tmp=tmp*10+stoi(string(1,s[j]));
            }
            if(se.find(tmp)!=se.end()) maxValue=max(maxValue,tmp);
            tmp=0;
        }
        else Try(i+1);
    }
}
int main() {
    int t;
    cin >>t;
    sang();

    while(t--) {
        memset(x,0,sizeof(x));
        maxValue=-1;
        cin >>s;
        Try(0);
        cout <<maxValue <<endl;
    }
    return 0;
}