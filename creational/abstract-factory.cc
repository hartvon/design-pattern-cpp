#include <iostream>
#include <string>
#include <memory>

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

class Factory {
public:
    virtual ~Factory() { std::cout << "~Factory" << std::endl; }
    virtual std::shared_ptr<Product> factoryMethod() = 0;
};

class ConcreteFactoryA : public Factory {
public:
    ~ConcreteFactoryA() { std::cout << "~ConcreteFactoryA" << std::endl; }
    std::shared_ptr<Product> factoryMethod() override {
        return std::make_shared<ConcreteProductA>();
    }
};

class ConcreteFactoryB : public Factory {
public:
    ~ConcreteFactoryB() { std::cout << "~ConcreteFactoryB" << std::endl; }
    std::shared_ptr<Product> factoryMethod() override {
        return std::make_shared<ConcreteProductB>();
    }
};

int main(int argc, char const *argv[])
{
    std::shared_ptr<Factory> creator = std::make_shared<ConcreteFactoryA>();
    std::shared_ptr<Product> product = creator->factoryMethod();
    std::cout << product->Operation() << std::endl;

    creator = std::make_shared<ConcreteFactoryB>();
    product = creator->factoryMethod();
    std::cout << product->Operation() << std::endl;

    return 0;
}
