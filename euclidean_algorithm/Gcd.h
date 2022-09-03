#pragma once
#include<iostream>
#include<vector>
class euclidean_algorithm {
private:
	int a;
	int b;
	int c;
public:
	euclidean_algorithm() {}
	euclidean_algorithm(int a, int b)
		:a(a), b(b),c(1) {
	}
	int gcdCalc()
	{
		std::vector<int> d;
		for (int i = 2; i < a; i++)
		{
			if (a%i == 0)
			{
				if (b%i == 0)
				{
					d.push_back(i);
				}
			}
		}
		auto iterator = d.end()-1;
		
		c = *iterator;

		return c;
	}
};