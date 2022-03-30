#ifndef _TIME_H
#define _TIME_H
class Time {
private:
	int hours;
	int minutes;
	int seconds;
public:
	Time(int h, int min, int s);//构造函数，初始化对象
	~Time();//析构函数
	int hour_get();//获得私有成员的数值
	int minute_get();
	int seconde_get();
	void hour_set(int h);//设置（覆盖）私有成员的数值
	void minute_set(int min);
	void second_set(int s);
	void assign(int h, int min, int s);//指派时间，同时设置时、分、秒
	void show();
};

#endif