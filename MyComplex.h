#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_

#include <iostream>
using namespace std;

class myComplex {
public:
  // Constructor (생성자)
  myComplex(int real = 0, int imag = 0);
  // Copy constructor (복사생성자)
  myComplex(const myComplex& number);
  // Accessorfunctions (접근자)
  int getRealPart() const;
  int getImaginaryPart() const;

  // Mutator functions (변경자)
  void setRealPart(int real);
  void setImaginaryPart(int imag);
  void set(int real, int imag);

  myComplex operator ++();
	myComplex operator ++(int);
	myComplex operator --();
	myComplex operator --(int);
	myComplex operator -();
	myComplex operator ~();

  // Overloaded binary operators
  myComplex operator +(const myComplex& number) const;
  myComplex operator +(int value) const;

  // Overloaded assignment operators
  myComplex& operator =(const myComplex& number);
  myComplex& operator =(int value);

  // Overloaded unary operators
  // myComplex operator -();

  myComplex operator -(const myComplex& number) const;
	myComplex operator -(int value) const;
	myComplex operator *(const myComplex& number) const;
	myComplex operator *(int value) const;
	myComplex& operator +=(const myComplex& number);
	myComplex& operator +=(int value);
	myComplex& operator -=(const myComplex& number);
	myComplex& operator -=(int value);
	myComplex& operator *=(const myComplex& number);
	myComplex& operator *=(int value);
	bool operator ==(const myComplex& number) const;
	bool operator !=(const myComplex& number) const;
	bool operator >(const myComplex& number) const;
	bool operator <(const myComplex& number) const;
	bool operator >=(const myComplex& number) const;
	bool operator <=(const myComplex& number) const;

  // unary minus
  private:
    int realPart;
    int imaginaryPart;
    int norm() const;

    friend myComplex operator+(int value, const myComplex &number);
    friend myComplex operator-(int value, const myComplex &number);
    friend myComplex operator*(int value, const myComplex &number);
    friend ostream& operator<<(ostream &outStream, const myComplex& number);
    friend istream& operator>>(istream &inStream, myComplex& number);
};

#endif
