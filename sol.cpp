#include <bits/stdc++.h>

using namespace std;

//int x[8] = {1, 0, -1, 0, 1, 1, -1, -1};
//int y[8] = {0, 1, 0, -1, 1, -1, 1, -1};

//int x[4] = {1, 0, -1, 0};
//int y[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		map<int, vector<int>> mp;
		for (int i = 0; i < n; i++) {
			mp[a[i]].push_back(i);
		}
		bool activate = true;
		vector<int> rem;
		vector<pair<int, int>> ans;
		int last = -1;
		for (auto x : mp) {
			if (activate) {
				for (int i = 0; i < (int) x.second.size(); i++) {
					rem.push_back(x.second[i]);
				}
				activate = false;
			} else {
				for (int i = 0; i < (int) x.second.size(); i++) {
					ans.push_back(make_pair(rem[0], x.second[i]));
					last = x.second[i];
				}
			}
		}
		for (int i = 1; i < (int) rem.size(); i++) {
			ans.push_back(make_pair(last, rem[i]));
		}
		bool checker = true;
		for (int i = 0; i < (int) ans.size(); i++) {
			checker &= (ans[i].first != -1 && ans[i].second != -1);
		}
		if (!checker || (int) ans.size() != n - 1) {
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
		for (auto x : ans) {
			cout << x.first + 1 << " " << x.second + 1 << '\n';
		}
	}
}
