#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

/*
공식은 (얼굴개수+1)x(상의개수+1)x(하의개수+1)x(겉옷개수+1)-1
각 의상에 +1 해주는 이유는 안입을수도 있는 경우
마지막에 -1을 해주는 이유는 스파이는 하루 최소 한개 이상의 의상을 입는다는 조건

*/
int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string,int> c_map;
    vector<int> c_vec;
    
    for(int i=0; i<clothes.size(); i++)
    {
        c_map[clothes[i][1]]++; // map에 2중 배열에서 부위에 해당하는것을 체크해서 플러스 해줌
    }
    for(auto itr: c_map)
    {
        c_vec.push_back(itr.second); // 맵을 이터레이터 써서 돌려가며 벡터 c_vec에 넣어줌.
        //이 과정을 거치면 c_vec에는 얼굴 개수, 상의 개수, 하의 개수, 겉옷 개수 이렇게 저장됨.
    }
    for(int i=0; i<c_vec.size(); i++)
    { // 위 공식을 따라 코딩함.
        if( i == 0)
            answer = c_vec[i]+1;
        else
            answer = answer*(c_vec[i]+1);
    }
    return answer-1; // 마지막 -1을 해줌.
}