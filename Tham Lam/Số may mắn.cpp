// Hoàng yêu thích các số may mắn. Ta biết rằng một số là số may mắn nếu biểu diễn thập phân của nó chỉ chứa các chữ số may mắn là 4 và 7. 
// Ví dụ, các số 47, 744, 4 là số may mắn và 5, 17, 467 không phải. Hoàng muốn tìm số may mắn bé nhất có tổng các chữ số bằng n. Hãy giúp anh ấy

// Dữ liệu vào: Dòng đầu ghi số bộ test, mỗi bộ test có một dòng chứa số nguyên n (1 ≤ n ≤ 10^6) — tổng các chữ số của số may mắn cần tìm.
// Kết quả: In ra trên 1 dòng số may mắn bé nhất, mà tổng các chữ số bằng n. Nếu không tồn tại số thỏa mãn, in ra -1.
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;

        int d4,d7,check=0;
        for(int i=0;;i++) {
            if(n-4*i<0) break;
            else if((n-4*i)%7==0) {
                d4=i;
                d7=(n-4*i)/7;
                check=1;
                break;
            }
        }
        if(check==0) cout <<-1 <<endl;
        else {
            for(int i=1;i<=d4;i++) cout <<4;
            for(int i=1;i<=d7;i++) cout <<7;
            cout <<endl;
        }
    }
    return 0;
}