#include "quick_sort.h"
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<Windows.h>
void quick_sort::algorithm_sort(int low, int high, sf::RenderWindow& window)
{
	int mid;
	if (low < high)
	{
		mid = part(low, high);
		int t_count = 0;
		std::cout << "this is the " << ++sort_count << " times quick sort" << std::endl;
		for (int i = 0; i < a.size(); i++)
		{
			std::cout << std::fixed << std::setprecision(2) << std::setw(5) << a[i] << ' ';
			if (++t_count == 10)
			{
				std::cout << std::endl;
				t_count = 0;
			}
		}
		if (t_count != 0) std::cout << std::endl;
		std::cout << std::endl;
		drawArray(window, "Quick Sort Step");
		Sleep(1000);
		algorithm_sort(low, mid - 1,window);
		algorithm_sort(mid + 1, high,window);	
	}
}
int quick_sort::part(int low, int high)
{
	//int point = a[low] + a[high] + a[(low + high) / 2] - std::min(std::min(a[low], a[(high + low) / 2]), a[high]) - std::max(std::max(a[low], a[(low + high) / 2]), a[high]);
	int i = low - 1, j;
	int point = a[high];
	for (j = low; j < high; j++)
	{
		if (a[j] <= point)
		{
			i++;
			std::swap(a[i], a[j]);
		}
	}
	std::swap(a[i + 1], a[high]);

	return i + 1;
}
// 辅助函数：用于绘制当前数组状态
void quick_sort::drawArray(sf::RenderWindow& window, const std::string& title)
{
	
	static sf::Font defaultFont;
	static bool fontLoaded = false;
	if (!fontLoaded) {
		if (!defaultFont.loadFromFile("ARIAL.TTF")) { // 换成你项目中存在的字体路径
			std::cerr << "Failed to load font!" << std::endl;
			return;
		}
		fontLoaded = true;
	}
	window.clear(sf::Color::White);
	float barWidth = 800.0f / a.size(); // 假设窗口宽度为800
	float maxValue = *std::max_element(a.begin(), a.end());

	for (size_t i = 0; i < a.size(); ++i) {
		float barHeight = (a[i] / maxValue) * 500.0f; // 按比例缩放高度，最大为500
		float x = i * barWidth;
		float y = 600 - barHeight; // 窗口高度为600

		// 绘制柱状图
		sf::RectangleShape bar(sf::Vector2f(barWidth - 2, barHeight));
		bar.setPosition(x, y);
		bar.setFillColor(sf::Color::Blue);
		window.draw(bar);

		// 显示数值
		//static sf::Font defaultFont; // 静态声明一次即可
		sf::Text text(std::to_string(a[i]), defaultFont, 16);
		text.setFillColor(sf::Color::Red);
		text.setPosition(x, y - 20); // 数值显示在柱状图上方
		window.draw(text);
	}

	window.display();
	sf::sleep(sf::seconds(0.5)); // 暂停以便观察变化
}