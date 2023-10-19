#include <iostream>
#include <string>

class Product {
public:
    virtual ~Product() { std::cout << "~Product" << std::endl; }
    virtual std::string Operation() const = 0;
};

class ConcreteProductA : public Product {
public:
    ~ConcreteProductA() { std::cout << "~ConcreteProductA" << std::endl; }
    std::string Operation() const override {
        return "Result of ConcreteProductA";
    }
};

class ConcreteProductB : public Product {
public:
    ~ConcreteProductB() { std::cout << "~ConcreteProductB" << std::endl; }
    std::string Operation() const override {
        return "Result of ConcreteProductB";
    }
};

class Creator {
public:
    virtual ~Creator() { std::cout << "~Creator" << std::endl; }
    virtual Product* factoryMethod() = 0;
};

class ConcreteCreatorA : public Creator {
public:
    ~ConcreteCreatorA() { std::cout << "~ConcreteCreatorA" << std::endl; }
    Product* factoryMethod() override {
        return new ConcreteProductA;
    }
};

class ConcreteCreatorB : public Creator {
public:
    ~ConcreteCreatorB() { std::cout << "~ConcreteCreatorB" << std::endl; }
    Product* factoryMethod() override {
        return new ConcreteProductB;
    }
};

int main(int argc, char const *argv[])
{
    auto lamda = [] (Creator* creator) {
        Product* product = creator->factoryMethod();
        std::cout << product->Operation() << std::endl;
        delete creator;
        delete product;
    };

    lamda(new ConcreteCreatorA);
    lamda(new ConcreteCreatorB);

    return 0;
}
