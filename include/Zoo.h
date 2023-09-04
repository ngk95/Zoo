#ifndef ZOO_H
#define ZOO_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Animal.h"
#include "Enclosure.h"
#include "Elephant.h"
#include "Horse.h"
#include "Lion.h"
class Zookeeper;

class Zoo {
private:
    std::string m_name;
    int m_days;
    int m_visitors;
    int m_foodStored;
    int m_budget;
    int m_capacity;
    std::vector<std::shared_ptr<Zookeeper>> m_zookeepers;
    std::vector<std::shared_ptr<Enclosure>> m_enclosures;
    std::vector<std::shared_ptr<Animal>> m_animals;
    int m_donations;

public:
    Zoo(const std::string& name);

    void endDay();
    void addAnimal(AnimalType type, std::string name, std::shared_ptr<Enclosure> enclosure);
    void hireZookeeper(const std::string& name);
    void fireZookeeper(std::shared_ptr<Zookeeper> zookeeperToFire);
    void buyFood(int amount);
    int provideFood(int amount);
    void acceptVisitors(int visitors);
    int askForDonations();

    void incrementBudget(int increment);
    int getDays() const;
    int getVisitors() const;
    int getFoodAmount() const;
    int getBudget() const;
    int getProfit() const;
    int getDonations() const;

    bool isAnimalPresent(std::string name) const;
    void removeAnimal(std::shared_ptr<Animal> animalToDelete);
    std::shared_ptr<Animal> findAnimal(const std::string& name) const;
    int countAnimals() const;

};

#endif // ZOO_H
