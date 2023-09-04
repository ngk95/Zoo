#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Zoo.h"
#include "Animal.h"

int main() {
    srand(time(0));
    std::unique_ptr<Zoo> myZoo = std::make_unique<Zoo>("Amazing Zoo");
    myZoo->hireZookeeper("Alex");
    myZoo->askForDonations();
    myZoo->hireZookeeper("Bob");
    std::shared_ptr<Enclosure> lionEnclosure = std::make_shared<Enclosure>(15, AnimalType::LION, 60);
    std::shared_ptr<Enclosure> elephantEnclosure = std::make_shared<Enclosure>(30, AnimalType::ELEPHANT, 100);
    myZoo->hireZookeeper("Mario");
    std::shared_ptr<Enclosure> horseEnclosure = std::make_shared<Enclosure>(21, AnimalType::HORSE, 80);
    myZoo->addAnimal(AnimalType::LION, "Peter", lionEnclosure);
    myZoo->addAnimal(AnimalType::ELEPHANT, "Mark", elephantEnclosure);
    myZoo->addAnimal(AnimalType::ELEPHANT, "Sandy", elephantEnclosure);
    myZoo->addAnimal(AnimalType::HORSE, "Andy", horseEnclosure);
    myZoo->findAnimal("Mark")->eat();
    myZoo->findAnimal("Mark")->eat();
    myZoo->findAnimal("Peter")->eat();
    myZoo->findAnimal("Peter")->eat();
    myZoo->acceptVisitors(100);
    myZoo->findAnimal("Mark")->performForVisitors(*myZoo);
    myZoo->findAnimal("Peter")->performForVisitors(*myZoo);
    myZoo->findAnimal("Sandy")->play(myZoo->findAnimal("Mark"));
    myZoo->buyFood(50);
    myZoo->endDay();
    return 0;
}
