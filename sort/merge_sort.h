#include"sort.h"
#pragma once
class merge_sort : public sort<int> //模板改为double型
{
public:
	void algorithm_sort(int left,int right);
	void merge(int left,int mid, int right);
};

