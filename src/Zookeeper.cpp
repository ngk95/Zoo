#include "Zookeeper.h"

Zookeeper::Zookeeper(const std::string& name, int daysExperience)
    : m_name(name), m_workDone(0), m_daysExperience(daysExperience) {}

void Zookeeper::shoeHorse(Horse& horse) {
    if (!horse.getIsShoed() && horse.getDaysSinceLastShoed() > 6) {
        horse.setIsShoed(true);
        horse.setDaysSinceLastShoed(0);
        m_workDone++;
    }
}

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
