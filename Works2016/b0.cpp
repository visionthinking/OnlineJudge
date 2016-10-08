#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

#define MAXN 1000+5
#define MAXM 100+5
int n,m;
int score[MAXN];
int val[MAXN];
vector<vector<int> > g;

struct TreeNode {
    int id;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : id(x), left(NULL), right(NULL) {}
};


TreeNode * buildTreeFromGraph(int id , int pid){
	int left_child_id = -1;
	int right_child_id = -1;
	TreeNode *root = new TreeNode(id);

	int degree = g[id].size();
	//cout<<"building : "<<id<<" "<<pid<<endl;
	if(degree == 1){
		if(g[id][0] != pid){
			left_child_id = g[id][0];
			//cout<<"left child :" << left_child_id<<endl;
		}
	}else if(degree == 2){
		left_child_id = g[id][0] == pid ? g[id][1] : g[id][0];
		// cout<<"left child :" << left_child_id<<endl;
	}else{
		int index;
		for(index=0;index<3;index++) if(g[id][index] == pid) break;
		// cout<<index<<endl;
		if(index == 0){
			left_child_id = g[id][1];
			right_child_id = g[id][2];
		}else if(index == 1){
			left_child_id = g[id][0];
			right_child_id = g[id][2];

		}else{
			left_child_id = g[id][0];
			right_child_id = g[id][1];
		}
		// cout<<"left child :" << left_child_id<<endl;
		// cout<<"right_child_id : "<< right_child_id<<endl;
	}
	if(left_child_id!=-1) root->left = buildTreeFromGraph(left_child_id,id);
	if(right_child_id!=-1) root->right = buildTreeFromGraph(right_child_id,id);
	return root;
}

void PreOrder(TreeNode *root){
	if(!root) return;
	cout<<root->id<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
	return;
}
void InOrder(TreeNode *root){
	if(!root) return;
	InOrder(root->left);
	cout<<root->id<<" ";
	InOrder(root->right);
	return;
}

void print(vector<vector<int> > x) {
	for(int i=0; i<=m; i++) {
		cout << x[0][i] << " ";
	}
	cout << endl;
	for(int i=0; i<=m; i++) {
		cout << x[1][i] << " ";
	}
	cout << endl;
	for(int i=0; i<=m; i++) {
		cout << x[2][i] << " ";
	}
	cout << endl;
	cout << endl;
}

vector<vector<int> >  dfs(TreeNode * root, int vp){
	vector<vector<int> > l;
	vector<vector<int> > r;
	vector<vector<int> > now(3, vector<int>(m+1, -1));
	if(!root) return now;
	
	int v0 = val[root->id];
	
	//leaf
	if(!root->left && !root->right){
		now[0][0] = 0;
		now[1][1] = v0 + vp;
	}
	// two child
	else if(root->left && root->right){
		l = dfs(root->left, v0);
		r = dfs(root->right, v0);
		int v1 = val[root->left->id], v2 = val[root->right->id];
		
		for(int i1=0; i1<3; i1++) for(int i2=0; i2<3; i2++) {
            for(int m1 = 0; m1 <= m; m1 ++) {
                if(l[i1][m1] == -1) continue;
                for(int m2 = 0; m2 <= m && m1+m2 <= m; m2++) {
                    if(r[i2][m2] == -1) continue;
                    int ls = l[i1][m1], rs = r[i2][m2];
                    
                    if(i1 == 1 && i2 == 1) {
                        if(m1+m2 < m) now[1][m1+m2+1] = max(now[1][m1+m2+1], ls + rs - v0 + vp);
                        now[2][m1+m2] = max(now[2][m1+m2], ls + rs - v0);
                    } else if(i1 == 1) {
                        if(i2 == 0) {
                            if(m1+m2 < m) now[1][m1+m2+1] = max(now[1][m1+m2+1], ls + rs + v2 + vp);
                            now[2][m1+m2] = max(now[2][m1+m2], ls + rs);
                        } else {
                            if(m1+m2 < m) now[1][m1+m2+1] = max(now[1][m1+m2+1], ls + rs + vp);
                            now[2][m1+m2] = max(now[2][m1+m2], ls + rs);
                        }
                    } else if(i2 == 1){
                        if(i1 == 0) {
                            if(m1+m2 < m) now[1][m1+m2+1] = max(now[1][m1+m2+1], ls + rs + v1 + vp);
                            now[2][m1+m2] = max(now[2][m1+m2], ls + rs);
                        } else {
                            if(m1+m2 < m) now[1][m1+m2+1] = max(now[1][m1+m2+1], ls + rs + vp);
                            now[2][m1+m2] = max(now[2][m1+m2], ls + rs);
                        }
                    } else {
                        if(i1 == 0 && i2 == 0) {
                            now[0][m1+m2] = max(now[0][m1+m2], ls + rs);
                            if(m1+m2 < m) now[1][m1+m2+1] = max(now[1][m1+m2+1], ls + rs + v0 + v1 + v2 + vp);
                        } else if(i1 == 0) {
                            now[0][m1+m2] = max(now[0][m1+m2], ls + rs);
                            if(m1+m2 < m) now[1][m1+m2+1] = max(now[1][m1+m2+1], ls + rs + v0 + v1 + vp);
                        } else if(i2 == 0) {
                            now[0][m1+m2] = max(now[0][m1+m2], ls + rs);
                            if(m1+m2 < m) now[1][m1+m2+1] = max(now[1][m1+m2+1], ls + rs + v0 + v2 + vp);
                        } else {
                            now[0][m1+m2] = max(now[0][m1+m2], ls + rs);
                            if(m1+m2 < m) now[1][m1+m2+1] = max(now[1][m1+m2+1], ls + rs + v0 + vp);
                        }
                    }
                }
            }

		}

	}else{
		l = dfs(root->left, v0);
		int v1 = val[root->left->id];
		for(int i=0; i<3; i++) {
			for(int m1 = 0; m1 <= m; m1 ++) {
				int ls = l[i][m1];
				if(ls == -1) continue;
				
				if(i == 0) {
					now[0][m1] = max(now[0][m1], ls);
					if(m1 < m) now[1][m1+1] = max(now[1][m1+1], ls + v0 + v1 + vp);
				}else if(i == 1) {
					now[2][m1] = max(now[2][m1], ls);
					if(m1 < m) now[1][m1+1] = max(now[1][m1+1], ls + vp);
				}else{
					now[0][m1] = max(now[0][m1], ls);
					if(m1 < m) {
						now[1][m1+1] = max(now[1][m1+1], ls + v0 + vp);
					}
				}
			}
		}
	}
	print(now);
	return now;
}



void printGraph(){
	for(int i=1;i<=n;i++){
		for(int j=0;j< g[i].size(); j++) cout<<g[i][j]<<" ";
		cout<<endl;
	}
	return;
}

void buildGraph(){
	int x,y;
	for(int i=1;i<=n-1;i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);

		score[x] += val[y];
		score[y] += val[x];
	}
	return;

}

void slove(){
	for(int i=1;i<=n;i++){
		cin>>val[i];
		score[i] = val[i];
	}
	buildGraph();

	cout<<"score :"<<endl;
	for(int i=1;i<=n;i++) cout<<score[i]<<" ";
	cout<<endl;

	cout<<"val :"<<endl;
	for(int i=1;i<=n;i++) cout<<val[i]<<" ";
	cout<<endl;

	//printGraph();
	//find degree equal 1 as root
	int rid = 1;
	for(int i=1;i<=n;i++){
		int dgree = g[i].size();
		if(dgree == 1){
			rid = i;
			break;
		}
	}
	int pid = -1;
	cout<<"root: "<<rid<<endl;
	//build binary tree
	TreeNode *root = buildTreeFromGraph(rid,pid);
	// cout<<"pre order :"<<endl;
	// PreOrder(root);
	// cout<<endl;
	// cout<<"in order :"<<endl;
	// InOrder(root);
	// cout<<endl;
    vector< vector<int>	> r = dfs(root, 0);
	int res = max(*max_element(r[0].begin(), r[0].end()), 
                max(*max_element(r[1].begin(), r[1].end()), *max_element(r[2].begin(), r[2].end()))
              );
	cout << res << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("b0.in", "r", stdin);
    while(cin>>n>>m){
    	memset(score,0,sizeof(score));
    	memset(val,0,sizeof(val));
    	g.assign(n+5,vector<int>());
    	slove();
    }
    return 0;
}
