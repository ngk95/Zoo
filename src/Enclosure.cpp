#include "Enclosure.h"

Enclosure::Enclosure(int capacity, AnimalType animalType, int foodCapacity)
    : m_capacity(capacity), m_animalType(animalType), m_isClean(true),
      m_foodCapacity(foodCapacity), m_foodStored(0) {}

int Enclosure::getCapacity() const {
    return m_capacity;
}

AnimalType Enclosure::getAnimalType() const {
    return m_animalType;
}

bool Enclosure::isClean() const {
    return m_isClean;
}

int Enclosure::getFoodCapacity() const {
    return m_foodCapacity;
}

int Enclosure::getFoodStored() const {
    return m_foodStored;
}

void Enclosure::setClean(bool cleanStatus) {
    m_isClean = cleanStatus;
}

void Enclosure::setFoodStored(int amount) {
    m_foodStored = amount;
}
