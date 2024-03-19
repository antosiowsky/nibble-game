export module Zespolona;

import <iostream>;

export class Zespolona {
private:
	double re;
	double im;
public:
	Zespolona(double reArg, double imArg) : re(reArg), im(imArg) {}
	void setIm(double imArg);
	void setRe(double reArg);
	double getIm();
	double getRe();
	Zespolona operator+(const Zespolona& other) const;
	Zespolona operator-(const Zespolona& other) const;
	Zespolona operator*(const Zespolona& other) const;
	Zespolona operator/(const Zespolona& other) const;

	friend std::ostream& operator<<(std::ostream& os, const Zespolona number) {
		os << number.re << (number.im >= 0 ? "+" : "-") << number.im << "i";
		return os;
	}
};
