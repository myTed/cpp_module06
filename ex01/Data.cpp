
#include "Data.hpp"
#include <iostream>

Data::Data()
: _name(""), _phoneNum(""), _orderNum(0), _grade(0)
{
	std::cout << "Data Default Constructor Called\n";	
}
	
Data::Data(const std::string& name, const std::string& phoneNum, int orderNum, int grade)
: _name(name),
  _phoneNum(phoneNum),
  _orderNum(orderNum),
  _grade(grade)
{
	std::cout << "Data Non Default Consturctor Called\n";
}
	
Data::~Data()
{
	std::cout << "Data Destructor Called\n";
}
	
Data::Data(const Data &rData)
: _name(rData._name), 
  _phoneNum(rData._phoneNum),
  _orderNum(rData._orderNum),
  _grade(rData._grade)
{
	std::cout << "Data Copy Constructor Called\n";
}
	
Data& Data::operator=(const Data& rData)
{
	if (this == &rData)
		return (*this);
	_name = rData._name;
	_phoneNum = rData._phoneNum;
	_orderNum = rData._orderNum;
	_grade = rData._grade;
	return (*this);	
}
	
void	Data::showInfo()
{
	std::cout << "name : " << _name << std::endl;
	std::cout << "_phoneNum : " << _phoneNum << std::endl;
	std::cout << "_orderNum : " << _orderNum << std::endl;
	std::cout << "_grade : " << _grade << std::endl;	
}

