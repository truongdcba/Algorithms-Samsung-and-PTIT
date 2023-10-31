// Trong một buổi học toán, giáo viên viết 2 số nguyên, A và B, và yêu cầu Tèo thực hiện phép cộng. 
// Tèo không bao giờ tính toán sai, nhưng thỉnh thoảng cậu ta chép các con số một cách không chính xác. 
// Lỗi duy nhất của là ghi nhầm '5' thành '6' hoặc ngược lại.  Cho hai số, A và B, tính tổng nhỏ nhất và lớn nhất mà Tèo có thể nhận được.

// Input: Có một dòng chứa hai số nguyên dương A và B ( 1 ≤ A, B ≤ 1 000 000).

// Output: In ra 2 số nguyên cách nhau một dấu cách, tổng nhỏ nhất và lớn nhất có thể nhận được.
#include <bits/stdc++.h>

using namespace std;

int minValue(string s1,string s2) {
    for(int i=0;i<s1.size();i++) {
        if(s1[i]=='6') s1[i]='5';
    }
    for(int i=0;i<s2.size();i++) {
        if(s2[i]=='6') s2[i]='5';
    }
    int num1=stoi(s1),num2=stoi(s2);
    return num1+num2;
}
int maxValue(string s1,string s2) {
    for(int i=0;i<s1.size();i++) {
        if(s1[i]=='5') s1[i]='6';
    }
    for(int i=0;i<s2.size();i++) {
        if(s2[i]=='5') s2[i]='6';
    }
    int num1=stoi(s1),num2=stoi(s2);
    return num1+num2;
}
int main() {
    string s1,s2;
    cin >>s1 >>s2;
    cout <<minValue(s1,s2) <<" " <<maxValue(s1,s2);
}