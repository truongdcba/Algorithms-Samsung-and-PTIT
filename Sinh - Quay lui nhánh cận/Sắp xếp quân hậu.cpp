// Cho một bàn cờ 8 x 8, mỗi ô có một giá trị A[i][j] nhất định (0 ≤ A[i][j] ≤ 100), tương ứng với điểm số đạt được nếu như bạn đặt một quân cờ vào đó.
// Nhiệm vụ của bạn là đặt 8 quân hậu lên bàn cờ, sao cho không có 2 quân nào ăn nhau, và số điểm đạt được là lớn nhất.
// Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test gồm 8 dòng, mỗi dòng 8 số nguyên mô tả bàn cờ.
// Output:  Với mỗi test, in ra đáp án trên một dòng.
#include <bits/stdc++.h>

using namespace std;
int arr[10][10],res=-1;
int x[10],cot[10],cheo1[10],cheo2[10];

void Try(int i) {
    for(int j=1;j<=8;j++) {
        if(!cot[j] && !cheo1[8+i-j] && !cheo2[i+j-1]) {
            x[i]=j;
            cot[j]=true;
            cheo1[8+i-j]=true;
            cheo2[i+j-1]=true;
            if(i==8) {
                int sum=0;
                for(int j=1;j<=8;j++) {
                    sum+=arr[j][x[j]];
                }
                res=max(res,sum);
            }
            else Try(i+1);
            cot[j]=false;
            cheo1[8+i-j]=false;
            cheo2[i+j-1]=false;
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        res=-1;
        for(int i=1;i<=8;i++) {
            for(int j=1;j<=8;j++) cin >>arr[i][j];
        }
        Try(1);
        cout <<res <<endl;
    }
    return 0;
}