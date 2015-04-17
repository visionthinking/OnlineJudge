#include <stdio.h>
#include <string.h>

const int MAX = 2000000000;
const char* MONTH[12] = {"January", "February", "March", "April", "May", "June", 
	"July", "August", "September", "October", "November" , "December"};

inline
bool isRunYear(int year){
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

inline 
int getMonth(char * a){
	for(int i=0;i<12;i++){
		if(strcmp(a, MONTH[i]) == 0){
			return i+1;
		}
	}
	return -1;
}

void solution(){
	int y1, m1, d1, y2, m2, d2;
	int i, j, k, count;
	char str[10];
	scanf("%s %d, %d", str, &d1, &y1);
	m1 = getMonth(str);
	scanf("%s %d, %d", str, &d2, &y2);
	m2 = getMonth(str);
	
	count = 0;
	for(i=y1+1;i<y2;i++){
		if(i % 4 == 0){
			break;
		}
	}	
	for(;i<y2;i+=4){
		if(isRunYear(i)){
			count += 1;
		}
	}
	
	if(y1 < y2){
		if(isRunYear(y1)){
			if(m1 <= 1 || (m1 == 2 && d1 <= 29)){
				count += 1;
			}
		}
		if(isRunYear(y2)){
			if(m2 > 2 || (m2 == 2 && d2 == 29)){
				count += 1;
			}
		}
	}else{
		if(isRunYear(y1)){
			if((m1 <= 1 || (m1 == 2 && d1 <= 29))
			&& (m2 > 2 || (m2 == 2 && d2 == 29))){
				count += 1;	
			}
		}
	}
	printf("%d", count);
}

int main(void){
	freopen("2015-1.in", "r", stdin);
	int n;
	scanf("%d", &n);
	printf("Case #1: ");
	solution();
	for(int i=2;i<=n;i++){
		printf("\nCase #%d: ", i);
		solution();
	}
	return 0;
}
