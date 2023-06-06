#include <iostream>
using namespace std;

class Person {
public:
	double money; // ���� ������ ��
	void addMoney(int money) {
		this->money += money;
	}

	static int sharedMoney; // ����
	static void addShared(int n) {
		sharedMoney += n;
	}
};

// static ���� ����. ���� ������ ����
int Person::sharedMoney=10;  // 10���� �ʱ�ȭ

// main() �Լ�
int main() {
	Person::addShared(50); // static ��� ����, ����=60
	cout << Person::sharedMoney << endl;

	Person han;
	han.money = 100;
	han.sharedMoney = 200; // static ��� ����, ����=200
	Person::sharedMoney = 300; // static ��� ����, ����=300
	Person::addShared(100); // static ��� ����, ����=400

	cout << han.money << ' ' << Person::sharedMoney << endl;
}