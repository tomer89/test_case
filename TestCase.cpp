#include <iostream>
#include <sstream>
#include <string>
#include "TestCase.hpp"
using namespace std;


/*int TestCase::PASSED = 0;
int TestCase::FAILED = 0;*/


//this is the only non-template therefore only this I can write in the .cpp file. Template file wouldve needed a clear declaration of what types I am using, if not it wouldve not
// been able to link the template functions to the func's in the header file.
void TestCase::print(){
    cout << _name <<": "<< to_string(FAILED) << " failed, " << to_string(PASSED) <<" passed, " << to_string(PASSED + FAILED) <<" total." << endl << "---" << endl;
}