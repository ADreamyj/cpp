#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;

void test1()
{

	//std::vector<int> first;
	//std::vector<int> second(4, 100);
	//std::vector<int> third(second.begin(), second.end());
	//std::vector<int> fourth(third);

	int a[] = { 1, 2, 3, 4 };
	vector <int> v(a, a + sizeof(a) / sizeof(int));

	v[0] = 10;
	cout << v[0] << endl;

	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";//10��2��3��4
	}
	cout << endl;

	vector<int> swapv;
	swapv.swap(v);//������������ֵ 

	cout << "v data:";
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " "; //��
	}
	cout << endl;

	cout << "swapv data:";
	for (size_t i = 0; i < swapv.size(); ++i)
	{
		cout << swapv[i] << " "; //10��2��3��4
	}
	cout << endl;

}
void test2()//resize�ڿ��ռ��ʱ����г�ʼ����Ӱ��size;
{
	std::vector<int> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(i);
		cout << v[i] << endl;
	}
	v.resize(5);

	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	v.resize(8, 100);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	v.resize(12);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
void test3()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	// ʵ��ɾ��v�е�����ż��
	// ����ĳ����������������ż����erase����itʧЧ  
	// ��ʧЧ�ĵ���������++it���ᵼ�³������ 
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.erase(it);
		}
		else
			++it;
	}
	for (auto a : v)
	{
		cout << a << " ";
	}
	cout << endl;
}
class String
{
public:
	String(const char* s = "")//����
		:_str(new char[strlen(s) + 1])
	{
		strcpy(_str, s);
	}
	String(const String& s)//��������
		:_str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			delete[]_str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
	char* c_str()
	{
		return this->_str;
	}
private:
	char* _str;
};
void test5()
{
	String s1("hello");
	cout << s1.c_str() << endl;
}
int main()
{
	//test1();
	//test2();
	//test3();
	test5();
	system("pause");
	return 0;
}