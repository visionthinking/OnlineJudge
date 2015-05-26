#include <stdio.h>
#include <string.h>

const int CYCLE[6] = {1, 5, 3, 2, 4, 0};
/* CYCLE_P[i] points to index of WORD. 
 * e.g. CYCLE_P[0] represents word 'W' has no cycle.
 */
const int CYCLE_P[6] = {5, 0, 3, 2, 4, 1};
const char WORD[6] = {'A', 'D', 'J', 'K', 'S', 'W'};
const int MAXW = 300;
const int MAXH = 300;

char a[MAXH][MAXW];
int mark[MAXH][MAXW];
int result[6];
int w, h;
int id, cnt;

void debug(){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			printf("%d", a[i][j]);		
		}
		printf("\n");
	}
	printf("\n");
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			printf("%2d", mark[i][j]);		
		}
		printf("\n");
	}
	printf("\n");
}

inline 
int hex2num(char a){
	int v;
	if('0' <= a && a <= '9'){
		v = a - '0';	
	}else if('a' <= a && a <= 'f'){
		v = a - 'a' + 10;	
	}else{
		v = a - 'A' + 10;
	}
	return v;
}

void fill_bg(int r, int c){
	if(r >= 0 && r < h && c >= 0 && c < w){
		if(a[r][c] == 0 && mark[r][c] == -1){
			mark[r][c] = 0;
			fill_bg(r+1, c);
			fill_bg(r-1, c);
			fill_bg(r, c+1);
			fill_bg(r, c-1);
		}
	}
}

void fill_word(int r, int c){
	if(r >= 0 && r < h && c >= 0 && c < w){
		if(mark[r][c] == -1){
			if(a[r][c] == 1){
				mark[r][c] = id;
				fill_word(r+1, c);
				fill_word(r-1, c);
				fill_word(r, c+1);
				fill_word(r, c-1);
			}else{
				fill_bg(r, c);
				cnt += 1;
			}
		}
	}
}

void solve(){
	memset(a, 0, sizeof(a));
	memset(mark, -1, sizeof(mark));
	memset(result, 0, sizeof(result));
	char tmp[MAXW];
	for(int i=1;i<=h;i++){
		scanf("%s", tmp);
		for(int j=0;j<w;j++){
			int v = hex2num(tmp[j]);
			a[i][1+j*4+0] = (v >> 3) & 1;
			a[i][1+j*4+1] = (v >> 2) & 1;
			a[i][1+j*4+2] = (v >> 1) & 1;
			a[i][1+j*4+3] = (v >> 0) & 1;
		}
	}
	h += 2;
	w =  w * 4 + 2;
	id = 0;
	fill_bg(0, 0);
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(mark[i][j] == -1 && a[i][j] == 1){
				cnt = 0;
				id += 1;
				fill_word(i, j);
				if(cnt <= 5){
					result[CYCLE_P[cnt]] += 1;
				}
			}
		}
	}
	
	for(int i=0;i<6;i++){
		for(int j=0;j<result[i];j++){
			printf("%c", WORD[i]);
		}
	}
	printf("\n");
}

int main(void){
	freopen("uva1103.in", "r", stdin);
	int case_id = 1;
	while(scanf("%d %d", &h, &w) != EOF){
		if(w == 0 && h == 0){
			break;	
		}
		printf("Case %d: ", case_id++);
		solve();
	}
	return 0;
}

