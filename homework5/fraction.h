#include <iostream>
#include <string>
#include <sstream>

class Fraction {
private:
    int _nominator;  // The numerator of the fraction.
    int _denominator; // The denominator of the fraction.
    
    // Helper function to calculate the Greatest Common Divisor (GCD) using Euclid's algorithm.
    int gcd(int a, int b);

public:
    // Default constructor that initializes a fraction with a value of 0/1.
    Fraction() : _nominator(0), _denominator(1) {}

    // Parameterized constructor for creating a fraction from two integers.
    Fraction(int nominator, int denominator);

    // Copy constructor for copying another Fraction object.
    Fraction(const Fraction& other);

    // Constructor for creating a fraction from a single integer, setting the denominator to 1.
    Fraction(int d);

    // Constructor for creating a fraction from a string in the format "integer_part.fraction_part".
    Fraction(std::string str);

    // Friend function for overloading the addition operator for Fractions.
    friend const Fraction operator+(const Fraction& a, const Fraction& b);

    // Friend function for overloading the multiplication operator for Fractions.
    friend const Fraction operator*(const Fraction& a, const Fraction& b);

    // Member function to return the reciprocal of the current Fraction.
    const Fraction reciprocal() const;

    // Overloads the assignment operator for Fractions.
    Fraction& operator=(const Fraction& other);

    // Member function to return the unary minus of the current Fraction.
    const Fraction operator-() const;

    // Implicit conversion operator to double.
    operator double() const;

    // Implicit conversion operator to string.
    operator std::string() const;

    // Overloads the less-than comparison operator for Fractions.
    bool operator<(const Fraction& other) const;

    // Overloads the less-than comparison operator for a Fraction and an integer.
    bool operator<(const int other) const;

    // Overloads the greater-than comparison operator for Fractions.
    bool operator>(const Fraction& other) const;

    // Overloads the greater-than comparison operator for a Fraction and an integer.
    bool operator>(const int other) const;

    // Overloads the equality comparison operator for Fractions.
    bool operator==(const Fraction& other) const;

    // Overloads the equality comparison operator for a Fraction and an integer.
    bool operator==(const int) const;

    // Overloads the less-than-or-equal-to comparison operator for Fractions.
    bool operator<=(const Fraction& other) const;

    // Overloads the less-than-or-equal-to comparison operator for a Fraction and an integer.
    bool operator<=(const int) const;

    // Overloads the greater-than-or-equal-to comparison operator for Fractions.
    bool operator>=(const Fraction& other) const;

    // Overloads the greater-than-or-equal-to comparison operator for a Fraction and an integer.
    bool operator>=(const int) const;

    // Overloads the not-equal-to comparison operator for Fractions.
    bool operator!=(const Fraction& other) const;

    // Overloads the not-equal-to comparison operator for a Fraction and an integer.
    bool operator!=(const int) const;

    // Member function to display the fraction as a string.
    void show() {
        std::string s = static_cast<std::string>(*this);
        std::cout << s << std::endl;
    }

    // Friend function for overloading the output stream operator for printing a Fraction.
    friend std::ostream& operator<<(std::ostream& os, Fraction& fraction);

    // Friend function for overloading the input stream operator for reading a Fraction.
    friend std::istream& operator>>(std::istream& is, Fraction& fraction);
};

// Declaration of the output stream operator overload for printing a Fraction.
std::ostream& operator<<(std::ostream& os, Fraction& fraction);

// Declaration of the input stream operator overload for reading a Fraction.
std::istream& operator>>(std::istream& is, Fraction& fraction);

// Declaration of the addition operator overload for adding two Fractions.
const Fraction operator+(const Fraction& a, const Fraction& b);

// Declaration of the addition operator overload for adding a Fraction and an integer.
const Fraction operator+(const Fraction& a, const int b);

// Declaration of the addition operator overload for adding an integer and a Fraction.
const Fraction operator+(const int a, const Fraction& b);

// Declaration of the subtraction operator overload for subtracting two Fractions.
const Fraction operator-(const Fraction& a, Fraction& b);

// Declaration of the subtraction operator overload for subtracting an integer from a Fraction.
const Fraction operator-(const Fraction& a, const int b);

// Declaration of the subtraction operator overload for subtracting a Fraction from an integer.
const Fraction operator-(const int a, const Fraction& b);

// Declaration of the multiplication operator overload for multiplying two Fractions.
const Fraction operator*(const Fraction& a, const Fraction& b);

// Declaration of the multiplication operator overload for multiplying a Fraction by an integer.
const Fraction operator*(const Fraction& a, const int b);

// Declaration of the multiplication operator overload for multiplying an integer by a Fraction.
const Fraction operator*(const int a, const Fraction& b);

// Declaration of the division operator overload for dividing two Fractions.
const Fraction operator/(const Fraction& a, const Fraction& b);

// Declaration of the division operator overload for dividing a Fraction by an integer.
const Fraction operator/(const Fraction& a, const int b);

// Declaration of the division operator overload for dividing an integer by a Fraction.
const Fraction operator/(const int a, const Fraction& b);