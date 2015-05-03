#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int TYPE_NUM = 0;
const int TYPE_OP = 1;
struct token {
	int type;
	int data;
};

vector<struct token> tokens;

inline 
int get_level(char x){
	int level = -1;
	switch(x){
    case '+':
    case '-':
        level = 3;
        break;
    case '*':
    case '/':
        level = 4;
        break;
    case '(':
	case ')':
        level = 5;
        break;
	
	}
	return level;
}

inline
int get_result(int a, int b, char op){
	int res = 0;
	switch(op){
	case '+':
		res = a + b;
		break;
	case '-':
		res = a - b;
		break;
	case '*':
		res = a * b;
		break;
	case '/':
		res = a / b;
		break;
	}
	return res;
}

void reverse_polish(const string & exp){
	tokens.clear();
	int len = exp.length();
	int t;
	bool nn = false;
	vector<char> ops;
	for(int i=0;i<len;i++){
		char ch = exp[i];
		if('0' <= ch && ch <= '9'){
			if(!nn){
				t = 0;
				nn = true;
			}
			t = t * 10 + (ch-'0');
		}else if(ch != ' '){
			if(nn){
				nn = false;
				tokens.push_back((struct token){TYPE_NUM, t});
			}
			
			if(ch == '('){
				ops.push_back(ch);
			}else if(ch == ')'){
				while(ops.size() > 0){
					char top = ops.back();
					ops.pop_back();
					if(top == '('){
						break;
					}
					tokens.push_back((struct token){TYPE_OP, top});
				}
			}else{
				while(ops.size() > 0 && ops.back() != '(' && get_level(ops.back()) >= get_level(ch)){
					tokens.push_back((struct token){TYPE_OP, ops.back()});
					ops.pop_back();
				}
				ops.push_back(ch);
			}
		}
	}
	if(nn){
		nn = false;
		tokens.push_back((struct token){TYPE_NUM, t});
	}
	while(ops.size() > 0){
		tokens.push_back((struct token){TYPE_OP, ops.back()});
		ops.pop_back();
	}
	
	//print reverse polish expr
#ifdef PRINT_REVERSE_POLISH
	for(int i=0;i<tokens.size();i++){
		if(tokens[i].type == TYPE_NUM){
			printf("%d ", tokens[i].data);
		}else{
			printf("%c ", tokens[i].data);
		}
	}
	printf("\n");
#endif
}

void calc_reverse_polish(){
	vector<struct token> s;
	for(int i=0;i<tokens.size();i+=1){
		if(tokens[i].type == TYPE_NUM){
			s.push_back(tokens[i]);
		}else{
			int num1, num2;
			if(s.size() >= 2 && s.back().type == TYPE_NUM){
				num2 = s.back().data;
				s.pop_back();
			}else{
				printf("error\n");
				return;
			}
			if(s.back().type == TYPE_NUM){
				num1 = s.back().data;
				s.pop_back();
			}else{
				printf("error\n");
				return;
			}
			s.push_back((struct token){TYPE_NUM, get_result(num1, num2, (char)tokens[i].data)});
		}
	}
	if(s.size() > 1 || (!s.empty() && s[0].type != TYPE_NUM)){
		printf("error\n");
	}else{
		printf("%d\n", s[0].data);
	}
}

int main(void){
	ios::sync_with_stdio(false);
	freopen("expression.in", "r", stdin);
	string exp;
	while(getline(cin, exp)){
		printf("\n%s\n", exp.c_str());
		reverse_polish(exp);
		calc_reverse_polish();
	}
	return 0;
}
