#include"time.h"
#include<iostream>
#include<iomanip>
using namespace std;
Time::Time(int h = 0, int min = 0, int s = 0): hours(h), minutes(min), seconds(s) {}
Time::~Time() {}
void Time::hour_set(int h) {
	if (h >= 0 && h <= 23) {
		hours = h;
	} else {
		hours = 0;
		cout << "hour error" << endl;
	}
}
void Time::minute_set(int min) {
	if (min >= 0 && min <= 59) {
		minutes = min;
	} else {
		minutes = 0;
		cout << "minute error!" << endl;
	}
}
void Time::second_set(int s) {
	if (s >= 0 && s <= 59) {
		seconds = s;
	} else {
		seconds = 0;
		cout << "second error!" << endl;
	}
}
void Time::assign(int h, int min, int s) {
	if (h < 0 || h > 23 || min < 0 || min > 59 || s < 0 || s > 59) {
		cout << "errors happened when assign!" << endl;
	}
	hour_set(h);
	minute_set(min);
	second_set(s);
}
void Time::show() {
	cout << setw(2) << setfill(' ') << hours;
	cout << ':' << setw(2) << setfill('0') << minutes;
	cout << ':' << setw(2) << setfill('0') << seconds;
	cout << endl;
}
