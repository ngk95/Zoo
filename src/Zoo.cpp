#include "Zoo.h"

Zoo::Zoo(const std::string& name)
    : m_name(name), m_days(0), m_visitors(0), m_foodAmount(0),
      m_budget(0), m_profit(0), m_donations(0) {
    std::cout << "The zoo " << m_name << " is now open!" << std::endl;
}

void Zoo::endDay() {
    m_days++;
    std::cout << "The zoo is closed for the day." << std::endl;
    std::cout << "Today's profit: " << m_profit << std::endl;
    std::cout << "Starting day: " << m_days + 1<< std::endl;

    for (std::vector<Enclosure>::iterator encIt = m_enclosures.begin(); encIt != m_enclosures.end(); ++encIt) {
        for (std::vector<Animal*>::iterator aniIt = encIt->getAnimalsBegin(); aniIt != encIt->getAnimalsEnd(); ++aniIt) {
            (*aniIt)->increaseHappiness();
            (*aniIt)->incrementMealsToday();
            (*aniIt)->update();
        }
    encIt->setClean(false);
}

    for (Zookeeper &zookeeper : m_zookeepers) {
        zookeeper.setWorkDone(0);
    }

    m_profit = m_visitors + m_donations - m_budget;
    m_visitors = 0;
    m_donations = 0;
}

void Zoo::hireZookeeper(const std::string& name, int daysExperience) {
    m_zookeepers.push_back(Zookeeper(name, daysExperience));
}

void Zoo::fireZookeeper(const std::string& name) {
    for (size_t i = 0; i < m_zookeepers.size(); i++) {
        if (m_zookeepers[i].getName() == name) {
            m_zookeepers.erase(m_zookeepers.begin() + i);
            return;
        }
    }
}

void Zoo::buyFood(int amount) {
    if (amount <= m_budget) {
        m_foodAmount += amount;
        m_budget -= amount;
    } else {
        std::cout << "Not enough budget to buy the food." << std::endl;
    }
}

void Zoo::acceptVisitors(int visitors) {
    m_visitors += visitors;
}

int Zoo::askForDonations() {
    if (m_budget > 0) {
        std::cout << "The zoo can't ask for donations because the budget is not low enough." << std::endl;
        return 0;
    }
    int donation = rand() % 100 + 1;
    m_budget += donation;
    m_donations += donation;
    std::cout << "The zoo received a donation of " << donation << std::endl;
    return donation;
}

int Zoo::getDays() const {
    return m_days;
}

int Zoo::getVisitors() const {
    return m_visitors;
}

int Zoo::getFoodAmount() const {
    return m_foodAmount;
}

int Zoo::getBudget() const {
    return m_budget;
}

int Zoo::getProfit() const {
    return m_profit;
}

int Zoo::getDonations() const {
    return m_donations;
}

void Enclosure::addAnimal(Animal* animal) {
    if (countAnimals() < m_capacity && animal->getType() == m_animalType) {
        animals.push_back(animal);
    }
}

void Enclosure::removeAnimal(Animal* animal) {
    std::vector<Animal*>::iterator it;
    for (it = animals.begin(); it != animals.end(); ++it) {
        if (*it == animal) {
            animals.erase(it);
            break;
        }
    }
}

int Enclosure::countAnimals() const {
    return animals.size();
}

std::vector<Animal*>::iterator Enclosure::begin() {
    return animals.begin();
}

std::vector<Animal*>::iterator Enclosure::end() {
    return animals.end();
}

std::vector<Animal*>::const_iterator Enclosure::begin() const {
    return animals.begin();
}

std::vector<Animal*>::const_iterator Enclosure::end() const {
    return animals.end();
}

std::vector<Animal*>::iterator Enclosure::getAnimalsBegin() {
    return animals.begin();
}

std::vector<Animal*>::iterator Enclosure::getAnimalsEnd() {
    return animals.end();
}
