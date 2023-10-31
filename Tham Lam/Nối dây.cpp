// Cho N sợi dây với độ dài khác nhau được lưu trong mảng A[]. 
// Nhiệm vụ của bạn là nối N sợi dây thành một sợi sao cho tổng chi phí nối dây là nhỏ nhất. Biết chi phí nối sợi dây thứ i và sợi dây thứ j là tổng độ dài hai sợi dây A[i] và A[j].

// Input:
// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào số lượng sợi dây N; 
// dòng tiếp theo đưa vào N số A[i] là độ dài của các sợi dây; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤10^6; 0≤A[i]≤10^6.
// Output:
// Đưa ra kết quả mỗi test theo từng dòng.
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	int t;
	cin >>t;
	
	while(t--) {
		int n;
		cin >>n;
		priority_queue<ll,vector<ll>,greater<ll>> q;
		
		for(int i=0;i<n;i++) {
			ll x;
			cin >>x;
			q.push(x);
		}
		ll sum=0;
		while(q.size()!=1) {
			ll top1=q.top();
			q.pop();
			ll top2=q.top();
			q.pop();
			sum+=top1+top2;
			q.push(top1+top2);
		}
		cout <<sum <<endl;	
	}
	return 0;
}