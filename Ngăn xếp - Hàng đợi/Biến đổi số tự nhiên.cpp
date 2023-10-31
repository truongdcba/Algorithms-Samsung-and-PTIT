// Cho số tự nhiên N (N<10^9) và hai phép biến đổi (a), (b) dưới đây.

// Thao tác (a): Trừ N đi 1 (N=N-1). Ví dụ N=17, thao tác (a) biến đổi N = N-1 =16.
// Thao tác (b): N = max(u,v) nếu u*v =N (u>1, v>1). Ví dụ N=16, thao tác (b) có thể biến đổi N = max(2, 8)=8 hoặc N=max(4, 4)=4.
// Chỉ được phép sử dụng hai thao tác (a) hoặc (b), hãy biến đổi N thành 1 sao số các thao tác (a), (b) được thực hiện ít nhất. Ví dụ với N=17, số các phép (a), (b) nhỏ nhất biến đổi N thành 1 là 4 bước như sau:

// Thao tác (a): N = N-1 = 17-1 = 16

// Thao tác (b): 16 = max(4,4) = 4

// Thao tác (b): 4 = max(2,2) = 2

// Thao tác (a): 2 = 2-1 = 1                                    

// Input:
// Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test;
// T dòng kế tiếp mỗi dòng ghi lại một bộ Test. Mỗi test là một số N.
#include <bits/stdc++.h>

using namespace std;

int convert(int n) {
    queue<pair<int,int>> q;
    q.push({n,0});
    set<int> se;
    se.insert(n);

    while(!q.empty()) {
        pair<int,int> top=q.front();
        q.pop();
        if(top.first==1) return top.second;

        if(se.find(top.first-1)==se.end() && top.first>1) {
            q.push({top.first-1,top.second+1});
            se.insert(top.first-1);
        }
        for(int i=2;i<=sqrt(top.first);i++) {
            if(top.first%i==0 && se.find(max(i,top.first/i))==se.end()) { 
                q.push({max(i,top.first/i),top.second+1});
                se.insert(max(i,top.first/i));
            }
        }
    }
    return 1;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        cout <<convert(n) <<endl;
    }
    return 0;
}