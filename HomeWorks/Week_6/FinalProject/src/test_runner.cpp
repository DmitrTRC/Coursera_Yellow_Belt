//
// Created by Dmitry Morozov on 26/11/22.
//

#include "test_runner.h"

#include <iostream>
#include <stdexcept>

using namespace std;


template<class TestFunc>
void TestRunner::RunTest(TestFunc func, const string &test_name) {

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

TestRunner::~TestRunner() {

    if (fail_count > 0) {
        cerr << fail_count << " unit tests failed. Terminate" << endl;
        exit(1);
    }
}
