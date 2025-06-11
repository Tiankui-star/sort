#include "merge_sort.h"
#include<vector>
#include<iomanip>
#include<Windows.h>
void merge_sort::merge(int left,int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	std::vector<int>L(n1), R(n2); //�޸�Ϊdouble����double�������
	for (int i = 0; i < n1; i++)
		L[i] = a[i+left];
	for (int j = 0; j < n2; j++)
		R[j] = a[mid + 1 + j];
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		a[k] = R[j];
		k++;
		j++;
	}
}
void merge_sort::algorithm_sort(int left, int right,sf::RenderWindow& window)
{
	if (left >= right) return;
	int mid = (left+right)/2;

	algorithm_sort(left, mid,window);
	algorithm_sort(mid + 1, right,window);
	merge(left, mid, right);
	int t_count = 0;
	std::cout << "this is the " << ++sort_count << " times quick sort" << std::endl;
	for (int i = 0; i < a.size(); i++)
	{
		std::cout  << std::fixed << std::setprecision(2) << std::setw(5) << a[i] << ' ';
		if (++t_count == 10)
		{
			std::cout << std::endl;
			t_count = 0;
		}
	}
	if (t_count != 0) std::cout << std::endl;
	std::cout << std::endl;
	drawArray(window, "Merge Sort Step");
	Sleep(1000);
}


// �������������ڻ��Ƶ�ǰ����״̬
void merge_sort::drawArray(sf::RenderWindow& window, const std::string& title)
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

