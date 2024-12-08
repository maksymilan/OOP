#include "fraction.h"

// Copy constructor for Fraction, copies the values of another Fraction object.
Fraction::Fraction(const Fraction& other) {
    _nominator = other._nominator;
    _denominator = other._denominator;
}

// Constructor for Fraction that takes a single integer and sets the denominator to 1.
Fraction::Fraction(int d) {
    _nominator = d;
    _denominator = 1;
}

// Parameterized constructor for Fraction with two integers as numerator and denominator.
// Throws an exception if the denominator is zero.
Fraction::Fraction(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Denominator can't be zero!");
    }
    // Simplify the fraction by dividing both numerator and denominator by their GCD.
    int GCD = gcd(a, b);
    a /= GCD;
    b /= GCD;
    _nominator = a;
    _denominator = b;
}

// Helper function to calculate the Greatest Common Divisor (GCD) using Euclid's algorithm.
int Fraction::gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Returns the reciprocal of the current Fraction.
const Fraction Fraction::reciprocal() const {
    return Fraction(_denominator, _nominator);
}

// Overloads the assignment operator for Fraction.
Fraction& Fraction::operator=(const Fraction& other) {
    if (&other == this) { // Check for self-assignment
        return *this;
    } else {
        this->_nominator = other._nominator;
        this->_denominator = other._denominator;
        return *this;
    }
}

// Constructor for Fraction that takes a string in the format "integer_part.fraction_part".
// Converts the string into a Fraction.
Fraction::Fraction(std::string str) {
    size_t dotPos = str.find(".");
    if (dotPos != std::string::npos) {
        std::string integer_part_string = str.substr(0, dotPos);
        std::string fraction_part_string = str.substr(dotPos + 1);
        int len_of_fraction = fraction_part_string.length();
        int denominator = 1;
        for (int i = 0; i < len_of_fraction; ++i)
            denominator *= 10;

        // Create fractions from the integer and fractional parts and add them together.
        Fraction f(std::stoi(fraction_part_string), denominator);
        Fraction i(std::stoi(integer_part_string));
        Fraction t = i + f;
        *this = t;
    } else {
        throw std::invalid_argument("The format of the string must be integer_part.fraction_part");
    }
}

// Overloads the addition operator for Fractions.
const Fraction operator+(const Fraction& a, const Fraction& b) {
    int nominator = a._nominator * b._denominator + a._denominator * b._nominator;
    int denominator = a._denominator * b._denominator;
    return Fraction(nominator, denominator);
}

// Overloads the addition operator for a Fraction and an integer.
const Fraction operator+(const Fraction& a, const int b) {
    Fraction other(b);
    return a + other;
}

// Overloads the addition operator for an integer and a Fraction.
const Fraction operator+(int a, const Fraction& b) {
    return b + a;
}

// Overloads the unary minus operator for a Fraction.
const Fraction Fraction::operator-() const {
    return Fraction(-_nominator, _denominator);
}

// Overloads the subtraction operator for Fractions.
const Fraction operator-(const Fraction& a, Fraction& b) {
    return a + (-b);
}

// Overloads the subtraction operator for a Fraction and an integer.
const Fraction operator-(const Fraction& a, int b) {
    return a + (-b);
}

// Overloads the subtraction operator for an integer and a Fraction.
const Fraction operator-(int a, const Fraction& b) {
    Fraction res = b - a;
    return -res;
}

// Overloads the multiplication operator for Fractions.
const Fraction operator*(const Fraction& a, const Fraction& b) {
    return Fraction(a._nominator * b._nominator, a._denominator * b._denominator);
}

// Overloads the multiplication operator for a Fraction and an integer.
const Fraction operator*(const Fraction& a, int b) {
    return a * Fraction(b);
}

// Overloads the multiplication operator for an integer and a Fraction.
const Fraction operator*(int a, const Fraction& b) {
    return b * Fraction(a);
}

// Overloads the division operator for Fractions.
const Fraction operator/(const Fraction& a, const Fraction& b) {
    return a * (b.reciprocal());
}

// Overloads the division operator for a Fraction and an integer.
const Fraction operator/(const Fraction& a, int b) {
    return a / Fraction(b);
}

// Overloads the division operator for an integer and a Fraction.
const Fraction operator/(int a, const Fraction& b) {
    return Fraction(a) / b;
}

// Implicit conversion operator to double.
Fraction::operator double() const {
    return static_cast<double>(_nominator) / _denominator;
}

// Implicit conversion operator to string.
Fraction::operator std::string() const {
    return std::to_string(_nominator) + "/" + std::to_string(_denominator);
}

// Overloads the less-than comparison operator for Fractions.
bool Fraction::operator<(const Fraction &other) const {
    if (this->_denominator * other._denominator > 0) {
        return this->_nominator * other._denominator < this->_denominator * other._nominator;
    } else {
        // Handle cases where one or both denominators are negative.
        if (this->_denominator < 0) {
            Fraction temp(-this->_nominator, -this->_denominator);
            return temp._nominator * other._denominator < temp._denominator * other._nominator;
        } else {
            Fraction temp(-other._nominator, -other._denominator);
            return this->_nominator * temp._denominator < this->_denominator * temp._nominator;
        }
    }
}

// Overloads the less-than comparison operator for a Fraction and an integer.
bool Fraction::operator<(const int other) const {
    return this->operator<(Fraction(other));
}

// Overloads the greater-than comparison operator for Fractions.
bool Fraction::operator>(const Fraction &other) const {
    return other < *this;
}

// Overloads the greater-than comparison operator for a Fraction and an integer.
bool Fraction::operator>(const int other) const {
    return Fraction(other) < *this;
}

// Overloads the equality comparison operator for Fractions.
bool Fraction::operator==(const Fraction &other) const {
    return this->_nominator == other._nominator && this->_denominator == other._denominator;
}

// Overloads the equality comparison operator for a Fraction and an integer.
bool Fraction::operator==(const int other) const {
    return *this == Fraction(other);
}

// Overloads the less-than-or-equal-to comparison operator for Fractions.
bool Fraction::operator<=(const Fraction &other) const {
    return !(*this > other);
}

// Overloads the less-than-or-equal-to comparison operator for a Fraction and an integer.
bool Fraction::operator<=(const int other) const {
    return !(*this > Fraction(other));
}

// Overloads the greater-than-or-equal-to comparison operator for Fractions.
bool Fraction::operator>=(const Fraction &other) const {
    return !(*this < other);
}

// Overloads the greater-than-or-equal-to comparison operator for a Fraction and an integer.
bool Fraction::operator>=(const int other) const {
    return !(*this < Fraction(other));
}

// Overloads the not-equal-to comparison operator for Fractions.
bool Fraction::operator!=(const Fraction &other) const {
    return !(*this == other);
}

// Overloads the not-equal-to comparison operator for a Fraction and an integer.
bool Fraction::operator!=(const int other) const {
    return !(*this == Fraction(other));
}

// Overloads the output stream operator for printing a Fraction.
std::ostream& operator<<(std::ostream& os, Fraction& fraction) {
    os << std::string(fraction);
    return os;
}

// Overloads the input stream operator for reading a Fraction.
std::istream& operator>>(std::istream& is, Fraction& fraction) {
    int nominator, denominator;
    is >> nominator >> denominator;
    if (denominator == 0) {
        std::cout << "The denominator can't be zero! Input failed!" << std::endl;
        return is;
    }
    fraction._nominator = nominator;
    fraction._denominator = denominator;
    std::cout << "Input success." << std::endl;
    return is;
}

// Main function to test various aspects of the Fraction class.
int main() {
    Fraction f_1(2, 3), f_2(1, 2), f_3(-7, 16), f_4(8, -19);
    Fraction f;

    // Test default constructor.
    Fraction F_3;
    F_3.show();

    // Test parameterized constructor with two integers.
    Fraction F_2(2, 9);
    F_2.show();

    // Test copy constructor.
    Fraction F_1 = f_3;
    F_1.show();

    // Test arithmetic operators (+, -, *, /).
    f = f_1 + f_2;
    f.show();
    f = f_1 - f_2;
    f.show();
    f = f_1 * f_2;
    f.show();
    f = f_1 / f_2;
    f.show();

    // Test relational operators.
    if (f_1 > f_2) {
        std::cout << "f_1 > f_2 is true" << std::endl;
    }
    if (f_2 < f_1) {
        std::cout << "f_2 < f_1 is true" << std::endl;
    }
    if (f_1 >= f_2) {
        std::cout << "f_1 >= f_2 is true" << std::endl;
    }
    if (f_2 <= f_1) {
        std::cout << "f_2 <= f_1 is true" << std::endl;
    }
    if (f_1 == f_1) {
        std::cout << "f_1 == f_1 is true" << std::endl;
    }
    if (f_1 != f_2) {
        std::cout << "f_1 != f_2 is true" << std::endl;
    }

    // Test typecasting to double.
    double d = static_cast<double>(f_1);
    std::cout << d << std::endl;

    // Test typecasting to string.
    std::string str = static_cast<std::string>(f_1);
    std::cout << str << std::endl;

    // Test stream insertion and extraction operators.
    std::cin >> f_1; // Directly input the nominator and denominator.
    std::cout << f_1 << std::endl;

    // Test conversion from finite decimal string.
    std::string decimal = "1.414";
    Fraction F_5(decimal);
    F_5.show();

    return 0;
}