/**
 * @author LuoHao, LiXingnan, FuMengxin
 * 定义property：在任意目标数组(object array)中，每一个不同元素的数值(value)、出现的次数(count)、
		每次出现时在数组中的位置(position)，这些属性定义为数组的特性(property)。
 * 实验要求：统计一个任意类型数据的数组每一个不同元素的特性(property)。
 * 实现方案：用动态链表作容器(Record)，每一个结点记录一个元素的property，
		在建立链表时，边从头到尾扫描object array的每一个元素，边将结点记录在链表中。
 * 方案优势：(1)记录性，用一个稳定的容器来记录一个数组的元素特性(proprety)；
		(2)动态性，对object array中的每一个元素a，在Record中查找，
		如果Record中的一个结点p处value为a，则在p中记录；如果找不到这样的结点p，则在Record的开头添加一个新的结点，记录这个新元素a。
 **/

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
typedef int position;//专用于记录数组的下标的数据类型

/**
 * 用Record结构体建立动态链表,记录一个元素a的property
 * val 是a的数值(value)
 * count 是a在array 中的出现次数
 * position *location 是a每一次出现的位置集合
 * Record(T,Record*)是构造函数
 **/
template <typename T> struct Record {
	T val;
	size_t count;
	position *location;
	Record* next;
	Record(T value, Record* nextRecord = nullptr): val(value), count(0), next(nextRecord) {}
};
/** 函数prtotypes列表 */
template <typename T> Record<T>* findRecord(T value, Record<T>* head);
template <typename T> Record<T>* createRecord(T _array[], const size_t max_size);
template <typename T> void printRecord(Record<T>* head);
template <typename T> void sort(T* _array, size_t num);
/** 测试集 */
//	int a[] = {0, 1, 1, 2, 3, 4, 5, 5, 5, 5, 6, 0};
//	float b[] = {3.14, 3.14, 2.73, 3.14, 2.73, 0.0};
//char c[] = "aabcdddefg(yes)";

/** 用户界面设计*/
/** 负责人：李兴男*/
int main() {
	int num, k, kind;
	do {
		do {
			cout << "please choose which kind of num do you want?" << endl
			     << " 0 for short,1 for long,2 for float, 3 for double ,4 for char" << endl;
			cin >> kind;
			if (kind != 1 && kind != 2 && kind != 3 && kind != 4 && kind != 0) {
				cout << "your input is wrong please try again" << endl;
			}
		} while (kind != 1 && kind != 2 && kind != 3 && kind != 4 && kind != 0);
		do {
			cout << "please input how many num; do you want?" << endl;
			cin >> num;
			if (num <= 0 || num > 100) {
				cout << "0 < num <= 100 please" << endl;
			}
			break;
		} while (1);

		cout << "plese input " << num << " numbers" << endl;
		if (kind == 0) {
			short a[100];
			for (int i = 0; i < num; i++) {
				cin >> a[i];
			}
			sort(a, num);
			auto record = createRecord(a, num);
			printRecord(record);
		} else if (kind == 1) {
			long b[100];
			for (int i = 0; i < num; i++) {
				cin >> b[i];
			}
			sort(b, num);
			auto record = createRecord(b, num);
			printRecord(record);
		} else if (kind == 2) {
			float c[100];
			for (int i = 0; i < num; i++) {
				cin >> c[i];
			}
			sort(c, num);
			auto record = createRecord(c, num);
			printRecord(record);
		} else if (kind == 3) {
			double d[100];
			for (int i = 0; i < num; i++) {
				cin >> d[i];
			}
			sort(d, num);
			auto record = createRecord(d, num);
			printRecord(record);
		} else if (kind == 4) {
			char e[100];
			for (int i = 0; i < num; i++) {
				cin >> e[i];
			}
			sort(e, num);
			auto record = createRecord(e, num);
			printRecord(record);
		}

		cout << "input 0 to over/1 to go on" << endl;
		fflush(stdin);
		cin >> k;
	} while (k == 1);
	return 0;
}

/** 用头插法建立Record链表 */
/** 函数作者：罗浩 */
template <typename T>
Record<T>* createRecord(T _array[], const size_t max_size) {
	Record<T>* head = new Record<T>(0);//用头插法建立链表，head结点不记录数据，最新插入的元素会放在head->next里。如果head->next==nullptr则说明容器是空的
	for (position i = 0; i < max_size; i++) {
		auto p = findRecord(_array[i], head);//查找容器中是否存在_array[i]，如果存在则得到的返回值是对应的结点；否则得到空指针
		if (p != nullptr) {		//如果已经存在_array[i]，则在p结点中更新_array[i]的property，添加一个新position，并把
			p->location[p->count++] = i;
		} else {				//如果容器中不存在_array[i],则在head和head->next中间插入一个新的结点newRecord
			auto newRecord = new Record<T>(_array[i], head->next);
			newRecord->location = new position[max_size];
			newRecord->location[newRecord->count++] = i;
			head->next = newRecord;
		}
	}
	return head;
}
/** 寻找链表中是否包含某个结点p，它记录了数值value的property，返回该节点p；如果不存在则返回nullptr */
/** 函数作者：符梦鑫*/	//注意：head自身不包含数据，第一组数据在head->next中
template <typename T>
Record<T>* findRecord(T value, Record<T>* head) {
	auto p = head->next;
	while (p) {
		if (abs(p->val - value) == 0)
			return p;
		p = p->next;
	}
	return nullptr;
}
/** 将容器的内容输出出来 */
/** 函数作者：李兴男*/
template <typename T>
void printRecord(Record<T>* head) {
	cout << fixed << setprecision(3);
	auto p = head->next;
	while (p) {
		cout << "元素值:" << setw(8) << p->val << " 出现次数:" << setw(4) << p->count << " ;他们的位置:";
		for (int i = 0; i < p->count; i++) {
			cout << setw(4) << p->location[i] + 1 << ", ";
		}
		cout << endl;
		p = p->next;
	}
}

template <typename T>
void sort(T* _array, size_t num) {
	for (int i = num - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (_array[j] > _array[j + 1]) {
				T temp = _array[j];
				_array[j] = _array[j + 1];
				_array[j + 1] = temp;
			}
}
