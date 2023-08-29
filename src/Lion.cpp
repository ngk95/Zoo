#include "Lion.h"

Lion::Lion()
    : Animal(AnimalType::LION, 2, 2), m_isAngry(true) {}

bool Lion::getIsAngry() const {
    return m_isAngry;
}

void Lion::setIsAngry(bool isAngry) {
    m_isAngry = isAngry;
}

void Lion::performForVisitors() {
    if (m_isAngry) {
        std::cout << "The lion is too angry to perform right now!" << std::endl;
    } else {
        std::cout << "The lion roars majestically for the visitors!" << std::endl;
        increaseHappiness();
    }
}

void Lion::update() {
    setIsAngry(true);
}
