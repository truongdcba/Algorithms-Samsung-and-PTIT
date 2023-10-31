// Cho n thành phố đánh số từ 1 đến n và các tuyến đường giao thông hai chiều giữa chúng, mạng lưới giao thông này được cho bởi mảng C[1…n, 1…n].
// Ở đây C[i][j] = C[j][i] là chi phí đi đoạn đường trực tiếp từ thành phố i đến thành phố j.
// Một người du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi thành phố đúng 1 lần và cuối cùng quay lại thành phố 1. Hãy chỉ ra chi phí ít nhất mà người đó phải bỏ ra.
// Dữ liệu vào: Dòng đầu tiên là số nguyên n – số thành phố (n ≤ 15); n dòng sau, mỗi dòng chứa n số nguyên thể hiện cho mảng 2 chiều C.
// Kết quả: Chi phí mà người đó phải bỏ ra.
#include <bits/stdc++.h>

using namespace std;
int n,arr[20][20],x[20];
bool visited[20];
int sum=0,cost=1e9,cmin=1e9;

void Try(int i) {
    for(int j=2;j<=n;j++) {
        if(!visited[j]) {
            x[i]=j;
            sum+=arr[x[i-1]][x[i]];
            visited[j]=true;
            if(i==n) {
                cost=min(cost,sum+arr[x[n]][1]);
            }
            else if(sum+(n-i+1)*cmin<cost) Try(i+1);
            sum-=arr[x[i-1]][x[i]];
            visited[j]=false;
        }
    }
}
int main() {
    cin >>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >>arr[i][j];
            if(arr[i][j]) cmin=min(cmin,arr[i][j]);
        }
    }
    x[1]=1;
    Try(2);
    cout <<cost;
    return 0;
}