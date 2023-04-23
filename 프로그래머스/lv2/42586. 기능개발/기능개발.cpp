#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int count = 0;
    int temp_num = 0;
    queue<int> p_q;
    for(int i=0; i<progresses.size(); i++)
    {
        float temp = ceil((100.0 - progresses[i]) / speeds[i]);
        cout<< temp << " < temp \n";
        p_q.push(temp);
    }
    while(!p_q.empty())
    {
        if(temp_num == 0)
        {
            cout << "temp_num = 0 / p_q.front() : " << p_q.front() << "\n";
            temp_num = p_q.front();
            p_q.pop();
            count ++;
            cout << "count : " << count << "\n";
        }
        if(p_q.front()<=temp_num)
        {
            cout << "temp_num =  / p_q.front() : " << p_q.front() << "\n";
            p_q.pop();
            count++;
            cout << "count : " << count << "\n";
            if(p_q.empty())
                answer.push_back(count);
        }
        else
        {
            answer.push_back(count);
            count = 0;
            temp_num = 0;
        }
    }
    
    return answer;
}