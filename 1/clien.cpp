#include<iostream>
#include"time.h"
using namespace std;
int main() {
	Time a(21, 13, 00);
	cout << a.get_hour() << a.get_minute() << a.get_second() << endl;
	return 0;
}