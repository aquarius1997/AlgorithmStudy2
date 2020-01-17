//bfs로 실행한다.
//기본 규칙은 연산테이블을 최소 연산으로 update할 수 있을 경우 해당 테이블로 이동
//이동했을 때의 방향테이블의 정보도 update한다
//update여부를 확인할 노드가 목적지 노드일 경우
//최종적으로 로봇이 바라봐야할 위치연산수까지 포함시켜 작으면 update한다
#include <cstdio>
#include <queue>
#define MAX 101
#define INF 987987987
using namespace std;
//입력으로 받은 테이블 크기
int N;  int M;
//입력으로 받은 출발지 행, 열, 방향정보
int s_r;  int s_c;  int s_d;
//입력으로 받은 목적지 행, 열, 방향정보
int d_r;  int d_c;  int d_d;
//최소 연산일 경우 로봇의 방향을 나타내는 테이블(동:1, 서:2, 남:3, 북:4)
int dir[MAX][MAX]={0, };
//최소 연산 횟수를 저장할 테이블(갈 수 없는 노드는 -1로 저장)
int T[MAX][MAX]={0, };
queue <int> Queue;

void bfs(){
    int row, col; int direction;
    int i;
    
    Queue.push(s_r);  Queue.push(s_c);
    
    while(!(Queue.empty())){
        row=Queue.front();  Queue.pop();
        col=Queue.front();  Queue.pop();
        direction=dir[row][col];
        //북쪽 방향 노드 update시도
        //180도 회전해야하므로 방향 바꾸는 연산을 2번수행+이동1번
        if(direction==3){
            //거리 1~3만큼 반복
            for(i=1; i<=3; i++){
                //배열의 범위를 벗어나지 않으면서
                if(row-i>=0){
                    if(T[row-i][col]==-1)
                        break;
                    //갈 수 있는 궤도에 대해 더 짧은 연산 횟수로 갈 수 있으면 update
                    //목적지 노드이면 방향까지 포함해서 연산횟수 저장
                    if(row-i==d_r && col==d_c){
                        if(dir[d_r][d_c]==3){ //180도 회전해야할 경우
                            if(T[row][col]+5<T[row-i][col])
                                T[row-i][col]=T[row][col]+5;
                        }else if(dir[d_r][d_c]==4){ //방향 회전할 필요 없을 경우
                            if(T[row][col]+3<T[row-i][col])
                                T[row-i][col]=T[row][col]+3;
                        }else{  //90도 회전해야할 경우
                            if(T[row][col]+4<T[row-i][col])
                                T[row-i][col]=T[row][col]+4;
                        }
                    }//목적지 노드 아닌 경우
                    else if(T[row][col]+3<T[row-i][col]){
                        T[row-i][col]=T[row][col]+3;
                        dir[row-i][col]=4;
                        Queue.push(row-i);  Queue.push(col);
                    }
                }
            }
        }else if(direction!=4){  //90도 회전이므로 방향바꾸는 연산1번수행+이동1번
            for(i=1; i<=3; i++){
                if(row-i>=0){
                    if(T[row-i][col]==-1)
                        break;
                    //목적지 노드일 경우
                    if(row-i==d_r && col==d_c){
                        if(dir[d_r][d_c]==3){ //180도 회전해야할 경우
                            if(T[row][col]+4<T[row-i][col])
                                T[row-i][col]=T[row][col]+4;
                        }else if(dir[d_r][d_c]==4){ //방향 회전할 필요 없을 경우
                            if(T[row][col]+2<T[row-i][col])
                                T[row-i][col]=T[row][col]+2;
                        }else{  //90도 회전해야할 경우
                            if(T[row][col]+3<T[row-i][col])
                                T[row-i][col]=T[row][col]+3;
                        }
                    }//목적지 노드 아닌 경우
                    else if(T[row][col]+2<T[row-i][col]){
                        T[row-i][col]=T[row][col]+2;
                        dir[row-i][col]=4;
                        Queue.push(row-i);  Queue.push(col);
                    }
                }
            }
        }else{
            for(i=1; i<=3; i++){
                if(row-i>=0){
                    if(T[row-i][col]==-1)
                        break;
                    //목적지 노드일 경우
                    if(row-i==d_r && col==d_c){
                        if(dir[d_r][d_c]==3){ //180도 회전해야할 경우
                            if(T[row][col]+3<T[row-i][col])
                                T[row-i][col]=T[row][col]+3;
                        }else if(dir[d_r][d_c]==4){ //방향 회전할 필요 없을 경우
                            if(T[row][col]+1<T[row-i][col])
                                T[row-i][col]=T[row][col]+1;
                        }else{  //90도 회전해야할 경우
                            if(T[row][col]+2<T[row-i][col])
                                T[row-i][col]=T[row][col]+2;
                        }
                    }//목적지 노드 아닌 경우
                    else if(T[row][col]+1<T[row-i][col]){
                        T[row-i][col]=T[row][col]+1;
                        dir[row-i][col]=4;
                        Queue.push(row-i);  Queue.push(col);
                    }
                }
            }
        }
        
        //남쪽 방향 노드 update시도
        //180도 회전해야하므로 방향 바꾸는 연산을 2번수행+이동1번
        if(direction==4){
            //거리 1~3만큼 반복
            for(i=1; i<=3; i++){
                //배열의 범위를 벗어나지 않으면서
                if(row+i<N){
                    if(T[row+i][col]==-1)
                        break;
                    //갈 수 있는 궤도에 대해 더 짧은 연산 횟수로 갈 수 있으면 update
                    //목적지 노드이면 방향까지 포함해서 연산횟수 저장
                    if(row+i==d_r && col==d_c){
                        if(dir[d_r][d_c]==4){ //180도 회전해야할 경우
                            if(T[row][col]+5<T[row+i][col])
                                T[row+i][col]=T[row][col]+5;
                        }else if(dir[d_r][d_c]==3){ //방향 회전할 필요 없을 경우
                            if(T[row][col]+3<T[row+i][col])
                                T[row+i][col]=T[row][col]+3;
                        }else{  //90도 회전해야할 경우
                            if(T[row][col]+4<T[row+i][col])
                                T[row+i][col]=T[row][col]+4;
                        }
                    }//목적지 노드 아닌 경우
                    else if(T[row][col]+3<T[row+i][col]){
                        T[row+i][col]=T[row][col]+3;
                        dir[row+i][col]=3;
                        Queue.push(row+i);  Queue.push(col);
                    }
                }
            }
        }else if(direction!=3){  //90도 회전이므로 방향바꾸는 연산1번수행+이동1번
            for(i=1; i<=3; i++){
                if(row+i<N){
                    if(T[row+i][col]==-1)
                        break;
                    //목적지 노드일 경우
                    if(row+i==d_r && col==d_c){
                        if(dir[d_r][d_c]==4){ //180도 회전해야할 경우
                            if(T[row][col]+4<T[row+i][col])
                                T[row+i][col]=T[row][col]+4;
                        }else if(dir[d_r][d_c]==3){ //방향 회전할 필요 없을 경우
                            if(T[row][col]+2<T[row+i][col])
                                T[row+i][col]=T[row][col]+2;
                        }else{  //90도 회전해야할 경우
                            if(T[row][col]+3<T[row+i][col])
                                T[row+i][col]=T[row][col]+3;
                        }
                    }//목적지 노드 아닌 경우
                    else if(T[row][col]+2<T[row+i][col]){
                        T[row+i][col]=T[row][col]+2;
                        dir[row+i][col]=3;
                        Queue.push(row+i);  Queue.push(col);
                    }
                }
            }
        }else{
            for(i=1; i<=3; i++){
                if(row+i<N){
                    if(T[row+i][col]==-1)
                        break;
                    //목적지 노드일 경우
                    if(row+i==d_r && col==d_c){
                        if(dir[d_r][d_c]==4){ //180도 회전해야할 경우
                            if(T[row][col]+3<T[row+i][col])
                                T[row+i][col]=T[row][col]+3;
                        }else if(dir[d_r][d_c]==3){ //방향 회전할 필요 없을 경우
                            if(T[row][col]+1<T[row+i][col])
                                T[row+i][col]=T[row][col]+1;
                        }else{  //90도 회전해야할 경우
                            if(T[row][col]+2<T[row+i][col])
                                T[row+i][col]=T[row][col]+2;
                        }
                    }//목적지 노드 아닌 경우
                    else if(T[row][col]+1<T[row+i][col]){
                        T[row+i][col]=T[row][col]+1;
                        dir[row+i][col]=3;
                        Queue.push(row+i);  Queue.push(col);
                    }
                }
            }
        }
        
        //서쪽 방향 노드 update시도
        //180도 회전해야하므로 방향 바꾸는 연산을 2번수행+이동1번
        if(direction==1){
            //거리 1~3만큼 반복
            for(i=1; i<=3; i++){
                //배열의 범위를 벗어나지 않으면서
                if(col-i>=0){
                    if(T[row][col-i]==-1)
                        break;
                    //갈 수 있는 궤도에 대해 더 짧은 연산 횟수로 갈 수 있으면 update
                    //목적지 노드이면 방향까지 포함해서 연산횟수 저장
                    if(row==d_r && col-i==d_c){
                        if(dir[d_r][d_c]==1){ //180도 회전해야할 경우
                            if(T[row][col]+5<T[row][col-i])
                                T[row][col-i]=T[row][col]+5;
                        }else if(dir[d_r][d_c]==2){ //방향 회전할 필요 없을 경우
                            if(T[row][col]+3<T[row][col-i])
                                T[row][col-i]=T[row][col]+3;
                        }else{  //90도 회전해야할 경우
                            if(T[row][col]+4<T[row][col-i])
                                T[row][col-i]=T[row][col]+4;
                        }
                    }//목적지 노드 아닌 경우
                    else if(T[row][col]+3<T[row][col-i]){
                        T[row][col-i]=T[row][col]+3;
                        dir[row][col-i]=2;
                        Queue.push(row);  Queue.push(col-i);
                    }
                }
            }
        }else if(direction!=2){  //90도 회전이므로 방향바꾸는 연산1번수행+이동1번
            for(i=1; i<=3; i++){
                if(col-i>=0){
                    if(T[row][col-i]==-1)
                        break;
                    //목적지 노드일 경우
                    if(row==d_r && col-i==d_c){
                        if(dir[d_r][d_c]==1){ //180도 회전해야할 경우
                            if(T[row][col]+4<T[row][col-i])
                                T[row][col-i]=T[row][col]+4;
                        }else if(dir[d_r][d_c]==2){ //방향 회전할 필요 없을 경우
                            if(T[row][col]+2<T[row][col-i])
                                T[row][col-i]=T[row][col]+2;
                        }else{  //90도 회전해야할 경우
                            if(T[row][col]+3<T[row][col-i])
                                T[row][col-i]=T[row][col]+3;
                        }
                    }//목적지 노드 아닌 경우
                    else if(T[row][col]+2<T[row][col-i]){
                        T[row][col-i]=T[row][col]+2;
                        dir[row][col-i]=2;
                        Queue.push(row);  Queue.push(col-i);
                    }
                }
            }
        }else{
            for(i=1; i<=3; i++){
                if(col-i>=0){
                    if(T[row][col-i]==-1)
                        break;
                    //목적지 노드일 경우
                    if(row==d_r && col-i==d_c){
                        if(dir[d_r][d_c]==1){ //180도 회전해야할 경우
                            if(T[row][col]+3<T[row][col-i])
                                T[row][col-i]=T[row][col]+3;
                        }else if(dir[d_r][d_c]==2){ //방향 회전할 필요 없을 경우
                            if(T[row][col]+1<T[row][col-i])
                                T[row][col-i]=T[row][col]+1;
                        }else{  //90도 회전해야할 경우
                            if(T[row][col]+2<T[row][col-i])
                                T[row][col-i]=T[row][col]+2;
                        }
                    }//목적지 노드 아닌 경우
                    else if(T[row][col]+1<T[row][col-i]){
                        T[row][col-i]=T[row][col]+1;
                        dir[row][col-i]=2;
                        Queue.push(row);  Queue.push(col-i);
                    }
                }
            }
        }
        
        //동쪽 방향 노드 update시도
        //180도 회전해야하므로 방향 바꾸는 연산을 2번수행+이동1번
        if(direction==2){
            //거리 1~3만큼 반복
            for(i=1; i<=3; i++){
                //배열의 범위를 벗어나지 않으면서
                if(col+i<M){
                    if(T[row][col+i]==-1)
                        break;
                    //갈 수 있는 궤도에 대해 더 짧은 연산 횟수로 갈 수 있으면 update
                    //목적지 노드이면 방향까지 포함해서 연산횟수 저장
                    if(row==d_r && col+i==d_c){
                        if(dir[d_r][d_c]==2){ //180도 회전해야할 경우
                            if(T[row][col]+5<T[row][col+i])
                                T[row][col]=T[row][col+i]+5;
                        }else if(dir[d_r][d_c]==1){ //방향 회전할 필요 없을 경우
                            if(T[row][col]+3<T[row][col+i])
                                T[row][col+i]=T[row][col]+3;
                        }else{  //90도 회전해야할 경우
                            if(T[row][col]+4<T[row][col+i])
                                T[row][col+i]=T[row][col]+4;
                        }
                    }//목적지 노드 아닌 경우
                    else if(T[row][col]+3<T[row][col+i]){
                        T[row][col+i]=T[row][col]+3;
                        dir[row][col+i]=1;
                        Queue.push(row);  Queue.push(col+i);
                    }
                }
            }
        }else if(direction!=1){  //90도 회전이므로 방향바꾸는 연산1번수행+이동1번
            for(i=1; i<=3; i++){
                if(col+i<M){
                    if(T[row][col+i]==-1)
                        break;
                    //목적지 노드일 경우
                    if(row==d_r && col+i==d_c){
                        if(dir[d_r][d_c]==2){ //180도 회전해야할 경우
                            if(T[row][col]+4<T[row][col+i])
                                T[row][col+i]=T[row][col]+4;
                        }else if(dir[d_r][d_c]==1){ //방향 회전할 필요 없을 경우
                            if(T[row][col]+2<T[row][col+i])
                                T[row][col+i]=T[row][col]+2;
                        }else{  //90도 회전해야할 경우
                            if(T[row][col]+3<T[row][col+i])
                                T[row][col+i]=T[row][col]+3;
                        }
                    }//목적지 노드 아닌 경우
                    else if(T[row][col]+2<T[row][col+i]){
                        T[row][col+i]=T[row][col]+2;
                        dir[row][col+i]=1;
                        Queue.push(row);  Queue.push(col+i);
                    }
                }
            }
        }else{
            for(i=1; i<=3; i++){
                if(col+i<M){
                    if(T[row][col+i]==-1)
                        break;
                    //목적지 노드일 경우
                    if(row==d_r && col+i==d_c){
                        if(dir[d_r][d_c]==2){ //180도 회전해야할 경우
                            if(T[row][col]+3<T[row][col+i])
                                T[row][col+i]=T[row][col]+3;
                        }else if(dir[d_r][d_c]==1){ //방향 회전할 필요 없을 경우
                            if(T[row][col]+1<T[row][col+i])
                                T[row][col+i]=T[row][col]+1;
                        }else{  //90도 회전해야할 경우
                            if(T[row][col]+2<T[row][col+i])
                                T[row][col+i]=T[row][col]+2;
                        }
                    }//목적지 노드 아닌 경우
                    else if(T[row][col]+1<T[row][col+i]){
                        T[row][col+i]=T[row][col]+1;
                        dir[row][col+i]=1;
                        Queue.push(row);  Queue.push(col+i);
                    }
                }
            }
        }
    }
}

int main() {
    int element;
    int i, j;
    
    scanf("%d %d", &N, &M);
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            scanf("%d", &element);
            if(element==0)
                T[i][j]=INF;
            else
                T[i][j]=-1;
        }
    }
    scanf("%d %d %d", &s_r, &s_c, &s_d);
    //편의상 배열 시작점을 0, 0으로 잡음
    s_r-=1; s_c-=1;
    dir[s_r][s_c]=s_d;  T[s_r][s_c]=0;
    scanf("%d %d %d", &d_r, &d_c, &d_d);
    d_r-=1; d_c-=1;
    dir[d_r][d_c]=d_d;
    
    
    bfs();
    /*
     for(i=0; i<N; i++){
     for(j=0; j<M; j++)
     printf("%3d", T[i][j]);
     printf("\n");
     }
     */
    printf("%d", T[d_r][d_c]);
    return 0;
}
