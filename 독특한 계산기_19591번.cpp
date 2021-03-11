#include<iostream>
#include<string>
#include<algorithm>
#include<deque>
using namespace std;

deque<long long> num;
deque<int> cal;

void change(char x) {

	if (x == '-') cal.push_back(0);
	else if (x == '+') cal.push_back(1);
	else if (x == '/') cal.push_back(2);
	else if (x == '*') cal.push_back(3);

}

long long result(long long a, long long b, int cal) {

	long long temp = 0;
	if (cal == 0) temp = a - b;
	else if (cal == 1) temp = a + b;
	else if (cal == 2) temp = a / b;
	else if (cal == 3) temp = a * b;

	return temp;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string input;
	cin >> input;

	// µ¡¼À, »¬¼ÀºÎÅÍ

	long long s = 0;

	string number;
	if (input[0] == '-') {
		s = 1;
		while (true) {
			if (input[s] >= '0' && input[s] <= '9') {
				number += input[s];
				s++;
			}
			else {
				long long temp = -1 * stoll(number);
				num.push_back(temp);
				change(input[s]);
				number.clear();
				s++;
				break;
			}
		}
	}

	for (long long i = s; i < input.size(); i++) {
		if (i == input.size() - 1) {
			number += input[i];
			long long temp = stoll(number);
			num.push_back(temp);
		}
		if (input[i] >= '0' && input[i] <= '9') {
			number += input[i];
		}
		else {
			long long temp = stoll(number);
			num.push_back(temp);
			change(input[i]);
			number.clear();
		}
	}
	// ÀÔ·Â

	if (cal.size() == 0) cout << num[0];

	else {
		long long temp = 0;

		while (true) {


			if (cal.size() == 1) {
				temp = result(num[0], num[1], cal[0]);
				cout << temp;
				break;
			}
			else {

				if (cal[0] / 2 > cal[cal.size() - 1] / 2) {

					temp = result(num[0], num[1], cal[0]);
					num.pop_front();
					num.pop_front();
					num.push_front(temp);
					cal.pop_front();
				}
				else if (cal[0] / 2 < cal[cal.size() - 1] / 2) {

					temp = result(num[cal.size() - 1], num[cal.size()], cal[cal.size() - 1]);
					num.pop_back();
					num.pop_back();
					num.push_back(temp);
					cal.pop_back();
				}
				else { // °°´Ù¸é
					long long a = result(num[0], num[1], cal[0]);
					long long b = result(num[cal.size() - 1], num[cal.size()], cal[cal.size() - 1]);

					if (a >= b) {
						temp = result(num[0], num[1], cal[0]);
						num.pop_front();
						num.pop_front();
						num.push_front(temp);
						cal.pop_front();
					}
					else {
						temp = result(num[cal.size() - 1], num[cal.size()], cal[cal.size() - 1]);
						num.pop_back();
						num.pop_back();
						num.push_back(temp);
						cal.pop_back();
					}
				}
			}
		}
	}
}