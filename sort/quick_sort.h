#include"sort.h"
#pragma once
class quick_sort : public sort<int> //ģ������int/double�������������
{
public:
	void algorithm_sort(int low, int high);
	int part(int low, int high);
};

