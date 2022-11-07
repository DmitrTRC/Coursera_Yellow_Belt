//
// Created by Dmitry Morozov on 20/9/22.
//

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

double getDiscriminant(double a, double b, double c) {

    return b * b - 4 * a * c;
}

int getLinearCount(double b, double c) {

    if (b == 0) {
        return 0;
    } else {
        return 1;
    }
}

int getRootCount(double a, double b, double c) {

    double discriminant = getDiscriminant(a, b, c);
    if (discriminant < 0) {
        return 0;
    } else if (discriminant == 0) {
        return 1;
    } else {
        return 2;
    }
}

int GetDistinctRealRootCount(double a, double b, double c) {

    if (a == 0) {
        return getLinearCount(b, c);
    } else {
        return getRootCount(a, b, c);
    }

}

void Test_getDiscriminant() {

    AssertEqual(getDiscriminant(1, 2, 1), 0, "getDiscriminant(1, 2, 1)");
    AssertEqual(getDiscriminant(1, 2, 2), -12, "getDiscriminant(1, 2, 2)");
    AssertEqual(getDiscriminant(1, 2, 3), -8, "getDiscriminant(1, 2, 3)");
    AssertEqual(getDiscriminant(1, 2, 4), -12, "getDiscriminant(1, 2, 4)");
    AssertEqual(getDiscriminant(1, 2, 5), 0, "getDiscriminant(1, 2, 5)");
    AssertEqual(getDiscriminant(1, 2, 6), 4, "getDiscriminant(1, 2, 6)");
    AssertEqual(getDiscriminant(1, 2, 7), 12, "getDiscriminant(1, 2, 7)");
    AssertEqual(getDiscriminant(1, 2, 8), 20, "getDiscriminant(1, 2, 8)");
    AssertEqual(getDiscriminant(1, 2, 9), 28, "getDiscriminant(1, 2, 9)");
    AssertEqual(getDiscriminant(1, 2, 10), 36, "getDiscriminant(1, 2, 10)");
    AssertEqual(getDiscriminant(1, 2, 11), 44, "getDiscriminant(1, 2, 11)");
    AssertEqual(getDiscriminant(1, 2, 12), 52, "getDiscriminant(1, 2, 12)");
    AssertEqual(getDiscriminant(1, 2, 13), 60, "getDiscriminant(1, 2, 13)");
    AssertEqual(getDiscriminant(1, 2, 14), 68, "getDiscriminant(1, 2, 14)");
    AssertEqual(getDiscriminant(1, 2, 15), 76, "getDiscriminant(1, 2, 15)");
    AssertEqual(get

}

void Test_getLinearCount() {

    AssertEqual(getLinearCount(0, 0), 0, "b = 0, c = 0");
    AssertEqual(getLinearCount(0, 1), 0, "b = 0, c = 1");
    AssertEqual(getLinearCount(1, 0), 1, "b = 1, c = 0");
    AssertEqual(getLinearCount(1, 1), 1, "b = 1, c = 1");
}

void Test_getRootCount() {

    AssertEqual(getRootCount(1, 0, 0), 2, "a = 1, b = 0, c = 0");
    AssertEqual(getRootCount(1, 0, 1), 0, "a = 1, b = 0, c = 1");
    AssertEqual(getRootCount(1, 1, 0), 1, "a = 1, b = 1, c = 0");
    AssertEqual(getRootCount(1, 1, 1), 0, "a = 1, b = 1, c = 1");
}

void Test_GetDistinctRealRootCount() {

    AssertEqual(GetDistinctRealRootCount(0, 0, 0), 0, "a = 0, b = 0, c = 0");
    AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0, "a = 0, b = 0, c = 1");
    AssertEqual(GetDistinctRealRootCount(0, 1, 0), 1, "a = 0, b = 1, c = 0");
    AssertEqual(GetDistinctRealRootCount(0, 1, 1), 1, "a = 0, b = 1, c = 1");
    AssertEqual(GetDistinctRealRootCount(1, 0, 0), 2, "a = 1, b = 0, c = 0");
    AssertEqual(GetDistinctRealRootCount(1, 0, 1), 0, "a = 1, b = 0, c = 1");
    AssertEqual(GetDistinctRealRootCount(1, 1, 0), 1, "a = 1, b = 1, c = 0");
    AssertEqual(GetDistinctRealRootCount(1, 1, 1), 0, "a = 1, b = 1, c = 1");
}

void TestAll() {

    TestRunner runner;
    runner.RunTest(Test_getDiscriminant, "Test_getDiscriminant");
    runner.RunTest(Test_getLinearCount, "Test_getLinearCount");
    runner.RunTest(Test_getRootCount, "Test_getRootCount");


}


int main() {
    TestAll();

    return 0;
}