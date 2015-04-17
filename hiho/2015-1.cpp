#include <stdio.h>
#include <string.h>

const int MAX 	= 2000000000;
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
	if(y1 == y2){
		if(isRunYear(y1)){
			if(m1<=2 && (m2>2 || (m2==2 && d2>=29))){
				count = 1;
			}
		}
	}else{
		count = (y2/4 - y2/100 + y2/400) - (y1/4 - y1/100 + y1/400);
		if(isRunYear(y1)){
			count += 1;
			if(!(m1<=2)){
				count -= 1;
			}
		}
		if(isRunYear(y2)){
			if(!(m2>2 || (m2==2 && d2>=29))){
				count -= 1;
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
