#include <iostream>
#include <vector>
#include <string>
using namespace std;
// 模拟简单的天气监测系统

// 抽象观察者
class Observer 
{
public:
	virtual void update(string temperature, string humidity, string pressure) = 0;
	virtual ~Observer() {}
};

// 抽象主题类
class Subject 
{
public:
	virtual void attach(Observer* observer) = 0;
	virtual void deatch(Observer* observer) = 0;
	virtual void notify() = 0;
protected:
	vector<Observer*> observers;
};

// 具体主题(天气数据)
class WeatherData : public Subject 
{
public:
	// 添加观察者
	virtual void attach(Observer* observer) override {
		observers.push_back(observer);
		cout << "已添加新用户" << endl;
	}
	// 删除观察者
	virtual void deatch(Observer* observer) override {
		for (auto it = observers.begin(); it == observers.end(); ++it) {
			if (*it == observer) {
				observers.erase(it);
				break;
			}
		}
	}
	// 通知观察者
	virtual void notify() override {
		for (auto it : observers) {
			it->update(_temperature, _humidity, _pressure);
		}
	}

	// 设置主题数据
	void setWeatherData(string temperature, string humidity, string pressure){
		_temperature = temperature;
		_humidity = humidity;
		_pressure = pressure;
		printf("天气数据已更新\n");
		notify(); // 更新数据后通知所有观察者
	}
private:
	string _temperature;
	string _humidity;
	string _pressure;
};

// 具体观察者
class WeatherPhoneApp : public Observer{
public:
	virtual void update(string temperature, string humidity, string pressure) {
		_temperature = temperature;
		_humidity = humidity;
		_pressure = pressure;
		printf("WeatherPhoneApp已更新数据 _temperature : %s, _humidity : %s, _pressure: %s \n", _temperature.c_str(), _humidity.c_str(), _pressure.c_str());
	}

private:
	string _temperature;
	string _humidity;
	string _pressure;
};

class WeathercomputerPC: public Observer {
public:
	virtual void update(string temperature, string humidity, string pressure) {
		_temperature = temperature;
		_humidity = humidity;
		_pressure = pressure;
		printf("WeathercomputerPC已更新数据 _temperature : %s, _humidity : %s, _pressure: %s \n", _temperature.c_str(), _humidity.c_str(), _pressure.c_str());
	}

private:
	string _temperature;
	string _humidity;
	string _pressure;
};

void test3() 
{
	WeatherData weatherdata;	// 具体主题
	WeatherPhoneApp phoneAPP;	// 具体观察者
	WeathercomputerPC computerPC;

	weatherdata.attach(&phoneAPP);
	weatherdata.attach(&computerPC);
	weatherdata.setWeatherData("28度", "xx湿度", "xx气压");
}

int main() {
	test3();
	return 0;
}
