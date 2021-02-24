#include<iostream>
#include<set>

using namespace std;

set<int> se;
int G, P;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> G >> P;

	for (int i = 1; i <= G; i++) {
		se.insert(i);
	}

	int input;
	for (int i = 1; i <= P; i++) {
		cin >> input;
		auto temp = se.upper_bound(input);
		if (temp == se.begin()) {
			break;
		}
		se.erase(--temp);

	}

	cout << G - se.size();
}