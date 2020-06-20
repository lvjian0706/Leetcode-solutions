#include<iostream>
#include<vector>
using namespace std;
//从小到大排列
/*
1.比较相邻元素，如果前面的元素大则交换两个元素,这样循环遍历完1轮后，最后一个元素为最大元素
2.重复len-1次，每次从第0个元素开始循环遍历到倒数第i+1和倒数第i个元素，则排序完成。
*/
void BubbleSort(vector<int> &numArray) {
	int len = numArray.size();
	for (int i = 0; i < len-1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (numArray[j] > numArray[j + 1]) {
				swap(numArray[j], numArray[j + 1]);
			}
		}
	}
}

/*
改进方法：
通过定义flag变量进行判断，如果在某一次遍历过程中，整整一轮中没有发生过1次交换，则说明已经排序完成。
*/
void BubbleSort2(vector<int> &numArray) {
	int len = numArray.size();
	for (int i = 0; i < len - 1; i++) {
		bool flag = false;
		for (int j = 0; j < len - i - 1; j++) {
			if (numArray[j] > numArray[j + 1]) {
				swap(numArray[j], numArray[j + 1]);
				flag = true;
			}
		}
		if (flag == false) break;
	}
}

int main1() {
	vector<int> numArray = { 9,8,7,6,0,1,2,3,4,5 };
	for (int i = 0; i < numArray.size(); i++) {
		cout << numArray[i] << ' ';
	}
	cout << endl;
	BubbleSort2(numArray);
	for (int i = 0; i < numArray.size(); i++) {
		cout << numArray[i] << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}