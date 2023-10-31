// Cho hai số nguyên N và K, trong đó N không quá 10^7, K không quá 10. 
// Số lớn nhất bậc K của N được định nghĩa là giá trị lớn nhất có thể sau khi thực hiện nhiều nhất K lần các chữ số của N. 
// Ví dụ K =3 và N = “1234567” ta số lớn nhất bậc K của N là “7654321”.

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số K; dòng tiếp theo là xâu ký tự S.
// T, K, S thỏa mãn ràng buộc: 1≤T≤100; 0≤K≤10; 1≤lengh(S)≤7.
// Output:
// Đưa ra số lớn nhất bậc K của N trên một dòng.
#include <bits/stdc++.h>

using namespace std;

int findIndex(int idx,string s,char value) {
    for(int i=s.size()-1;i>idx;i--) {
        if(s[i]==value) return i;
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int k;
        string s;
        cin >>k >>s;

        string tmp=s;
        sort(tmp.begin(),tmp.end(),greater<char>());

        for(int i=0;i<s.size();i++) {
            if(k==0) break;
            
            if(s[i]!=tmp[i]) {
                int j=findIndex(i,s,tmp[i]);
                swap(s[i],s[j]);
                k--;
            }
        }
        cout <<s <<endl;
    }
    return 0;
}