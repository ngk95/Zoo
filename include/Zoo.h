#ifndef ZOO_H
#define ZOO_H

#include <string>
#include <iostream>
#include <vector>
#include "Zookeeper.h"
#include "Enclosure.h"
#include "Lion.h"
#include "Horse.h"
#include "Elephant.h"

class Zoo {
private:
    std::string m_name;
    int m_days;
    int m_visitors;
    int m_foodAmount;
    int m_budget;
    std::vector<Zookeeper> m_zookeepers;
    std::vector<Enclosure> m_enclosures;
    std::vector<Animal*> animals;
    int m_profit;
    int m_donations;

public:
    Zoo(const std::string& name);

    void endDay();
    void hireZookeeper(const std::string& name, int daysExperience);
    void fireZookeeper(const std::string& name);
    void buyFood(int amount);
    void acceptVisitors(int visitors);
    int askForDonations();

    int getDays() const;
    int getVisitors() const;
    int getFoodAmount() const;
    int getBudget() const;
    int getProfit() const;
    int getDonations() const;

    void addAnimal(Animal* animal);
    void removeAnimal(Animal* animal);

    int countAnimals() const;

    std::vector<Animal*>::iterator begin();
    std::vector<Animal*>::iterator end();

    std::vector<Animal*>::const_iterator begin() const;
    std::vector<Animal*>::const_iterator end() const;

    std::vector<Animal*>::iterator getAnimalsBegin();
    std::vector<Animal*>::iterator getAnimalsEnd();

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

};

#endif // ZOO_H
