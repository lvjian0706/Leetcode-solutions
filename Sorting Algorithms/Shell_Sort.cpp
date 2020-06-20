#include<iostream>
#include<vector>
using namespace std;

/*
1.将原始数组拆分为len/2组，分别对每组进行插入排序，
其中每组从第m+k个元素开始(当组数为k时，m为0到k-1，即为每组第一个元素)，前后元素间隔为k
2.每轮将数组合并为原始组数的两倍，也就是间隔缩小一半
*/
void ShellSort(vector<int> &numArray) {
	int len = numArray.size();
	for (int k = len / 2; k >= 1; k /= 2) {
		for (int m = 0; m < k; m++) {
			for (int i = m+k; i < len; i += k) {
				int temp = numArray[i];
				int j = i;
				while (j > m && numArray[j - k] > temp) {
					numArray[j] = numArray[j - k];
					j -= k;
				}
				numArray[j] = temp;
			}
		}
	}
}

/*
改进方法：
不再依次对每个组进行排序（排完一个组再排下一个组），而是轮流对所有组的元素进行排序
*/
void ShellSort2(vector<int> &numArray) {
	int len = numArray.size();
	for (int k = len / 2; k > 0; k /= 2) {
		for (int i = k; i < len; i++) {
			int temp = numArray[i];
			int j = i;
			while (j-k >= 0 && numArray[j - k] > temp) {
				numArray[j] = numArray[j - k];
				j -= k;
			}
			numArray[j] = temp;
		}
	}
}

int main4() {
	vector<int> numArray = { 9,8,7,6,0,1,2,3,4,5 };
	for (int i = 0; i < numArray.size(); i++) {
		cout << numArray[i] << ' ';
	}
	cout << endl;
	ShellSort2(numArray);
	for (int i = 0; i < numArray.size(); i++) {
		cout << numArray[i] << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}