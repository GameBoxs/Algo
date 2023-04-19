#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(pair<int, int> a, pair<int,int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int deleteCnt = tangerine.size() - k;
    
    map<int, int> m;
    
    for(int i=0; i<tangerine.size(); i++) {
        m[tangerine[i]] += 1;
    }
    
    vector<pair<int, int>> v (m.begin(), m.end());
    
    sort(v.begin(), v.end(), cmp);
    
    answer = v.size();
    for(int i=0; i<v.size(); i++) {
        if(deleteCnt == 0) {
            break;
        }
        if(v[i].second <= deleteCnt) {
            deleteCnt = (deleteCnt - v[i].second);
            v[i].second = 0;
            answer -= 1;
        } else if(v[i].second > deleteCnt) {
            v[i].second -= deleteCnt;
            deleteCnt = 0;
        }
    }
    
    return answer;
}