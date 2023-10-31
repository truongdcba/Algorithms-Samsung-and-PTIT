// Xâu con của một xâu ký tự S được tạo ra bằng cách lấy một hoặc nhiều ký tự trong S và giữ nguyên thứ tự ban đầu.
// Cho xâu S chỉ bao gồm các chữ cái viết thường. Hãy in ra xâu con có thứ tự từ điển là lớn nhất.
// Input
// Chỉ có xâu ký tự S, độ dài không quá 100000. Không có khoảng trống.
// Output
// Ghi ra xâu con có thứ tự từ điển lớn nhất.
// VD Input: abbcbccacbbcbaaba, Output: cccccbba
#include <bits/stdc++.h>

using namespace std;
vector<pair<char,int>> v;

bool cmp(pair<char,int> a,pair<char,int> b) {
	if(a.first!=b.first) return a.first>b.first;
	return a.second<b.second;
}
void find() {
	string tmp="";
	int index=-1;
	for(auto it : v) {
		if(it.second>index) {
			tmp+=it.first;
			index=it.second;
		}
	}
	cout <<tmp;
}
int main() {	
	string s;
	cin >>s;
	
	for(int i=0;i<s.size();i++) {
		v.push_back({s[i],i});
	}
	sort(v.begin(),v.end(),cmp);
	find();
	return 0;
}