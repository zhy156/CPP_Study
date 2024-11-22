#include<iostream>
using namespace std;

class BeverageMake{
public:
	void makeBeverage() {
		boil();
		brew();
		addCondition();
		putInCup();
	}

	// 提取出抽象部分
	virtual void brew() = 0;		
	virtual void addCondition() = 0;
private:
	void boil() {
		cout << "烧热水" << endl;
	}

	void putInCup() {
		cout << "放进杯中" << endl;
	}
};

// 做茶
class TeaMake : public BeverageMake{
public:
	virtual void brew() {
		cout << "冲茶" << endl;
	}

	virtual void addCondition() {
		cout << "添加条件 -- 茶" << endl;
	}
};

// 做咖啡
class CoffeMake : public BeverageMake {
public:
	virtual void brew() {
		cout << "冲咖啡" << endl;
	}

	virtual void addCondition() {
		cout << "添加条件 -- 咖啡" << endl;
	}
};

void test() {
	BeverageMake* teamake = new TeaMake();
	BeverageMake* coffemake = new CoffeMake();

	teamake->makeBeverage();
	coffemake->makeBeverage();

	delete teamake;
	delete coffemake;
}

int main() {
	test();
	return 0;
}
