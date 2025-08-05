#include <iostream>
using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;
	int gcd(int a, int b) const
	{
		if(a==b) return a;
		if(a>b) return gcd(a-b, b);
		return gcd(a, b-a);
	}

	void normalize()
	{
		if(denominator<0)
		{
			numerator = -numerator;
			denominator = -denominator;
		}
	}

public:
	Fraction() : numerator(0), denominator(1) {}
	Fraction(int num, int denom)
	{
		if(denom==0) throw invalid_argument("Denominator can not be zero.");
		numerator = num;
		denominator = denom;
		simplify();
	}	

	void simplify()
	{
		int d = gcd(numerator, denominator);
		numerator /= d;
		denominator /= d;
		normalize();
	}

	double toDouble() const
	{
		return static_cast<double>(numerator) / denominator;
	}

	Fraction operator + (const Fraction& other) const
	{
		int num = numerator * other.denominator + other.numerator * denominator;
		int denom = denominator * other.denominator;
		return Fraction(num, denom);
	}

	Fraction operator - (const Fraction& other) const
	{
		int num = numerator * other.denominator - other.numerator * denominator;
		int denom = denominator * other.denominator;
		return Fraction(num, denom);
	}

	Fraction operator * (const Fraction& other) const
	{
		return Fraction(numerator * other.numerator, denominator * other.denominator);
	}

	Fraction operator / (const Fraction & other) const
	{
		if(other.numerator==0) throw invalid_argument("Division by zero.");
		return Fraction(numerator * other.denominator, denominator * other.numerator);
	}

	bool operator == (const Fraction& other) const
	{
		return numerator == other.numerator && denominator == other.denominator;
	}

	bool operator != (const Fraction& other) const
	{
		return !(*this == other);
	}

	bool operator > (const Fraction& other) const
	{
		return numerator * other.denominator > denominator * other.numerator;
	}

	bool operator < (const Fraction& other) const
	{
		return numerator * other.denominator < denominator * other.numerator;
	}

	friend ostream& operator << (ostream& os, const Fraction& f)
	{
		os<<f.numerator<<"/"<<f.denominator;
		return os;
	}
};

int main()
{
	Fraction a(3, 4);
	Fraction b(2, 5);
	cout<<"a = "<<a<<", b = "<<b<<endl;
	cout<<"a + b = "<<(a+b)<<endl;
	cout<<"a - b = "<<(a-b)<<endl;
	cout<<"a * b = "<<(a*b)<<endl;
	cout<<"a / b = "<<(a/b)<<endl;

	cout<<"a == b? "<<(a==b)<<endl;
	cout<<"a != b? "<<(a!=b)<<endl;
	cout<<"a > b? "<<(a>b)<<endl;
	cout<<"a < b? "<<(a<b)<<endl;

	Fraction c(10, 30);
	cout<<"Before simplify: 10/30, After simplify: "<<c<<endl;
	cout<<"a as double = "<<a.toDouble()<<endl;
	return 0;
}
