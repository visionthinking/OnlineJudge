#include <stdio.h>
#include <string.h>

const int MAX 	= 2000000000;
const int MAX_S =     100001;
const char* MONTH[12] = {"January", "February", "March", "April", "May", "June", 
	"July", "August", "September", "October", "November" , "December"};

int s[MAX_S];

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

int getSum(int y1, int y2){
	int count = 0;
	int i;
	i = y1;
	if(y2 - y1 >= 10000){
		count = (y2 - y1)/10000 * 2425;
		i = y1 + ((y2 - y1)/10000)*10000;
	}
	for(;i<=y2;i++){
		if(i % 4 == 0){
			break;
		}
	}	
	for(;i<=y2;i+=4){
		if(isRunYear(i)){
			count += 1;
		}
	}
	return count;
}


void debug(){
	int i, t;
	s[0] = getSum(1992000, 2000000);
	printf("\ncalc:\n");
	printf("s[0]=%d", s[0]);
	for(i=1;i<=MAX_S;i++){
		//s[i] = getSum(20000*i, 20000*(i+1)-1);
		int diff = 1237;
		t = getSum(10000*i + diff, 10000*(i+1)-1 + diff);
		if(t != 2425){
			printf("%d\n", t);
		}
	}
}


void solution(){
	int y1, m1, d1, y2, m2, d2;
	int i, j, k, count;
	char str[10];
	scanf("%s %d, %d", str, &d1, &y1);
	m1 = getMonth(str);
	scanf("%s %d, %d", str, &d2, &y2);
	m2 = getMonth(str);
	
	count = getSum(y1+1, y2-1);
	
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
