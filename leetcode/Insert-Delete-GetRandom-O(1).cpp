#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <utility>

using namespace std;

class RandomizedSet {
private:
	unordered_map<int, int> map;
	vector< int > data;
public:
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
    	if(map.count(val) > 0) {
    		return false;
		}
		
		map.insert({ val, data.size() });
		data.push_back(val);
        
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
    	auto it = map.find(val);
        if(it == map.end()) {
    		return false;
		}
		
		/* move last to index */
		int last = data[data.size() - 1];
		int index = it->second;
		data[index] = last;
		data.pop_back();
		map.find(last)->second = index;
		map.erase(val);
		
		return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return data[rand() % data.size()];
    }
};


int main(void) {
	ios::sync_with_stdio(false);
	
	RandomizedSet obj;
 	
	cout << obj.insert(1) << '\n';
	cout << obj.insert(1) << '\n';
 	cout << obj.remove(2) << '\n';
 	cout << "Should be 1: " << obj.getRandom() << '\n';
	
	cout << obj.insert(2) << '\n';
	cout << "Should be 1 or 2: " << obj.getRandom() << '\n';
	cout << obj.remove(1) << '\n';
	cout << obj.insert(2) << '\n';
	cout << "Should be 2: " << obj.getRandom() << '\n';
	
	auto x = {1, 2};
	
	return 0;
}
