#include "Convert.hpp"
#include <iostream>
#include <string>
#include <cerrno>
#include <climits>
#include <stdlib.h>
#include <cfloat>
#include <iomanip>

Convert::Convert()
: _line("")
{
	std::cout << "Convert Default Constructor Called\n";
	_doubleRangedOut = 0;
	_doubleImpossible = 0;
	_floatImpossible = 0;
	_doubleNaned = 0;
	_doubleInfinited = 0;
	_doubleVal = 0;
	_intVal = 0;
	_str_end = 0;
}

Convert::Convert(const char *str)
 : _line(str)
{
	std::cout << "Convert NonDefault Constructor Called\n";
	_doubleRangedOut = 0;
	_doubleImpossible = 0;
	_floatImpossible = 0;
	_doubleNaned = 0;
	_doubleInfinited = 0;
	_doubleVal = 0;
	_intVal = 0;
	_str_end = 0;
}
	
Convert::~Convert()
{
	std::cout << "Convert Destructor Called\n";
}
	
Convert::Convert(const Convert& rC)
: _line(rC._line)
{
	std::cout << "Convert Copy Constructor Called\n";
	_doubleRangedOut = rC._doubleRangedOut;
	_doubleImpossible = rC._doubleImpossible;
	_floatImpossible = rC._floatImpossible;
	_doubleNaned = rC._doubleNaned;
	_doubleInfinited = rC._doubleInfinited;
	_doubleVal = rC._doubleVal;
	_intVal = rC._intVal;
	_str_end = rC._str_end;
}
	
Convert& Convert::operator=(const Convert& rC)
{
	if (this == &rC)
		return (*this);
	_line = rC._line;
	_doubleRangedOut = rC._doubleRangedOut;
	_doubleImpossible = rC._doubleImpossible;
	_floatImpossible = rC._floatImpossible;
	_doubleNaned = rC._doubleNaned;
	_doubleInfinited = rC._doubleInfinited;
	_doubleVal = rC._doubleVal;
	_intVal = rC._intVal;
	_str_end = rC._str_end;
	return (*this);
}

void	Convert::getLine()
{
	if (_line == "")
		throw InputFailedException();
	changeActualType();
}

void	Convert::changeActualType()
{
	errno = 0;
	if (_line.size() == 1)
	{
		_intVal = static_cast<int>(_line.c_str()[0]);
		if (_intVal >= '0' && _intVal <= '9')
			_intVal -= '0';
	}
	else
	{
		_doubleVal = strtod(_line.c_str(), &_str_end);
		checkRangeError();
		checkInfinityAndNan();
	}
}

void	Convert::checkRangeError()
{
	if (errno == ERANGE)
		_doubleRangedOut = 1;
	if ((*_str_end != 0) && ((*_str_end != 'f') || (_str_end[1] != 0)))
	{
		_doubleImpossible = 1;
		_floatImpossible = 1;
	}
}

void	Convert::showInfo()
{
	if (_line.size() == 1)
		showInfoFromInt();
	else
		showInfoFromDouble();
}

void	Convert::showInfoFromDouble()
{
	showChar();
	showInt();
	showFloat();
	showDouble();
}

void	Convert::showInfoFromInt()
{
	if ((_intVal > CHAR_MAX) || (_intVal < CHAR_MIN))
		std::cout << "char : Out of Ranged!\n";
	else if ((_intVal > CHAR_DISPLAY_MAX) || (_intVal < CHAR_DISPLAY_MIN))
		std::cout << "char : Non displable.\n";
	else
		std::cout << "char : " << static_cast<char>(_intVal) << std::endl;
	std::cout << "int : " << _intVal << std::endl;
	std::cout << std::showpoint << std::fixed;
	std::cout << std::setprecision(1);
	std::cout << "float : " << static_cast<float>(_intVal) << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(_intVal) << std::endl;
}


void	Convert::showChar()
{
	if (_doubleRangedOut)
	{
		std::cout << "char: Out of Ranged!\n";
		return ;
	}
	if (_doubleNaned || _doubleImpossible || (*_str_end != 0 && _str_end[1] != 0))
	{
		std::cout << "char : impossible\n";
		return ;
	}
	if (_doubleInfinited)
	{
		std::cout << "char: Out of Ranged!\n";
		return ;
	}
	if ((_doubleVal > CHAR_MAX) || (_doubleVal < CHAR_MIN))
	{
		std::cout << "char : Out of Ranged!\n";
		return ;
	}
	if ((_doubleVal > CHAR_DISPLAY_MAX) || (_doubleVal < CHAR_DISPLAY_MIN))
	{
		std::cout << "char : Non displable.\n";
		return ;
	}
	std::cout << "char : " << static_cast<char>(_doubleVal) << std::endl;
}

void	Convert::showInt()
{
	if (_doubleRangedOut)
	{
		std::cout << "int : Out of Ranged!\n";
		return ;
	}
	if (_doubleNaned || _doubleImpossible || ((*_str_end != 0) && ((*_str_end != 'f') || (_str_end[1] != 0))))
	{
		std::cout << "int : impossible\n";
		return ;
	}
	if (_doubleInfinited)
	{
		std::cout << "int : Out of Ranged!\n";
		return ;
	}
	if ((_doubleVal > INT_MAX) || (_doubleVal < INT_MIN))
	{
		std::cout << "int : Out of Ranged!\n";
		return ;
	}
	std::cout << "int : " << static_cast<int>(_doubleVal) << std::endl;
}

void	Convert::showFloat()
{
	if (_floatImpossible)
	{
		std::cout << "float : impossible\n";
		return ;
	}
	std::cout << std::showpoint << std::fixed;
	std::cout << std::setprecision(1);
	std::cout << "float : " << static_cast<float>(_doubleVal) << "f" << std::endl;
}

void	Convert::checkInfinityAndNan()
{
	long long unsigned int tmp;
	tmp = *(reinterpret_cast<long long unsigned int*>(&_doubleVal));
	if ((tmp == 0x7FF0000000000000) || (tmp == 0xFFF0000000000000))
	{
		_doubleInfinited =1;
		return ;
	}
	else if ((tmp & 0x7FF0000000000000) == 0x7FF0000000000000)
	{
		_doubleNaned = 1;
		return ;
	}
	else
		return ;
}

void	Convert::showDouble()
{
	if (_doubleImpossible)
	{
		std::cout << "double : impossible\n";
		return ;
	}
	std::cout << std::showpoint << std::fixed;
	std::cout << std::setprecision(1);
	std::cout << "double : " << _doubleVal << std::endl;
}

const char* Convert::InputFailedException::what() const throw()
{
	return "Input Line Failed";
}
