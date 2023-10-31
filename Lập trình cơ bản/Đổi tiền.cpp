// Tại ngân hàng có các mệnh giá bằng 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000. Tổng số tiền cần đổi có giá trị bằng N. 
// Hãy xác định xem có ít nhất bao nhiêu tờ tiền sau khi đổi tiền?
// Input:
// Dòng đầu tiên là số lượng bộ test T (T ≤ 50).  Mỗi test gồm 1 số nguyên N ( 1 ≤ N ≤ 100 000).
// Output:  Với mỗi test, in ra đáp án trên một dòng.
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;
        int arr[10] = {1000,500,200,100,50,20,10,5,2,1};
        int dem=0;

        for(int i=0;i<10;i++) {
            dem+=n/arr[i];
            n%=arr[i];
        }
        cout <<dem <<endl;
    }
    return 0;
}