/* Uva12171, refer to book page 171. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

typedef long long ull;
struct box {
	int x0, y0, z0, x, y, z;	
};

const int MAX = 105;
int xs[MAX], ys[MAX], zs[MAX];
map<int, int> idx, idy, idz;
int a[MAX][MAX][MAX];
struct box b[MAX];
int n, xnum, ynum, znum;
ull max_di;

struct node {
	int x, y, z;	
};
struct node q[MAX*MAX*MAX];
ull volume, surface;

const int D[6][3] = {{1, 0, 0}, {-1, 0, 0},
                     {0, 1, 0}, {0, -1, 0},
					 {0, 0, 1}, {0, 0, -1}};

void print(int * x, int len){
	printf("len = %d\n", len);
	for(int i=0;i<len;i+=1){
		printf("%d ", x[i]);
	}
	printf("\n");
}

void input(){
	scanf("%d", &n);
	max_di = 1005;
	for(int i=1;i<=n;i+=1){
		scanf("%d%d%d%d%d%d", &b[i].x0, &b[i].y0, &b[i].z0, &b[i].x, &b[i].y, &b[i].z);
		xs[i*2] = b[i].x0;
		xs[i*2+1] = b[i].x0 + b[i].x;
		ys[i*2] = b[i].y0;
		ys[i*2+1] = b[i].y0 + b[i].y;
		zs[i*2] = b[i].z0;
		zs[i*2+1] = b[i].z0 + b[i].z;
	}
	xs[0] = ys[0] = zs[0] = 0;
	xs[1] = ys[1] = zs[1] = max_di;
}

int init(int * _xs, map<int, int> & _idx){
	sort(_xs, _xs+(n+1)*2);
	int _xnum = unique(_xs, _xs+(n+1)*2) - _xs;
	_idx.clear();
	for(int i=0;i<_xnum;i+=1){
		_idx[_xs[i]] = i;
	}
	return _xnum;
}

bool inside(int x, int y, int z){
	return (0 <= x && x < xnum-1 && 0 <= y && y < ynum-1 && 0 <= z && z < znum-1);
}

// marks/id: 0 for space, 2 for boxes, -1 for air-space, -2 for boxes-accessed.
void flood_fill_air(int x0, int y0, int z0){
	q[0].x = x0; q[0].y = y0; q[0].z = z0;
	int p = 0, qlen = 1;
	a[x0][y0][z0] = -1;
	while(p < qlen){
		int x = q[p].x, y = q[p].y, z = q[p].z;
		for(int i=0;i<6;i+=1){
			int tx = x + D[i][0], ty = y + D[i][1], tz = z + D[i][2];
			if(inside(tx, ty, tz) && a[tx][ty][tz] >= 0){
				if(a[tx][ty][tz] == 0){
					a[tx][ty][tz] = -1;
					q[qlen].x = tx;
					q[qlen].y = ty;
					q[qlen].z = tz;
					qlen += 1;
				}else if(a[tx][ty][tz] == 2){
					if(D[i][0]){
						surface += (ys[ty+1]-ys[ty])*(zs[tz+1]-zs[tz]);
					}else if(D[i][1]){
						surface += (xs[tx+1]-xs[tx])*(zs[tz+1]-zs[tz]);
					}else if(D[i][2]){
						surface += (xs[tx+1]-xs[tx])*(ys[ty+1]-ys[ty]);
					}
				}
			}
		}
		p += 1;
	}	
}

void flood_fill_boxes(int x0, int y0, int z0){
	q[0].x = x0; q[0].y = y0; q[0].z = z0;
	int p = 0, qlen = 1;
	a[x0][y0][z0] = -2;
	while(p < qlen){
		int x = q[p].x, y = q[p].y, z = q[p].z;
		volume += (xs[x+1]-xs[x])*(ys[y+1]-ys[y])*(zs[z+1]-zs[z]);
		// printf("(%d %d %d) vol=%d\n", x, y, z, volume);
		for(int i=0;i<6;i+=1){
			int tx = x + D[i][0], ty = y + D[i][1], tz = z + D[i][2];
			if(inside(tx, ty, tz) && a[tx][ty][tz] >= 0){
				a[tx][ty][tz] = -2;
				q[qlen].x = tx;
				q[qlen].y = ty;
				q[qlen].z = tz;
				qlen += 1;
			}
		}
		p += 1;
	}	
}

void solve(){
	xnum = init(xs, idx);
	ynum = init(ys, idy);
	znum = init(zs, idz);
	memset(a, 0, sizeof(a));
	int blk = 0;
	for(int i=1;i<=n;i+=1){
		int _x0 = idx[b[i].x0], _x1 = idx[b[i].x0 + b[i].x];
		int _y0 = idy[b[i].y0], _y1 = idy[b[i].y0 + b[i].y];
		int _z0 = idz[b[i].z0], _z1 = idz[b[i].z0 + b[i].z];
		for(int _x=_x0; _x < _x1; _x+=1){
			for(int _y=_y0; _y < _y1; _y+=1){
				for(int _z=_z0; _z < _z1; _z+=1){
					a[_x][_y][_z] = 2;
					// printf("(%d %d %d)\n", _x, _y, _z);
					blk += 1;
				}
			}
		}
	}
	volume = surface = 0;
	// fill air-space
	flood_fill_air(0, 0, 0);
	// fill boxes
	for(int _x=0; _x < xnum-1; _x+=1){
		for(int _y=0; _y < ynum-1; _y+=1){
			for(int _z=0; _z < znum-1; _z+=1){
				if(a[_x][_y][_z] >= 0){
					flood_fill_boxes(_x, _y, _z);
				}
			}
		}	
	}
	printf("%llu %llu\n", surface, volume);
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
