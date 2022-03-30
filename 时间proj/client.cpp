#include<iostream>
#include"time.h"
using namespace std;
int main() {
	Time a(22, 13, 00);
	a.show();
	a.assign(3, 12, 5);
	a.show();
	return 0;
}
