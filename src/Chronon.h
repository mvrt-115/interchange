#ifndef __INTERCHANGE_CHRONON_H
#define __INTERCHANGE_CHRONON_H

class Chronon {
public:
	Chronon(short mantissa, short exponent);

	friend Chronon operator+( Chronon &a, Chronon &b);
	friend Chronon operator-(Chronon &a, Chronon &b);
	friend Chronon operator*(Chronon &a, Chronon &b);
	friend Chronon operator/(Chronon &a, Chronon &b);
	

	enum timeExponent {
		seconds = 0,
		deciseconds = 1,
		centiseconds = 2,
		milliseconds = 3,
		microseconds = 6,
		nanoseconds = 9
	};

	short getMantissa(Chronon &a);
	short getExponent(Chronon &a);
	void changeExponent(Chronon &a, short newExponent);

	//Operators +=,-=,*=,/= directly edit the left-side term
	void operator+=(Chronon &a) {

		Chronon chronon(this->mantissa, this->exponent);

		if (chronon.mantissa == mantissa) {
			mantissa += chronon.mantissa;
		}
		else {
			for (short e = exponent; e > 0; e--)
				mantissa *= mantissa;
			for (short e = chronon.exponent; e > 0; e--)
				chronon.mantissa *= chronon.mantissa;
			mantissa += chronon.mantissa;
			for (short e = exponent; e > 0; e--)
				mantissa /= mantissa;
		}
	}

	void operator-=(Chronon & a) {

		Chronon chronon(this->mantissa, this->exponent);

		if (chronon.mantissa == mantissa) {
			mantissa -= chronon.mantissa;
		}
		else {
			for (short e = exponent; e > 0; e--)
				mantissa *= mantissa;
			for (short e = chronon.exponent; e > 0; e--)
				chronon.mantissa *= chronon.mantissa;
			mantissa -= chronon.mantissa;
			for (short e = exponent; e > 0; e--)
				mantissa /= mantissa;
		}
	}

	void operator*=(Chronon &a) {

		Chronon chronon(this->mantissa, this->exponent);

		if (chronon.mantissa == mantissa) {
			mantissa *= chronon.mantissa;
		}
		else {
			for (short e = exponent; e > 0; e--)
				mantissa *= mantissa;
			for (short e = chronon.exponent; e > 0; e--)
				chronon.mantissa *= chronon.mantissa;
			mantissa *= chronon.mantissa;
			for (short e = exponent; e > 0; e--)
				mantissa /= mantissa;
		}
	}

	void operator/=(Chronon & a) {

		Chronon chronon(this->mantissa, this->exponent);

		if (chronon.mantissa == mantissa) {
			mantissa /= chronon.mantissa;
		}
		else {
			for (short e = exponent; e > 0; e--)
				mantissa *= mantissa;
			for (short e = chronon.exponent; e > 0; e--)
				chronon.mantissa *= chronon.mantissa;
			mantissa /= chronon.mantissa;
			for (short e = exponent; e > 0; e--)
				mantissa /= mantissa;
		}
	}

	void operator=(const Chronon &rs) {
		Chronon chronon(this->mantissa, this->exponent);
		chronon = rs;
	}

	//== and != are fairly straightforward
	bool operator==(Chronon &a) {
		Chronon chronon(this->mantissa, this->exponent);
		if (chronon.exponent == exponent)
			return (chronon.mantissa == a.mantissa);
		else {
			short m = a.mantissa;
			short cm = chronon.mantissa;
			for (short e = a.exponent; e > 0; e--)
				m *= m;
			for (short e = chronon.exponent; e > 0; e--) cm *= cm;
			return (m == cm);
		}

	}

	bool operator!=(Chronon &a) {
		Chronon chronon(this->mantissa, this->exponent);
		if (chronon.exponent != exponent)
			return (chronon.mantissa != a.mantissa);
		else {
			short m = a.mantissa;
			short cm = chronon.mantissa;
			for (short e = a.exponent; e > 0; e--)
				m *= m;
			for (short e = chronon.exponent; e > 0; e--) cm *= cm;
			return (m != cm);
		}
	}


private:
	short mantissa;
	short exponent;

}
;

//Other operators are inside the class

//Operators +,-,*,/ return a Chronon with the exponent of the first term
Chronon operator+(Chronon &a, Chronon &b) {
	if (a.exponent == b.exponent)
		return Chronon(a.mantissa + b.mantissa, a.exponent);
	else {
		for (short e = a.exponent; e > 0; e--)
			a.mantissa *= a.mantissa;
		for (short e = b.exponent; e > 0; e--)
			b.mantissa *= b.mantissa;
		short tempMantissa = a.mantissa + b.mantissa;
		for (short e = a.exponent; e > 0; e--)
			tempMantissa /= tempMantissa;
		return Chronon(tempMantissa, a.exponent);
	}
}

Chronon operator-(Chronon &a, Chronon &b) {

	if (a.exponent == b.exponent)
		return Chronon(a.mantissa + b.mantissa, a.exponent);
	else {
		for (short e = a.exponent; e > 0; e--)
			a.mantissa *= a.mantissa;
		for (short e = b.exponent; e > 0; e--)
			b.mantissa *= b.mantissa;
		short tempMantissa = a.mantissa - b.mantissa;
		for (short e = a.exponent; e > 0; e--)
			tempMantissa /= tempMantissa;
		return Chronon(tempMantissa, a.exponent);
	}
}

Chronon operator*(Chronon &a, Chronon &b) {

	if (a.exponent == b.exponent)
		return Chronon(a.mantissa + b.mantissa, a.exponent);
	else {
		for (short e = a.exponent; e > 0; e--)
			a.mantissa *= a.mantissa;
		for (short e = b.exponent; e > 0; e--)
			b.mantissa *= b.mantissa;
		short tempMantissa = a.mantissa * b.mantissa;
		for (short e = a.exponent; e > 0; e--)
			tempMantissa /= tempMantissa;
		return Chronon(tempMantissa, a.exponent);
	}
}

Chronon operator/(Chronon &a, Chronon &b) {

	if (a.exponent == b.exponent)
		return Chronon(a.mantissa + b.mantissa, a.exponent);
	else {
		for (short e = a.exponent; e > 0; e--)
			a.mantissa *= a.mantissa;
		for (short e = b.exponent; e > 0; e--)
			b.mantissa *= b.mantissa;
		short tempMantissa = a.mantissa / b.mantissa;
		for (short e = a.exponent; e > 0; e--)
			tempMantissa /= tempMantissa;
		return Chronon(tempMantissa, a.exponent);
	}
}





#endif //__INTERCHANGE_CHRONON_H
