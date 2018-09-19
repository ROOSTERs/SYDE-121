//September 18th Tutorial
#include <iostream>

using namespace std;

int main() {

    int test_int = 2147483647;
    cout << (test_int + 1) << endl;

    unsigned int test_uint = 4294967295;
    cout << (test_uint + 1) << endl; //returns 0 because of overflow

    return 0;
}


