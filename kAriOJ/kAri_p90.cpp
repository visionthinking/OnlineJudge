#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

int solution(char * a, int len){
    int m = 1 << 30;
    int sum = 0;
    for(char k='a';k<='z'; k++){
        sum = 0;
        for(int i=0; i<len; i++){
            sum += min((a[i] - k + 26) % 26, (k - a[i] + 26) % 26);
        }
        m = min(m, sum);
    }
    return m;
}

int main(void){
    int t, i, len;
    char str[1005];
    
    FILE * f = fopen("p90.in", "r");
    fscanf(f, "%d", &t);
    for(i=0; i<t; i++){
        str[0] = 0;
        fscanf(f, "%s", str);
        len = strlen(str);
        printf("%d\n", solution(str, len));
    }
    fclose(f);
    system("pause");
    return 0;
}
