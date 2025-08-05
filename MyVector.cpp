#include <iostream>
using namespace std;

class MyVector {
public:
	MyVector(unsigned int size, int value = 0) :m_size(size) 
	{
		m_arr = new int[m_size];
		for(unsigned int i=0; i<m_size; i++)
		{
			m_arr[i] = value;
		}
	}
	
	MyVector(const MyVector& other) : m_size(other.m_size) 
	{
		m_arr = new int[m_size];
		for(unsigned int i=0; i<m_size; i++)
		{
			m_arr[i]=other.m_arr[i];
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
			m_arr = new int[m_size];
			for(unsigned int i=0; i<m_size; i++)
			{
				m_arr[i] = other.m_arr[i];
			}
		}
		return *this;
	}

	void resize(unsigned int n)
	{
		int* newArr = new int[n];
		unsigned int minSize = (n<m_size) ? n : m_size;
		for(unsigned int i=0; i<minSize; i++)
		{
			newArr[i] = m_arr[i];
		}
		for(unsigned int i=minSize; i<n; i++)
		{
			newArr[i] = 0;
		}
		delete[] m_arr;
		m_arr = newArr;
		m_size = n;
	}

	void print() const
	{
		for(unsigned int i=0; i<m_size; i++)
		{
			cout<<m_arr[i]<<" ";
		}
		cout<<endl;
	}

	int& operator [] (int index)
	{
		return m_arr[index];
	}

	int operator [] (int index) const
	{
		return m_arr[index];
	}

	unsigned int size() const
	{
		return m_size;
	}

private:
	int* m_arr;
	unsigned int m_size;	
};

int main()
{
	cout<<"Create vector v1(4, 2):\n";
	MyVector v1(4, 2);
	v1.print();
	
	cout<<"Resize v1 to size 7:\n";
	v1.resize(7);
	v1.print();

	cout<<"Resize v1 to size 3:\n";
	v1.resize(3);
	v1.print();

	cout<<"Copy Constructor:\n";
	MyVector v2 = v1;
	v2.print();

	cout<<"= operator:\n";
	MyVector v3(4, 9);
	v3 = v1;
	v3.print();

	cout<<"Modify element:\n";
	v3[1] = 36;
	v3.print();
	return 0;
}
