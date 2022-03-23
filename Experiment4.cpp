/**
 * @author LuoHao, LiXingnan, FuMengxin
 * ����property��������Ŀ������(object array)�У�ÿһ����ͬԪ�ص���ֵ(value)�����ֵĴ���(count)��
		ÿ�γ���ʱ�������е�λ��(position)����Щ���Զ���Ϊ���������(property)��
 * ʵ��Ҫ��ͳ��һ�������������ݵ�����ÿһ����ͬԪ�ص�����(property)��
 * ʵ�ַ������ö�̬����������(Record)��ÿһ������¼һ��Ԫ�ص�property��
		�ڽ�������ʱ���ߴ�ͷ��βɨ��object array��ÿһ��Ԫ�أ��߽�����¼�������С�
 * �������ƣ�(1)��¼�ԣ���һ���ȶ�����������¼һ�������Ԫ������(proprety)��
		(2)��̬�ԣ���object array�е�ÿһ��Ԫ��a����Record�в��ң�
		���Record�е�һ�����p��valueΪa������p�м�¼������Ҳ��������Ľ��p������Record�Ŀ�ͷ���һ���µĽ�㣬��¼�����Ԫ��a��
 **/

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
typedef int position;//ר���ڼ�¼������±����������

/**
 * ��Record�ṹ�彨����̬����,��¼һ��Ԫ��a��property
 * val ��a����ֵ(value)
 * count ��a��array �еĳ��ִ���
 * position *location ��aÿһ�γ��ֵ�λ�ü���
 * Record(T,Record*)�ǹ��캯��
 **/
template <typename T> struct Record {
	T val;
	size_t count;
	position *location;
	Record* next;
	Record(T value, Record* nextRecord = nullptr): val(value), count(0), next(nextRecord) {}
};
/** ����prtotypes�б� */
template <typename T> Record<T>* findRecord(T value, Record<T>* head);
template <typename T> Record<T>* createRecord(T _array[], const size_t max_size);
template <typename T> void printRecord(Record<T>* head);
template <typename T> void sort(T* _array, size_t num);
/** ���Լ� */
//	int a[] = {0, 1, 1, 2, 3, 4, 5, 5, 5, 5, 6, 0};
//	float b[] = {3.14, 3.14, 2.73, 3.14, 2.73, 0.0};
//char c[] = "aabcdddefg(yes)";

/** �û��������*/
/** �����ˣ�������*/
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

/** ��ͷ�巨����Record���� */
/** �������ߣ��޺� */
template <typename T>
Record<T>* createRecord(T _array[], const size_t max_size) {
	Record<T>* head = new Record<T>(0);//��ͷ�巨��������head��㲻��¼���ݣ����²����Ԫ�ػ����head->next����head->next==nullptr��˵�������ǿյ�
	for (position i = 0; i < max_size; i++) {
		auto p = findRecord(_array[i], head);//�����������Ƿ����_array[i]�����������õ��ķ���ֵ�Ƕ�Ӧ�Ľ�㣻����õ���ָ��
		if (p != nullptr) {		//����Ѿ�����_array[i]������p����и���_array[i]��property�����һ����position������
			p->location[p->count++] = i;
		} else {				//��������в�����_array[i],����head��head->next�м����һ���µĽ��newRecord
			auto newRecord = new Record<T>(_array[i], head->next);
			newRecord->location = new position[max_size];
			newRecord->location[newRecord->count++] = i;
			head->next = newRecord;
		}
	}
	return head;
}
/** Ѱ���������Ƿ����ĳ�����p������¼����ֵvalue��property�����ظýڵ�p������������򷵻�nullptr */
/** �������ߣ�������*/	//ע�⣺head�����������ݣ���һ��������head->next��
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
/** ������������������� */
/** �������ߣ�������*/
template <typename T>
void printRecord(Record<T>* head) {
	cout << fixed << setprecision(3);
	auto p = head->next;
	while (p) {
		cout << "Ԫ��ֵ:" << setw(8) << p->val << " ���ִ���:" << setw(4) << p->count << " ;���ǵ�λ��:";
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
