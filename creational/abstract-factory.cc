#include <iostream>
#include <string>
#include <memory>

class Product {
public:
    virtual ~Product() = default;
    virtual std::string Operation() const = 0;
};

class ConcreteProductA : public Product {
public:
    ~ConcreteProductA() = default;
    std::string Operation() const override {
        return "Result of ConcreteProductA";
    }
};

class ConcreteProductB : public Product {
public:
    ~ConcreteProductB() = default;
    std::string Operation() const override {
        return "Result of ConcreteProductB";
    }
};

class Creator {
public:
    virtual ~Creator() = default;
    virtual std::shared_ptr<Product> createProduct() = 0;
};

class ConcreteCreatorA : public Creator {
public:
    ~ConcreteCreatorA() = default;
    std::shared_ptr<Product> createProduct() override {
        return std::make_shared<ConcreteProductA>();
    }
};

class ConcreteCreatorB : public Creator {
public:
    ~ConcreteCreatorB() = default;
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
