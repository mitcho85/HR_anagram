#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


unordered_map <char, int> createMap(string a) {
	// parse string a into a map
	unordered_map<char, int> map;
	for (int i = 0; i < a.length(); ++i) {
		map[a[i]]++;
	}
	return map;
}

int findFreqDifference(unordered_map<char, int> mapA, string a) {
	// counter to keep track of the frequency difference
	int tfd = 0;
	// decrement the map for every character in string a
	for (int i = 0; i < a.length(); ++i) {
		mapA[a[i]]--;
	}

	// find the sum of the non-zero abslute values in the map
	for (auto it = mapA.begin(); it != mapA.end(); it++) {
		if (it->second != 0) {
			tfd = tfd + abs(it->second);
		}
	}

	// return the total frequency difference
	return tfd;
}

int number_needed(string a, string b) {
	// create maps for each string
	unordered_map<char, int> mapA = createMap(a);
	unordered_map<char, int> mapB = createMap(b);

	// find the frequency difference between each one
	int tfd1 = findFreqDifference(mapA, b);
	int tfd2 = findFreqDifference(mapB, a);;

	// return the greater of the two, which represents the minimum number of characters needed to 
	// make each string an anagram of each other
	return tfd1 < tfd2 ? tfd1 : tfd2;
}

int main() {
	string a;
	cin >> a;
	string b;
	cin >> b;
	cout << number_needed(a, b) << endl;
	cin >> b;
	return 0;
}