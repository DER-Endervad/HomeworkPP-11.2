#pragma once
#include <iostream>
#include <string>

class big_integer
{
private:
	std::string number_;
public:
	big_integer(std::string input);

	big_integer(const big_integer& other);
	big_integer(big_integer&& other) noexcept;

	big_integer& operator=(const big_integer& other);
	big_integer& operator=(big_integer&& other) noexcept;

	std::string getNumber() const;

	big_integer operator +(const big_integer& integer);
	big_integer operator *(const int& integer);
};

std::ostream& operator <<(std::ostream& os, const big_integer& integer);

