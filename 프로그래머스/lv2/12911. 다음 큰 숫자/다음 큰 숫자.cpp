#include <string>
#include <vector>
#include <bitset>

using namespace std;

bool checkAllOne(int n) {
    int multi = 1;
    while(multi < 1000001) {
        if(multi == n) {
            return true;
        }
        multi = (multi * 2) + 1;
    }
    return false;
}

string convertAnswer(string str) {
    int changeIdx = 0;
    int oneCnt = 0;
    int zeroCnt = 0;
    bool isFirst = false;
    for(int i=0; i<str.size(); i++) {
        if(isFirst) {
                if(str[i] == '1' && str[i-1] == '0') {
                str[i] = '0';
                str[i-1] = '1';
                changeIdx = i+1;
                break;
            }
        } else {
            if(str[i] == '1') {
                isFirst = true;
            }
        }
    }
    
    for(int i=changeIdx; i<str.size(); i++) {
        if(str[i] == '0') {
            zeroCnt += 1;
        } else {
            oneCnt += 1;
        }
    }
    for(int i=changeIdx; i<str.size(); i++) {
        if(zeroCnt > 0) {
            str[i] = '0';
            zeroCnt -= 1;
        } else {
            str[i] = '1';
            oneCnt -= 1;
        }
    }
    return str;
}

int solution(int n) {
    int answer = 0;
    if(checkAllOne(n)) {
        if( n == 1) {
            answer = 2;
        } else {
            answer = n + ((n/2)+1);
        }
    } else {
        bitset<50> bits(n);
        int oneCnt = bits.count();
        for(int i=n+1; ;i++) {
            bitset<50> bits(i);
            int cnt = bits.count();
            
            if(oneCnt == cnt) {
                answer = i;
                break;
            }
        }
    }
    return answer;
}