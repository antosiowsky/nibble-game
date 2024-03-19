module Zespolona;

void Zespolona::setRe(double reArg) {
	re = reArg;
}
void Zespolona::setIm(double imArg) {
	im = imArg;
}
double Zespolona::getIm() {
	return im;
}
double Zespolona::getRe() {
	return re;
}

Zespolona Zespolona::operator+(const Zespolona& other) const {
	return Zespolona(re + other.re, im + other.im);
}
Zespolona Zespolona::operator-(const Zespolona& other) const {
	return Zespolona(re - other.re, im - other.im);
}
Zespolona Zespolona::operator*(const Zespolona& other) const {
	return Zespolona(re * other.re - im * other.im, re * other.im + im * other.re);
}
Zespolona Zespolona::operator/(const Zespolona& other) const {
	double sprzezenie = other.re * other.re + other.im + other.im;
	if (sprzezenie == 0) {
		std::cerr << "cant divide by 0" << std::endl;
		return Zespolona(0, 0);
	}

	return Zespolona((re * other.re + im * other.im) / sprzezenie, (im * other.re - re * other.im) / sprzezenie);

}
