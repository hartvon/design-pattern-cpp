#include <iostream>
#include <string>
#include <mutex>
#include <thread>

class Singleton {
public:
    Singleton(Singleton& ) = delete;
    void operator=(const Singleton& ) = delete;

    static Singleton* getInstance(const std::string& value);
    std::string getValue() const {
        return value_;
    }

protected:
    Singleton(const std::string& value) : value_(value) {}
    std::string value_;

private:
    static Singleton* pinstance_;
    static std::mutex mutex_;
};

Singleton* Singleton::pinstance_ = nullptr;
std::mutex Singleton::mutex_;

Singleton* Singleton::getInstance(const std::string& value) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!pinstance_) {
        pinstance_ = new Singleton(value);
    }
    return pinstance_;
}

void threadFoo() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::getInstance("Foo");
    std::cout << singleton->getValue() << std::endl;
}

void threadBar() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::getInstance("Bar");
    std::cout << singleton->getValue() << std::endl;
}

int main(int argc, char const *argv[])
{
    std::thread t1(threadFoo);
    std::thread t2(threadBar);
    t1.join();
    t2.join();
    return 0;
}
