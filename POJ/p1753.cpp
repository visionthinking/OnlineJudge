#include <stdio.h>
#include <bitset>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

inline void filp(char & x) {
    x=1-x;
}

void print(char * a){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%d", a[i*4+j]);
        }
        printf("\n");
    }
}

inline int hash(char * a){
    int r = 0;
    for(int i=0;i<16;i++){
        if(a[i] == 1){
            r |= (1 << i);
        }
    }
    return r;
}

inline void op(char * a, int p){
    int x = p / 4;
    int y = p % 4;
    filp(a[p]);
    if(x-1>=0){
        filp(a[(x-1)*4+y]);
    }
    if(x+1<4){
        filp(a[(x+1)*4+y]);
    }
    if(y-1>=0){
        filp(a[x*4+y-1]);
    }
    if(y+1<4){
        filp(a[x*4+y+1]);
    }
}

struct node {
    int step;
    char a[16];
};

int f(int target, struct node start){
    bitset<1 << 16> flag;
    queue<struct node> q;
    int min = 1 << 30;
    int n;
    
    q.push(start);
    flag.set(hash(start.a));
    
    while(!q.empty()){
        for(int i=0;i<16;i++){
            struct node tmp = q.front();
            op(tmp.a, i);
            n = hash(tmp.a);
            
            if(n == target){
                //printf("result=%d\n", tmp.step + 1);
                if(min > tmp.step + 1){
                    min = tmp.step + 1;   
                }
                break;
            }
            
            if(!flag.test(n)){
                tmp.step = q.front().step + 1;
                q.push(tmp);
                flag.set(n);
            }
        }
        q.pop();
    }
    return min;
}

void solution(){
    char a[16];
    int n = 0;
    while(n < 16){
        scanf("%c", &a[n]);
        if(a[n]=='b' || a[n]=='w'){
            a[n] = (a[n] == 'b') ? 0 : 1;
            n += 1;
        }
    }
    
    //print(a);
    
    int target = hash(a);
    
    if(target == 0 || target == 65535){
        printf("0");
        return;
    }
    
    int result1, result2;
    struct node start;
    memset(&start, 0, sizeof(start));
    result1 = f(target, start);
    
    start.step = 0;
    for(int i=0;i<16;i++){
        start.a[i] = 1;
    }
    result2 = f(target, start);
    
    if(result1 == result2 && result1 == 1 << 30){
        printf("Impossible");
    }else{
        printf("%d", result1 < result2 ? result1 : result2);
    }
}

int main(void){
    

    freopen("p1753.in", "r", stdin);
    
    solution();
    
	return 0;
}
