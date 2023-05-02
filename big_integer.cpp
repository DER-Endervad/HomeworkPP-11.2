#include "big_integer.h"

big_integer::big_integer(std::string input) {
	this->number_ = input;
}

big_integer::big_integer(const big_integer& other) {
	number_ = other.number_;
}

big_integer::big_integer(big_integer&& other) noexcept {
	number_ = std::move(other.number_);
}

big_integer& big_integer::operator=(const big_integer& other) {
	return *this = big_integer(other);
}

big_integer& big_integer::operator=(big_integer&& other) noexcept {
	std::swap(number_, other.number_);
	return *this;
}

std::string big_integer::getNumber() const {
	return number_;
}

big_integer big_integer::operator +(const big_integer& integer) {
	int i = number_.length()-1, j = integer.number_.length()-1;
	while (true) {
		if (i < 0 || j < 0) {
			break;
		}
		int temp = (number_[i] - '0') + (integer.number_[j] - '0');
		if (temp >= 10) {
			int temp2 = temp / 10;
			temp -= 10;
			number_[i] = temp + '0';
			if (i > 0) number_[i - 1] += temp2;
			else number_.insert(number_.begin(), (temp2 + '0'));
		}
		else number_[i] = temp + '0';
		--i; --j;
	}
	for (int x = number_.length() - 1; x >= 0; --x) {
		if (number_[x] - '0' >= 10) {
			int temp = (number_[x] - '0') / 10;
			number_[x] -= temp*10;
			if (x > 0) number_[x - 1] += temp;
			else number_.insert(number_.begin(), (temp + '0'));
		}
	}
	return *this;
}

big_integer big_integer::operator *(const int& integer) {
	int size = number_.length() - 1;
	std::string number_2 = number_;
	std::string number_3 = number_;
	std::string input = std::to_string(integer);
	int size2 = input.length() - 1;
	for (int i = 0; i < size+1; ++i) {
		number_2[i] = '0';
		number_3[i] = '0';
	}

	for (int i = size; i >= 0; --i) {
		int amount = 0;
		for (int j = size2; j >= 0; --j) {
			int temp = (number_[i] - '0') * (input[j] - '0');
			if (temp >= 10) {
				int temp2 = temp / 10;
				temp -= temp2 * 10;

				if (i + amount >= 0) number_2[i + amount] = ((number_2[i + amount] - '0') + temp) + '0';
				else number_2.insert(number_2.begin(), (temp + '0'));
				
				if (i + amount - 1 >= 0) number_2[i + amount - 1] = ((number_2[i + amount - 1] - '0') + temp2) + '0';
				else number_2.insert(number_2.begin(), (temp2 + '0'));
			}
			else {
				if (i + amount >= 0) number_2[i + amount] = ((number_2[i + amount] - '0') + temp) + '0';
				else number_2.insert(number_2.begin(), (temp + '0'));
			}
			amount--;
			}
	}
	number_ = number_2;
	for (int x = number_.length() - 1; x >= 0; --x) {
		if (number_[x] - '0' >= 10) {
			int temp = (number_[x] - '0') / 10;
			number_[x] -= temp*10;
			if (x > 0) number_[x - 1] += temp;
			else number_.insert(number_.begin(), (temp + '0'));
		}
	}
	return *this;
}

std::ostream& operator <<(std::ostream& os, const big_integer& integer) {
	return os << integer.getNumber();
}
