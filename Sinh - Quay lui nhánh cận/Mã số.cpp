// Số lượng máy tính ở các phòng thực hành nhà A3 tăng lên nhanh chóng. Để gán mã cho các máy tính của PTIT người ta sử dụng mã gồm 2*N ký tự, trong đó:

// N ký tự đầu tiên là hoán vị của N chữ cái in hoa đầu tiên, tính từ A.
// N ký tự tiếp theo là các ký tự số bất kỳ từ 1 đến N (có thể trùng nhau).
// Người ta ước tính chỉ cần N = 5 là đủ để gán mã cho toàn bộ máy tính kể cả khi mở rộng quy mô các phòng thực hành. Hãy viết chương trình liệt kê các mã tạo được với giá trị N cho trước.

// Input
// Chỉ có duy nhất số N (1 < N < 6)
// Output
// Ghi ra lần lượt các mã khác nhau tạo được theo thứ tự từ điển, mỗi mã ghi trên một dòng
#include <bits/stdc++.h>

using namespace std;
int n;
string num,alp,s="ABCDE";
vector<string> number,alpha,res;
bool visited[10];

void TryNumber(int i) {
    for(int j=1;j<=n;j++) {
        num+=to_string(j);
        if(i==n) {
            number.push_back(num);
        }
        else TryNumber(i+1);
        num.pop_back();
    }
}
void Try(int i) {
    for(int j=0;j<n;j++) {
        if(!visited[j]) {
            alp+=s[j];
            visited[j]=true;
            if(i==n) {
                for(string x : number) {
                    string tmp=alp+x;
                    res.push_back(tmp);
                }
            }
            else Try(i+1);
            alp.pop_back();
            visited[j]=false;
        }
    }
}
int main() {
    cin >>n;
    TryNumber(1);
    Try(1);

    for(string x : res) cout <<x <<endl;
    return 0;
}