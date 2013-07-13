#ifndef VECTOR3_
#define VECTOR3_

#include <cmath>

///
/// Template class for three element vectors.
///

template<class T>
class vector3
{
public:
	vector3();
	vector3(const T x, const T y, const T z);
	vector3(const vector3<T>& v);

	// utility operations
	vector3<T>& zero();
	vector3<T>& set(const T x, const T y, const T z);
	vector3<T>& normalize();

	// math operations
	const T norm() const;
	const T sum() const;
	const T dot(const vector3<T>&) const;
	const vector3<T> cross(const vector3<T>&) const;
	const vector3<T> abs() const;

	// operators
	vector3<T>& operator= (const vector3<T>& v);	// assignment

	const T operator[] (const int i) const;			// indexing
	T& operator[] (const int i);					// indexing

	const vector3<T> operator-();					// unary negate

	vector3<T>& operator+=(const T s);				// scalar addition
	vector3<T>& operator-=(const T s);				// scalar subtraction
	vector3<T>& operator*=(const T s);				// scalar multiplication
	vector3<T>& operator/=(const T s);				// scalar division

	vector3<T>& operator+=(const vector3<T>& v);	// vector addition
	vector3<T>& operator-=(const vector3<T>& v);	// vector subtraction
	vector3<T>& operator*=(const vector3<T>& v);	// element-wise multiplication
	vector3<T>& operator/=(const vector3<T>& v);	// element-wise division

	const vector3<T> operator < (const T s);		// compare each element with s, return vector of 1 or 0 based on test
	const vector3<T> operator > (const T s);

	const vector3<T> operator < (const vector3<T>& v);	// element-wise comparion, return vector of 1 or 0 based on test
	const vector3<T> operator > (const vector3<T>& v);

	bool operator == (const vector3<T>& v);				// test vector for equality
	bool operator != (const vector3<T>& v);				// test vector for inequality

	T* ptr(){return _v;} // return reference to array (use with caution)

private:
	T _v[3];
};


//
// Binary operations
//
/*
inline const vector3<T> operator+ (const vector3<T>& v, const T& s);	// scalar operations
inline const vector3<T> operator- (const vector3<T>& v, const T& s);
inline const vector3<T> operator* (const vector3<T>& v, const T& s);
inline const vector3<T> operator/ (const vector3<T>& v, const T& s);

inline const vector3<T> operator+ (const vector3<T>& v1, const vector3<T>& v2);	// element-wise addition
inline const vector3<T> operator- (const vector3<T>& v1, const vector3<T>& v2);	// element-wise subtraction
inline const vector3<T> operator* (const vector3<T>& v1, const vector3<T>& v2);	// dot product
inline const vector3<T> operator^ (const vector3<T>& v1, const vector3<T>& v2);	// cross product
*/

//
// Function definitions
//


template <class T>
vector3<T>::vector3()
{
	_v[0] = 0.0;
	_v[1] = 0.0;
	_v[2] = 0.0;
}


template <class T>
vector3<T>::vector3(const vector3<T>& v)
{
	_v[0] = v[0];
	_v[1] = v[1];
	_v[2] = v[2];
}


template <class T>
vector3<T>::vector3(const T x, const T y, const T z)
{
	_v[0] = x;
	_v[1] = y;
	_v[2] = z;
}


template <class T>
vector3<T>& vector3<T>::zero()
{
    _v[0] = 0.0;
    _v[1] = 0.0;
    _v[2] = 0.0;
	return *this;
}


template <class T>
vector3<T>& vector3<T>::set(const T x, const T y, const T z)
{
	_v[0] = x;
	_v[1] = y;
	_v[2] = z;
	return *this;
}


template <class T>
inline const T vector3<T>::operator [] (const int i) const
{
	return _v[i];
}


template <class T>
T& vector3<T>::operator [] (const int i)
{
	return _v[i];
}


template <class T>
inline const vector3<T> vector3<T>::abs() const
{
    return vector3<T>(std::abs(_v[0]), std::abs(_v[1]), std::abs(_v[2]));
}


template <class T>
inline const T vector3<T>::sum() const
{
    return _v[0] + _v[1] + _v[2];
}


template <class T>
inline const T vector3<T>::dot(const vector3<T>& v) const
{
    return _v[0]*v[0] + _v[1]*v[1] + _v[2]*v[2];
}


template <class T>
inline const vector3<T> vector3<T>::cross(const vector3<T>& v) const
{
    return vector3<T>(
		(_v[1] * v[2]) - (_v[2] * v[1]),
		(_v[2] * v[0]) - (_v[0] * v[2]),
		(_v[0] * v[1]) - (_v[1] * v[0])
	);
}


template <class T>
inline const T vector3<T>::norm() const
{
    return (T) sqrt(dot(*this)); // cast to type
}


template <class T>
vector3<T>& vector3<T>::normalize()
{
    T n = norm();
	if(n){
	_v[0]/=n;
	_v[1]/=n;
	_v[2]/=n;
	}
	return *this;
}


template <class T>
vector3<T>& vector3<T>::operator= (const vector3<T>& v)
{
	_v[0] = v[0];
	_v[1] = v[1];
	_v[2] = v[2];
	return *this;
}


template <class T>
vector3<T>& vector3<T>::operator += (const vector3<T>& v)
{
	_v[0] += v[0];
	_v[1] += v[1];
	_v[2] += v[2];
	return *this;
}


template <class T>
vector3<T>& vector3<T>::operator += (T v)
{
	_v[0] += v;
	_v[1] += v;
	_v[2] += v;
	return *this;
}


template <class T>
vector3<T>& vector3<T>::operator -= (const vector3<T>& v)
{
	_v[0] -= v[0];
	_v[1] -= v[1];
	_v[2] -= v[2];
	return *this;
}


template <class T>
vector3<T>& vector3<T>::operator -= (T v)
{
	_v[0] -= v;
	_v[1] -= v;
	_v[2] -= v;
	return *this;
}


template <class T>
vector3<T>& vector3<T>::operator *= (T v)
{
	_v[0] *= v;
	_v[1] *= v;
	_v[2] *= v;
	return *this;
}


template <class T>
vector3<T>& vector3<T>::operator *= (const vector3<T>& v)
{
	_v[0] *= v[0];
	_v[1] *= v[1];
	_v[2] *= v[2];
	return *this;
}


template <class T>
vector3<T>& vector3<T>::operator /= (T v)
{
	_v[0] /= v;
	_v[1] /= v;
	_v[2] /= v;
	return *this;
}


template <class T>
vector3<T>& vector3<T>::operator /= (const vector3<T>& v)
{
	_v[0] /= v[0];
	_v[1] /= v[1];
	_v[2] /= v[2];
	return *this;
}


template<class T>
inline const vector3<T> vector3<T>::operator < (const T s)
{
	return vector3<T>(_v[0]<s, _v[1]<s, _v[2]<s);
}


template<class T>
inline const vector3<T> vector3<T>::operator > (const T s)
{
	return vector3<T>(_v[0]>s, _v[1]>s, _v[2]>s);
}


template<class T>
inline const vector3<T> vector3<T>::operator < (const vector3<T>& v)
{
	return vector3<T>(_v[0]<v[0], _v[1]<v[1], _v[2]<v[2]);
}


template<class T>
inline const vector3<T> vector3<T>::operator > (const vector3<T>& v)
{
	return vector3<T>(_v[0]>v[0], _v[1]>v[1], _v[2]>v[2]);
}


template<class T>
inline const vector3<T> vector3<T>::operator - ()
{
	return vector3<T>(-_v[0], -_v[1], -_v[2]);
}


template <class T>
inline bool vector3<T>::operator == (const vector3<T>& v)
{
  return    _v[0] == v[0]
         && _v[1] == v[1]
         && _v[2] == v[2];
}


template <class T>
inline bool vector3<T>::operator != (const vector3<T>& v)
{
  return    _v[0] != v[0]
         || _v[1] != v[1]
         || _v[2] != v[2];
}



template<class T>
inline const vector3<T> operator && (const vector3<T>& v1, const vector3<T>& v2)
{
	return vector3<T>(v1[0]&&v2[0], v1[1]&&v2[1], v1[2]&&v2[2]);
}


template<class T>
inline const vector3<T> operator || (const vector3<T>& v1, const vector3<T>& v2)
{
	return vector3<T>(v1[0]||v2[0], v1[1]||v2[1], v1[2]||v2[2]);
}


template <class T>
inline const vector3<T> operator + (const vector3<T>& v, const T& s)
{
	return vector3<T>(v) += s;
}


template <class T>
inline const vector3<T> operator - (const vector3<T>& v, const T& s)
{
	return vector3<T>(v) -= s;
}


template <class T>
inline const vector3<T> operator * (const vector3<T>& v, const T& s)
{
	return vector3<T>(v) *= s;
}


template <class T>
inline const vector3<T> operator / (const vector3<T>& v, const T& s)
{
	return vector3<T>(v) /= s;
}


template <class T>
inline const vector3<T> operator + (const vector3<T>& v1, const vector3<T>& v2)
{
	return vector3<T>(v1) += v2;
}


template <class T>
inline const vector3<T> operator - (const vector3<T>& v1, const vector3<T>& v2)
{
	return vector3<T>(v1) -= v2;
}


template <class T>
inline const T operator * (const vector3<T>& v1, const vector3<T>& v2)
{
	return v1.dot(v2);
}


template <class T>
inline const vector3<T> operator ^ (const vector3<T>& v1, const vector3<T>& v2)
{
	return v1.cross(v2);
}




#endif//VECTOR3_HPP_
