#include <stdio.h>
#include <string.h>

struct node {
    int parent;
};

#define MAX_LEN 105
struct node a[MAX_LEN];

int get_level(int p){
    int lv = 1;
    int t = p;
    while(a[t].parent != 0){
        lv += 1;
        t = a[t].parent;
    }
    return lv;
}

void solution(){
    int n, t1, t2, len, m, tmp, p;
    memset(a, 0, sizeof(struct node) * MAX_LEN);
    
    scanf("%d", &n);
    len = n;

    //build
    for(int i = 1; i < n; i++){
        scanf("%d %d", &t1, &t2);
        a[t2].parent = t1;
    }
    
    //find
    scanf("%d", &m);
    while(m--){
        scanf("%d %d", &t1, &t2);
        int l1 = get_level(t1);
        int l2 = get_level(t2);
        if(l1 < l2){
            tmp = l1;
            l1 = l2;
            l2 = tmp;
            tmp = t1;
            t1 = t2;
            t2 = tmp;
        }
        tmp = l1 - l2;
        while(tmp--){
            t1 = a[t1].parent;
        }
        while(t1 != t2){
            t1 = a[t1].parent;
            t2 = a[t2].parent;
        }
        printf("%d\n", t1);
    }
}

int main(void){
    int n;
    
    freopen("p257.in", "r", stdin);
    
    scanf("%d", &n);
    while(n--){
        solution();
    }
	return 0;
}
