#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int h = park.size();
    int w = park[0].size();
    pair<int,int> puppy(make_pair(0,0));
    vector<vector<char>> map(h);
    
    for(int y=0; y<park.size(); y++) {
        for(int x=0; x<park[y].size(); x++) {
            map[y].push_back(park[y][x]);
            if(park[y][x] == 'S') {
                puppy.first = y;
                puppy.second = x;
            }
        }
    }
    
    for(int i=0; i<routes.size(); i++) {
        char heading = routes[i][0];
        int moveCnt = routes[i][2]-'0';
        
        int hIdx = 0;
        switch(heading) {
            case 'N':
                hIdx = 0;
                break;
            case 'E':
                hIdx = 1;
                break;
            case 'S':
                hIdx = 2;
                break;
            case 'W':
                hIdx = 3;
                break;
        }
        int ny = puppy.first + dy[hIdx];
        int nx = puppy.second + dx[hIdx];
        for(int j=0; j<moveCnt; j++) {
            if(ny >= 0 && ny < h && nx >= 0 && nx < w) {
                if(map[ny][nx] == 'X') break;
            } else {
                break;
            }
            if(j == moveCnt-1) {
                puppy.first = ny;
                puppy.second = nx;
            }
            ny += dy[hIdx];
            nx += dx[hIdx];
        }
    }
    
    answer.push_back(puppy.first);
    answer.push_back(puppy.second);
    
    return answer;
}