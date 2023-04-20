#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> dq;
    
    // cacheSize가 0이면 cities 갯수 * 5
    if(cacheSize == 0) {
        return cities.size() * 5;
    }
    
    for(int i=0;i<cities.size(); i++) {
        string str = cities[i];
        // 소문자로 전부 바꿔줌
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        
        // 덱큐가 비어 있으면 추가하고 5초 추가
        if(i == 0) {
            dq.push_back(str);
            answer += 5;
            continue;
        }
        
        bool isChange = false;
        // dq사이즈 만큼 돌면서 도시 이름 일치하는 원소가 있는지 찾기
        for(int j=0; j<dq.size(); j++) {
            if(dq[j] == str) {
                // 있다면, 도시 이름을 맨뒤에 넣어주고 이전에 존재하던 위치의 원소는 지우고 1초 증가
                dq.push_back(str);
                dq.erase(dq.begin()+j);
                answer += 1;
                isChange = true;
                break;
            }
        }
        // 만약 도시 이름이 일치하는 원소가 없다면, 맨 앞 요소를 빼고 새로운 도시를 뒤에 넣고 5초 증가
        if(isChange == false) {
            // 캐시 사이즈보다 덱큐사이즈가 크거나 같으면 맨 앞 빼기
            if(dq.size() >= cacheSize) {
                dq.pop_front();
            }
            dq.push_back(str);
            answer += 5;
        }
    }
    return answer;
}