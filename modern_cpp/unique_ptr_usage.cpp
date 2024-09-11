#include <memory>
#include <iostream>

class myObject {
public:
    myObject(int a, int b) {
        m_sum = a + b;
    }
    int getSecret() const { return m_secret; }
    void setSecret(int n) { m_secret = n;    }
    int getSum()    const { return m_sum;    }
private:
    int m_secret = 69;
    int m_sum;
};

int myFunc(std::unique_ptr<int>& somePtr) {
    return (*somePtr)++;
}

std::unique_ptr<int> myOtherFunc(std::unique_ptr<int> somePtr) {
    std::cout << "Inside: " << *somePtr << std::endl;
    return somePtr;
}

int main() {
    std::unique_ptr<int> myPtr = std::make_unique<int>(69);
    std::unique_ptr<myObject> myOtherPtr = std::make_unique<myObject>(12, 13);
    std::unique_ptr<myObject> anotherPtr(new myObject(13, 13));

    std::cout << myOtherPtr->getSum() << std::endl;
    std::cout << anotherPtr->getSum() << std::endl;

    // Passing by reference, no change in ownership
    myFunc(myPtr);

    std::cout << *myPtr << std::endl;

    // Transferring ownership to myOtherFunc then taking ownership back
    myPtr = myOtherFunc(std::move(myPtr));

    std::cout << *myPtr << std::endl;

    return 0;
}
