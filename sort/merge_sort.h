#include"sort.h"
#pragma once
class merge_sort : public sort<int> //ģ���Ϊdouble��
{
public:
	void algorithm_sort(int left,int right);
	void merge(int left,int mid, int right);
};

