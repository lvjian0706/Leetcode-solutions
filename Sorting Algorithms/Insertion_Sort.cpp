#include<iostream>
#include<vector>
using namespace std;

/*
1.每轮默认前i-1个元素已经排好序了，取出第i个元素，从后向前依次与前面元素进行比较，
当前面元素大于取出元素时，将前面的元素向后移动一位；当前面元素小于取出元素时，将取出元素放置于当前位置
2.从i=1开始遍历（默认i=0位置已经排好序了），遍历到len-1位置
*/
void InsertionSort(vector<int> &numArray) {
	int len = numArray.size();
	for (int i = 1; i < len; i++) {
		int temp = numArray[i];
		int j = i;
		while (j > 0 && numArray[j - 1] > temp) {
			numArray[j] = numArray[j - 1];
			j--;
		}
		numArray[j] = temp;
	}
}

int main3() {
	vector<int> numArray = { 9,8,7,6,0,1,2,3,4,5 };
	for (int i = 0; i < numArray.size(); i++) {
		cout << numArray[i] << ' ';
	}
	cout << endl;
	InsertionSort(numArray);
	for (int i = 0; i < numArray.size(); i++) {
		cout << numArray[i] << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}