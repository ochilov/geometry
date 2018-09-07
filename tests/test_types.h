//---------------------------------------------------------------------------
#pragma once
#ifndef TestTypesH
#define TestTypesH

#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include "../src/types.h"

//---------------------------------------------------------------------------
// =============================================================================
//		PRINT TYPES
// =============================================================================
#define DS(x) std::setw(2) << (x)
template <typename T> std::string str(T x)					{ std::stringstream ss; ss << DS(x); return ss.str(); };
template <typename T> std::string str(T x, T y)				{ std::stringstream ss; ss << DS(x) << ", " << DS(y); return ss.str(); };
template <typename T> std::string str(T x, T y, T z)		{ std::stringstream ss; ss << DS(x) << ", " << DS(y) << ", " << DS(z); return ss.str(); };
template <typename T> std::string str(T x, T y, T z, T w)	{ std::stringstream ss; ss << DS(x) << ", " << DS(y) << ", " << DS(z) << ", " << DS(w); return ss.str(); };

template <typename T> std::string str(const sgl::TVec2<T>& vec) { return "Vec2 {" + ( vec.empty() ? std::string("empty") : str(vec.x, vec.y) ) + "}"; }
template <typename T> std::string str(const sgl::TVec3<T>& vec) { return "Vec3 {" + ( vec.empty() ? std::string("empty") : str(vec.x, vec.y, vec.z) ) + "}"; }
template <typename T> std::string str(const sgl::TVec4<T>& vec) { return "Vec4 {" + ( vec.empty() ? std::string("empty") : str(vec.x, vec.y, vec.z, vec.w) ) + "}"; }

template <typename T> std::ostream& operator << (std::ostream& o, const sgl::TVec2<T>& vec) { o << str(vec); return o; };
template <typename T> std::ostream& operator << (std::ostream& o, const sgl::TVec3<T>& vec) { o << str(vec); return o; };
template <typename T> std::ostream& operator << (std::ostream& o, const sgl::TVec4<T>& vec) { o << str(vec); return o; };

extern std::string str(bool x);
extern std::ostream& operator << (std::ostream& o, const std::string  & str);


// =============================================================================
//		TestTypes
// =============================================================================
class TestTypes {
public:
	TestTypes(std::ostream&);
	int RunTests();
	int TestVec2();
	int TestVec3();
	int TestVec4();

	void PrintErrors();

	std::string Check(bool check_result, const std::string& msg = std::string());

private:
	std::ostream& out;

	typedef std::vector<std::string> v_strings;
	v_strings totalErrors, totalWarnings;

};
#endif
