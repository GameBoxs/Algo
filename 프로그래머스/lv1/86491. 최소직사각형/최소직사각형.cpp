#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<int> left;
    vector<int> right;
    
    for(int i=0; i<sizes.size(); i++) {
        if(sizes[i][0] >= sizes[i][1]) {
            left.push_back(sizes[i][0]);
            right.push_back(sizes[i][1]);
        } else {
            right.push_back(sizes[i][0]);
            left.push_back(sizes[i][1]);
        }
    }
    int lMax = 0;
    int rMax = 0;
    for(int i=0; i<left.size(); i++) {
        lMax = max(left[i], lMax);
        rMax = max(right[i], rMax);
    }
    answer = lMax * rMax;
    return answer;
}