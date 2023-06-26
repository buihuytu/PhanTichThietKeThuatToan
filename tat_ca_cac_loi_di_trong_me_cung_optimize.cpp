#include<bits/stdc++.h>
using namespace std;
int n, m, a[30][30];
map<string, int> M;
void Try(int i, int j, string s){
	if(i == n && j == m){
		M[s]++;
	}
	if(a[i+1][j] == 0 && i != n){
		a[i][j] = 1;
		Try(i+1, j, s+"N");
		a[i][j] = 0;
	}
	if(a[i][j+1] == 0 && j != m){
		a[i][j] = 1;
		Try(i, j+1, s+"D");
		a[i][j] = 0;
	}
	if(a[i][j-1] == 0 && j != 1){
		a[i][j] = 1;
		Try(i, j-1, s+"T");
		a[i][j] = 0;
	}
	if(a[i-1][j] == 0 && i != 1){
		a[i][j] = 1;
		Try(i-1, j, s+"B");
		a[i][j] = 0;
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
	if(M.size() == 0) cout << "rua khong di duoc\n";
	else {
		for(auto x : M)
			cout << x.first << "\n";
	}
	cout << endl;
}

