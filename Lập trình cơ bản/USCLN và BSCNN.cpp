#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int gcd(int a,int b) {
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(int a,int b) {
    return 1ll*(a/gcd(a,b))*b;
}
int main() {
    int t;
    cin >>t;

    while(t--) {
        int a,b;
        cin >>a >>b;
        cout <<gcd(a,b) <<" " <<lcm(a,b) <<endl;
    }    
    return 0;
}