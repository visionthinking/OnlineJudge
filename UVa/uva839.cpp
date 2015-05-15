#include <stdio.h>

bool solve(int & W){
	int w1, w2, d1, d2;
	bool b1, b2;
	scanf("%d %d %d %d", &w1, &d1, &w2, &d2);
	b1 = true;
	b2 = true;
	if(w1 == 0){
		b1 = solve(w1);
	}
	if(w2 == 0){
		b2 = solve(w2);	
	}
	W = w1 + w2;
	return b1 && b2 && (w1 * d1 == w2 * d2);
}

int main(void){
	freopen("uva839.in", "r", stdin);
	int t, w;
	scanf("%d", &t);
	for(int i=0;i<t;i++){
		if(i > 0){
			printf("\n");	
		}
		
		printf("%s\n", solve(w) ? "YES" : "NO" );
	}
	return 0;
}
