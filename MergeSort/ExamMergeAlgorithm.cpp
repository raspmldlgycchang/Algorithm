#include<iostream>
#include"MergeSort.h"

int main(void)
{
	int data[8] = {5,2,4,7,1,3,2,6};
	
	std::vector<int> v;
	for (int i = 7; i >-1; i--)
		v.push_back(data[i]);

	std::cout << "정렬 전 >>" << std::endl;

	for (int i = 0; i < 8; i++)
		std::cout << data[i] << " ";

	MergeAlgorithm obj;

	obj.mergeSort(0, v);

	std::cout << "정렬 후 >> " << std::endl;

	for (int i = 0; i < 8; i++)
		std::cout << v[i] << " ";
}