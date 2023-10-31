// Cho ba số N, P, S. Trong đó, P là một số nguyên tố. Nhiệm vụ của bạn là đưa ra tất cả N số nguyên tố tính từ P có tổng bằng S. 
// Ví dụ với S = 28, P=7, N =2 ta có kết quả 11 + 17 = 28. Với N = 3, P = 2, S = 23 ta có kết quả : {3, 7, 13}, {5, 7, 11}

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ ba số S, P, N được viết trên một dòng.
// S, P, N thỏa mãn ràng buộc: 1≤T ≤100; 1 ≤ N ≤ 10; 2≤S, P≤200.
// Output:
// Với mỗi test, dòng đầu tiên in ra số lượng đáp án tìm được. Mỗi dòng tiếp theo in ra kết quả tìm được theo thứ tự từ điển.
#include <bits/stdc++.h>

using namespace std;
int n,p,s;
int f[400];
vector<vector<int>> v;
vector<int> tmp;
int sum=0;

void sang() {
    for(int i=0;i<=200;i++) f[i]=1;
    f[0]=f[1]=0;
    for(int i=2;i<=sqrt(200);i++) {
        if(f[i]) {
            for(int j=i*i;j<=200;j+=i) f[j]=0;
        }
    }
}
void Try(int i,int index) {
    for(int j=index+1;j<s;j++) {
        if(f[j]) {
            sum+=j;
            tmp.push_back(j);
            if(i==n && sum==s) v.push_back(tmp);
            else if(i<n && sum<s) Try(i+1,j+1);
            sum-=j;
            tmp.pop_back();
        }
    }
}
int main() {
    int t;
    cin >>t;
    sang();

    while(t--) {
        v.clear();
        cin >>n >>p >>s;
        Try(1,p);

        cout <<v.size() <<endl;
        for(auto it : v) {
            for(auto x : it) cout <<x <<" ";
            cout <<endl;
        }
    } 
    return 0;
}