#include <string>
#include <vector>
#include <iostream>

using namespace std;

int number = 0;

void DFS(vector<int> numbers, int currentN, int idx, int target) {
    if(idx == numbers.size()) {
        if(currentN == target) {
            number += 1;
        }
    } else {
        DFS(numbers, currentN+numbers[idx], idx+1, target);
        DFS(numbers, currentN-numbers[idx], idx+1, target);   
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    DFS(numbers, 0+numbers[0], 1, target);
    DFS(numbers, 0-numbers[0], 1, target);
    answer = number;
    return answer;
}