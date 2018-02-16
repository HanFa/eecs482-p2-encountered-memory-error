#include <iostream>
#include "thread.hh"

thread::thread() {
    impl_ptr = new impl;
}

void thread::echoValue() {
    std::cout << "the val in impl is " << 
        impl_ptr -> value << std::endl;
}