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
// �������������ڻ��Ƶ�ǰ����״̬
void quick_sort::drawArray(sf::RenderWindow& window, const std::string& title)
{
	
	static sf::Font defaultFont;
	static bool fontLoaded = false;
	if (!fontLoaded) {
		if (!defaultFont.loadFromFile("ARIAL.TTF")) { // ��������Ŀ�д��ڵ�����·��
			std::cerr << "Failed to load font!" << std::endl;
			return;
		}
		fontLoaded = true;
	}
	window.clear(sf::Color::White);
	float barWidth = 800.0f / a.size(); // ���贰�ڿ��Ϊ800
	float maxValue = *std::max_element(a.begin(), a.end());

	for (size_t i = 0; i < a.size(); ++i) {
		float barHeight = (a[i] / maxValue) * 500.0f; // ���������Ÿ߶ȣ����Ϊ500
		float x = i * barWidth;
		float y = 600 - barHeight; // ���ڸ߶�Ϊ600

		// ������״ͼ
		sf::RectangleShape bar(sf::Vector2f(barWidth - 2, barHeight));
		bar.setPosition(x, y);
		bar.setFillColor(sf::Color::Blue);
		window.draw(bar);

		// ��ʾ��ֵ
		//static sf::Font defaultFont; // ��̬����һ�μ���
		sf::Text text(std::to_string(a[i]), defaultFont, 16);
		text.setFillColor(sf::Color::Red);
		text.setPosition(x, y - 20); // ��ֵ��ʾ����״ͼ�Ϸ�
		window.draw(text);
	}

	window.display();
	sf::sleep(sf::seconds(0.5)); // ��ͣ�Ա�۲�仯
}