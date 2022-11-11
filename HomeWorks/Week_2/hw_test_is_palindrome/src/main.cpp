// Check if the string is a palindrome
// empty string is a palindrome
// string of length 1 is a palindrome
// Include all symbols and spaces
// Errors:
// Ignoring first , last symbols
// Ignoring spaces
// Compare stops before the middle of the string
#include <string>

using namespace std;

bool IsPalindrom(const string &s) {

    if (s.empty()) {
        return true;
    }
    if (s.size() == 1) {
        return true;
    }
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

#include <map>
#include <set>
#include <iostream>
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

void TestAll() {

    TestRunner tr;
    tr.RunTest([] {
        AssertEqual(IsPalindrom(""), true, "empty string is a palindrome");
    }, "empty string is a palindrome");
    tr.RunTest([] {
        AssertEqual(IsPalindrom("a"), true, "string of length 1 is a palindrome");
    }, "string of length 1 is a palindrome");
    tr.RunTest([] {
        AssertEqual(IsPalindrom("ab"), false, "string of length 2 is not a palindrome");
    }, "string of length 2 is not a palindrome");
    tr.RunTest([] {
        AssertEqual(IsPalindrom("aba"), true, "string of length 3 is a palindrome");
    }, "string of length 3 is a palindrome");
    tr.RunTest([] {
        AssertEqual(IsPalindrom("abba"), true, "string of length 4 is a palindrome");
    }, "string of length 4 is a palindrome");
    tr.RunTest([] {
        AssertEqual(IsPalindrom("abacaba"), true, "string of length 7 is a palindrome");
    }, "string of length 7 is a palindrome");
    tr.RunTest([] {
        AssertEqual(IsPalindrom("abacab"), false, "string of length 6 is not a palindrome");
    }, "string of length 6 is not a palindrome");
    tr.RunTest([] {
        AssertEqual(IsPalindrom("madam"), true, "string of length 5 is a palindrome");
    }, "string of length 5 is a palindrome");
    tr.RunTest([] {
        AssertEqual(IsPalindrom("level"), true, "string of length 5 is a palindrome");
    }, "string of length 5 is a palindrome");
    tr.RunTest([] {
        AssertEqual(IsPalindrom("wasitacaroracatisaw"), true, "string of length 19 is a palindrome");
    }, "string of length 19 is a palindrome");

    tr.RunTest([] {
        AssertEqual(IsPalindrom("madam"), true, "string of length 5 is a palindrome");
    }, "string of length 18 is not a palindrome");

    tr.RunTest([] {
        AssertEqual(IsPalindrom("wasitacaroracatisaw madam"), false, "string of length 19 is a palindrome");
    }, "string of length 19 is not a palindrome");


}


int main() {

    TestAll();
    return 0;
}
