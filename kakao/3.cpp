#include <iostream>
#include <vector>

using namespace std;
int x, y;

vector<int> solution(vector<vector<int> > v) {
  //vector<vector<int> >의 값은 다음과 같이 읽어올 수 있습니다.
    if(v[0][0] == v[1][0])
        x = v[2][0];
    else{
        if(v[0][0] == v[2][0])
            x = v[1][0];
        else
            x = v[0][0];
    }
    
    if(v[0][1] == v[1][1])
        y = v[2][1];
    else{
        if(v[0][1] == v[2][1])
            y = v[1][1];
        else
            y = v[0][1];
    }
    
    vector<int> ans;
    ans.reserve(2);
    ans.push_back(x);
    ans.push_back(y);
    return ans;
}