#include <stdio.h>
#include <string.h>

const char D[4] = {'N', 'E', 'S', 'W'};
const int DXY[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
const int MAX = 105;

struct rbt {
	int x, y;
	int d;
};

struct cmd {
	int id, repeat;
	char d;
};

int w, h;
int n, m;
int a[MAX][MAX];
struct rbt robot[MAX];
struct cmd cmds[MAX];

bool inside(int x, int y){
	return x > 0 && y > 0 && x <= w && y <= h;
}

inline
int convert(char d){
	switch(d){
	case 'N':
		return 0;
	case 'E':
		return 1;
	case 'S':
		return 2;
	case 'W':
		return 3;
	}
}

void solve(){
	memset(a, 0, sizeof(a));
	memset(robot, 0, sizeof(robot));
	
	scanf("%d %d", &w, &h);
	scanf("%d %d", &n, &m);
	
	for(int i=1;i<=n;i++){
		char d = 0;
		scanf("%d %d", &robot[i].x, &robot[i].y);
		do{
			scanf("%c", &d);
		}while(!(d == 'W' || d == 'S' || d == 'E' || d == 'N'));
		robot[i].d = convert(d);
		a[robot[i].x][robot[i].y] = i;
		//printf("%d %d %d\n", robot[i].x, robot[i].y, robot[i].d);
	}
	
	for(int i=0;i<m;i++){
		scanf("%d %c %d", &cmds[i].id, &cmds[i].d, &cmds[i].repeat);
		//printf("%d %c %d\n", id, d, repeat);
	}
	
	for(int i=0;i<m;i++){
		int & id = cmds[i].id;
		int & repeat = cmds[i].repeat;
		char & d = cmds[i].d;
		
		if(!inside(robot[id].x, robot[id].y)){
			printf("Robot %d crashes into the wall\n", id);
			return;
		}
		
		for(int j=0;j<repeat;j++){
			if(d == 'F'){
				int & tx = robot[id].x;
				int & ty = robot[id].y;
				a[tx][ty] = 0;
				tx += DXY[robot[id].d][0];
				ty += DXY[robot[id].d][1];
				
				if(!inside(tx, ty)){
					printf("Robot %d crashes into the wall\n", id);
					return;
				}
				
				if(a[tx][ty] != 0){
					printf("Robot %d crashes into robot %d\n", id, a[tx][ty]);
					return;
				}
				a[tx][ty] = id;
			}else if(d == 'L'){
				robot[id].d = (robot[id].d + 4 - 1) % 4;
			}else if(d == 'R'){
				robot[id].d = (robot[id].d + 4 + 1) % 4;	
			}
		}
	}
	
	printf("OK\n");
}

int main(void){
	freopen("p2632.in", "r", stdin);
	
	int kase;
	scanf("%d", &kase);
	for(int i=0;i<kase;i++){
		solve();
	}
	return 0;
}

