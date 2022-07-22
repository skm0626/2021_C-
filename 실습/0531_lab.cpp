#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include "0531_team.h"
using namespace std;
template <class T>

void print_container(const T& container, string s = "") {
    cout << s << "(" << container.size() << ")";
    auto it = container.begin();
    for(; it != container.end(); it++) cout << *it << " ";
    cout << endl;
}

bool teamCmp_byName (const Team & a, const Team& b) { return a.name < b.name ;}

struct TeamCmp_byVictory {
  	bool operator() (const Team& a, const Team& b) { return a.victory < b.victory; }
};

int main(int argc, char * argv[]) {
	Team t[] = {Team("Bulls", 7), Team("Warriors", 5), Team("Spurs", 2)};
  vector<Team> v(begin(t), end(t));
  print_container(v, "v= ");

	sort(v.begin(), v.end(), teamCmp_byName);
  print_container(v, "v= ");

	sort(v.begin(), v.end(), TeamCmp_byVictory());
  print_container(v, "v= ");

	v.insert(v.begin(), Team("Lakers", 3));
  print_container(v, "v= ");

	set<Team, TeamCmp_byVictory> s(begin(t), end(t));
  print_container(s, "s= ");

	s.insert(s.begin(), Team("Lakers", 3));
  print_container(s, "s= ");

	priority_queue<Team, vector<Team>, TeamCmp_byVictory> p(begin(t), end(t));

	p.push(Team("Lakers", 3));

	cout << "priority queue : ";
	while(p.size() > 0) {
		cout << p.top() << " ";
		p.pop();
	}
	cout << endl;
  return 0;
}
