#include<iostream>
using namespace std;
void max(int a, int b, int c = 0);
int main() {
	int a, b, c, n, k = 0;
	do {
		cout << "please choose how many positive integer will you input ? 2 or 3 " << endl;
		cin >> n;
		if (n == 2) {
			while (1) {
				cout << "please input 2 positive integer" << endl;
				cin >> a >> b ;
				if (a < 0 || b < 0) {
					cout << "input is valid" << endl;
				} else {
					max(a, b);
					return 0;
				}
			}
		}
		if (n == 3) {
			while (1) {
				cout << "please input 3 positive integer" << endl;
				cin >> a >> b >> c;
				if (a < 0 || b < 0 || c < 0) {
					cout << "input is valid" << endl;
				} else {
					max(a, b, c);
					return 0;
				}
			}
		} else {
			k = 1;
			cout << "input is invalid" << endl;
		}
	} while (k);
}
void max(int a, int b, int c) {
	int m = c;
	if (b > m)m = b;
	if (a > m)m = a;
	cout << "m=" << m << endl;
	return ;
}



