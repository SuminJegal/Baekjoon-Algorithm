#include <iostream>

using namespace std;

int dp[2][5001];
int test_dp[5001];

int main(){
    string input_string;
    cin >> input_string;

    for(int i=0; i<input_string.size(); i++){
        if(i==0){
            int tmp = (int)input_string[i] - 48;
            if(tmp == 0){
                dp[0][i] = 0;
                continue;
            }
            dp[0][i] = 1;
            continue;
        }
        dp[0][i] = (dp[0][i-1] + dp[1][i-1])%1000000;
        int now_input = (int)input_string[i] - 48;
        int before_input = (int)input_string[i-1] - 48;

        if(now_input==0){
            dp[0][i] = 0;
            if(before_input <= 2)
                dp[1][i] = dp[0][i-1];
        }
        else {
            if((before_input==1) || (before_input==2 && now_input<=6))
                dp[1][i] = dp[0][i-1];
            else
                dp[1][i] = 0;
        }

    }

    // for(int i=0; i<=input_string.size(); i++){
    //     cout << dp[1][i] << " "<< dp[0][i] << endl;
    // }

    cout << (dp[0][input_string.size()-1] + dp[1][input_string.size()-1])%1000000 << endl;
}