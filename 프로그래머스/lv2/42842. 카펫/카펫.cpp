#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int col=1; col<=yellow; col++) {
        if(yellow % col == 0) {
            int y = col;
            int x = yellow/y;
            
            int calcul = (y+2)*(x+2);
            if(calcul - yellow == brown && x+2>=y+2) {
                answer.push_back(x+2);
                answer.push_back(y+2);
                break;
            }
        }
    }
    return answer;
}