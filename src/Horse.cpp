#include "Horse.h"

Horse::Horse()
    : Animal(AnimalType::HORSE, 3, 3), m_isShoed(false), m_daysSinceLastShoed(0) {}

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
