#include <iostream>

using namespace std;

int sum(int n) {
    int res=0;
    while(n) {
        res+=n%10;
        n/=10;
    }
    return res;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int n;
        cin >>n;    
        cout <<sum(n) <<endl;
    }
    return 0;
}