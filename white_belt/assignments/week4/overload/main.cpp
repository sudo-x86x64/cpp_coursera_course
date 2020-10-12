#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <set>
#include <map>

using namespace std;

class Rational {
private:
    int _numerator;
    int _denominator;
    int _calculate_gcd(int a, int b) {
        if (b == 0) return a;
        return _calculate_gcd(b, a % b);
    }
    int _calculate_lcm(int a, int b) {return (a * b)/_calculate_gcd(a, b);}
public:
    int Numerator() const {return this->_numerator;};
    int Denominator() const {return this->_denominator;};

    bool operator == (const Rational &b) const {
        if ((this->_numerator == b.Numerator()) && (this->_denominator == b.Denominator())) return true;
        else return false;
    }

    Rational operator + (const Rational &b) {
        int lcm = _calculate_lcm(this->_denominator, b.Denominator());
        int tmp_numerator = ((this->_numerator * lcm)/this->_denominator) + ((b.Numerator() * lcm)/b.Denominator());
        return Rational(tmp_numerator, lcm);
    }

    Rational operator - (const Rational &b) {
        int lcm = _calculate_lcm(this->_denominator, b.Denominator());
        int tmp_numerator = (this->_numerator * lcm/this->_denominator) - (b.Numerator() * lcm/b.Denominator());
        return Rational(tmp_numerator, lcm);
    }

    Rational operator * (const Rational &b) {
        return Rational(this->_numerator * b.Numerator(), this->_denominator * b.Denominator());
    }

    Rational operator / (const Rational &b) {
        return Rational(this->_numerator * b.Denominator() , this->_denominator * b.Numerator());
    }

    Rational(int numerator, int denominator) { 
        int gcd = _calculate_gcd(numerator, denominator);

        if (gcd) {
            numerator /= gcd;
            denominator /= gcd;
        } 

        if (!numerator) denominator = 1;

        if ((numerator < 0) && (denominator < 0)) {
            numerator = abs(numerator);
            denominator = abs(denominator);
        } else if ((numerator > 0) && (denominator < 0)) {
            numerator *= -1;
            denominator = abs(denominator);
        }

        this->_numerator = numerator;
        this->_denominator = denominator;
    }
    
    Rational() {
        this->_numerator= 0;
        this->_denominator = 1;
    }
};

istringstream& operator >> (istringstream &stream, Rational &r) {
    int numerator = r.Numerator();
    int denominator = r.Denominator();
    const regex myRegex( "[0-9]\\/[0-9]" );

    if (!stream.rdbuf()->in_avail()) {
        stream >> numerator && stream.ignore(1) && stream >> denominator;
        r = Rational(numerator, denominator);
    } else  if(!regex_search(stream.str(),myRegex)) {
        r = Rational();
    } else if (stream >> numerator && stream.ignore(1) && stream >> denominator) {
        r = Rational(numerator, denominator);
    }
  
    return stream;
}

istream& operator >> (istream &stream, Rational &r) {
    int numerator = r.Numerator();
    int denominator = r.Denominator();
    const regex myRegex( "[0-9]\\/[0-9]" );

    if (!stream.rdbuf()->in_avail()) {
        stream >> numerator && stream.ignore(1) && stream >> denominator;
        r = Rational(numerator, denominator);
    } else if (stream >> numerator && stream.ignore(1) && stream >> denominator) {
        r = Rational(numerator, denominator);
    }
  
    return stream;
}

ostream& operator << (ostream &stream, const Rational &r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

ostringstream& operator << (ostringstream &stream, const Rational &r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

bool operator < (const Rational& left, const Rational& right) {
    return ((left.Numerator() - right.Numerator()) < 0);
}

int main() { 
    cout << "OK" << endl;
    return 0;
}