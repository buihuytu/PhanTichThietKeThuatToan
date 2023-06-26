#include<bits/stdc++.h>
using namespace std;
int n, m, a[30][30];
bool ok[30][30];
vector<string> res;

void Try(int i, int j, string s){
	if(a[1][1] == 1 || a[n][m] == 1){
		return;
	}
	if(i == n && j == m){
		res.push_back(s);
	}
	if(a[i+1][j] == 0 && i != n && !ok[i+1][j]){
		ok[i][j] = true;
		Try(i+1, j, s+"N");
		ok[i][j] = false;
	}
	if(a[i][j+1] == 0 && j != m && !ok[i][j+1]){
		ok[i][j] = true;
		Try(i, j+1, s+"D");
		ok[i][j] = false;
	}
	if(a[i][j-1] == 0 && j != 1 && !ok[i][j-1]){
		ok[i][j] = true;
		Try(i, j-1, s+"T");
		ok[i][j] = false;
	}
	if(a[i-1][j] == 0 && i != 1 && !ok[i-1][j]){
		ok[i][j] = true;
		Try(i-1, j, s+"B");
		ok[i][j] = false;
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	Try(1, 1, "");
	if(res.size() == 0) cout << "rua khong di duoc\n";
	else {
		sort(res.begin(), res.end());
		for(auto x : res)
			cout << x << "\n";
	}
	cout << endl;
}

