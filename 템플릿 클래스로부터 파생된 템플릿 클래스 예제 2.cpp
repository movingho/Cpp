//template class inherited from another template class
//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=vjhh0712v&logNo=221561418596 에서 수정

#include<iostream>
using namespace std;

template <typename T>
class Base {
	T asset;
public:
	Base(T a) { asset = a; }
	void showBase() { cout << asset << endl; }
};

template <typename T>
class Derived : public Base<T> {
	T asset;
public:
	Derived(T a, T b) : Base<T>(a) { asset = b; }
	void showDerived() { cout << asset << endl; }
};

int main()
{
	Derived<int> D(2, 1);

	D.showBase();
	D.showDerived();

	return 0;
}