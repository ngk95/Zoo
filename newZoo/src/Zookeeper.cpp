#include "Zookeeper.h"

Zookeeper::Zookeeper(const std::string& name)
    : m_name(name), m_workDone(0), m_daysExperience(0) {}

void Zookeeper::assignToEnclosure(std::shared_ptr<Enclosure> enclosure) {
    m_assignedEnclosure = enclosure;
}

void Zookeeper::removeFromEnclosure() {
    m_assignedEnclosure.reset();
}

bool Zookeeper::isAssigned() const {
    return m_assignedEnclosure != nullptr;
}

void Zookeeper::fillFoodStorage() {
    if (!isAssigned()) {
        std::cout << m_name << " is not assigned to any enclosure" << std::endl;
        return;
    }
    int enclosureFoodStored = m_assignedEnclosure->getFoodStored();
    int foodNeeded = m_assignedEnclosure->getFoodCapacity() - enclosureFoodStored;
/*
    int foodProvided = Zoo::provideFood(foodNeeded);

    m_assignedEnclosure->setFoodStored(enclosureFoodStored + foodProvided);
    incrementWorkDone(foodProvided);
*/
}
/*
void Zookeeper::shoeHorse(std::shared_ptr<Horse> horse) {
    if (!horse.getIsShoed() && horse.getDaysSinceLastShoed() > 6) {
        horse.setIsShoed(true);
        horse.setDaysSinceLastShoed(0);
        m_workDone++;
    }
}
*/
std::string Zookeeper::getName() const {
    return m_name;
}

int Zookeeper::getWorkDone() const {
    return m_workDone;
}

void Zookeeper::setWorkDone(int workDone) {
    m_workDone += workDone;
}
int Zookeeper::getDaysExperience() const {
    return m_daysExperience;
}

void Zookeeper::incrementWorkDone(int amount) {
    m_workDone += amount;
}
