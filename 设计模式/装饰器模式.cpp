#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
// 装饰器模式: 在不改变对象结构的情况下, 动态的增加或删除功能
// 图形组件接口
class Shape 
{
public:
	virtual void draw() = 0; // 具体的组件 和 抽象类装饰器都要继承它
	virtual ~Shape() {}
};

// 具体图形组件
class Rectangle : public Shape
{
	virtual void draw()override
	{
		cout << "画一个矩形" << endl;
	}
};

// 抽象类装饰器
class ShapeDecorator : public Shape
{
public:
	ShapeDecorator(Shape* shape) :decoratedShape(shape) {}
	~ShapeDecorator() {
		delete decoratedShape; // 释放自己指向的资源
	}
	void draw()override
	{
		if (decoratedShape != nullptr) {
			decoratedShape->draw();
		}
	}
protected:
	Shape* decoratedShape; // 包含图形组件的指针, 调用被装饰对象原来的函数
};

// 具体的装饰器类
class colorShapeDecorator : public ShapeDecorator 
{
public:
	colorShapeDecorator(Shape* decoratedShape, string color) : ShapeDecorator(decoratedShape) , _color(color){}
	// 重写draw函数, 添加新功能
	void draw()override
	{
		decoratedShape->draw();
		cout << "为这个矩形添加颜色: " << _color << endl;
	}
	string _color;
};

class borderShapeDecorator : public ShapeDecorator
{
public:
	borderShapeDecorator(Shape* decoratedShape) : ShapeDecorator(decoratedShape) {}
	void draw()override
	{
		decoratedShape->draw();
		cout << "为这个矩形添加边框"  << endl;
	}
};

void test() {
	Shape* rectangle = new Rectangle;
	Shape* colorrectangle = new colorShapeDecorator(rectangle ,"red");
	Shape* finalshape = new borderShapeDecorator(colorrectangle);
	finalshape->draw();

	delete finalshape;
}

int main() 
{
	test();
	return 0;
}

/* 总结

组件接口: 是一个抽象类, 定义了被装饰对象的基本接口, 具体组件和抽象装饰器类都要实现这个接口
具体组件接口: 实现了组件接口, 是被装饰的原始对象
抽象装饰器类: 实现了组件接口, 并包含一个指向组件接口的引用变量(用来调用被装饰对象原来的方法)
具体装饰器类: 调用被装饰对象原来的方法 + 添加新功能
*/
