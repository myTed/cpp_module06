#ifndef _DATA_HPP
#define _DATA_HPP

#include <string>

struct Data
{
	std::string _name;
	std::string _phoneNum;
	int			_orderNum;
	int			_grade;
	
	Data();
	Data(const std::string& name, const std::string& phoneNum, int orderNum, int grade);
	~Data();
	Data(const Data &rData);
	Data& operator=(const Data& rData);
	void	showInfo();
};

#endif
