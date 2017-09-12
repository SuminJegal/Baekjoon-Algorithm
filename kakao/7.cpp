#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int string_list[5][20001];
int dp[20001];

vector<int> getPi(string p) {
    int m = p.size(), j = 0;
    vector<int> pi(m, 0);
    for(int i = 1; i < m; i++) {
        while(j > 0 && p[i] != p[j])
            j = pi[j-1];
        if(p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

vector<int> kmp(string s, string p) {
    vector<int> ans;
    auto pi = getPi(p);
    int n = s.size(), m = p.size(), j = 0;
    for(int i = 0; i < n; i++) {
        while(j > 0 && s[i] != p[j])
            j = pi[j-1];
        if(s[i] == p[j]) {
            if(j == m-1) {
                ans.push_back(i - m + 1);
                j = pi[j];
            } else j++;
        }
    }
    return ans;
}


int solution(vector<string> strs, string t)
{
	int answer = 0;
    for(int i=0; i<strs.size(); i++){
        auto piece = kmp(t,strs[i]);
        for(int j=0; j<piece.size(); j++){
            int p_size = strs[i].size();
            string_list[p_size-1][piece[j]+p_size-1] = 1;
        }
    }
    
    for(int i=0; i<t.size(); i++)
        dp[i] = 20001;
    
    for(int i=0; i<t.size(); i++){
        for(int j=4; j>=0; j--){
            if(i>=j){
                if(string_list[j][i] != 0){
                    if( (i-j-1) >= 0)
                        dp[i] = min(dp[i- j-1] + 1, dp[i]);
                    else
                        dp[i] = 1;
                }
            }
        }
    }
    
    for(int j=0; j<t.size(); j++)
            printf("%d ", dp[j]);
    
    answer = (dp[t.size()-1] == 20001 ? -1 : dp[t.size()-1]);
	return answer;
}