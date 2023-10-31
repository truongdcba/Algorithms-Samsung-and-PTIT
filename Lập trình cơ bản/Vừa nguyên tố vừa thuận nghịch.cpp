// Viết chương trình liệt kê các số vừa nguyên tố, vừa thuận nghịch trong đoạn [a,b] với a,b là các số nguyên dương thỏa mãn 10<a<b<106.

// Input
// Dòng đầu ghi số bộ test. Mỗi bộ test là một cặp số a,b.
// Output
// Với mỗi bộ test, ghi lần lượt các số thỏa mãn, mỗi số cách nhau một khoảng trống, mỗi dòng ghi đúng 10 số. 
// Khi hết một test thì bỏ trống một dòng trước khi ghi kết quả test tiếp theo.
#include <iostream>
#include <cmath>

using namespace std;
int nt[1000001];

void sang() {
    for(int i=0;i<=1000000;i++) {
        nt[i]=1;
    }
    nt[0]=nt[1]=0;
    for(int i=2;i<=sqrt(1000000);i++) {
        if(nt[i]) {
            for(int j=i*i;j<=1000000;j+=i) nt[j]=0;
        }
    }
}
bool checkTn(int n) {
    int res=0,tmp=n;
    while(n) {
        res=res*10+n%10;
        n/=10;
    }
    return res==tmp;
}
int main() {
    int t;
    cin >>t;
    sang();

    while(t--) {
        int a,b;
        cin >>a >>b;
        int dem=0;
        for(int i=a;i<=b;i++) {
            if(checkTn(i) && nt[i]) {
                dem++;
                cout <<i <<" ";
                if(dem==10) {
                    cout <<endl;
                    dem=0;
                }
            }
        }
        cout <<endl;
    }
    return 0;
}