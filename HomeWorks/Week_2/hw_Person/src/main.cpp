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

//string FindNameByYear(const map<int, string> &names, int year) {
//
//    string name;  // изначально имя неизвестно
//
//    // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
//    for (const auto &item: names) {
//        // если очередной год не больше данного, обновляем имя
//        if (item.first <= year) {
//            name = item.second;
//        } else {
//            // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
//            break;
//        }
//    }
//
//    return name;
//}
//
//class Person {
//public:
//    void ChangeFirstName(int year, const string &first_name) {
//
//        first_names[year] = first_name;
//    }
//
//    void ChangeLastName(int year, const string &last_name) {
//
//        last_names[year] = last_name;
//    }
//
//    string GetFullName(int year) {
//        // получаем имя и фамилию по состоянию на год year
//        const string first_name = FindNameByYear(first_names, year);
//        const string last_name = FindNameByYear(last_names, year);
//
//        // если и имя, и фамилия неизвестны
//        if (first_name.empty() && last_name.empty()) {
//            return "Incognito";
//
//            // если неизвестно только имя
//        } else if (first_name.empty()) {
//            return last_name + " with unknown first name";
//
//            // если неизвестна только фамилия
//        } else if (last_name.empty()) {
//            return first_name + " with unknown last name";
//
//            // если известны и имя, и фамилия
//        } else {
//            return first_name + " " + last_name;
//        }
//    }
//
//private:
//    map<int, string> first_names;
//    map<int, string> last_names;
//};


//TESTS

void Test_ChangeFirstName() {

    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeFirstName(1967, "Appolinaria");

    AssertEqual(person.GetFullName(1964), "Incognito", "1964");
    AssertEqual(person.GetFullName(1966), "Polina with unknown last name", "1966");
    AssertEqual(person.GetFullName(1968), "Appolinaria with unknown last name", "1968");
}

void Test_ChangeLastName() {

    Person person;

    person.ChangeLastName(1965, "Sergeeva");
    person.ChangeLastName(1967, "Volkova");

    AssertEqual(person.GetFullName(1964), "Incognito", "1964");
    AssertEqual(person.GetFullName(1966), "Sergeeva with unknown first name", "1966");
    AssertEqual(person.GetFullName(1968), "Volkova with unknown first name", "1968");
}

void TestChange_FirstNameAndLastName() {

    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");

    AssertEqual(person.GetFullName(1964), "Incognito", "1964");
    AssertEqual(person.GetFullName(1966), "Polina with unknown last name", "1966");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva", "1968");
}

void Test_GetFullName() {

    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");

    AssertEqual(person.GetFullName(1964), "Incognito", "1964");
    AssertEqual(person.GetFullName(1966), "Polina with unknown last name", "1966");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva", "1968");
}

void Test_FindingNameByYear() {

    map<int, string> names = {
            {1960, "Polina"},
            {1967, "Appolinaria"},
            {1970, "Polina"},
            {1971, "Olga"},
            {1973, "Ann"},
    };

    AssertEqual(FindNameByYear(names, 1960), "Polina", "1960");
    AssertEqual(FindNameByYear(names, 1966), "Polina", "1966");
    AssertEqual(FindNameByYear(names, 1967), "Appolinaria", "1967");
    AssertEqual(FindNameByYear(names, 1969), "Appolinaria", "1969");
    AssertEqual(FindNameByYear(names, 1970), "Polina", "1970");
    AssertEqual(FindNameByYear(names, 1971), "Olga", "1971");
    AssertEqual(FindNameByYear(names, 1972), "Olga", "1972");
    AssertEqual(FindNameByYear(names, 1973), "Ann", "1973");
    AssertEqual(FindNameByYear(names, 1974), "Ann", "1974");
}


void Test_Person() {

    Person person;

    person.ChangeFirstName(1965, "Polina");

    AssertEqual(person.GetFullName(1964), "Incognito", "1964");
    AssertEqual(person.GetFullName(1966), "Polina with unknown last name", "1966");

    person.ChangeLastName(1967, "Sergeeva");

    AssertEqual(person.GetFullName(1968), "Polina Sergeeva", "1968");

    person.ChangeFirstName(1970, "Appolinaria");
    AssertEqual(person.GetFullName(1969), "Polina Sergeeva", "1969");
    AssertEqual(person.GetFullName(1970), "Appolinaria Sergeeva", "1970");

    person.ChangeLastName(1968, "Volkova");
    AssertEqual(person.GetFullName(1968), "Polina Volkova", "1968");
    AssertEqual(person.GetFullName(1969), "Polina Volkova", "1969");
    AssertEqual(person.GetFullName(1970), "Appolinaria Volkova", "1970");

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    AssertEqual(person.GetFullName(1990), "Polina Volkova-Sergeeva", "1990");
    AssertEqual(person.GetFullName(1991), "Polina Volkova-Sergeeva", "1991");

    person.ChangeFirstName(1966, "Pauline");
    person.ChangeLastName(1960, "Volkova");
    AssertEqual(person.GetFullName(1966), "Pauline Volkova", "1966");
}

void TestAll() {

    TestRunner runner;

    runner.RunTest(Test_ChangeFirstName, "Test_ChangeFirstName");
    runner.RunTest(Test_ChangeLastName, "Test_ChangeLastName");
    runner.RunTest(TestChange_FirstNameAndLastName, "TestChange_FirstNameAndLastName");
    runner.RunTest(Test_GetFullName, "Test_GetFullName");
    runner.RunTest(Test_FindingNameByYear, "Test_FindingNameByYear");
    runner.RunTest(Test_Person, "Test_Person");

}


int main() {

    TestAll();

    return 0;
}