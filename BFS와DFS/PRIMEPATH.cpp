
#include <cstdio>
#include <math.h>
#include <queue>

using namespace std;

int isPrime[10000] = {0, }; //isPrime[i] = 0 : i는 소수가 아님, isPrime[i] = 1 : i는 소수임
int dist[10000] = {0, };
int startN, endN;
int minCount;

//넷째 자리 숫자들 중에서 소수인 숫자를 알아내는 함수
void getPrime() {
    int p, i;
    int sqrtr;
    int flag;
    
    //넷째 자리숫자에 대하여 소수 판별을 한다
    for(p=1000; p<10000; p++) {
        sqrtr = (int)sqrt(p);
        
        flag = 0;
        for(i=2; i<=sqrtr; i++) {
            if(p % i == 0) {
                flag = 1;   // 소수가 아님을 표시
                break;
            }
        }
        
        if(flag == 0) {
            isPrime[p] = 1; //p는 소수임을 표시
        }
        
    }
}

void bfs(int primeN) {
    int num;
    int temp, d;
    queue <int> Queue;
    int i;
    
    Queue.push(primeN);
    
    while(!Queue.empty()) {
        num = Queue.front();    Queue.pop();
        d = dist[num] + 1;
        
        //1000의 자리 수 변경
        for(i=1; i<=9; i++) {
            temp = (i*1000) + (num % 1000);
           
            if(isPrime[temp] == 1 && (dist[temp] == 0 || dist[temp] > d)) {
                dist[temp] = d;
                Queue.push(temp);
            }
        }
        
        //100의자리
        for(i=0; i<=9; i++) {
            temp = (num - (num % 1000)) + (i * 100) + (num % 100);

            if(isPrime[temp] == 1 && (dist[temp] == 0 || dist[temp] > d)) {
                dist[temp] = d;
                Queue.push(temp);
            }
        }
        
        //10의자리
        for(i=0; i<=9; i++) {
            temp = (num - (num % 100)) + (i * 10) + (num % 10);
            
            if(isPrime[temp] == 1 && (dist[temp] == 0 || dist[temp] > d)) {
                dist[temp] = d;
                Queue.push(temp);
            }
        }
        
        //1의자리
        for(i=0; i<=9; i++) {
            temp = (num - (num % 10)) + i;

            if(isPrime[temp] == 1 && (dist[temp] == 0 || dist[temp] > d)) {
                dist[temp] = d;
                Queue.push(temp);
            }
        }
    }
    
}




int main(void) {
    int T;
    int t, i;
    
    //소수 먼저 구하기
    getPrime();
    
    
    scanf("%d", &T);
    
    for(t=0; t<T; t++) {
        //시작 끝을 입력으로 받고
        scanf("%d %d", &startN, &endN);
        
        bfs(startN);
        
        printf("%d\n", dist[endN]);
        
        for(i=1000; i<10000; i++) {
            dist[i] = 0;
        }
    }
    
    return 0;
}

