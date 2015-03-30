#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

#define MAX_LEN 505

struct node {
    string name;
    string sex;
    int year, month, day;
};

struct node v[MAX_LEN];

void query(const string & q, int n){
	string name, sex, birth;
	int y, m, d, p;
	y = m = d = -1;
	
	p = q.find("Name='", 0);
	if(p >= 0){
		name = q.substr(p + 6, q.find("'", p + 6) - (p + 6));
	}
	
	p = q.find("Sex='", 0);
	if(p >= 0){
		sex = q.substr(p + 5, q.find("'", p + 5) - (p + 5));
	}
	
	p = q.find("Birthday='", 0);
	if(p >= 0){
		birth = q.substr(p + 10, q.find("'", p + 10) - (p + 10));
		int found = 0;
		if(birth[0] == '*'){
			found += 2;
		}else{
			sscanf(birth.c_str(), "%d", &y);
			found += 5;
		}
		if(birth[found] == '*'){
			found += 2;
		}else{
			sscanf(birth.c_str() + found, "%d", &m);
			found += 3;
		}
		if(birth[found] == '*'){
			found += 2;
		}else{
			sscanf(birth.c_str() + found, "%d", &d);
			found += 3;
		}
		
	}
	
	//cout << q << endl;
	//printf("[%s][%s] %d/%d/%d\n", name.c_str(), sex.c_str(), y, m, d);
	bool flag = false;
	for(int i=0;i<n;i++){
		if((name.empty() || v[i].name.compare(name)==0)
			 && (sex.empty() || v[i].sex.compare(sex)==0)
			 && (y == -1 || y == v[i].year)
			 && (m == -1 || m == v[i].month)
			 && (d == -1 || d == v[i].day)){
			printf("%s\n", v[i].name.c_str());
			flag = true;
		}
	}
	if(!flag){
		printf("NULL\n");	
	}
}

void solution(){
	int n, m;
	scanf("%d %d", &n, &m);
	//data
	for(int i=0;i<n;i++){
		cin >> v[i].name;
		cin >> v[i].sex;
		scanf("%d/%d/%d", &v[i].year, &v[i].month, &v[i].day);
		//printf("[%s] [%s] %d/%d/%d\n", v[i].name.c_str(), v[i].sex.c_str(), v[i].year, v[i].month, v[i].day);
	}
	
	//query
	for(int i=0;i<m;){
		string qstr;
		getline(cin, qstr);
		if(!qstr.empty()){
			query(qstr, n);
			i++;
		}
	}
}

int main(void){
	int n;
    
    freopen("p258.in", "r", stdin);
    
    scanf("%d", &n);
    while(n--){
        solution();
    }
	return 0;	
}
