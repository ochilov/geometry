//---------------------------------------------------------------------------
#include "test_types.h"

//---------------------------------------------------------------------------
using namespace std;
using namespace sgl;

////////////////////////////////////////////////////////////////////////////////
std::string str(bool x) { std::stringstream ss; ss << std::boolalpha << std::setw(5) << x; return ss.str(); };
std::ostream& operator << (std::ostream& o, const std::string  & str) { o << str.c_str(); return o; }

////////////////////////////////////////////////////////////////////////////////
template <typename T> int TestVec2(TestTypes* owner, ostream& out, T x, T y);
template <typename T> int TestVec3(TestTypes* owner, ostream& out, T x, T y, T z);
template <typename T> int TestVec4(TestTypes* owner, ostream& out, T x, T y, T z, T w);

////////////////////////////////////////////////////////////////////////////////
//			TESTS
////////////////////////////////////////////////////////////////////////////////
// =============================================================================
TestTypes::TestTypes(std::ostream& ss) : out(ss) {
};

// =============================================================================
int TestTypes::RunTests() {
	out << "\'sgl/types\' tests begin..." << endl;

	out << endl;
	TestVec2();

	out << endl;
	TestVec3();

	out << endl;
	TestVec4();

	out << endl;
	out << "\'sgl/types\' tests end, " << totalErrors.size() << " errors, " << totalWarnings.size() << " warnings" << endl;

	return 0;
};

// =============================================================================
int TestTypes::TestVec2() {
	out << "=====\tTVect2\t=====" << endl;
	double x = 12, y = 23;
	int res = ::TestVec2(this, out, x, y);
	out << endl;
	return res;
}

// =============================================================================
int TestTypes::TestVec3() {
	out << "=====\tTVect3\t=====" << endl;
	double x = 12, y = 23, z = 34;
	int res = ::TestVec3(this, out, x, y, z);
	out << endl;
	return res;
}


// =============================================================================
int TestTypes::TestVec4() {
	out << "=====\tTVect4\t=====" << endl;
	double x = 12, y = 23, z = 34, w = 45;
	int res = ::TestVec4(this, out, x, y, z, w);
	out << endl;
	return res;
}


// =============================================================================
std::string TestTypes::Check(bool check_ok, const std::string& msg) {
	if (check_ok)
		return " ok";
	totalErrors.push_back(msg);
	return " ERROR";
};

// =============================================================================
void TestTypes::PrintErrors() {
	for (std::size_t i = 0u, cnt = totalErrors.size(); i < cnt; ++i) {
		out << "[" << setw(3) << i << "] " << totalErrors[i] << endl;
	}
};



////////////////////////////////////////////////////////////////////////////////
//			TEST MACROS
////////////////////////////////////////////////////////////////////////////////
#define __NAME__(a) (#a)
#define EXPECT_EQ(a, b, res) std::string(__NAME__(a)) + " == " + std::string(__NAME__(b)) + ": " + str((a) == (b)) + owner->Check( ((a) == (b)) == (res), str(a) + " == " + str(b) + " fail" )
#define EXPECT_NE(a, b, res) std::string(__NAME__(a)) + " != " + std::string(__NAME__(b)) + ": " + str((a) != (b)) + owner->Check( ((a) != (b)) == (res), str(a) + " != " + str(b) + " fail" )
#define EXPECT_LT(a, b, res) std::string(__NAME__(a)) + " <  " + std::string(__NAME__(b)) + ": " + str((a) <  (b)) + owner->Check( ((a) <  (b)) == (res), str(a) + " <  " + str(b) + " fail" )
#define EXPECT_LE(a, b, res) std::string(__NAME__(a)) + " <= " + std::string(__NAME__(b)) + ": " + str((a) <= (b)) + owner->Check( ((a) <= (b)) == (res), str(a) + " <= " + str(b) + " fail" )
#define EXPECT_GT(a, b, res) std::string(__NAME__(a)) + " >  " + std::string(__NAME__(b)) + ": " + str((a) >  (b)) + owner->Check( ((a) >  (b)) == (res), str(a) + " >  " + str(b) + " fail" )
#define EXPECT_GE(a, b, res) std::string(__NAME__(a)) + " >= " + std::string(__NAME__(b)) + ": " + str((a) >= (b)) + owner->Check( ((a) >= (b)) == (res), str(a) + " >= " + str(b) + " fail" )

#define EXPECT_PLUS(a, b, res) std::string(__NAME__(a)) + " + " + std::string(__NAME__(b)) + ": " + str((a) + (b)) + owner->Check( ((a) + (b)) == (res), str(a) + " + "  + str(b) + " = " + str((a) + (b)) + " fail" )
#define EXPECT_MNUS(a, b, res) std::string(__NAME__(a)) + " - " + std::string(__NAME__(b)) + ": " + str((a) - (b)) + owner->Check( ((a) - (b)) == (res), str(a) + " - "  + str(b) + " = " + str((a) - (b)) + " fail" )
#define EXPECT_MULT(a, b, res) std::string(__NAME__(a)) + " * " + std::string(__NAME__(b)) + ": " + str((a) * (b)) + owner->Check( ((a) * (b)) == (res), str(a) + " * "  + str(b) + " = " + str((a) * (b)) + " fail" )
#define EXPECT_DEVD(a, b, res) std::string(__NAME__(a)) + " / " + std::string(__NAME__(b)) + ": " + str((a) / (b)) + owner->Check( ((a) / (b)) == (res), str(a) + " / "  + str(b) + " = " + str((a) / (b)) + " fail" )

#define EXPECT_A_PLUS(a, b, res) std::string(__NAME__(a)) + " += " + std::string(__NAME__(b)) + ": " + str((a) += (b)) + owner->Check( (a) == (res), str((a) + (b)) + " += "  + str(b) + " = " + str((a)) + " fail" )
#define EXPECT_A_MNUS(a, b, res) std::string(__NAME__(a)) + " -= " + std::string(__NAME__(b)) + ": " + str((a) -= (b)) + owner->Check( (a) == (res), str((a) - (b)) + " -= "  + str(b) + " = " + str((a)) + " fail" )
#define EXPECT_A_MULT(a, b, res) std::string(__NAME__(a)) + " *= " + std::string(__NAME__(b)) + ": " + str((a) *= (b)) + owner->Check( (a) == (res), str((a) * (b)) + " *= "  + str(b) + " = " + str((a)) + " fail" )
#define EXPECT_A_DEVD(a, b, res) std::string(__NAME__(a)) + " /= " + std::string(__NAME__(b)) + ": " + str((a) /= (b)) + owner->Check( (a) == (res), str((a) / (b)) + " /= "  + str(b) + " = " + str((a)) + " fail" )



////////////////////////////////////////////////////////////////////////////////
//						TEST TEMPLATES
////////////////////////////////////////////////////////////////////////////////
// =============================================================================
template <typename T> bool empty(const TVec2<T>& v) {return is_zero(v.x) && is_zero(v.y);};
template <typename T> bool empty(const TVec3<T>& v) {return is_zero(v.x) && is_zero(v.y) && is_zero(v.z);};
template <typename T> bool empty(const TVec4<T>& v) {return is_zero(v.x) && is_zero(v.y) && is_zero(v.z) && is_zero(v.w);};

template <typename T> bool zero(const TVec2<T>& v) {return is_zero(v.x) || is_zero(v.y);};
template <typename T> bool zero(const TVec3<T>& v) {return is_zero(v.x) || is_zero(v.y) || is_zero(v.z);};
template <typename T> bool zero(const TVec4<T>& v) {return is_zero(v.x) || is_zero(v.y) || is_zero(v.z) || is_zero(v.w);};

// =============================================================================
template <typename T> int TestVec2(TestTypes* owner, ostream& out, T x, T y) {
	typedef T vec_type;
	typedef TVec2<vec_type> Vec2;

	////////////////////////////////////////////////////////////////////////////
	out << "Constructors" << endl;
	out << "Vec2 v0\t\t\t: "; 							Vec2 v0;				out << v0 << owner->Check((v0.x == 0 && v0.y == 0), "TVec2::TVec2()") << endl;
	out << "Vec2 v1(" << str(x) 		<< ")\t\t: ";	Vec2 v1(x);				out << v1 << owner->Check((v1.x == x && v1.y == x), "TVec2::TVec2(" + str(x) + ")") << endl;
	out << "Vec2 v2(" << str(x, y) 		<< ")\t\t: ";	Vec2 v2(x, y);			out << v2 << owner->Check((v2.x == x && v2.y == y), "TVec2::TVec2(" + str(x, y) + ")") << endl;
	out << "Vec2 v3(v2)\t\t: ";							Vec2 v3(v2);			out << v3 << owner->Check((v3.x == x && v3.y == y), "TVec2::TVec2(TVec2)") << endl;

	////////////////////////////////////////////////////////////////////////////
	out << endl << "Methods" << endl;
	out << "v0::empty() = " << str(v0.empty()) << ", v0::have_zero() = " << str(v0.have_zero()) << owner->Check((v0.empty() == empty(v0) && v0.have_zero() == zero(v0)), str(v0) + "::empty(), have_zero()") << endl;
	out << "v1::empty() = " << str(v1.empty()) << ", v1::have_zero() = " << str(v1.have_zero()) << owner->Check((v1.empty() == empty(v1) && v1.have_zero() == zero(v1)), str(v0) + "::empty(), have_zero()") << endl;
	out << "v3::empty() = " << str(v3.empty()) << ", v3::have_zero() = " << str(v3.have_zero()) << owner->Check((v3.empty() == empty(v3) && v3.have_zero() == zero(v3)), str(v0) + "::empty(), have_zero()") << endl;

	////////////////////////////////////////////////////////////////////////////
	out << endl << "getter / setter" << endl;
	out << "v1[ 0][ 1] = " << str(v1[ 0], v1[ 1]) << owner->Check((v1[ 0] == v1.x && v1[ 1] == v1.y), str(v1) + "::[ 0.. 1]") << endl;
	out << "v1[-2][-1] = " << str(v1[-2], v1[-1]) << owner->Check((v1[-2] == v1.x && v1[-1] == v1.y), str(v1) + "::[-2..-1]") << endl;
	out << "v1[ 2] = "; try {out << v1[ 2]; owner->Check(false, str(v1)+"::[ 2] - need excepted"); } catch(exception& e) { cout << "catch except: " << e.what() << owner->Check(true); } out << endl;
	out << "v1[-3] = "; try {out << v1[-3]; owner->Check(false, str(v1)+"::[-3] - need excepted"); } catch(exception& e) { cout << "catch except: " << e.what() << owner->Check(true); } out << endl;

	////////////////////////////////////////////////////////////////////////////
	out << endl << "Relational operators (==, != , >, <, >=, <=)" << endl;
	out << EXPECT_EQ(v3, v2,  true) << endl; // ==
	out << EXPECT_NE(v3, v2, false) << endl; // !=
	out << EXPECT_LT(v3, v2, false) << endl; // <
	out << EXPECT_LE(v3, v2,  true) << endl; // <=
	out << EXPECT_GT(v3, v2, false) << endl; // >
	out << EXPECT_GE(v3, v2,  true) << endl; // >=

	out << EXPECT_EQ(v3, v1, false) << endl; // ==
	out << EXPECT_NE(v3, v1,  true) << endl; // !=
	out << EXPECT_LT(v3, v1, false) << endl; // <
	out << EXPECT_LE(v3, v1, false) << endl; // <=
	out << EXPECT_GT(v3, v1,  true) << endl; // >
	out << EXPECT_GE(v3, v1,  true) << endl; // >=

	out << EXPECT_LT(v1, v2,  true) << endl; // <
	out << EXPECT_GT(v1, v2, false) << endl; // >

	out << EXPECT_EQ(v1, 12,  x == 12) << endl; // ==
	out << EXPECT_LT(v2, (v2 + Vec2(0, 1)), true) << endl; // <
	out << EXPECT_GT(v2, (v2 - Vec2(0, 1)), true) << endl; // >

	////////////////////////////////////////////////////////////////////////////
	out << endl << "Arithmetic operators (+, -, *, /)" << endl;
	Vec2 v3_plus_v1(v3.x+v1.x, v3.y+v1.y);
	Vec2 v3_mnus_v1(v3.x-v1.x, v3.y-v1.y);
	Vec2 v3_mult_v1(v3.x*v1.x, v3.y*v1.y);
	Vec2 v3_devd_v1 = v1.have_zero() ? (v3) : Vec2(v3.x/v1.x, v3.y/v1.y);

	out << EXPECT_PLUS(v3, v1, v3_plus_v1) << endl; // +
	out << EXPECT_MNUS(v3, v1, v3_mnus_v1) << endl; // -
	out << EXPECT_MULT(v3, v1, v3_mult_v1) << endl; // *
	if (v1.have_zero()) {
		out << "v3 / v1: ";
		try {Vec2 t = v3 / v1; cout << (str(t) + owner->Check(false, str(v3) + " / "  + str(v1) + " - need exception" )); }
		catch (exception& e) { cout << "catch except: " << e.what() << owner->Check(true); }
		out << endl;
	}
	else {
		out << EXPECT_DEVD(v3, v1, v3_devd_v1) << endl; // /
	}

	////////////////////////////////////////////////////////////////////////////
	vec_type val = 10;
	out << endl << "Arithmetic operators with val = " << str(val) << endl;
	Vec2 v3_plus_val(v3.x+val, v3.y+val);
	Vec2 v3_mnus_val(v3.x-val, v3.y-val);
	Vec2 v3_mult_val(v3.x*val, v3.y*val);
	Vec2 v3_devd_val = is_zero(val) ? (v3) : Vec2(v3.x/val, v3.y/val);

	out << EXPECT_PLUS(v3, val, v3_plus_val) << endl; // +
	out << EXPECT_MNUS(v3, val, v3_mnus_val) << endl; // -
	out << EXPECT_MULT(v3, val, v3_mult_val) << endl; // *
	if (is_zero(val)) {
		out << "v3 / " << str(val) << ": ";
		try {Vec2 t = v3 / val; cout << (str(t) + owner->Check(false, str(v3) + " / "  + str(val) + " - need exception" )); }
		catch (exception& e) { cout << "catch except: " << e.what() << owner->Check(true); }
		out << endl;
	}
	else {
		out << EXPECT_DEVD(v3, val, v3_devd_val) << endl; // /
	}

	////////////////////////////////////////////////////////////////////////////
	out << endl << "Assignment operators (+=, -=, *=, /=) with v2 = " << str(v2) << endl;
	Vec2 tmp_v3 = v3;
	out << "v3 += v1 = "; tmp_v3 += v1; out << (str(tmp_v3) + owner->Check(tmp_v3 == v3_plus_v1, str(v3) + " += " + str(v1) + " = " + str(tmp_v3) + " fail" ) ) << endl;
	out << "v3 -= v1 = "; tmp_v3 -= v1; out << (str(tmp_v3) + owner->Check(tmp_v3 == v3        , str(v3) + " -= " + str(v1) + " = " + str(tmp_v3) + " fail" ) ) << endl;
	out << "v3 *= v1 = "; tmp_v3 *= v1; out << (str(tmp_v3) + owner->Check(tmp_v3 == v3_mult_v1, str(v3) + " *= " + str(v1) + " = " + str(tmp_v3) + " fail" ) ) << endl;
	out << "v3 /= v1 = ";
	try {tmp_v3 /= v1; out << (str(tmp_v3) + owner->Check(!v1.have_zero() && tmp_v3 == v3, str(v3) + " /= " + str(v1) + " = " + str(tmp_v3) + " fail" ) );}
	catch (exception &e) {out << "catch except: " << e.what() << owner->Check(v1.have_zero()); }
	out << endl;

	////////////////////////////////////////////////////////////////////////////
	out << endl << "Assignment operators (+=, -=, *=, /=) with val = " << str(val) << endl;
	tmp_v3 = v3;
	out << "v3 += val = "; tmp_v3 += val; out << (str(tmp_v3) + owner->Check(tmp_v3 == v3_plus_val, str(v3) + " += " + str(val) + " = " + str(tmp_v3) + " fail" ) ) << endl;
	out << "v3 -= val = "; tmp_v3 -= val; out << (str(tmp_v3) + owner->Check(tmp_v3 == v3         , str(v3) + " -= " + str(val) + " = " + str(tmp_v3) + " fail" ) ) << endl;
	out << "v3 *= val = "; tmp_v3 *= val; out << (str(tmp_v3) + owner->Check(tmp_v3 == v3_mult_val, str(v3) + " *= " + str(val) + " = " + str(tmp_v3) + " fail" ) ) << endl;
	out << "v3 /= val = ";
	try {tmp_v3 /= val; out << (str(tmp_v3) + owner->Check(!is_zero(val) && tmp_v3 == v3, str(v3) + " /= " + str(val) + " = " + str(tmp_v3) + " fail" ) );}
	catch (exception &e) {out << "catch except: " << e.what() << owner->Check(is_zero(val)); }
	out << endl;

	return 0;
};

// =============================================================================
template <typename T> int TestVec3(TestTypes* owner, ostream& out, T x, T y, T z) {
	typedef T vec_type;
	typedef TVec2<vec_type> Vec2;
	typedef TVec3<vec_type> Vec3;

	////////////////////////////////////////////////////////////////////////////
	out << "Constructors" << endl;
	out << "Vec3 v0\t\t\t: "; 							Vec3 v0;				out << v0 << owner->Check((v0.x == 0 && v0.y == 0 && v0.z == 0), "TVec3::TVec3()") << endl;
	out << "Vec3 v1(" << str(x) 		<< ")\t\t: ";	Vec3 v1(x);				out << v1 << owner->Check((v1.x == x && v1.y == x && v1.z == x), "TVec3::TVec3(" + str(x) + ")") << endl;
	out << "Vec3 v2(" << str(x, y) 		<< ")\t\t: ";	Vec3 v2(x, y);			out << v2 << owner->Check((v2.x == x && v2.y == y && v2.z == 0), "TVec3::TVec3(" + str(x, y) + ")") << endl;
	out << "Vec3 v3(" << str(x, y, z)	<< ")\t: ";		Vec3 v3(x, y, z);		out << v3 << owner->Check((v3.x == x && v3.y == y && v3.z == z), "TVec3::TVec3(" + str(x, y, z) + ")") << endl;
	out << "Vec3 v4(v3)\t\t: ";							Vec3 v4(v3);			out << v4 << owner->Check((v4.x == x && v4.y == y && v4.z == z), "TVec3::TVec3(TVec3)") << endl;

	////////////////////////////////////////////////////////////////////////////
	out << endl << "Methods" << endl;
	out << "v0::empty() = " << str(v0.empty()) << ", v0::have_zero() = " << str(v0.have_zero()) << owner->Check((v0.empty() == empty(v0) && v0.have_zero() == zero(v0)), str(v0) + "::empty(), have_zero()") << endl;
	out << "v2::empty() = " << str(v2.empty()) << ", v2::have_zero() = " << str(v2.have_zero()) << owner->Check((v2.empty() == empty(v2) && v2.have_zero() == zero(v2)), str(v0) + "::empty(), have_zero()") << endl;
	out << "v4::empty() = " << str(v4.empty()) << ", v4::have_zero() = " << str(v4.have_zero()) << owner->Check((v4.empty() == empty(v4) && v4.have_zero() == zero(v4)), str(v0) + "::empty(), have_zero()") << endl;

	////////////////////////////////////////////////////////////////////////////
	out << endl << "getter / setter" << endl;
	out << "v2[ 0][ 1][ 2] = " << str(v2[ 0], v2[ 1], v2[ 2]) << owner->Check((v2[ 0] == v2.x && v2[ 1] == v2.y && v2[ 2] == v2.z), str(v2) + "::[ 0.. 2]") << endl;
	out << "v2[-3][-2][-1] = " << str(v2[-3], v2[-2], v2[-1]) << owner->Check((v2[-3] == v2.x && v2[-2] == v2.y && v2[-1] == v2.z), str(v2) + "::[-3..-1]") << endl;
	out << "v2[ 4] = "; try {out << v2[ 4]; owner->Check(false, str(v2)+"::[ 4] - need excepted"); } catch(exception& e) { cout << "catch except: " << e.what() << owner->Check(true); } out << endl;
	out << "v2[-4] = "; try {out << v2[-4]; owner->Check(false, str(v2)+"::[-4] - need excepted"); } catch(exception& e) { cout << "catch except: " << e.what() << owner->Check(true); } out << endl;

	////////////////////////////////////////////////////////////////////////////
	out << endl << "Relational operators (==, != , >, <, >=, <=)" << endl;
	out << EXPECT_EQ(v4, v3,  true) << endl; // ==
	out << EXPECT_NE(v4, v3, false) << endl; // !=
	out << EXPECT_LT(v4, v3, false) << endl; // <
	out << EXPECT_LE(v4, v3,  true) << endl; // <=
	out << EXPECT_GT(v4, v3, false) << endl; // >
	out << EXPECT_GE(v4, v3,  true) << endl; // >=

	out << EXPECT_EQ(v4, v2, false) << endl; // ==
	out << EXPECT_NE(v4, v2,  true) << endl; // !=
	out << EXPECT_LT(v4, v2, false) << endl; // <
	out << EXPECT_LE(v4, v2, false) << endl; // <=
	out << EXPECT_GT(v4, v2,  true) << endl; // >
	out << EXPECT_GE(v4, v2,  true) << endl; // >=

	out << EXPECT_LT(v1, v2, false) << endl; // <
	out << EXPECT_GT(v1, v2, false) << endl; // >

	out << EXPECT_EQ(v1, 12,  x == 12) << endl; // ==
	out << EXPECT_LT(v2, (v2 + Vec3(Vec2(), 1)), true) << endl; // <
	out << EXPECT_GT(v2, (v2 - Vec3(Vec2(), 1)), true) << endl; // >

	////////////////////////////////////////////////////////////////////////////
	out << endl << "Arithmetic operators (+, -, *, /)" << endl;
	Vec3 v4_plus_v2(v4.x+v2.x, v4.y+v2.y, v4.z+v2.z);
	Vec3 v4_mnus_v2(v4.x-v2.x, v4.y-v2.y, v4.z-v2.z);
	Vec3 v4_mult_v2(v4.x*v2.x, v4.y*v2.y, v4.z*v2.z);
	Vec3 v4_devd_v2 = v2.have_zero() ? (v4) : Vec3(v4.x/v2.x, v4.y/v2.y, v4.z/v2.z);

	out << EXPECT_PLUS(v4, v2, v4_plus_v2) << endl; // +
	out << EXPECT_MNUS(v4, v2, v4_mnus_v2) << endl; // -
	out << EXPECT_MULT(v4, v2, v4_mult_v2) << endl; // *
	if (v2.have_zero()) {
		out << "v4 / v2: ";
		try {Vec3 t = v4 / v2; cout << (str(t) + owner->Check(false, str(v4) + " / "  + str(v2) + " - need exception" )); }
		catch (exception& e) { cout << "catch except: " << e.what() << owner->Check(true); }
		out << endl;
	}
	else {
		out << EXPECT_DEVD(v4, v2, v4_devd_v2) << endl; // /
	}

	////////////////////////////////////////////////////////////////////////////
	Vec2 v2_1(11, 22);
	out << endl << "Arithmetic operators with v2_1 = " << str(v2_1) << endl;
	Vec3 v4_plus_v2_1(v4.x+v2_1.x, v4.y+v2_1.y, v4.z);
	Vec3 v4_mnus_v2_1(v4.x-v2_1.x, v4.y-v2_1.y, v4.z);
	Vec3 v4_mult_v2_1(v4.x*v2_1.x, v4.y*v2_1.y, v4.z);
	Vec3 v4_devd_v2_1 = v2_1.have_zero() ? (v4) : Vec3(v4.x/v2_1.x, v4.y/v2_1.y, v4.z);

	out << EXPECT_PLUS(v4, v2_1, v4_plus_v2_1) << endl; // +
	out << EXPECT_MNUS(v4, v2_1, v4_mnus_v2_1) << endl; // -
	out << EXPECT_MULT(v4, v2_1, v4_mult_v2_1) << endl; // *
	if (v2_1.have_zero()) {
		out << "v4 / " << str(v2_1) << ": ";
		try {Vec3 t = v4 / v2_1; cout << (str(t) + owner->Check(false, str(v4) + " / "  + str(v2_1) + " - need exception" )); }
		catch (exception& e) { cout << "catch except: " << e.what() << owner->Check(true); }
		out << endl;
	}
	else {
		out << EXPECT_DEVD(v4, v2_1, v4_devd_v2_1) << endl; // /
	}

	////////////////////////////////////////////////////////////////////////////
	vec_type val = 10;
	out << endl << "Arithmetic operators with val = " << str(val) << endl;
	Vec3 v4_plus_val(v4.x+val, v4.y+val, v4.z+val);
	Vec3 v4_mnus_val(v4.x-val, v4.y-val, v4.z-val);
	Vec3 v4_mult_val(v4.x*val, v4.y*val, v4.z*val);
	Vec3 v4_devd_val = is_zero(val) ? (v4) : Vec3(v4.x/val, v4.y/val, v4.z/val);

	out << EXPECT_PLUS(v4, val, v4_plus_val) << endl; // +
	out << EXPECT_MNUS(v4, val, v4_mnus_val) << endl; // -
	out << EXPECT_MULT(v4, val, v4_mult_val) << endl; // *
	if (is_zero(val)) {
		out << "v4 / " << str(val) << ": ";
		try {Vec3 t = v4 / val; cout << (str(t) + owner->Check(false, str(v4) + " / "  + str(val) + " - need exception" )); }
		catch (exception& e) { cout << "catch except: " << e.what() << owner->Check(true); }
		out << endl;
	}
	else {
		out << EXPECT_DEVD(v4, val, v4_devd_val) << endl; // /
	}

	////////////////////////////////////////////////////////////////////////////
	out << endl << "Assignment operators (+=, -=, *=, /=) with v2 = " << str(v2) << endl;
	Vec3 tmp_v4 = v4;
	out << "v4 += v2 = "; tmp_v4 += v2; out << (str(tmp_v4) + owner->Check(tmp_v4 == v4_plus_v2, str(v4) + " += " + str(v2) + " = " + str(tmp_v4) + " fail" ) ) << endl;
	out << "v4 -= v2 = "; tmp_v4 -= v2; out << (str(tmp_v4) + owner->Check(tmp_v4 == v4        , str(v4) + " -= " + str(v2) + " = " + str(tmp_v4) + " fail" ) ) << endl;
	out << "v4 *= v2 = "; tmp_v4 *= v2; out << (str(tmp_v4) + owner->Check(tmp_v4 == v4_mult_v2, str(v4) + " *= " + str(v2) + " = " + str(tmp_v4) + " fail" ) ) << endl;
	out << "v4 /= v2 = ";
	try {tmp_v4 /= v2; out << (str(tmp_v4) + owner->Check(!v2.have_zero() && tmp_v4 == v4, str(v4) + " /= " + str(v2) + " = " + str(tmp_v4) + " fail" ) );}
	catch (exception &e) {out << "catch except: " << e.what() << owner->Check(v2.have_zero()); }
	out << endl;

	////////////////////////////////////////////////////////////////////////////
	out << endl << "Assignment operators (+=, -=, *=, /=) with v2_1 = " << str(v2_1) << endl;
	tmp_v4 = v4;
	out << "v4 += v2_1 = "; tmp_v4 += v2_1; out << (str(tmp_v4) + owner->Check(tmp_v4 == v4_plus_v2_1, str(v4) + " += " + str(v2_1) + " = " + str(tmp_v4) + " fail" ) ) << endl;
	out << "v4 -= v2_1 = "; tmp_v4 -= v2_1; out << (str(tmp_v4) + owner->Check(tmp_v4 == v4          , str(v4) + " -= " + str(v2_1) + " = " + str(tmp_v4) + " fail" ) ) << endl;
	out << "v4 *= v2_1 = "; tmp_v4 *= v2_1; out << (str(tmp_v4) + owner->Check(tmp_v4 == v4_mult_v2_1, str(v4) + " *= " + str(v2_1) + " = " + str(tmp_v4) + " fail" ) ) << endl;
	out << "v4 /= v2_1 = ";
	try {tmp_v4 /= v2_1; out << (str(tmp_v4) + owner->Check(!v2_1.have_zero() && tmp_v4 == v4, str(v4) + " /= " + str(v2_1) + " = " + str(tmp_v4) + " fail" ) );}
	catch (exception &e) {out << "catch except: " << e.what() << owner->Check(v2_1.have_zero()); }
	out << endl;

	////////////////////////////////////////////////////////////////////////////
	out << endl << "Assignment operators (+=, -=, *=, /=) with val = " << str(val) << endl;
	tmp_v4 = v4;
	out << "v4 += val = "; tmp_v4 += val; out << (str(tmp_v4) + owner->Check(tmp_v4 == v4_plus_val, str(v4) + " += " + str(val) + " = " + str(tmp_v4) + " fail" ) ) << endl;
	out << "v4 -= val = "; tmp_v4 -= val; out << (str(tmp_v4) + owner->Check(tmp_v4 == v4         , str(v4) + " -= " + str(val) + " = " + str(tmp_v4) + " fail" ) ) << endl;
	out << "v4 *= val = "; tmp_v4 *= val; out << (str(tmp_v4) + owner->Check(tmp_v4 == v4_mult_val, str(v4) + " *= " + str(val) + " = " + str(tmp_v4) + " fail" ) ) << endl;
	out << "v4 /= val = ";
	try {tmp_v4 /= val; out << (str(tmp_v4) + owner->Check(!is_zero(val) && tmp_v4 == v4, str(v4) + " /= " + str(val) + " = " + str(tmp_v4) + " fail" ) );}
	catch (exception &e) {out << "catch except: " << e.what() << owner->Check(is_zero(val)); }
	out << endl;

	return 0;
};

template <typename T> int TestVec4(TestTypes* owner, ostream& out, T x, T y, T z, T w) {
	typedef T vec_type;
	typedef TVec3<vec_type> Vec3;
	typedef TVec4<vec_type> Vec4;

	////////////////////////////////////////////////////////////////////////////
	out << "Constructors" << endl;
	out << "Vec4 v0\t\t\t: "; 							Vec4 v0;				out << v0 << owner->Check((v0.x == 0 && v0.y == 0 && v0.z == 0 && v0.w == 0), "TVec4::TVec4()") << endl;
	out << "Vec4 v1(" << str(x) 		<< ")\t\t: ";	Vec4 v1(x);				out << v1 << owner->Check((v1.x == x && v1.y == x && v1.z == x && v1.w == x), "TVec4::TVec4(" + str(x) + ")") << endl;
	out << "Vec4 v2(" << str(x, y) 		<< ")\t\t: ";	Vec4 v2(x, y);			out << v2 << owner->Check((v2.x == x && v2.y == y && v2.z == 0 && v2.w == 0), "TVec4::TVec4(" + str(x, y) + ")") << endl;
	out << "Vec4 v3(" << str(x, y, z)	<< ")\t: ";		Vec4 v3(x, y, z);		out << v3 << owner->Check((v3.x == x && v3.y == y && v3.z == z && v3.w == 0), "TVec4::TVec4(" + str(x, y, z) + ")") << endl;
	out << "Vec4 v4(" << str(x, y, z, w)<< ")\t: ";		Vec4 v4(x, y, z, w);	out << v4 << owner->Check((v4.x == x && v4.y == y && v4.z == z && v4.w == w), "TVec4::TVec4(" + str(x, y, z, w) + ")") << endl;
	out << "Vec4 v5(v4)\t\t: ";							Vec4 v5(v4);			out << v5 << owner->Check((v5.x == x && v5.y == y && v5.z == z && v5.w == w), "TVec4::TVec4(TVec4)") << endl;

	////////////////////////////////////////////////////////////////////////////
	out << endl << "Methods" << endl;
	out << "v0::empty() = " << str(v0.empty()) << ", v0::have_zero() = " << str(v0.have_zero()) << owner->Check((v0.empty() == empty(v0) && v0.have_zero() == zero(v0)), str(v0) + "::empty(), have_zero()") << endl;
	out << "v3::empty() = " << str(v3.empty()) << ", v3::have_zero() = " << str(v3.have_zero()) << owner->Check((v3.empty() == empty(v3) && v3.have_zero() == zero(v3)), str(v0) + "::empty(), have_zero()") << endl;
	out << "v5::empty() = " << str(v5.empty()) << ", v5::have_zero() = " << str(v5.have_zero()) << owner->Check((v5.empty() == empty(v5) && v5.have_zero() == zero(v5)), str(v0) + "::empty(), have_zero()") << endl;

	////////////////////////////////////////////////////////////////////////////
	out << endl << "getter / setter" << endl;
	out << "v3[ 0][ 1][ 2][ 3] = " << str(v3[ 0], v3[ 1], v3[ 2], v3[ 3]) << owner->Check((v3[ 0] == v3.x && v3[ 1] == v3.y && v3[ 2] == v3.z && v3[ 3] == v3.w), str(v3) + "::[ 0.. 3]") << endl;
	out << "v3[-4][-3][-2][-1] = " << str(v3[-4], v3[-3], v3[-2], v3[-1]) << owner->Check((v3[-4] == v3.x && v3[-3] == v3.y && v3[-2] == v3.z && v3[-1] == v3.w), str(v3) + "::[-4..-1]") << endl;
	out << "v3[ 5] = "; try {out << v3[ 5]; owner->Check(false, str(v3)+"::[ 5] - need excepted"); } catch(exception& e) { cout << "catch except: " << e.what() << owner->Check(true); } out << endl;
	out << "v3[-5] = "; try {out << v3[-5]; owner->Check(false, str(v3)+"::[-5] - need excepted"); } catch(exception& e) { cout << "catch except: " << e.what() << owner->Check(true); } out << endl;

	////////////////////////////////////////////////////////////////////////////
	out << endl << "Relational operators (==, != , >, <, >=, <=)" << endl;
	out << EXPECT_EQ(v5, v4,  true) << endl; // ==
	out << EXPECT_NE(v5, v4, false) << endl; // !=
	out << EXPECT_LT(v5, v4, false) << endl; // <
	out << EXPECT_LE(v5, v4,  true) << endl; // <=
	out << EXPECT_GT(v5, v4, false) << endl; // >
	out << EXPECT_GE(v5, v4,  true) << endl; // >=

	out << EXPECT_EQ(v5, v3, false) << endl; // ==
	out << EXPECT_NE(v5, v3,  true) << endl; // !=
	out << EXPECT_LT(v5, v3, false) << endl; // <
	out << EXPECT_LE(v5, v3, false) << endl; // <=
	out << EXPECT_GT(v5, v3,  true) << endl; // >
	out << EXPECT_GE(v5, v3,  true) << endl; // >=

	out << EXPECT_LT(v1, v2, false) << endl; // <
	out << EXPECT_GT(v1, v2, false) << endl; // >

	out << EXPECT_EQ(v1, 12,  x == 12) << endl; // ==
	out << EXPECT_LT(v3, (v3 + Vec4(Vec3(), 1)), true) << endl; // <
	out << EXPECT_GT(v3, (v3 - Vec4(Vec3(), 1)), true) << endl; // >

	////////////////////////////////////////////////////////////////////////////
	out << endl << "Arithmetic operators (+, -, *, /)" << endl;
	Vec4 v5_plus_v3(v5.x+v3.x, v5.y+v3.y, v5.z+v3.z, v5.w+v3.w);
	Vec4 v5_mnus_v3(v5.x-v3.x, v5.y-v3.y, v5.z-v3.z, v5.w-v3.w);
	Vec4 v5_mult_v3(v5.x*v3.x, v5.y*v3.y, v5.z*v3.z, v5.w*v3.w);
	Vec4 v5_devd_v3 = v3.have_zero() ? (v5) : Vec4(v5.x/v3.x, v5.y/v3.y, v5.z/v3.z, v5.w/v3.w);

	out << EXPECT_PLUS(v5, v3, v5_plus_v3) << endl; // +
	out << EXPECT_MNUS(v5, v3, v5_mnus_v3) << endl; // -
	out << EXPECT_MULT(v5, v3, v5_mult_v3) << endl; // *
	if (v3.have_zero()) {
		out << "v5 / v3: ";
		try {Vec4 t = v5 / v3; cout << (str(t) + owner->Check(false, str(v5) + " / "  + str(v3) + " - need exception" )); }
		catch (exception& e) { cout << "catch except: " << e.what() << owner->Check(true); }
		out << endl;
	}
	else {
		out << EXPECT_DEVD(v5, v3, v5_devd_v3) << endl; // /
	}

	////////////////////////////////////////////////////////////////////////////
	Vec3 v3_1(11, 22, 33);
	out << endl << "Arithmetic operators with v3_1 = " << str(v3_1) << endl;
	Vec4 v5_plus_v3_1(v5.x+v3_1.x, v5.y+v3_1.y, v5.z+v3_1.z, v5.w);
	Vec4 v5_mnus_v3_1(v5.x-v3_1.x, v5.y-v3_1.y, v5.z-v3_1.z, v5.w);
	Vec4 v5_mult_v3_1(v5.x*v3_1.x, v5.y*v3_1.y, v5.z*v3_1.z, v5.w);
	Vec4 v5_devd_v3_1 = v3_1.have_zero() ? (v5) : Vec4(v5.x/v3_1.x, v5.y/v3_1.y, v5.z/v3_1.z, v5.w);

	out << EXPECT_PLUS(v5, v3_1, v5_plus_v3_1) << endl; // +
	out << EXPECT_MNUS(v5, v3_1, v5_mnus_v3_1) << endl; // -
	out << EXPECT_MULT(v5, v3_1, v5_mult_v3_1) << endl; // *
	if (v3_1.have_zero()) {
		out << "v5 / " << str(v3_1) << ": ";
		try {Vec4 t = v5 / v3_1; cout << (str(t) + owner->Check(false, str(v5) + " / "  + str(v3_1) + " - need exception" )); }
		catch (exception& e) { cout << "catch except: " << e.what() << owner->Check(true); }
		out << endl;
	}
	else {
		out << EXPECT_DEVD(v5, v3_1, v5_devd_v3_1) << endl; // /
	}

	////////////////////////////////////////////////////////////////////////////
	vec_type val = 10;
	out << endl << "Arithmetic operators with val = " << str(val) << endl;
	Vec4 v5_plus_val(v5.x+val, v5.y+val, v5.z+val, v5.w+val);
	Vec4 v5_mnus_val(v5.x-val, v5.y-val, v5.z-val, v5.w-val);
	Vec4 v5_mult_val(v5.x*val, v5.y*val, v5.z*val, v5.w*val);
	Vec4 v5_devd_val = is_zero(val) ? (v5) : Vec4(v5.x/val, v5.y/val, v5.z/val, v5.w/val);

	out << EXPECT_PLUS(v5, val, v5_plus_val) << endl; // +
	out << EXPECT_MNUS(v5, val, v5_mnus_val) << endl; // -
	out << EXPECT_MULT(v5, val, v5_mult_val) << endl; // *
	if (is_zero(val)) {
		out << "v5 / " << str(val) << ": ";
		try {Vec4 t = v5 / val; cout << (str(t) + owner->Check(false, str(v5) + " / "  + str(val) + " - need exception" )); }
		catch (exception& e) { cout << "catch except: " << e.what() << owner->Check(true); }
		out << endl;
	}
	else {
		out << EXPECT_DEVD(v5, val, v5_devd_val) << endl; // /
	}

	////////////////////////////////////////////////////////////////////////////
	out << endl << "Assignment operators (+=, -=, *=, /=) with v3 = " << str(v3) << endl;
	Vec4 tmp_v5 = v5;
	out << "v5 += v3 = "; tmp_v5 += v3; out << (str(tmp_v5) + owner->Check(tmp_v5 == v5_plus_v3, str(v5) + " += " + str(v3) + " = " + str(tmp_v5) + " fail" ) ) << endl;
	out << "v5 -= v3 = "; tmp_v5 -= v3; out << (str(tmp_v5) + owner->Check(tmp_v5 == v5        , str(v5) + " -= " + str(v3) + " = " + str(tmp_v5) + " fail" ) ) << endl;
	out << "v5 *= v3 = "; tmp_v5 *= v3; out << (str(tmp_v5) + owner->Check(tmp_v5 == v5_mult_v3, str(v5) + " *= " + str(v3) + " = " + str(tmp_v5) + " fail" ) ) << endl;
	out << "v5 /= v3 = ";
	try {tmp_v5 /= v3; out << (str(tmp_v5) + owner->Check(!v3.have_zero() && tmp_v5 == v5, str(v5) + " /= " + str(v3) + " = " + str(tmp_v5) + " fail" ) );}
	catch (exception &e) {out << "catch except: " << e.what() << owner->Check(v3.have_zero()); }
	out << endl;

	////////////////////////////////////////////////////////////////////////////
	out << endl << "Assignment operators (+=, -=, *=, /=) with v3_1 = " << str(v3_1) << endl;
	tmp_v5 = v5;
	out << "v5 += v3_1 = "; tmp_v5 += v3_1; out << (str(tmp_v5) + owner->Check(tmp_v5 == v5_plus_v3_1, str(v5) + " += " + str(v3_1) + " = " + str(tmp_v5) + " fail" ) ) << endl;
	out << "v5 -= v3_1 = "; tmp_v5 -= v3_1; out << (str(tmp_v5) + owner->Check(tmp_v5 == v5          , str(v5) + " -= " + str(v3_1) + " = " + str(tmp_v5) + " fail" ) ) << endl;
	out << "v5 *= v3_1 = "; tmp_v5 *= v3_1; out << (str(tmp_v5) + owner->Check(tmp_v5 == v5_mult_v3_1, str(v5) + " *= " + str(v3_1) + " = " + str(tmp_v5) + " fail" ) ) << endl;
	out << "v5 /= v3_1 = ";
	try {tmp_v5 /= v3_1; out << (str(tmp_v5) + owner->Check(!v3_1.have_zero() && tmp_v5 == v5, str(v5) + " /= " + str(v3_1) + " = " + str(tmp_v5) + " fail" ) );}
	catch (exception &e) {out << "catch except: " << e.what() << owner->Check(v3_1.have_zero()); }
	out << endl;

	////////////////////////////////////////////////////////////////////////////
	out << endl << "Assignment operators (+=, -=, *=, /=) with val = " << str(val) << endl;
	tmp_v5 = v5;
	out << "v5 += val = "; tmp_v5 += val; out << (str(tmp_v5) + owner->Check(tmp_v5 == v5_plus_val, str(v5) + " += " + str(val) + " = " + str(tmp_v5) + " fail" ) ) << endl;
	out << "v5 -= val = "; tmp_v5 -= val; out << (str(tmp_v5) + owner->Check(tmp_v5 == v5         , str(v5) + " -= " + str(val) + " = " + str(tmp_v5) + " fail" ) ) << endl;
	out << "v5 *= val = "; tmp_v5 *= val; out << (str(tmp_v5) + owner->Check(tmp_v5 == v5_mult_val, str(v5) + " *= " + str(val) + " = " + str(tmp_v5) + " fail" ) ) << endl;
	out << "v5 /= val = ";
	try {tmp_v5 /= val; out << (str(tmp_v5) + owner->Check(!is_zero(val) && tmp_v5 == v5, str(v5) + " /= " + str(val) + " = " + str(tmp_v5) + " fail" ) );}
	catch (exception &e) {out << "catch except: " << e.what() << owner->Check(is_zero(val)); }
	out << endl;

	return 0;
}

