
class thread {

    class impl;
    
public:
    impl * impl_ptr;
    thread();
    ~thread() {}
    void echoValue();
};

class thread::impl{
public:
    int value = 100;
};