#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> v, int n) {
    vector<bool> visit(n+1);
    
    queue<int> q;
    q.push(1);
    visit[1] = true;
    int cnt = 1;
    
    while(!q.empty()) {
        int popN = q.front();
        q.pop();
        
        for(int i=0; i<v[popN].size(); i++) {
            if(!visit[v[popN][i]]) {
                cnt += 1;
                q.push(v[popN][i]);
                visit[v[popN][i]] = true;
            }
        }
    }
    return abs(cnt - (n-cnt));
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 99999999;
    
    vector<vector<int>> v(n+1);
    
    for(int i=0; i<wires.size(); i++) {
        v.clear();
        v.resize(n+1);
        for(int j=0; j<wires.size(); j++) {
            if(i == j) continue;
            v[wires[j][0]].push_back(wires[j][1]);
            v[wires[j][1]].push_back(wires[j][0]);
        }
        answer = min(bfs(v, n),answer);
    }
    
    return answer;
}