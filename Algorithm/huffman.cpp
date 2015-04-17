#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 256;

struct node {
	int count;
	struct node *parent, *lchild, *rchild;
	char is_leaf;
	char c;
};

class mycmp {
public:
	bool operator() (const struct node * lhs, const struct node * rhs) const {
		return (lhs->count) > (rhs->count);
	}		
};

int get_level(struct node * t){
	int lv = 0;	
	while(t){
		lv += 1;
		t = t->parent;
	}
	return lv;
}

void solution(){
	int a[MAX];
	char c;
	
	memset(a, 0, sizeof(int) * MAX);
	
	while(scanf("%c", &c) != EOF){
		a[c] += 1;
	}
	
	vector<struct node *> v;
	for(int i=0;i<MAX;i++){
		if(a[i]){
			struct node * tmp = new struct node;
			tmp->count = a[i];
			tmp->c = i;
			tmp->parent = tmp->lchild = tmp->rchild = NULL;
			tmp->is_leaf = 1;
			v.push_back(tmp);
		}
	}
	
	priority_queue<struct node *, vector<struct node *>, mycmp> q(v.begin(), v.end());
	
	while(q.size() >= 2){
		struct node * t1 = q.top();
		q.pop();
		struct node * t2 = q.top();
		q.pop();
		struct node * t3 = new struct node;
		t3->count = t1->count + t2->count;
		t3->c = 0;
		t3->parent = NULL;
		t3->lchild = t1;
		t3->rchild = t2;
		t3->is_leaf = 0;
		t1->parent = t3;
		t2->parent = t3;
		q.push(t3);
	}
	
	int sum = 0;
	for(int i=0;i<v.size();i++){
		//printf("[%c] %d level = %d\n", v[i]->c, v[i]->count, get_level(v[i]));
		sum += v[i]->count * (get_level(v[i]) - 1);
	}
	printf("%d\n", sum);
}

int main(void){
	
	freopen("huffman.in", "r", stdin);
	
	solution();
	
	return 0;
}
