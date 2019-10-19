#include <stdio.h>

int D, W, K;
int arr[25][25] = {0, };
int A[25];
int makeC = 0;
int ok = 0;


//각 열에 대해 k개 이상 같은 성분이 나오는지 검증하는 함수
int is_K(void) {
    int colCount, counting;
    int flag;
    int i, j;
    
    colCount = 0;
    
    //각 열에 대해 반복
    for(j=0; j<W; j++) {
        flag = 0;
        counting = 1;
        for(i=1; i<D; i++) {
            
            //약품들어가있으면
            if(A[i] != -1) {
                //그 전에 행도 약품 들어가있으면
                if(A[i-1] != -1) {
                    if(A[i-1] == A[i]) {
                        counting++;
                        if(counting >= K) {
                            flag = 1;    break;
                        }
                    }else {
                        if(counting >= K) {
                            flag = 1;   break;
                        }
                        counting = 1;
                    }
                }else { //그 전에 행에는 약품이 안들어가있으면
                    if(arr[i-1][j] == A[i]) {
                        counting++;
                        if(counting >= K) {
                            flag = 1;   break;
                        }
                    }else {
                        if(counting >= K) {
                            flag = 1;   break;
                        }
                        counting = 1;
                    }
                }
            }else { //현재 라인에 약품이 안들어가있고
                if(A[i-1] != -1) {  //그 전에 행은 약품이 들어가있으면
                    if(arr[i][j] == A[i-1]) {
                        counting++;
                        if(counting >= K) {
                            flag = 1;   break;
                        }
                    }else {
                        if(counting >= K) {
                            flag = 1;   break;
                        }
                        counting = 1;
                    }
                }else {
                    if(arr[i-1][j] == arr[i][j]) {
                        counting++;
                        if(counting >= K) {
                            flag = 1;   break;
                        }
                    }else {
                        if(counting >= K) {
                            flag = 1;   break;
                        }
                        counting = 1;
                    }
                }
            }
            
        }   //end inner for
        
        //마지막열까지 포함해서 K개 이상일 경우 확인
        if(counting >= K) {
            flag = 1;
        }
        
        //해당 열에서 동일 셀이 K개 이상 연속되지 않으면
        if(flag == 0) {
            break;
        }else {
            colCount++;
        }
        
    }   //end 각 열에 대해 반복
    
    
    if(colCount == W)
        return 1;
    else
        return -1;
}

//행의 약품 정보를 저장하는 배열의 모든 경우의 수를 만든다
void dfs(int row, int c) {

    //약품 정보를 저장하는 배열을 바탕으로 각 열에 대해 K개 이상 같은 성분이 나오는지 검증한다
    if(c >= makeC) {
        
        if(is_K() == 1) {
            ok = 1;
        }
        
        return;
    }else {
        
        A[row] = 0;
        
        if(row == D-1) {    //더이상 탐색할 범위가 없을 때
            if(is_K() == 1)
                ok = 1;
        }else {
            for(int i=row; i<D; i++) {
                
                if(A[i] == -1) {
                    
                    dfs(i, c+1);
                }
            }
        }
        
        A[row] = 1;
        
        if(row == D-1) {
            if(is_K() == 1)
                ok = 1;
        }else {
            for(int i=row; i<D; i++) {
                if(A[i] == -1) {
                    dfs(i, c+1);
                }
            }
        }
        
        A[row] = -1;
        
    }
    
}


int main(void) {
    int T, t;
    int i, j;
    
    scanf("%d", &T);
    
    //테스트 케이스 반복
    for(t=0; t<T; t++) {
        ok = makeC = 0;
        scanf("%d %d %d", &D, &W, &K);
        
        for(i=0; i<D; i++) {
            for(j=0; j<W; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        
        for(i=0; i<D; i++){
            A[i] = -1;
        }
        
        //각 열에 대해 k개 이상 같은 성분이 나오는지 검증한다
        while(1) {
            
            
            //모든 열에 대해서 조건을 만족할 경우 종료
            if(is_K() == 1)
                break;
            
            //모든 열에 대해 조건을 만족하지 못할 경우
            //약품수 + 1
            makeC++;
            
            for(i=0; i<D; i++) {
                dfs(i, 0);
                
                if(ok == 1) {
                    break;
                }
                
                for(j=0; j<25; j++)
                    A[j] = -1;
            }
            
            if(ok == 1)
                break;
        }
        
        printf("#%d %d\n", t+1, makeC);
    }
    
    return 0;
}

