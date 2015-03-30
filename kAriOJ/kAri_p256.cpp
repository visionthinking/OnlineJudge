#include <stdio.h>

void solution(){
    int n, count, max, diff;
    int num, last;
    
    scanf("%d", &n);
    scanf("%d", &num);
    last = num;
    count = 1;
    max = 1;
    if(n >= 2){
        scanf("%d", &num);
        diff = num - last;
        max = 2;
        count = 2;
        last = num;
        for(int i=2;i<n;i++){
            scanf("%d", &num);
            if(diff == num - last){
                count += 1;
                max = count > max ? count : max;   
            }else{
                diff = num - last;
                count = 2;   
            }
            last = num;
        }
        printf("%d\n", max);
    }else{
        printf("%d\n", n);   
    }
    
    
}

int main(void){
    int n;
    
    freopen("p256.in", "r", stdin);
    
    scanf("%d", &n);
    while(n--){
        solution();
    }
	return 0;
}
