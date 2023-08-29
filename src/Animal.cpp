#include "Animal.h"
#include <iostream>

Animal::Animal(AnimalType type, int foodPerMeal, int weight)
    : m_type(type), m_foodPerMeal(foodPerMeal), m_happiness(0), m_mealsToday(0), m_weight(weight) {}

Animal::~Animal() {}

void Animal::eat() {
    if (m_mealsToday < 3) {
        m_mealsToday++;
        increaseHappiness();
    } else {
        std::cout << "This animal has already eaten 3 times today." << std::endl;
    }
}

void Animal::play(Animal& other) {
    if (this->m_type == other.m_type) {
        this->increaseHappiness();
        other.increaseHappiness();
    } else {
        std::cout << "Different types of animals cannot play together." << std::endl;
    }
}

void Animal::update() {}

void Animal::increaseHappiness() {
    m_happiness++;
}

int Animal::getHappiness() const {
    return m_happiness;
}

int Animal::getMealsToday() const {
    return m_mealsToday;
}

AnimalType Animal::getType() const {
    return m_type;
}

int Animal::getWeight() const {
    return m_weight;
}

void Animal::setHappiness(int happiness) {
    m_happiness = happiness;
}

void Animal::incrementMealsToday() {
    m_mealsToday++;
}

void Animal::setType(AnimalType type) {
    m_type = type;
}

void Animal::setWeight(int weight) {
    m_weight = weight;
}
