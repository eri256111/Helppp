#include <iostream>
using namespace std;

#define endl '\n'
#define _ << ' ' <<

inline void FAST(){ ios::sync_with_stdio(false); cin.tie(0); }

const int MAX = (1024 + 5);
const int dx[4][4] = {{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {0, 1, 0, 1}};
const int dy[4][4] = {{0, 1, 1, 0}, {0, 0, 1, 1}, {0, 1, 1, 0}, {0, 0, 1, 1}};
					//  .		   . 			..			..
					// ..		   ..			 .			.
int n, x, y;
int land[MAX][MAX];

inline void print(){
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cerr _ land[i][j];
		}
		cerr _ endl;
	}
	cerr _ endl;
}

inline int scan(const int &N, const int &X, const int &Y){
	int nx, ny, M = N / 2;
	bool flag = true;
	for(int i = X ; i < X + N and flag ; i++){
		for(int j = Y ; j < Y + N and flag ; j++){
			if(land[i][j] == 1){
				nx = i, ny = j, flag = false;
				break;
			}
		}
	}
	if(nx < X + M and ny < Y + M)return 0;
	else if(nx < X + M)return 1;
	else if(ny < Y + M)return 2;
	else return 3;
}

inline void get_domain(const int &N, int &X, int &Y){
	int lx = 1, ly = 1;
	while(lx + N <= X)lx += N;
	while(ly + N <= Y)ly += N;
	X = lx, Y = ly;
}

void Report(int x1, int y1, int x2, int y2, int x3, int y3){
	cerr _ "Report:" _ x1 _ y1 _ x2 _ y2 _ x3 _ y3 _ endl;
}

void solve(int N, int X, int Y){
	land[X][Y] = 1;
	if(N >= 2){
		int nx = X, ny = Y, d, 
			x1, y1, x2, y2, x3, y3, x4, y4;
		get_domain(N, nx, ny);
		d = scan(N, nx, ny);
		nx = (nx + nx + N - 1) / 2, ny = (ny + ny + N - 1) / 2;
		x1 = dx[d][0] + nx, y1 = dy[d][0] + ny;
		x2 = dx[d][1] + nx, y2 = dy[d][1] + ny;
		x3 = dx[d][2] + nx, y3 = dy[d][2] + ny;
		x4 = dx[d][3] + nx, y4 = dy[d][3] + ny;
		Report(x1, y1, x2, y2, x3, y3);
		solve(N / 2, x1, y1);
		solve(N / 2, x2, y2);
		solve(N / 2, x3, y3);
		solve(N / 2, x4, y4);
	}
}

int main(){
	FAST();

	cin >> n >> x >> y;
	solve(n, x, y);
	return 0;
}