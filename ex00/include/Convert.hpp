#ifndef _CONVERT_HPP
#define _CONVERT_HPP

#include <exception>
#include <string>

class	Convert
{
public:
	class InputFailedException : std::exception
	{
	public:
		const char* what() const throw();
	};
private:
	enum {CHAR_DISPLAY_MIN = 32, CHAR_DISPLAY_MAX = 126};
	std::string		_line;
	unsigned int	_doubleRangedOut;
	unsigned int 	_doubleImpossible;
	unsigned int	_floatImpossible;
	unsigned int	_doubleNaned;
	unsigned int	_doubleInfinited;
	double			_doubleVal;
	int				_intVal;
	char *			_str_end;

	void	changeActualType();
	void	checkRangeError();
	void	checkInfinityAndNan();
	void	showDouble();
	void	showInt();
	void	showChar();
	void	showFloat();
	void	showInfoFromInt();
	void	showInfoFromDouble();
public:
	Convert();
	Convert(const char* str);
	~Convert();
	Convert(const Convert& rC);
	Convert& operator=(const Convert& rC);
	
	void	getLine();
	void	showInfo();
};
#endif

