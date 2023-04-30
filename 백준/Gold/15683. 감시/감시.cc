#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cctvData {
	int x;
	int y;
	int typeN;
	cctvData(int X, int Y, int N) : x(X), y(Y), typeN(N) {};
};

int w = 0;
int h = 0;
int blankCnt = 0;
vector<cctvData> cctv;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int answer = 0;
vector<vector<vector<int>>> cctvMove = {
	{},
	{{0},{1},{2},{3}},
	{{0,2},{1,3}},
	{{0,1},{1,2},{2,3},{3,0}},
	{{0,1,2},{1,2,3},{2,3,0},{3,0,1}},
	{{0,1,2,3}},
};

int countBlank(vector<vector<int>> copyMap) {
	int cnt = 0;
	for (int y = 0; y < copyMap.size(); y++) {
		for (int x = 0; x < copyMap[y].size(); x++) {
			if (copyMap[y][x] == 0) {
				cnt += 1;
			}
		}
	}
	return cnt;
}

bool check(int ny, int nx) {
	if (ny >= 0 && ny < h && nx >= 0 && nx < w) return true;
	return false;
}

void dfs(int cctvN, vector<vector<int>> map) {
	if (answer != 0) {
		if (cctvN == cctv.size()) {
			answer = min(countBlank(map), answer);
		} else {
			cctvData cd = cctv[cctvN];
			for (int i = 0; i < cctvMove[cd.typeN].size(); i++) {
				vector<vector<int>> copyMap(map);
				for (int j = 0; j < cctvMove[cd.typeN][i].size(); j++) {
					int ny = cd.y + dy[cctvMove[cd.typeN][i][j]];
					int nx = cd.x + dx[cctvMove[cd.typeN][i][j]];
					while (true) {
						if (check(ny, nx) && copyMap[ny][nx] != 6) {
							copyMap[ny][nx] = 7;
							ny += dy[cctvMove[cd.typeN][i][j]];
							nx += dx[cctvMove[cd.typeN][i][j]];
						} else {
							break;
						}
					}
				}
				dfs(cctvN + 1, copyMap);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> h >> w;

	vector<vector<int>> map(h);

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			int tempN = 0;
			cin >> tempN;
			if (tempN == 0) answer += 1;
			else if (tempN >= 1 && tempN <= 5) cctv.push_back(cctvData(x, y, tempN));
			map[y].push_back(tempN);
		}
	}
	dfs(0, map);
	cout << answer;
}