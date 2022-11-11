#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template<class T>
ostream &operator<<(ostream &os, const vector<T> &s) {

    os << "{";
    bool first = true;
    for (const auto &x: s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template<class T>
ostream &operator<<(ostream &os, const set<T> &s) {

    os << "{";
    bool first = true;
    for (const auto &x: s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template<class K, class V>
ostream &operator<<(ostream &os, const map<K, V> &m) {

    os << "{";
    bool first = true;
    for (const auto &kv: m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T &t, const U &u, const string &hint = {}) {

    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string &hint) {

    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template<class TestFunc>
    void RunTest(TestFunc func, const string &test_name) {

        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception &e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {

        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

//class Rational {
//public:
//
//    Rational() : Rational(0, 1) {};
//
//    Rational(int numerator, int denominator) {
//
//        if (denominator == 0) {
//            throw invalid_argument("Invalid argument");
//        }
//
//        if (numerator == 0) {
//            _numerator = 0;
//            _denominator = 1;
//        } else {
//            int gcd = GCD(numerator, denominator);
//            _numerator = numerator / gcd;
//            _denominator = denominator / gcd;
//            if (_denominator < 0) {
//                _numerator *= -1;
//                _denominator *= -1;
//            }
//        }
//    }
//
//    int Numerator() const {
//
//        return _numerator;
//    }
//
//    int Denominator() const {
//
//        return _denominator;
//    }
//
//private:
//    int _numerator;
//    int _denominator;
////GCD for whole integers range
//    int GCD(int a, int b) {
//
//        if (a < 0) {
//            a *= -1;
//        }
//        if (b < 0) {
//            b *= -1;
//        }
//        while (a > 0 && b > 0) {
//            if (a > b) {
//                a %= b;
//            } else {
//                b %= a;
//            }
//        }
//        return a + b;
//
//    }
//};

void TestDefaultConstructor() {

    Rational r;
    AssertEqual(r.Numerator(), 0);
    AssertEqual(r.Denominator(), 1);
}

void TestConstructor() {

    Rational r(1, 2);
    AssertEqual(r.Numerator(), 1, "1");
    AssertEqual(r.Denominator(), 2, "2");
    AssertEqual(Rational(1, -2).Numerator(), -1, "3");
    AssertEqual(Rational(1, -2).Denominator(), 2, "4");
    AssertEqual(Rational(-1, 2).Numerator(), -1, "5");
    AssertEqual(Rational(-1, 2).Denominator(), 2, "6");
    AssertEqual(Rational(-1, -2).Numerator(), 1, "7");
    AssertEqual(Rational(-1, -2).Denominator(), 2, "8");

}

void TestZeroNumerator() {

    Rational r(0, 2);
    AssertEqual(r.Numerator(), 0);
    AssertEqual(r.Denominator(), 1);
}


void TestAll() {

    TestRunner runner;

    runner.RunTest(TestDefaultConstructor, "TestDefaultConstructor");
    runner.RunTest(TestConstructor, "TestConstructor");
    runner.RunTest(TestZeroNumerator, "TestZeroNumerator");
}

int main() {

    TestAll();

    return 0;
}