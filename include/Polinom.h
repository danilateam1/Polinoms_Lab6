#pragma once
#include"List.h"
#include<math.h>
#include<iostream>

class Monom
{
public:
	double coef;
	double degX;
	double degY;
	double degZ;


	Monom(double c = 1., double x = 0., double y = 0., double z = 0.) : coef{ c }, degX{ x }, degY{ y }, degZ{ z }
	{}

	Monom(const Monom& mOther)
	{
		coef = mOther.coef;
		degX = mOther.degX;
		degY = mOther.degY;
		degZ = mOther.degZ;
	}

	~Monom()
	{
		coef = 0;
		degX = 0;
		degY = 0;
		degZ = 0;
	}

	Monom& operator=(const Monom& mOther)
	{
		coef = mOther.coef;
		degX = mOther.degX;
		degY = mOther.degY;
		degZ = mOther.degZ;
		return *this;
	}

	Monom operator+(const Monom& mOther)
	{	
		Monom res(*this);
		res.coef += mOther.coef;
		return res;
	}

	Monom operator*(const Monom& mOther)
	{
		Monom res(*this);
		res.coef *= mOther.coef;
		res.degX += mOther.degX;
		res.degY += mOther.degY;
		res.degZ += mOther.degZ;
		return res;
	}

	Monom operator/(const Monom& mOther)
	{
		Monom res(*this);
		res.coef /= mOther.coef;
		res.degX -= mOther.degX;
		res.degY -= mOther.degY;
		res.degZ -= mOther.degZ;
		return res;
	}

	Monom operator*(double n)
	{
		Monom res(*this);
		res.coef *= n;
		return res;
	}

	Monom operator/(double n)
	{
		Monom res(*this);
		res.coef /= n;
		return res;
	}

	bool operator==(const Monom& mOther) const 
	{
		if ((coef == mOther.coef) && (degX == mOther.degX) && (degY == mOther.degY) && (degZ == mOther.degZ))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(const Monom& mOther) const
	{
		return(!(*this == mOther));
	}

	//����������� �� ����������
	Monom deriv(char var)
	{
		Monom res(*this);
		switch (var)
		{
		case 'x':
			res.coef *= res.degX;
			res.degX -= 1.;
			break;
		case 'y':
			res.coef *= res.degY;
			res.degY -= 1.;
			break;
		case 'z':
			res.coef *= res.degZ;
			res.degZ -= 1.;
			break;
		}
		return res; 
	}

	//�������� �� ����������
	Monom integral(char var)
	{
		Monom res(*this);
		switch (var)
		{
		case 'x':
			res.coef /= res.degX + 1.;
			res.degX += 1.;
			break;
		case 'y':
			res.coef /= res.degY + 1.;
			res.degY += 1.;
			break;
		case 'z':
			res.coef /= res.degZ + 1.;
			res.degZ += 1.;
			break;
		}
		return res;
	}

	//�������� � �����(�������� ��� ��������� ������ �, �, z, � � �, � � z, � �.�)
	Monom pointValue(double x = 1, double y = 1, double z = 1)
	{
		Monom res(coef);
		res.coef *= (pow(x, degX) * pow(y, degY) * pow(z, degZ));
		return res;
	}

	//�����(������� ��� ������ ����� � ������������)
	friend ostream& operator<<(ostream& ostr, const Monom& m)
	{
		if (m.coef != 1)
		{
			ostr << m.coef << "x^" << m.degX << "y^" << m.degY << "z^" << m.degZ;
		}
		else
		{
			std::cout << "x^" << m.degX << "y^" << m.degY << "z^" << m.degZ;
		}
		return ostr;
	}

};


class Polinom
{
public:
	List<Monom> monoms;

	Polinom(List<Monom> list) : monoms{ list }
	{}

	Polinom operator+(const Polinom& pOther)
	{
	}

	Polinom operator-(const Polinom& pOther)
	{
	}

	Polinom operator*(const Polinom& pOther)
	{
	}

	Polinom operator/(const Polinom& pOther)
	{
	}

	Polinom operator*(double n)
	{
	}
	
	Polinom operator/(double n)
	{
	}

	Polinom operator+(double n)
	{
	}

	Polinom operator-(double n)
	{
	}


	//�����
	friend ostream& operator<<(ostream& ostr, const Polinom& p)
	{
	}
};