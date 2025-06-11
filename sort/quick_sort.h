#include"sort.h"
#pragma once
class quick_sort : public sort<int> //模板生成int/double类型随机数排序
{
public:
	void algorithm_sort(int left, int right, sf::RenderWindow& window);
	int part(int low, int high);
	void drawArray(sf::RenderWindow& window, const std::string& title);
};

