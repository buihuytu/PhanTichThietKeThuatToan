#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> point;
queue<point> Q;
map<point, int> M;

bool check(int x, int y, int n){
	if(1 <= x && x <= n && 1 <= y && y <= n){
		return true;
	}
	return false;
}

int BFS(int sx, int sy, int fx, int fy, int n){
	int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
	int dy[] = {1, -1, 2, -2, 2, -2, -1, 1};
	M.clear();
	while(!Q.empty()){
		Q.pop();
	}
	Q.push({sx, sy});
	while(Q.size()){
		point u = Q.front(); Q.pop();
		for(int i = 0; i < 8; i++){
			int x = u.first + dx[i];
			int y = u.second + dy[i];
			if(check(x, y, n) && M[{x, y}] == 0){
				Q.push({x, y});
				M[{x, y}] = M[u]+1;
			}
		}
		if(M.find({fx, fy}) != M.end()) break;
	}
	if(M.find({fx, fy}) == M.end()) return -1;
	else
		return M[{fx, fy}];
}

int main(){
	int n, x1, y1, x2, y2, xf, yf;
	cin >> n >> x1 >> y1 >> x2 >> y2 >> xf >> yf;
	
	int a = BFS(x1, y1, xf, yf, n);
	int b = BFS(x2, y2, xf, yf, n);

	if(a < b){
        if(a == -1){
            cout << "2" << "\n";
        }
        else{
            cout << "1" << "\n";
        }
    }
    if(a > b){
        cout << "2" << "\n";
    }
    if(a == b){
        cout << "0" << "\n";
    }
    cout << a << " " << b;
//	cout << a << " " << b << endl;
//    cout << M.size() << endl;
//	for(auto x : M){
//		cout << x.second << " ";
//	}
}

