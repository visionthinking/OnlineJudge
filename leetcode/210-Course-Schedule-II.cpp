#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
	vector<vector<int>> a;
    vector<int> access; //0 for unaccess, 1 for accessed, -1 for accessing
	vector<int> res;
	int p;
public:
    bool dfs(int x) {
    	access[x] = -1;
    	for(int i : a[x]) {
    		if(access[i] == -1){
    			return false;
    		} else if(access[i] == 0 && !dfs(i)){
    			return false;	
    		}
    	}
    	access[x] = 1;
    	res[--p] = x;
    	return true;
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		a = vector<vector<int>>(numCourses, vector<int>());
	    access = vector<int>(numCourses, 0);
		res = vector<int>(numCourses, -1);
		p = numCourses;
		
		for(auto x : prerequisites) {
            a[x.second].push_back(x.first);
        }
        
        for(int i=0; i<numCourses; i+=1) {
        	if(access[i] == 0){
				if(!dfs(i)){
	        		res = vector<int>();
					break;	
	        	}
	        }
        }
        
        return res;
    }
};

int main(void) {
	Solution s;
	vector<pair<int, int>> prerequisites;
	prerequisites.push_back({0, 1});
	s.findOrder(2, prerequisites);
	return 0;
}
