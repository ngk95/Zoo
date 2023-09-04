#include "Lion.h"

Lion::Lion(std::string name, std::shared_ptr<Enclosure> enclosure)
    : Animal(AnimalType::LION, name, enclosure, 2, 4), m_isAngry(true) {}

bool Lion::getIsAngry() const {
    return m_isAngry;
}

void Lion::setIsAngry(bool isAngry) {
    m_isAngry = isAngry;
}

void Lion::performForVisitors(Zoo& zoo) {
    if (m_isAngry) {
        std::cout << this->getName() << " is too angry to perform right now!" << std::endl;
    } else {
        std::cout << "The lion " << this->getName() << " roars majestically for the visitors!" << std::endl;
        increaseHappiness();
    }
}

void Lion::update() {
    setIsAngry(true);
}
