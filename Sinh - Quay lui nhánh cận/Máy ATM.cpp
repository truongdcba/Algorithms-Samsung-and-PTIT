// Một máy ATM hiện có n (n ≤ 30) tờ tiền có giá trị t[1], t[2], …, t[n]. 
// Hãy tìm cách trả ít tờ nhất với số tiền đúng bằng S (các tờ tiền có giá trị bất kỳ và có thể bằng nhau, mỗi tờ tiền chỉ được dùng một lần).

// Input: Dòng đầu tiên ghi số bộ test T (T<10). Mỗi bộ test gồm 2 số nguyên n và S (S ≤ 109). Dòng thứ hai chứa n số nguyên t[1], t[2], …, t[n] (t[i] ≤ 109)
// Output: Với mỗi bộ test ghi ra số tờ tiền ít nhất phải trả.
// Nếu không thể tìm được kết quả, in ra -1.
#include <bits/stdc++.h>

using namespace std;
int n,s,arr[50];
int sum=0,res=1e9;

void Try(int i,int index) {
    for(int j=index;j<=n;j++) {
        if(sum+arr[j]<=s) {
            sum+=arr[j];
            if(sum==s) res=min(res,i);
            else Try(i+1,j+1);
            sum-=arr[j];
        }
        else return;
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        res=1e9;
        cin >>n >>s;
        for(int i=1;i<=n;i++) cin >>arr[i];
        sort(arr+1,arr+n+1,greater<int>());
        Try(1,1);
        if(res==1e9) cout <<-1 <<endl;
        else cout <<res <<endl;
    }
    return 0;
}