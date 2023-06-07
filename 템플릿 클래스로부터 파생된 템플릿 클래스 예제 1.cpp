//http://www.cplusplus.com/forum/general/49425/에서 수정
//template class inherited from another template class

#include<iostream>
using namespace std;

template <typename T>
class Base 
{
protected:
	T primary;
};

template <typename T>
class Derived : public Base<T>
{
public:
	using Base<T>::primary;
	T get() { return primary; }
	void set(T setPrim) { primary = setPrim; }
};

int main()
{
	Derived<int> test;
	test.set(5);
	cout << test.get() << endl;
}