// Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một. Hãy sắp xếp dãy theo thứ tự giảm dần, sau đó liệt kê tất cả các dãy con của A[] có tổng các phần tử là số nguyên tố.
// Input
// Dòng đầu ghi số bộ test, mỗi test có 2 dòng:
// Dòng đầu ghi số N (2 < N <15)
// Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, nhỏ hơn 100 và khác nhau từng đôi một.
// Output
// Với mỗi test, liệt kê tất cả các dãy con có tổng các phần tử là số nguyên tố theo, mỗi dãy con trên một dòng. 
#include <bits/stdc++.h>

using namespace std;
int n,sum=0,f[1500];
int arr[20];
vector<vector<int>> v;
vector<int> tmp;

void sang() {
    for(int i=0;i<=1500;i++) f[i]=1;
    f[0]=f[1]=0;
    for(int i=2;i<=sqrt(1500);i++) {
        if(f[i]) {
            for(int j=i*i;j<=1500;j+=i) f[j]=0;
        }
    }
}
void Try(int index) {
    for(int j=index;j<=n;j++) {
        sum+=arr[j];
        tmp.push_back(arr[j]);
        if(f[sum]) {
            v.push_back(tmp);
        }
        Try(j+1);
        sum-=arr[j];
        tmp.pop_back();
    }
}
int main() {
    int t;
    cin >>t;
    sang();

    while(t--) {
        v.clear();
        cin >>n;
        for(int i=1;i<=n;i++) cin >>arr[i];
        sort(arr+1,arr+n+1,greater<int>());

        Try(1);
        sort(v.begin(),v.end());
        for(auto it : v) {
            for(int i=0;i<it.size();i++) {
                cout <<it[i] <<" ";
            }
            cout <<endl;
        }
    }
    return 0;
}