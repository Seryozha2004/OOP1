#include <iostream>
using namespace std;

template <typename T>
class MyVector {
public:
	MyVector(unsigned int size, const T& value = T()) : m_size(size), m_capacity(size)
	{
		if(m_capacity > 0)
			m_arr = new T[m_capacity];
		else 
			m_arr = nullptr;
		for(unsigned int i=0; i<m_size; i++)
		{
			m_arr[i] = value;
		}
	}
	
	MyVector(const MyVector& other) : m_size(other.m_size), m_capacity(other.m_capacity)
	{
		if(m_capacity > 0)
			m_arr = new T[m_capacity];
		else 
			m_arr = nullptr;
		for(unsigned int i=0; i<m_size; i++)
		{
			m_arr[i] = other.m_arr[i];
		}
	}

	~MyVector()
	{
		delete[] m_arr;
	}

	MyVector& operator = (const MyVector& other)
	{
		if(this != &other)
		{
			delete[] m_arr;
			m_size = other.m_size;
			m_capacity = other.m_capacity;
			if(m_capacity > 0)
				m_arr = new T[m_capacity];
			else
				m_arr = nullptr;
			for(unsigned int i=0; i<m_size; i++)
			{
				m_arr[i] = other.m_arr[i];
			}
		}
		return *this;
	}

	void resize(unsigned int n, const T& value = T())
	{
		if(n > m_capacity)
			reserve(n);
		if(n > m_size)
		{
			for(unsigned int i=m_size; i<n; i++)
			{
				m_arr[i] = value;
			}
		}
		m_size = n;
	}

	void reserve(unsigned int newCapacity)
	{
		if(newCapacity <= m_capacity) return;
		T* newArr = new T[newCapacity];
		for(unsigned int i=0; i<m_size; i++)
		{
			newArr[i] = m_arr[i];
		}
		delete[] m_arr;
		m_arr = newArr;
		m_capacity = newCapacity;
	}

	void push_back(const T& value)
	{
		if(m_size == m_capacity)
		{
			if(m_capacity == 0)
			{
				reserve(1);
			}
			else 
			{
				reserve(m_capacity*2);
			}
		}
		m_arr[m_size] = value;
		m_size++;
	}

	void pop_back()
	{
		if(m_size == 0) 
			cout<<"Error: pop_back on empty vector\n";
		else m_size--;
	}

	void print() const
	{
		for(unsigned int i=0; i<m_size; i++)
		{
			cout<<m_arr[i]<<" ";
		}
		cout<<endl;
	}

	T& operator [] (unsigned int index)
	{
		return m_arr[index];
	}

	T operator [] (unsigned int index) const
	{
		return m_arr[index];
	}

	unsigned int size() const
	{
		return m_size;
	}

	unsigned int capacity() const
	{
		return m_capacity;
	}

private:
	T* m_arr;
	unsigned int m_size;
	unsigned int m_capacity;
};

int main()
{
	cout<<"Create vector v1(4, 2):\n";
	MyVector<int> v1(4, 2);
	v1.print();
	
	cout<<"Resize v1 to size 7:\n";
	v1.resize(7, 5);
	v1.print();

	cout<<"Resize v1 to size 3:\n";
	v1.resize(3);
	v1.print();

	cout<<"Copy Constructor:\n";
	MyVector<int> v2 = v1;
	v2.print();

	cout<<"= operator:\n";
	MyVector<int> v3(4, 9);
	v3 = v1;
	v3.print();

	cout<<"push_back:\n";
	v3.push_back(35);
	v3.push_back(50);
	v3.print();
	cout<<"Size: "<<v3.size()<<" Capacity: "<<v3.capacity()<<endl;

	cout<<"pop_back:\n";
	v3.pop_back();
	v3.print();
	cout<<"Size: "<<v3.size()<<" Capacity: "<<v3.capacity()<<endl;

	cout<<"Modify element:\n";
	v3[1] = 36;
	v3.print();
	return 0;
}
