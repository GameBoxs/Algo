#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

map<string,int> idMap;
vector<vector<int>> v;
vector<int> announce;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    for(int i=0; i<id_list.size(); i++) {
        idMap.insert({id_list[i],i});
    }
    
    v.resize(id_list.size());
    
    for(int y=0; y<id_list.size(); y++) {
        for(int x=0; x<id_list.size(); x++) {
            v[y].push_back(0);
        }
    }
    
    for(int i=0; i<report.size(); i++) {
        stringstream ss;
        string temp = "";
        ss.str(report[i]);
        vector<string> tempV;
        while(getline(ss,temp,' ')){
            tempV.push_back(temp);
        }
        int reportId = idMap[tempV[0]];
        int targetId = idMap[tempV[1]];
        
        if(v[reportId][targetId] == 0) v[reportId][targetId] = 1;
    }
    
    for(int x=0; x<id_list.size(); x++) {
        int cnt = 0;
        for(int y=0; y<id_list.size(); y++) {
            if(v[y][x] == 1) cnt += 1;
        }
        if(cnt >= k) announce.push_back(x);
    }
    
    for(int y=0; y<id_list.size(); y++) {
        int cnt = 0;
        for(int x=0; x<announce.size(); x++) {
            if(v[y][announce[x]] == 1) cnt += 1;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}