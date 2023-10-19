#include <iostream>
#include <string>

class ProductA {
public:
    ~ProductA() { std::cout << "~ProductA" << std::endl; }
    virtual std::string Operation() const = 0;
};

class ConcreteProductAX : public ProductA {
public:
    ~ConcreteProductAX() { std::cout << "~ConcreteProductAX" << std::endl; }
    std::string Operation() const override {
        return "result of ConcreteProductAX";
    }
};

class ConcreteProductAY : public ProductA {
public:
    ~ConcreteProductAY() { std::cout << "~ConcreteProductAY" << std::endl; }
    std::string Operation() const override {
        return "result of ConcreteProductAY";
    }
};

class ProductB {
public:
    ~ProductB() { std::cout << "~ProductB" << std::endl; }
    virtual std::string Operation() const = 0;
};

class ConcreteProductBX : public ProductB {
public:
    ~ConcreteProductBX() { std::cout << "~ConcreteProductBX" << std::endl; }
    std::string Operation() const override {
        return "result of ConcreteProductBX";
    }
};

class ConcreteProductBY : public ProductB {
public:
    ~ConcreteProductBY() { std::cout << "~ConcreteProductBY" << std::endl; }
    std::string Operation() const override {
        return "result of ConcreteProductBY";
    }
};

class AbstractFactory {
public:
    virtual ~AbstractFactory() { std::cout << "~AbstractFactory" << std::endl; }
    virtual ProductA* createProductA() = 0;
    virtual ProductB* createProductB() = 0;
};

class ConcreteFactoryX : public AbstractFactory {
public:
    ~ConcreteFactoryX() { std::cout << "~ConcreteFactoryX" << std::endl; }
    ProductA* createProductA() override {
        return new ConcreteProductAX;
    }
    ProductB* createProductB() override {
        return new ConcreteProductBX;
    }
};

class ConcreteFactoryY : public AbstractFactory {
public:
    ~ConcreteFactoryY() { std::cout << "~ConcreteFactoryY" << std::endl; }
    ProductA* createProductA() override {
        return new ConcreteProductAY;
    }
    ProductB* createProductB() override {
        return new ConcreteProductBY;
    }
};

int main(int argc, char const *argv[])
{
    auto lambda = [] (AbstractFactory* af) {
        ProductA* productA = af->createProductA();
        ProductB* productB = af->createProductB();

        std::cout << productA->Operation() << std::endl;
        std::cout << productB->Operation() << std::endl;
    
        delete af;
        delete productA;
        delete productB;
    };

    lambda(new ConcreteFactoryX);
    lambda(new ConcreteFactoryY);

    return 0;
}
