// 单列模式1 -- 饿汉模式
class Sigleton1 {
private:
	static Sigleton1* _ins;
	Sigleton1() {} // 构造函数私有化
	Sigleton1(const Sigleton1&) = delete; // 拷贝构造和赋值封掉
	Sigleton1& operator=(const Sigleton1&) = delete;
public:
	static Sigleton1* getInstance() {
		return _ins;
	}
};
Sigleton1* Sigleton1::_ins = new Sigleton1();

// 单列模式2 -- 懒汉模式(双检查加锁)
class Singleton2{
private:
	static Singleton2* _ins;
	static mutex _mtx;
	Singleton2() {}
	Singleton2(const Singleton2&) = delete;
	Singleton2& operator=(const Singleton2&) = delete;
public:
	static Singleton2* getInstance() {
		if(_ins == nullptr){
			lock_guard<mutex> guard(_mtx);
			if (_ins == nullptr) {
				_ins = new Singleton2();
			}
		}
		return _ins;
	}
};
Singleton2* Singleton2::_ins = nullptr;
mutex Singleton2::_mtx;

// 单列模式3 -- 懒汉模式(静态局部变量)
class Sigleton3 {
private:
	Sigleton3() {}
	Sigleton3(const Sigleton3& ) = delete;
	Sigleton3& operator=(const Sigleton3& ) = delete;
public:
	static Sigleton3* getInstance(){
		static Sigleton3 _ins;
		return &_ins;
	}
};
