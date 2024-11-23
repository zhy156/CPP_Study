#include<iostream>
using namespace std;

// 抽象产品类
class Product {
public:
	virtual void operation() = 0; // 定义产品接口
	virtual ~Product() {}
};

// 具体产品类
class ProductA : public Product {
public:
	void operation() {
		cout << " ProductA operation " << endl;
	}
};

class ProductB : public Product{
public:
	void operation() {
		cout << " ProductB operation " << endl;
	}
};

// 简单工厂模式
class SimpleFactory {
public:
	// static接口, 直接调用
	static unique_ptr<Product> createProduct(const string& type) {
		if (type == "A") {
			return make_unique<ProductA>();
		}
		else if (type == "B") {
			return make_unique<ProductB>();
		}
	}
};

void test1() {
	// 创建产品A
	unique_ptr<Product> productA = SimpleFactory::createProduct("A");
	productA->operation();
	// 创建产品B
	unique_ptr<Product> productB = SimpleFactory::createProduct("B");
	productB->operation();
}


// 抽象工厂模式
class Factory {
public:
	virtual unique_ptr<Product> createProduct() = 0;
	virtual ~Factory(){}
};

// 具体工厂
class FactoryA : public Factory {
public:
	unique_ptr<Product> createProduct() {
		return make_unique<ProductA>();
	}
};

class FactoryB : public Factory {
public:
	unique_ptr<Product> createProduct() {
		return make_unique<ProductB>();
	}
};

void test2() {
	// 需要实例化具体的工厂
	unique_ptr<Factory> factoryA = make_unique<FactoryA>();
	unique_ptr<Product> productA = factoryA->createProduct();
	productA->operation();

	unique_ptr<Factory> factoryB = make_unique<FactoryB>();
	unique_ptr<Product> productB = make_unique<ProductB>();
	productB->operation();
}

int main() {
	test1();
	test2();
	return 0;
}
