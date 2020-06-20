#include<iostream>
#include<vector>
using namespace std;

/*
1.每轮在未排序元素中找到最小元素的索引，然后与第1个未排序元素交换
2.循环遍历len-1次
*/
void SelectionSort(vector<int> &numArray) {
	int len = numArray.size();
	for (int i = 0; i < len - 1; i++) {
		int min_ind = i;
		for (int j = i; j < len; j++) {
			if (numArray[j] < numArray[min_ind]) {
				min_ind = j;
			}
		}
		swap(numArray[min_ind], numArray[i]);
	}
}

/*
改进方法：
每次既计算最小值也计算最大值，最小值与第1个未排序元素交换，最大值与最后1个未排序元素交换
注意：
当搜索到的最大值索引为第1个未排序元素时，
由于先将最小值与第1个未排序元素交换，所以最大值被交换到最小值索引处，
因此需要将最大值索引更新，更新为最小值索引再进行交换
*/
void SelectionSort2(vector<int> &numArray) {
	int len = numArray.size();
	for (int i = 0; i < len/2; i++) {
		int min_ind = i;
		int max_ind = len - i - 1;
		for (int j = i; j < len-i; j++) {
			if (numArray[j] < numArray[min_ind]) {
				min_ind = j;
			}
			if (numArray[j] > numArray[max_ind]) {
				max_ind = j;
			}
		}
		swap(numArray[min_ind], numArray[i]);
		if (max_ind == i) max_ind = min_ind;
		swap(numArray[max_ind], numArray[len-i-1]);
	}
}

int main2() {
	vector<int> numArray = { 9,8,7,6,0,1,2,3,4,5 };
	for (int i = 0; i < numArray.size(); i++) {
		cout << numArray[i] << ' ';
	}
	cout << endl;
	SelectionSort2(numArray);
	for (int i = 0; i < numArray.size(); i++) {
		cout << numArray[i] << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}