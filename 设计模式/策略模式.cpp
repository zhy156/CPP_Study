#include <iostream>
#include <vector>
using namespace std;

// 抽象的策略
class SortStrategy{
public:
	virtual void sort(vector<int>& data) = 0;
	virtual ~SortStrategy() {}
};

// 具体的策略
class BubbleSort : public SortStrategy{
public:
	void sort(vector<int>& data) {
		size_t n = data.size();
		for (int i = 0; i < n - 1; ++i) {
			for (int j = 0; j < n - i - 1; ++j) {
				if (data[j] > data[j + 1]) {
					swap(data[j], data[j + 1]);
				}
			}
		}
	}
};

class QuickSort : public SortStrategy {
private:
	void qsort(vector<int>& data, int l, int r) {
		if (l > r)return;

		// 获取key
		int key = getRandomKey(data, l, r);
		// 做一次快排
		int i = l, left = l - 1, right = r + 1;
		while (i < right) {
			if (data[i] < key)swap(data[i++], data[++left]);
			else if (data[i] == key)++i;
			else swap(data[i], data[--right]);
		}
		// 重复
		qsort(data, l, left);
		qsort(data, right, r);
	}

	int getRandomKey(vector<int>& data, int l, int r) {
		return data[rand() % (r - l + 1) + l];
	}

public:
	void sort(vector<int>& data) {
		srand((unsigned int)time(NULL));
		qsort(data, 0, data.size() - 1);
	}
};

// 上下文
class Sorter
{
public:
	Sorter(SortStrategy* strategy):_strategy(strategy){}
	~Sorter() {
		delete _strategy;
	}

	// 更换策略
	void setStrategy(SortStrategy* newstrategy) {
		delete _strategy;
		_strategy = newstrategy;
	}

	// 调用策略
	void sortArray(vector<int>& data) {
		_strategy->sort(data);
	}
private:
	SortStrategy* _strategy;
};


int main()
{
	vector<int> data1 = { 5,4,3,2,1 };
	SortStrategy*  bubbleSort= new BubbleSort();
	SortStrategy*  quickSort= new QuickSort();
	Sorter sorter(bubbleSort);


	// 先使用冒泡排序
	cout << " 冒泡排序 ";
	sorter.sortArray(data1);
	for (auto num : data1) {
		cout << num << " ";
	}
	cout << endl;

	// 更换快速排序
	vector<int> data2 = { 5,4,3,2,1 };
	cout << " 快速排序 ";
	sorter.setStrategy(quickSort);
	sorter.sortArray(data2);
	for (auto num : data2) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}
