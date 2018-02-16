#include <iostream>
#include "thread.hh"

using namespace std;

int main() {
    if (true) {
        // the thread is inside the IF scope 
        thread t1;
        t1.echoValue();

        // if impl is deleted
        delete t1.impl_ptr;
        t1.echoValue();
    }
}