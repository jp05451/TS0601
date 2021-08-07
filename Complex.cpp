#include"Complex.h"

Complex::Complex() 
{
				realValue = 0; 
				imaginaryValue = 0; 
}
//~Complex();
Complex::Complex(double r)
{
				realValue = r; 
				imaginaryValue = 0; 
}
//~Complex(double r);
Complex::Complex(double r, double i) 
{
				realValue = r;
				imaginaryValue = i; 
}
//~Complex(double r, double i);
double Complex::real() 
{
				return realValue; 
}
double Complex::imag() 
{
				return imaginaryValue;
}
double Complex::norm() 
{
				return sqrt(pow(realValue, 2) + pow(imaginaryValue, 2)); 
}
double real(Complex c) 
{
				return c.realValue; 
}
double imag(Complex c) 
{
				return c.imaginaryValue; 
}

double norm(Complex c)
{ 
				return sqrt(pow(c.realValue, 2) + pow(c.imaginaryValue, 2)); 
}
Complex Complex::operator+(Complex c) 
{
				Complex temp;
				temp.realValue = c.realValue + realValue;
				temp.imaginaryValue = c.imaginaryValue + imaginaryValue;
				return temp;
}
Complex Complex::operator-(Complex c) 
{
				Complex temp;
				temp.realValue = realValue-c.realValue;
				temp.imaginaryValue = imaginaryValue-c.imaginaryValue;
				return temp;
}
Complex Complex::operator*(Complex x) 
{
				Complex temp;
				double a = real(), b = imag();
				double c = x.real(), d = x.imag();
				temp.realValue = a * c - b * d;
				temp.imaginaryValue = a * d + b * c;
				return temp;
}
Complex Complex::operator/(Complex x) 
{
				Complex temp;
				double a = this->real(), b = this->imag();
				double c = x.real(), d = x.imag();
				double n = pow(c, 2) + pow(d, 2);
				temp.realValue = (a * c + b * d) / n;
				temp.imaginaryValue = (a * -1 * d + b * c) / n;
				return temp;
}

Complex operator+(double d, Complex c) 
{
				Complex temp;
				temp.realValue = c.realValue + d;
				temp.imaginaryValue = c.imaginaryValue;
				return temp;
}
Complex operator-(double d, Complex c) 
{
				Complex temp;
				temp.realValue = d-c.realValue;
				temp.imaginaryValue = -1*c.imaginaryValue;
				return temp;
}
Complex operator*(double d, Complex c) 
{
				Complex temp;
				temp.realValue = c.realValue * d;
				temp.imaginaryValue = c.imaginaryValue * d;
				return temp;
}
Complex operator/(double d, Complex x) 
{
				Complex temp;
				double a = x.real();
				double b = x.imag();
				double n = pow(a, 2) + pow(b, 2);
				temp.realValue = d / n * a;
				temp.imaginaryValue = d / n * b * -1;
				return temp;
}
bool operator==(const Complex c1, const Complex c2)
{
				return (c1.imaginaryValue == c2.imaginaryValue && c1.realValue == c2.realValue);
}
ostream& operator<<(ostream& strm, const Complex& c) 
{
				strm<< c.realValue << " + " << c.imaginaryValue << "*i" ;
				return strm;
}
istream& operator>>(istream& strm, Complex& c) 
{
				string str;
				size_t a=0;
				getline(strm, str);
				//cout << test << endl;
				sscanf_s(str.c_str()+1, " = %lf + %lf", &c.realValue, &c.imaginaryValue);
				//c.realValue=stod(&str[4], &a);//x = 3 + 4*i
				//c.imaginaryValue=stod(&str[a + 5]);
				return strm;
}
