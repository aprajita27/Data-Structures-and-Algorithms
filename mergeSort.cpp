// Merge Sort: TC = O(nlog(n))
#include <iostream>
#include <vector>

using namespace std;
void merge(vector<int>& left, vector<int>& right, vector<int>& nums);
void mergeSort(vector<int>& nums) {
	int n = nums.size();
	if (n == 1)
		return;
	int mid = n / 2;
	vector<int> left;
	vector<int> right;
	for (int i = 0; i < mid; ++i)
		left.push_back(nums[i]);
	for (int i = mid; i < n; ++i)
		right.push_back(nums[i]);

	mergeSort(left);
	mergeSort(right);
	merge(left, right, nums);	
}

void merge(vector<int>& left, vector<int>& right, vector<int>& nums) {
	int nLeft = left.size();
	int nRight = right.size();
	int i = 0, j = 0, k = 0;

	while (i < nLeft && j < nRight) {
		if (left[i] <= right[j]) {
			nums[k] = left[i];
			i++;
			k++;
		}
		else if (left[i] > right[j]) {
			nums[k] = right[j];
			j++;
			k++;
		}
	}
	while (i < nLeft) {
		nums[k] = left[i];
		i++;
		k++;
	}
	while (j < nRight) {
		nums[k] = right[j];
		j++;
		k++;
	}
}
int main() {
	int elem, n;
	vector<int> nums;
	cout << "\nEnter size of vector: ";
	cin >> n;
	cout << "\nEnter vector elements: ";
	for (int i = 0; i < n; ++i) {
		cin >> elem;
		nums.push_back(elem);
	}

	mergeSort(nums);
	cout << "\nSorted vector: ";
	for (auto e : nums)
		cout << e << " ";

}
