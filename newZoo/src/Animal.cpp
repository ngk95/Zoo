#include "Animal.h"
#include "Enclosure.h"
#include <iostream>
#include <string>

Animal::Animal(AnimalType type, std::string name, std::shared_ptr<Enclosure> enclosure, int foodPerMeal, int weight)
    : m_type(type), m_name(name), m_happiness(0), m_mealsToday(0), enclosure(enclosure), m_foodPerMeal(foodPerMeal), m_weight(weight) {}

Animal::~Animal() {}

void Animal::eat() {
    if (m_mealsToday < 3) {
        if (enclosure->getFoodStored() >= m_foodPerMeal) {
            m_mealsToday++;
            increaseHappiness();
            enclosure->decrementFood(m_foodPerMeal);
            std::cout << m_name << " has eaten. Remaining food in enclosure: " << enclosure->getFoodStored() << std::endl;
        } else {
            std::cout << "Not enough food to feed " << m_name << std::endl;
        }
    } else {
        std::cout << m_name << " has already eaten 3 times today" << std::endl;
    }
}

void Animal::play(std::shared_ptr<Animal> other) {
    if (this->m_type == other->m_type) {
        this->increaseHappiness();
        other->increaseHappiness();
        std::cout << this->m_name << " and " << other->getName() << " played together and are now happier" << std::endl;
    } else {
        std::cout << "These animals can't play together" << std::endl;
    }
}

void Animal::performForVisitors(Zoo& zoo) {
    std::cout << "Performing" << std::endl;
}

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

std::string Animal::getName() const{
    return m_name;
}

void Animal::setHappiness(int happiness) {
    m_happiness = happiness;
}

void Animal::incrementMealsToday() {
    m_mealsToday++;
}

void Animal::resetMealsToday(){
    m_mealsToday = 0;
}

void Animal::setType(AnimalType type) {
    m_type = type;
}
