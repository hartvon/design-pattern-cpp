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

class Creator {
public:
    virtual ~Creator() { std::cout << "~Creator" << std::endl; }
    virtual std::shared_ptr<Product> createProduct() = 0;
};

class ConcreteCreatorA : public Creator {
public:
    ~ConcreteCreatorA() { std::cout << "~ConcreteCreatorA" << std::endl; }
    std::shared_ptr<Product> createProduct() override {
        return std::make_shared<ConcreteProductA>();
    }
};

class ConcreteCreatorB : public Creator {
public:
    ~ConcreteCreatorB() { std::cout << "~ConcreteCreatorB" << std::endl; }
    std::shared_ptr<Product> createProduct() override {
        return std::make_shared<ConcreteProductB>();
    }
};

int main(int argc, char const *argv[])
{
    std::shared_ptr<Creator> creator = std::make_shared<ConcreteCreatorA>();
    std::shared_ptr<Product> product = creator->createProduct();
    std::cout << product->Operation() << std::endl;

    creator = std::make_shared<ConcreteCreatorB>();
    product = creator->createProduct();
    std::cout << product->Operation() << std::endl;

    return 0;
}
