#ifndef _TIME
class Time {
private:
	/* data */
	double hours;
	double minutes;
	double seconds;
public:
	Time(double h, double min, double s);
	~Time();
	double get_hour();
	double get_minute();
	double get_second();
	void set_hour(double h);
	void set_minute(double min);
	void set_second(double s);
};

#endif