// Cho dãy A[] có N số nguyên, mỗi số có đúng K chữ số (có thể có chữ số 0 ở đầu). 
// Gọi độ chênh lệch của dãy là hiệu giữa phần tử lớn nhất và bé nhất của dãy.
// Bạn có thể hoán vị các chữ số của một số để tạo số mới (có thể có chữ số 0 ở đầu). 
// Bằng cách hoán vị tất cả n số theo cùng một cách, ta nhận được dãy số mới.
// Tìm độ chênh lệch nhỏ nhất có thể tạo được.

// Input:
// Dòng đầu chứa 2 số N và K. (1 ≤ N, K ≤ 8)
// N dòng sau, mỗi dòng chứa 1 số nguyên có K chữ số.
// Output:
// Độ chênh lệch nhỏ nhất tìm được.
#include <iostream>

using namespace std;
int n,k,x[10]; //mảng x lưu hoán vị các vị trí từ 1 -> k
string arr[10];
bool visited[10];
int res=1e9;

void find() {
    int minValue=1e9, maxValue=0;
    for(int i=0;i<n;i++) {
        int tmp=0;
        for(int j=1;j<=k;j++) {
            tmp=tmp*10+stoi(string(1,arr[i][x[j]-1]));
        }
        minValue=min(minValue,tmp);
        maxValue=max(maxValue,tmp);
    }
    res=min(res,maxValue-minValue);
}
void Try(int i) {
    for(int j=1;j<=k;j++) {
        if(!visited[j]) {
            x[i]=j;
            visited[j]=true;
            if(i==k) {
                find();
            }
            else Try(i+1);
            visited[j]=false;
        }
    }
}
int main() {
    cin >>n >>k;
    for(int i=0;i<n;i++) cin >>arr[i];
    Try(1);
    cout <<res;
    return 0;
}