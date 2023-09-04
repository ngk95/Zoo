#include "Horse.h"

Horse::Horse(std::string name, std::shared_ptr<Enclosure> enclosure)
    : Animal(AnimalType::HORSE, name, enclosure, 3, 2), m_isShoed(false), m_daysSinceLastShoed(0) {}

bool Horse::getIsShoed() const {
    return m_isShoed;
}

int Horse::getDaysSinceLastShoed() const {
    return m_daysSinceLastShoed;
}

void Horse::setIsShoed(bool isShoed) {
    m_isShoed = isShoed;
}

void Horse::setDaysSinceLastShoed(int days) {
    m_daysSinceLastShoed = days;
}

void Horse::incrementShoeing() {
    m_daysSinceLastShoed++;
}

void Horse::update() {
    if (getDaysSinceLastShoed() > 6) {
        setIsShoed(false);
    }
}

void Horse::performForVisitors(Zoo& zoo) {
    if (m_isShoed && this->getHappiness() >= 3){
        std::cout << "The horse " << this->getName() << " happily performs for the visitors" << std::endl;
        zoo.incrementBudget(zoo.getVisitors());
    } else {
        std::cout << "The horse " << this->getName() << " can't perform right now" << std::endl;
    }
}
