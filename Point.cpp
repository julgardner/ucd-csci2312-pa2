// Julian Gardner
// 102215161
// CSCI 2312 002 Intermediate Programming
// Last modified Feb. 22, 2016

// Implementation file for the Point class, which is a representation of a point in n-dimensional space.

#include <iostream> // Needed for istreams and ostreams
#include <cmath> // Needed for square root function sqrt()
#include <string> //Needed for strings
#include <sstream> //Needed for stringstreams
#include "Point.h" // Needed for Point declaration

namespace Clustering
{
	// VARIABLE DECLARATIONS

	// next id to be assigned
	unsigned int Point::__idGen = 0;


	// CONSTRUCTORS

	// creates a point with dims dimensions 
	Point::Point(int dims)
	{
		__dim = dims; // make sure the object knows how many dimensions it has
		__values = new double[__dim]; // create the array holding the coordinates
		for (int i = 0; i < __dim; ++i) // now the program copies all elements of the array dataPtr points to into its data
		{
			__values[i] = 0;
		}
		__id = __idGen; // assign the id
		++__idGen; // since the id in __idGen is now used, the program needs to increment __idGen
	}

	// creates a point with dims dimensions and a set of coordinates
	Point::Point(int dims, double* dataPtr)
	{
		__dim = dims; // make sure the object knows how many dimensions it has
		__values = new double[__dim]; // create the array
		__id = __idGen; // assign the id
		++__idGen; // since the id in __idGen is now used, the program needs to increment __idGen
		for (int i = 0; i < __dim; ++i) // now the program copies all elements of the array dataPtr points to into its data
		{
			__values[i] = dataPtr[i];
		}
	}


	// COPY CONSTRUCTOR, ASSIGNMENT OPERATOR, & DESTRUCTOR

	// copy constructor
	Point::Point(const Point& other)
	{
		__dim = other.getDims();
		__values = new double[__dim];
		__id = other.getId(); // not getting a new id, only copying the other point's id
		for (int i = 0; i < __dim; ++i) // copy the values
		{
			__values[i] = other.getValue(i);
		}
	}

	// assignment operator
	Point& Point::operator=(const Point& other)
	{
		delete[] __values; // we don't want the point's values anymore because we're assigning
		__dim = other.getDims();
		__values = new double[__dim];
		__id = other.getId(); // not getting a new id, only copying the other point's id
		for (int i = 0; i < __dim; ++i) // copy the values
		{
			__values[i] = other.getValue(i);
		}
		return *this;
	}

	// destructor
	Point::~Point()
	{
		delete[] __values;
	}


	// ACCESSORS & MUTATORS

	int Point::getId() const
	{
		return __id;
	}

	int Point::getDims() const
	{
		return __dim;
	}

	void Point::setValue(int index, double data)
	{
		__values[index] = data;
	}

	double Point::getValue(int index) const
	{
		return __values[index];
	}


	// MEMBER FUNCTIONS

	// computes distance to another Point
	double Point::distanceTo(const Point& other) const
	{
		double squareSum = 0; // the sum of the squares of the distances
		double result;
		for (int i = 0; i < __dim; ++i)
		{
			squareSum += std::pow(__values[i] - other.getValue(i), 2.0);
		}
		result = std::sqrt(squareSum);
		return result;
	}


	// OPERATORS

	// each coordinate of the calling object is multiplied by multiplier
	Point& Point::operator*=(double multiplier)
	{
		for (int i = 0; i < __dim; ++i)
		{
			__values[i] *= multiplier;
		}
		return *this;
	}

	// each coordinate of the calling object is divided by divisor
	Point& Point::operator/=(double divisor)
	{
		for (int i = 0; i < __dim; ++i)
		{
			__values[i] /= divisor;
		}
		return *this;
	}

	// each coordinate of the calling object is multiplied by multiplier
	const Point Point::operator*(double multiplier) const
	{
		return Point(*this) *= multiplier;
	}

	// each coordinate of the calling object is divided by divisor
	const Point Point::operator/(double divisor) const
	{
		return Point(*this) /= divisor;
	}

	// returns the coordinate at index
	double& Point::operator[](int index)
	{
		return __values[index];
	}


	// FRIEND OPERATORS

	// dimensionwise addition of the right-hand point to the left-hand one
	Point &operator+=(Point& left, const Point& right)
	{
		for (int i = 0; i < left.__dim; ++i)
		{
			left.__values[i] += right.__values[i];
		}
		return left;
	}

	// dimensionwise subtraction of the right-hand point from the left-hand one
	Point &operator-=(Point& left, const Point& right)
	{
		for (int i = 0; i < left.__dim; ++i)
		{
			left.__values[i] -= right.__values[i];
		}
		return left;
	}

	// dimensionwise addition of the points on both sides
	const Point operator+(const Point& left, const Point& right)
	{
		Point result(left);
		result += right;
		return result;
	}

	// dimensionwise subtraction of the right-hand point from the left-hand one
	const Point operator-(const Point& left, const Point& right)
	{
		Point result(left);
		result -= right;
		return result;
	}

	// Equality test of id and values
	bool operator==(const Point& left, const Point& right)
	{
		if (left.__id == right.__id)
		{
			for (int i = 0; i < left.__dim; ++i)
			{
				if (left.__values[i] != right.__values[i])
				{
					return false; // Only one value must be different for the points to be different
				}
			}
			return true; // If we reach here, all values are equal
		}
		else
		{
			return false;
		}
	}

	// Equality test of id and values, returns true if any of them are not equal
	bool operator!=(const Point& left, const Point& right)
	{
		return (!(left == right));
	}

	// Lexographical less-than comparison of two points
	bool operator<(const Point& left, const Point& right)
	{
		for (int i = 0; i < left.__dim; ++i)
		{
			if (left.__values[i] < right.__values[i])
			{
				return true;
			}
			else if (left.__values[i] > right.__values[i])
			{
				return false;
			}
			// if the values at i are equal, continue going through the loop
		}
		return false; // if we get here, the values are all equal
	}

	// Lexographical greater-than or equal-to comparison of two points
	bool operator>=(const Point& left, const Point& right)
	{
		return (!(left < right));
	}

	// Lexographical greater-than comparison of two points
	bool operator>(const Point& left, const Point& right)
	{
		bool result = false;
		for (int i = 0; i < left.__dim; ++i)
		{
			if (left.__values[i] != right.__values[i])
			{
				result = true; // The values of left and right aren't equal, so one of our conditions is satisfied
			}
		}
		result = (result) && (left >= right);
		return result;
	}

	// Lexographical less-than or equal-to comparison of two points
	bool operator<=(const Point& left, const Point& right)
	{
		return (!(left > right));
	}

	// Insertion operator from a point into an ostream
	std::ostream &operator<<(std::ostream& output, const Point& right)
	{
		for (int i = 0; i < (right.__dim - 1); ++i)
		{
			output << right.__values[i] << ", ";
		}
		output << right.__values[right.__dim - 1];
		return output;
	}

	// Extraction operator from an istream into a point
	std::istream &operator>>(std::istream& input, Point& right)
	{
		std::string line, strValue; // line is the whole point, strValue is a single dimension
		std::getline(input, line);
		std::stringstream lineStream(line);
		int i = 0;
		double value;
		while (std::getline(lineStream, strValue, ','))
		{
			value = std::stod(strValue);
			right.__values[i] = value;
			++i;
		}
		return input;
	}
}