#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
#define ll long long
ll target, a, n;
vector<ll> v[100];
set<ll> s[100][100];
int main(){
	cin >> target; // target
	cin >> n; // number of rows
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= i; j++){
			cin >> a;
			v[i].push_back(a);
		}
	}
	for (int i = n - 1; i >= 0; i--){
		for (int j = 0; j <= i; j++){
			if (i == n - 1){
				s[i][j].insert(v[i][j]);
				continue;
			} else {
				for (set<ll>::iterator it = s[i + 1][j].begin(); it != s[i + 1][j].end(); it++){
					s[i][j].insert(v[i][j]*(*it));
				}
				for (set<ll>::iterator it = s[i + 1][j + 1].begin(); it != s[i + 1][j + 1].end(); it++){
					s[i][j].insert(v[i][j]*(*it));
				}
			}
		}
	}

	vector<char> ans;
	int level = 0, idx = 0;
	ll t = target;
	if (s[0][0].find(target) == s[0][0].end()){
		cout << -1 << endl; // impossible
		return 0;
	}
	while (level < n - 1){

		t /= v[level][idx];
		if (s[level + 1][idx].find(t) != s[level + 1][idx].end()){
			ans.push_back('L');
			level++;
			continue;
		}
		if (s[level + 1][idx + 1].find(t) != s[level + 1][idx + 1].end()){
			ans.push_back('R');
			level++;
			idx++;
			continue;
		}
		cout << -1 << endl;
		return 0;
	}
	for (vector<char>::iterator it = ans.begin(); it != ans.end(); it++){
		cout << *it;
	}
	cout << endl;;
	
}
