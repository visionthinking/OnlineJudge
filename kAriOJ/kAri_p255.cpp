#include <stdio.h>

void solution(){
    int n, t;
    int sum_odd, sum_even;
    sum_odd = 0;
    sum_even = 0;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &t);
        if(t % 2 == 0){
            sum_even += t;
        }else{
            sum_odd += t;   
        }
    }
    printf("%d %d\n", sum_odd, sum_even);
}

int main(void){
    int n;
    
    freopen("p255.in", "r", stdin);
    
    scanf("%d", &n);
    while(n--){
        solution();
    }
	return 0;
}
