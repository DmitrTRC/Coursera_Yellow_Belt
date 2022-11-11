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

int GCD(int a, int b) {

    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
    while (a > 0 && b > 0) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

class Rational {
public:
    Rational() {  // дробь по умолчанию — 0/1
        numerator = 0;
        denominator = 1;
    }

    Rational(int new_numerator, int new_denominator) {

        const int gcd = GCD(new_numerator, new_denominator);
        // сократим дробь, разделив числитель и знаменатель на их НОД
        numerator = new_numerator / gcd;
        denominator = new_denominator / gcd;
        // знаменатель должен быть положительным
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

    int Numerator() const {

        return numerator;
    }

    int Denominator() const {

        return denominator;
    }

private:
    int numerator;
    int denominator;
};

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
    AssertEqual(Rational(-2, -3).Numerator(), 2, "9");
    AssertEqual(Rational(-2, -3).Denominator(), 3, "10");
    AssertEqual(Rational(10, 15).Numerator(), 2, "11");
    AssertEqual(Rational(10, 15).Denominator(), 3, "12");
    AssertEqual(Rational(-10, 15).Numerator(), -2, "13");
    AssertEqual(Rational(-10, 15).Denominator(), 3, "14");
    AssertEqual(Rational(10, -15).Numerator(), -2, "15");
    AssertEqual(Rational(10, -15).Denominator(), 3, "16");

}

void TestZeroNumerator() {

    Rational r(0, 2);
    AssertEqual(r.Numerator(), 0);
    AssertEqual(r.Denominator(), 1);

//    Rational r1(0, 0);
//    AssertEqual(r1.Numerator(), 0);
//    AssertEqual(r1.Denominator(), 1);

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