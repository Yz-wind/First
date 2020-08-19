//案例描述：实现一个通用的数组类，要求如下：
//1 可以对内置数据类型以及自定义数据类型的数据进行存储
//2 将数组中的数据存储到堆区
//3 构造函数中可以传入数组的容量
//4 提供对应的拷贝函数以及operator防止浅拷贝问题
//5 提高尾插法和尾删法对数组中的数据进行增加和删除
//6 可以通过下标的方式访问数组中的元素
//7 可以获取数组中当前元素个数与数组容量

MyArray.hpp
//自己通用的数组类
#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	//有参构造 参数 容量
	MyArray(int capacity)
	{
		//cout << "Myarray有参构造调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];

	}

	//拷贝构造
	MyArray(const MyArray& arr)
	{
		//cout << "Myarray拷贝构造调用" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;

		//深拷贝
		this->pAddress = new T[arr.m_Capacity];
		//将arr中的数据都拷贝过来
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator= 防止浅拷贝问题
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "Myarray 的 operator= 调用" << endl;
		//先判断原来堆区是否有数据，如果有，先释放
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
			
		//深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
		
	}

	//尾插法
	void Push_Back(const T& val)
	{
		//判断容量是否等于大小
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;//在数组末尾插入数据
		this->m_Size++;   //更新数组大小
	}

	//尾删法
	void Pop_Back()
	{
		//让用户访问不到最后一个元素，即为尾删，逻辑删除
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	//通过下标方式访问数组中的元素
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//返回数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}

	//返回数组大小
	int getSize()
	{
		return this->m_Size;
	}
		

	//析构函数
	~MyArray()
	{
		//cout << "Myarray析构函数调用" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}

	}

private:
	T* pAddress;//指针指向堆区开辟的真实数组
	int m_Capacity;//数组容量
	int m_Size;//数组大小
};
