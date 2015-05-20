#include <stdio.h>
#include <string.h>

const int MAX = 100000;
long long cc[MAX];

void build(int index){
	int v;
	scanf("%d", &v);
	if(v == -1) {
		return;	
	}
	cc[index] += v;
	build(index - 1);
	build(index + 1);
}

bool solve(int case_id){
	int v, mid;
	scanf("%d", &v);
	if(v == -1){
		return false;	
	}
	
	memset(cc, 0, sizeof(cc));
	mid = MAX / 2;
	cc[mid] = v;
	build(mid - 1);
	build(mid + 1);
	
	printf("Case %d:\n", case_id);
	bool flag = false;
	for(int i=0;i<MAX;i++){
		if(cc[i] > 0){
			if(!flag){
				flag = true;	
			}else{
				printf(" ");	
			}
			printf("%d", cc[i]);
		}
	}
	printf("\n\n");
	return true;
}

int main(void){
	freopen("uva699.in", "r", stdin);
	int case_id = 1;
	while(solve(case_id)){
		case_id += 1;
	}
	return 0;
}
