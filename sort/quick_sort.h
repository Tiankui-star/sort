#include"sort.h"
#pragma once
class quick_sort : public sort<int> //模板生成int/double类型随机数排序
{
public:
	void algorithm_sort(int low, int high);
	int part(int low, int high);
};

