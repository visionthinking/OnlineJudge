/* Uva12171, refer to book page 171. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct box {
	int x0, y0, z0, x, y, z;	
};

const int MAX = 105;
const int ID_MAX = 505;
int xs[MAX], ys[MAX], zs[MAX];
int idx[ID_MAX], idy[ID_MAX], idz[ID_MAX];
int a[MAX][MAX][MAX];
struct box b[MAX];
int n, xn, yn, zn;

void input(){
	scanf("%d", &n);
	xs[0] = ys[0] = zs[0] = 0;
	xs[1] = ys[1] = zs[1] = 501;
	
	for(int i=1;i<=n;i+=1){
		scanf("%d%d%d%d%d%d", &b[i].x0, &b[i].y0, &b[i].z0, &b[i].x, &b[i].y, &b[i].z);
		xs[i*2] = b[i].x0;
		xs[i*2+1] = b[i].x0 + b[i].x;
		ys[i*2] = b[i].y0;
		ys[i*2+1] = b[i].y0 + b[i].y;
		zs[i*2] = b[i].z0;
		zs[i*2+1] = b[i].z0 + b[i].z;
	}
}

void print(int * x, int len){
	printf("len = %d\n", len);
	for(int i=0;i<len;i+=1){
		printf("%d ", x[i]);
	}
	printf("\n");
}

int init(int * _xs, int * _idx){
	sort(_xs, _xs+(n+1)*2);
	int xn = unique(_xs, _xs+(n+1)*2) - _xs;
	memset(_idx, 0, sizeof(int) * ID_MAX);
	for(int i=0;i<xn;i+=1){
		_idx[_xs[i]] = i;
	}
	return xn;
}

int volume, surface;
void flood_fill(int x, int y, int z, int d){
	if(!(0 <= x && x < xn-1 && 0 <= y && y < yn-1 && 0 <= z && z < zn-1)) return;
	if(a[x][y][z] == 0){
		a[x][y][z] = -1;
		volume += (xs[x+1]-xs[x])*(ys[y+1]-ys[y])*(zs[z+1]-zs[z]);
		flood_fill(x+1, y, z, 0);
		flood_fill(x-1, y, z, 0);
		flood_fill(x, y+1, z, 1);
		flood_fill(x, y-1, z, 1);
		flood_fill(x, y, z+1, 2);
		flood_fill(x, y, z-1, 2);
	}else if(a[x][y][z] > 0){
		if(d == 0){
			surface += (ys[y+1]-ys[y])*(zs[z+1]-zs[z]);
		}else if(d == 1){
			surface += (xs[x+1]-xs[x])*(zs[z+1]-zs[z]);
		}else if(d == 2){
			surface += (xs[x+1]-xs[x])*(ys[y+1]-ys[y]);
		}
	}
}

void solve(){
	xn = init(xs, idx);
	yn = init(ys, idy);
	zn = init(zs, idz);
	// printf("x=%d y=%d z=%d sizeof(a)=%u\n", xn, yn, zn, sizeof(a));
	// print(xs, xn);
	memset(a, 0, sizeof(a));
	for(int i=1;i<=n;i+=1){
		// printf("%d %d %d %d %d %d\n", b[i].x0, b[i].y0, b[i].z0, b[i].x, b[i].y, b[i].z);
		for(int _x=idx[b[i].x0]; xs[_x] < b[i].x0 + b[i].x; _x+=1){
			for(int _y=idy[b[i].y0]; ys[_y] < b[i].y0 + b[i].y; _y+=1){
				for(int _z=idz[b[i].z0]; zs[_z] < b[i].z0 + b[i].z; _z+=1){
					a[_x][_y][_z] = i;
				}
			}
		}
	}
	// flood fill
	volume = surface = 0;
	flood_fill(0, 0, 0, 0);
	volume = 501*501*501 - volume;
	printf("%d %d\n", surface, volume);
}

int main(void){
	freopen("uva12171.in", "r", stdin);
	int kase;
	scanf("%d", &kase);
	for(int i=0;i<kase;i+=1){
		input();
		solve();
	}
	return 0;
}
