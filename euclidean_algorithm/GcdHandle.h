#pragma once
#include"Gcd.h"
class GcdHandle {
public:
	GcdHandle() {}
	~GcdHandle() {}
	int operator()(int a, int b)
	{
		euclidean_algorithm obj(a, b);

		int gcdCalcResult = obj.gcdCalc();

		return gcdCalcResult;
	}
};
