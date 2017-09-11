#include <cstdio>

using namespace std;
int solution(int n)
{
   int div = 1;
    int answer = 0;
    int quot;
    do{
        quot = n/div;
        div = div*10;
        answer = answer + (quot%10);
    }while(quot > 0);
    return answer;
}