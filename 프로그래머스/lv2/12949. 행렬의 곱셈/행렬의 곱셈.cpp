#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int> (arr2[0].size()));
    for(int i=0; i<arr1.size(); i++) {
        for(int j=0; j<arr2[0].size(); j++) {
            int temp = 0;
            for(int n=0; n<arr2.size(); n++) {
                temp += arr1[i][n] * arr2[n][j];
            }
            answer[i][j] = temp;
        }
    }
    return answer;
}