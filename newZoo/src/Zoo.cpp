#include "Zoo.h"
#include "Zookeeper.h"

Zoo::Zoo(const std::string& name)
    : m_name(name), m_days(1), m_visitors(0), m_foodStored(0),
      m_budget(100), m_donations(0) {
    std::cout << "The zoo " << m_name << " is now open!" << std::endl;
}

void Zoo::endDay() {
    std::cout << "The zoo is closed for the day" << std::endl;
    std::cout << "Visitors today: " << m_visitors << std::endl << std::endl;
    std::cout << "Starting day: " << m_days + 1<< " with a budget of " << m_budget << std::endl;

    m_days++;

    for (auto& animal : m_animals) {
        animal->setHappiness(0);
        animal->resetMealsToday();
    }

    for (auto& zookeeper : m_zookeepers) {
        zookeeper->setWorkDone(0);
    }

    m_visitors = 0;
    m_donations = 0;
}

void Zoo::hireZookeeper(const std::string& name) {
    std::shared_ptr<Zookeeper> newZookeeper = std::make_shared<Zookeeper>(name);
    m_zookeepers.push_back(newZookeeper);
}

void Zoo::fireZookeeper(std::shared_ptr<Zookeeper> zookeeperToFire) {
    m_zookeepers.erase(std::remove(m_zookeepers.begin(), m_zookeepers.end(), zookeeperToFire), m_zookeepers.end());
}

void Zoo::buyFood(int amount) {
    if (amount <= m_budget) {
        m_foodStored += amount;
        m_budget -= amount;
        std::cout << "You successfully purchased " << amount << " units of food" << std::endl;
    } else {
        std::cout << "Not enough budget to buy the food" << std::endl;
    }
}

int Zoo::provideFood(int amount) {
    if (m_foodStored <= amount) {
        m_foodStored -= amount;
        return amount;
    } else if (m_foodStored < amount && m_foodStored > 0) {
        m_foodStored = 0;
        return m_foodStored;
    } else {
        std::cout << "There is no food in the zoo" << std::endl;
        return 0;
    }
}

void Zoo::acceptVisitors(int visitors) {
    m_visitors += visitors;
}

int Zoo::askForDonations() {
    if (m_budget > 200) {
        std::cout << "The zoo can't ask for donations because the budget is not low enough" << std::endl;
        return 0;
    }
    int donation = rand() % 100 + 1;
    m_budget += donation;
    std::cout << "The zoo received a donation of " << donation << std::endl;
    return donation;
}

void Zoo::incrementBudget(int increment) {
    m_budget += increment;
}

int Zoo::getDays() const {
    return m_days;
}

int Zoo::getVisitors() const {
    return m_visitors;
}

int Zoo::getFoodAmount() const {
    return m_foodStored;
}

int Zoo::getBudget() const {
    return m_budget;
}

int Zoo::getDonations() const {
    return m_donations;
}

bool Zoo::isAnimalPresent(std::string name) const {
    for (auto& animal : m_animals) {
        if (animal->getName() == name) {
            return true;
        }
    }
    return false;
}

void Zoo::addAnimal(AnimalType type, std::string name, std::shared_ptr<Enclosure> enclosure) {
    if (countAnimals() < enclosure->getCapacity() && type == enclosure->getAnimalType() && !isAnimalPresent(name)) {
        std::shared_ptr<Animal> animal;
        if (type == AnimalType::LION) {
            animal = std::make_shared<Lion>(name, enclosure);
        } else if (type == AnimalType::ELEPHANT) {
            animal = std::make_shared<Elephant>(name, enclosure);
        } else if (type == AnimalType::HORSE) {
            animal = std::make_shared<Horse>(name, enclosure);
        }
        if (animal != nullptr) {
            m_animals.push_back(animal);
            std::cout << name << " was successfully added to " << m_name << std::endl;
        }
    } else {
        std::cout << name << " can't be included in " << m_name << std::endl;
    }
}

void Zoo::removeAnimal(std::shared_ptr<Animal> animalToDelete) {
    m_animals.erase(std::remove(m_animals.begin(), m_animals.end(), animalToDelete), m_animals.end());
}

std::shared_ptr<Animal> Zoo::findAnimal(const std::string& name) const {
    for (const auto& animal : m_animals) {
        if (animal->getName() == name) {
            return animal;
        }
    }
    return nullptr;
}

int Zoo::countAnimals() const {
    return m_animals.size();
}
