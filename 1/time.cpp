#include"time.h"
Time::Time(double h, double min, double s): hours(h), minutes(min), seconds(s) {}
Time::~Time() {}
double Time::get_hour() {
	return hours;
}
double Time::get_minute() {
	return minutes;
}
double Time::get_second() {
	return seconds;
}
void Time::set_hour(double h) {
	hours = h;
}
void Time::set_minute(double min) {
	minutes = min;
}
void Time::set_second(double s) {
	seconds = s;
}
