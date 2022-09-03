#pragma once
#include<iostream>
#include<vector>
class MergeAlgorithm {
public:
	void mergeSort(const int low, std::vector<int> data);
	
	void merge(int low, int mid, std::vector<int>, std::vector<int>, std::vector<int>);
};

template<typename T>
std::vector<T> create_copy1(std::vector<T> const vec)
{
	std::vector<T> v;

	v = vec;

	return v;
}

template<typename T>
std::vector<T> create_copy2(std::vector<T> const vec, int begin_idx, int size)
{
	std::vector<T> v(size);

	auto iterator = vec.begin() + begin_idx + size - 1;

	std::copy(vec.begin()+begin_idx, iterator, v.begin());

	return v;
}

void MergeAlgorithm::mergeSort(const int low, std::vector<int> data)
{
	int size = data.size();

	if (size > 1)
	{
		const int mid = size / 2;

		const int left_size = mid;

		const int right_size = size - mid;

		std::vector<int> left, right;

		left = create_copy2(data,  0, left_size);

		right = create_copy2(data, mid, right_size);

		mergeSort(left_size, left);

		mergeSort(mid, right);

		merge(left_size, mid, left, right, data);
	}
}

void MergeAlgorithm::merge(int low, int mid, std::vector<int> left, std::vector<int> right, std::vector<int> data)
{
	int i = low, j = mid + 1, k = low, high = data.size()-1;

	auto iterator = data.begin();

	int temp[8];

	while (i <= mid && j <= high)
	{
		if (data[i] < data[j])
			temp[k++] = *(iterator+i++);
		else
			temp[k++] = *(iterator+j++);
	}

	iterator = data.begin();

	while (i <= mid)	temp[k++] = *(iterator+i++);

	while (j <= high)	temp[k++] = *(iterator+j++);

	for (int a = low; a <= high; a++)
		data[a] = temp[a];

}

