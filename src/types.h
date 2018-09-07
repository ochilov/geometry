/****************************************************************************
** Copyright (c) 2018 Ochilov.U
**
** Contacts: neo.trion@gmail.com
**
** This file is part of the Simple geometry library (SGL)
**
** This file may be distributed under the terms of the SGL
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

//---------------------------------------------------------------------------
#pragma once
#ifndef _SGL_TYPES_H
#define _SGL_TYPES_H

#include <exception>
//---------------------------------------------------------------------------

namespace sgl {

inline bool is_zero(bool      val) { return (val == false); };
inline bool is_zero(short     val) { return (val == 0); };
inline bool is_zero(int       val) { return (val == 0); };
inline bool is_zero(long long val) { return (val == 0l); };
inline bool is_zero(float     val) { static float  eps = 1e-6f ; return (-eps <= val && val <= eps); };
inline bool is_zero(double    val) { static double eps = 1e-12; return (-eps <= val && val <= eps); };

template<typename T> struct TVec3;
template<typename T> struct TVec4;

///////////////////////////////////////////////////////////////////////////////
//			TVec2
///////////////////////////////////////////////////////////////////////////////
template<typename T> struct TVec2 {
	// Constructors
	T x, y;
	TVec2()					:x(0.0), y(0.0){};
	TVec2(T _x)				:x( _x), y( _x){};
	TVec2(T _x, T _y)		:x( _x), y( _y){};
	TVec2(const TVec2& v)	:x(v.x), y(v.y){};

	// Field getters/setters
		  T& operator[](int i)			{ if (i < 0) i += count; if (i < 0 || count <= i) throw(std::out_of_range("invalid TVec2<T> subscript")); return (i == 0) ? x : y; };
	const T& operator[](int i) const	{ if (i < 0) i += count; if (i < 0 || count <= i) throw(std::out_of_range("invalid TVec2<T> subscript")); return (i == 0) ? x : y; };

	// Other methods
	int size()			const { return count; };
	bool empty() 		const { return (is_zero(x) && is_zero(y)); };
	bool have_zero()	const { return (is_zero(x) || is_zero(y)); };

	// Assignment operators (+=, -=, *=, /=)
	TVec2& operator += (const TVec2& r)	{ x += r.x; y += r.y; return *this; }
	TVec2& operator -= (const TVec2& r)	{ x -= r.x; y -= r.y; return *this; }
	TVec2& operator *= (const TVec2& r)	{ x *= r.x; y *= r.y; return *this; }
	TVec2& operator /= (const TVec2& r)	{ if (r.have_zero()) throw(std::domain_error("division by zero in TVec4<T>")); x /= r.x; y /= r.y; return *this; }

	// Arithmetic operators (+, -, *, /)
	friend inline const TVec2 operator +(const TVec2& l, const TVec2& r)	{ return  TVec2<T>(l.x + r.x, l.y + r.y); }
	friend inline const TVec2 operator -(const TVec2& l, const TVec2& r)	{ return  TVec2<T>(l.x - r.x, l.y - r.y); }
	friend inline const TVec2 operator *(const TVec2& l, const TVec2& r)	{ return  TVec2<T>(l.x * r.x, l.y * r.y); }
	friend inline const TVec2 operator /(const TVec2& l, const TVec2& r)	{ TVec2<T> l1(l); l1 /= r; return  l1; }

	// Relational operators (==, != , >, <, >=, <=)
	friend inline bool operator ==(const TVec2& l, const TVec2& r)	{ return (l.x == r.x && l.y == r.y); }
	friend inline bool operator !=(const TVec2& l, const TVec2& r)	{ return!(l.x == r.x && l.y == r.y); }
	friend inline bool operator <=(const TVec2& l, const TVec2& r)	{ return (l.x <= r.x && l.y <= r.y); }
	friend inline bool operator < (const TVec2& l, const TVec2& r)	{ return (l.x <  r.x && l.y <= r.y) ||
																			 (l.x <= r.x && l.y <  r.y); }
	friend inline bool operator >=(const TVec2& l, const TVec2& r)	{ return (l.x >= r.x && l.y >= r.y); }
	friend inline bool operator > (const TVec2& l, const TVec2& r)	{ return (l.x >  r.x && l.y >= r.y) ||
																			 (l.x >= r.x && l.y >  r.y); }

private:
	static const int count;
};



///////////////////////////////////////////////////////////////////////////////
//			TVec3
///////////////////////////////////////////////////////////////////////////////
template<typename T> struct TVec3 {
	// Constructors
	T x, y, z;
	TVec3()					                :x(0.0), y(0.0), z(0.0) {};
	TVec3(T _x)				                :x( _x), y( _x), z( _x) {};
	TVec3(T _x, T _y, T _z = T(0.0))		:x( _x), y( _y), z( _z) {};
	TVec3(const TVec2<T>& v, T _z = T(0.0))	:x(v.x), y(v.y), z( _z) {};
	TVec3(const TVec3& v)	:x(v.x), y(v.y), z(v.z) {};

	// Field getters/setters
		  T& operator[](int i)			{ if (i < 0) i += count; if (i < 0 || count <= i) throw(std::out_of_range("invalid TVec3<T> subscript")); return (i == 0) ? x : (i == 1) ? y : z; };
	const T& operator[](int i) const	{ if (i < 0) i += count; if (i < 0 || count <= i) throw(std::out_of_range("invalid TVec3<T> subscript")); return (i == 0) ? x : (i == 1) ? y : z; };

	// Other methods
	int size()			const { return count; };
	bool empty()		const { return (is_zero(x) && is_zero(y)) && is_zero(z); };
	bool have_zero()	const { return (is_zero(x) || is_zero(y)) || is_zero(z); };

    // Assignment operators (+=, -=, *=, /=)
	TVec3& operator += (const TVec3& r)	    { x += r.x; y += r.y; z += r.z; return *this; }
	TVec3& operator -= (const TVec3& r)	    { x -= r.x; y -= r.y; z -= r.z; return *this; }
	TVec3& operator *= (const TVec3& r)	    { x *= r.x; y *= r.y; z *= r.z; return *this; }
	TVec3& operator /= (const TVec3& r)	    { if (r.have_zero()) throw(std::domain_error("division by zero in TVec4<T>")); x /= r.x; y /= r.y; z /= r.z; return *this; }

	TVec3& operator *= (const TVec2<T>& r)	{ (*this) *= TVec3<T>(r, 1); return *this; }
	TVec3& operator /= (const TVec2<T>& r)	{ (*this) /= TVec3<T>(r, 1); return *this; }

	TVec3& operator *= (const T& r)			{ (*this) *= TVec3<T>(r); return *this; }
	TVec3& operator /= (const T& r)			{ (*this) /= TVec3<T>(r); return *this; }

	// Arithmetic operators (+, -, *, /)
	friend inline const TVec3 operator +(const TVec3& l, const TVec3& r)	{ return  TVec3<T>(l.x + r.x, l.y + r.y, l.z + r.z); }
	friend inline const TVec3 operator -(const TVec3& l, const TVec3& r)	{ return  TVec3<T>(l.x - r.x, l.y - r.y, l.z - r.z); }
	friend inline const TVec3 operator *(const TVec3& l, const TVec3& r)	{ return  TVec3<T>(l.x * r.x, l.y * r.y, l.z * r.z); }
	friend inline const TVec3 operator /(const TVec3& l, const TVec3& r)	{ TVec3<T> l1(l); l1 /= r; return  l1;  }

	friend inline const TVec3 operator *(const TVec3& l, const TVec2<T>& r)	{ return  l * TVec3<T>(r, 1.0); }
	friend inline const TVec3 operator /(const TVec3& l, const TVec2<T>& r)	{ return  l / TVec3<T>(r, 1.0); }
	friend inline const TVec3 operator *(const TVec3& l, T r)				{ return  l * TVec3<T>(r); }
	friend inline const TVec3 operator /(const TVec3& l, T r)				{ return  l / TVec3<T>(r); }


	friend inline const TVec3 operator *(const TVec2<T>& l, const TVec3& r)	{ return  TVec3<T>(l, 1.0) * r; }
	friend inline const TVec3 operator /(const TVec2<T>& l, const TVec3& r)	{ return  TVec3<T>(l, 1.0) / r; }
	friend inline const TVec3 operator *(const T l, const TVec3& r)			{ return  TVec3<T>(l) * r; }
	friend inline const TVec3 operator /(const T l, const TVec3& r)			{ return  TVec3<T>(l) / r; }

	// Relational operators (==, != , >, <, >=, <=)
	friend inline bool operator ==(const TVec3& l, const TVec3& r)	{ return (l.x == r.x && l.y == r.y && l.z == r.z); }
	friend inline bool operator !=(const TVec3& l, const TVec3& r)	{ return!(l.x == r.x && l.y == r.y && l.z == r.z); }
	friend inline bool operator <=(const TVec3& l, const TVec3& r)	{ return (l.x <= r.x && l.y <= r.y && l.z <= r.z); }
	friend inline bool operator < (const TVec3& l, const TVec3& r)	{ return (l.x <  r.x && l.y <= r.y && l.z <= r.z) ||
																			 (l.x <= r.x && l.y <  r.y && l.z <= r.z) ||
																			 (l.x <= r.x && l.y <= r.y && l.z <  r.z); }
	friend inline bool operator >=(const TVec3& l, const TVec3& r)	{ return (l.x >= r.x && l.y >= r.y && l.z >= r.z); }
	friend inline bool operator > (const TVec3& l, const TVec3& r)	{ return (l.x >  r.x && l.y >= r.y && l.z >= r.z) ||
																			 (l.x >= r.x && l.y >  r.y && l.z >= r.z) ||
																			 (l.x >= r.x && l.y >= r.y && l.z >  r.z); }

private:
	static const int count;
};



///////////////////////////////////////////////////////////////////////////////
//			TVec4
///////////////////////////////////////////////////////////////////////////////
template<typename T> struct TVec4 {
	// Constructors
	T x, y, z, w;
	TVec4()							                        :x(0.0), y(0.0), z(0.0), w(0.0) {};
	TVec4(T _x)						                        :x( _x), y( _x), z( _x), w( _x) {};
	TVec4(T _x, T _y, T _z = T(0.0), T _w = T(0.0))	        :x( _x), y( _y), z( _z), w( _w) {};
	TVec4(const TVec2<T>& v, T _z = T(0.0), T _w = T(0.0))	:x(v.x), y(v.y), z( _z), w( _w) {};
	TVec4(const TVec3<T>& v, T _w = T(0.0))					:x(v.x), y(v.y), z(v.z), w( _w) {};
	TVec4(const TVec4& v)									:x(v.x), y(v.y), z(v.z), w(v.w) {};

	// Field getters/setters
		  T& operator[](int i)			{ if (i < 0) i += count; if (i < 0 || count <= i) throw(std::out_of_range("invalid TVec4<T> subscript")); return (i == 0) ? x : (i == 1) ? y : (i == 2) ? z : w; };
	const T& operator[](int i) const	{ if (i < 0) i += count; if (i < 0 || count <= i) throw(std::out_of_range("invalid TVec4<T> subscript")); return (i == 0) ? x : (i == 1) ? y : (i == 2) ? z : w; };

	// Other methods
	int size()			const { return count; };
	bool empty()		const { return (is_zero(x) && is_zero(y)) && is_zero(z) && is_zero(w); };
	bool have_zero()	const { return (is_zero(x) || is_zero(y)) || is_zero(z) || is_zero(w); };

    // Assignment operators (+=, -=, *=, /=)
	TVec4& operator += (const TVec4& r)		{ x += r.x; y += r.y; z += r.z; w += r.w; return *this; }
	TVec4& operator -= (const TVec4& r)		{ x -= r.x; y -= r.y; z -= r.z; w -= r.w; return *this; }
	TVec4& operator *= (const TVec4& r)		{ x *= r.x; y *= r.y; z *= r.z; w *= r.w; return *this; }
	TVec4& operator /= (const TVec4& r)		{ if (r.have_zero()) throw(std::domain_error("division by zero in TVec4<T>")); x /= r.x; y /= r.y; z /= r.z; w /= r.w; return *this; }

	TVec4& operator *= (const TVec3<T>& r)	{ (*this) *= TVec4<T>(r, 1); return *this; }
	TVec4& operator /= (const TVec3<T>& r)	{ (*this) /= TVec4<T>(r, 1); return *this; }

	TVec4& operator *= (const TVec2<T>& r)	{ (*this) *= TVec4<T>(r, 1, 1); return *this; }
	TVec4& operator /= (const TVec2<T>& r)	{ (*this) /= TVec4<T>(r, 1, 1); return *this; }

	TVec4& operator *= (const T& r)			{ (*this) *= TVec4<T>(r); return *this; }
	TVec4& operator /= (const T& r)			{ (*this) /= TVec4<T>(r); return *this; }

	// Arithmetic operators (+, -, *, /)
	friend inline const TVec4 operator +(const TVec4& l, const TVec4& r)	{ return  TVec4<T>(l.x + r.x, l.y + r.y, l.z + r.z, l.w + r.w); }
	friend inline const TVec4 operator -(const TVec4& l, const TVec4& r)	{ return  TVec4<T>(l.x - r.x, l.y - r.y, l.z - r.z, l.w - r.w); }
	friend inline const TVec4 operator *(const TVec4& l, const TVec4& r)	{ return  TVec4<T>(l.x * r.x, l.y * r.y, l.z * r.z, l.w * r.w); }
	friend inline const TVec4 operator /(const TVec4& l, const TVec4& r)	{ TVec4<T> l1(l); l1 /= r; return  l1;  }

	friend inline const TVec4 operator *(const TVec4& l, const TVec3<T>& r)	{ return  l * TVec4<T>(r, 1.0); }
	friend inline const TVec4 operator /(const TVec4& l, const TVec3<T>& r)	{ return  l / TVec4<T>(r, 1.0); }
	friend inline const TVec4 operator *(const TVec4& l, const TVec2<T>& r)	{ return  l * TVec4<T>(r, 1.0, 1.0); }
	friend inline const TVec4 operator /(const TVec4& l, const TVec2<T>& r)	{ return  l / TVec4<T>(r, 1.0, 1.0); }
	friend inline const TVec4 operator *(const TVec4& l, T r)				{ return  l * TVec4<T>(r); }
	friend inline const TVec4 operator /(const TVec4& l, T r)				{ return  l / TVec4<T>(r); }

	friend inline const TVec4 operator *(const TVec3<T>& l, const TVec4& r)	{ return  TVec4<T>(l, 1.0) * r; }
	friend inline const TVec4 operator /(const TVec3<T>& l, const TVec4& r)	{ return  TVec4<T>(l, 1.0) / r; }
	friend inline const TVec4 operator *(const TVec2<T>& l, const TVec4& r)	{ return  TVec4<T>(l, 1.0, 1.0) * r; }
	friend inline const TVec4 operator /(const TVec2<T>& l, const TVec4& r)	{ return  TVec4<T>(l, 1.0, 1.0) / r; }
	friend inline const TVec4 operator *(const T l, const TVec4& r)			{ return  TVec4<T>(l) * r; }
	friend inline const TVec4 operator /(const T l, const TVec4& r)			{ return  TVec4<T>(l) / r; }

	// Relational operators (==, != , >, <, >=, <=)
	friend inline bool operator ==(const TVec4& l, const TVec4& r)	{ return (l.x == r.x && l.y == r.y && l.z == r.z && l.w == r.w); }
	friend inline bool operator !=(const TVec4& l, const TVec4& r)	{ return!(l.x == r.x && l.y == r.y && l.z == r.z && l.w == r.w); }
	friend inline bool operator <=(const TVec4& l, const TVec4& r)	{ return (l.x <= r.x && l.y <= r.y && l.z <= r.z && l.w <= r.w); }
	friend inline bool operator < (const TVec4& l, const TVec4& r)	{ return (l.x <  r.x && l.y <= r.y && l.z <= r.z && l.w <= r.w) ||
																			 (l.x <= r.x && l.y <  r.y && l.z <= r.z && l.w <= r.w) ||
																			 (l.x <= r.x && l.y <= r.y && l.z <  r.z && l.w <= r.w) ||
																			 (l.x <= r.x && l.y <= r.y && l.z <= r.z && l.w <  r.w); }
	friend inline bool operator >=(const TVec4& l, const TVec4& r)	{ return (l.x >= r.x && l.y >= r.y && l.z >= r.z && l.w >= r.w); }
	friend inline bool operator > (const TVec4& l, const TVec4& r)	{ return (l.x >  r.x && l.y >= r.y && l.z >= r.z && l.w >= r.w) ||
																			 (l.x >= r.x && l.y >  r.y && l.z >= r.z && l.w >= r.w) ||
																			 (l.x >= r.x && l.y >= r.y && l.z >  r.z && l.w >= r.w) ||
																			 (l.x >= r.x && l.y >= r.y && l.z >= r.z && l.w >  r.w); }

private:
	static const int count;
};

template<typename T> const int TVec2<T>::count = 2;
template<typename T> const int TVec3<T>::count = 3;
template<typename T> const int TVec4<T>::count = 4;


///////////////////////////////////////////////////////////////////////////////
//			implementations
///////////////////////////////////////////////////////////////////////////////
typedef TVec2 <bool		> vec2b;
typedef TVec2 <int		> vec2i;
typedef TVec2 <float	> vec2f;
typedef TVec2 <double	> vec2d;

typedef TVec3 <bool		> vec3b;
typedef TVec3 <int		> vec3i;
typedef TVec3 <float	> vec3f;
typedef TVec3 <double	> vec3d;

typedef TVec4 <bool		> vec4b;
typedef TVec4 <int		> vec4i;
typedef TVec4 <float	> vec4f;
typedef TVec4 <double	> vec4d;

inline const vec2b operator | (const vec2b& l, const vec2b& r) { return vec2b(l.x | r.x, l.y | r.y); };
inline const vec2b operator & (const vec2b& l, const vec2b& r) { return vec2b(l.x & r.x, l.y & r.y); };

inline const vec3b operator | (const vec3b& l, const vec3b& r) { return vec3b(l.x | r.x, l.y | r.y, l.z | r.z); };
inline const vec3b operator & (const vec3b& l, const vec3b& r) { return vec3b(l.x & r.x, l.y & r.y, l.z & r.z); };

inline const vec4b operator | (const vec4b& l, const vec4b& r) { return vec4b(l.x | r.x, l.y | r.y, l.z | r.z, l.w | r.w); };
inline const vec4b operator & (const vec4b& l, const vec4b& r) { return vec4b(l.x & r.x, l.y & r.y, l.z & r.z, l.w & r.w); };

/*
TODO
	cross
	dot
	magnitude
	normalize
	outer
	projection
	separate
*/

}

#endif
