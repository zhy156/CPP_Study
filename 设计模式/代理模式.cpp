#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// 抽象主题类
class Subject 
{
public:
	virtual void request() = 0;
};

// 真实主题类
class RealSubject : public Subject
{
public:
	void request()override
	{
		cout << "真实的请求" << endl;
	}
};

// 代理类
class Proxy : public Subject
{
	RealSubject* realsubject = nullptr;
	bool start = false;

public:
	Proxy() 
	{
		if (realsubject == nullptr) {
			realsubject = new RealSubject;
		}
		start = true;
	}
	
	~Proxy() 
	{
		if (realsubject != nullptr) {
			delete realsubject;
		}
	}

	void request()override
	{
		if (start == true) {
			cout << "执行代理" << endl;
			realsubject->request();
		}
	}
public:
	// 其它功能
	bool check_start() {
		return start;
	}

	bool set_start(int flag) 
	{
		start = flag;
	}
};

void test() 
{
	// 使用代理进行请求
	Subject* A_Subject = new Proxy;
	A_Subject->request();
	cout << endl;

	// 不使用代理
	Subject* B_Subject = new RealSubject;
	B_Subject->request();

	delete A_Subject;
	delete B_Subject;
}

int main() 
{
	test();
	return 0;
}
