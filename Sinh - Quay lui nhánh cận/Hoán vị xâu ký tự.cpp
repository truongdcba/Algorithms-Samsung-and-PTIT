// Cho xâu ký tự S bao gồm các ký tự in hoa khác nhau. Hãy đưa ra tất cả các hoán vị của xâu ký tự S. 
// Ví dụ S=”ABC” ta có kết quả {ABC ACB BAC BCA CAB CBA}. 

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test là một xâu ký tự S được viết trên 1 dòng.
// T, S thỏa mãn ràng buộc: 1≤T≤10; 1≤length(S) ≤10;
#include <iostream>

using namespace std;
bool visited[20];
string s,tmp="";

void Try(int i) {
    for(int j=0;j<s.size();j++) {
        if(!visited[j]) {
            tmp+=s[j];
            visited[j]=true;
            if(i==s.size()) {
                cout <<tmp <<" ";
            }
            else Try(i+1);
            tmp.pop_back();
            visited[j]=false;
        }
    }
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        cin >>s;
        Try(1);
        cout <<endl;
    }
    return 0;
}