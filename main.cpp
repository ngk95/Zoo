#include <iostream>
#include <string>
#include <vector>
#include "Zoo.h"

int main() {
    Zoo myZoo("First Zoo");
    myZoo.hireZookeeper("Alex", 10);
    myZoo.hireZookeeper("Bob", 5);
    Enclosure lionEnclosure(15, AnimalType::LION, 200);
    Enclosure elephantEnclosure(30, AnimalType::ELEPHANT, 500);
    Lion lion;
    Elephant elephant;
    lionEnclosure.addAnimal(&lion);
    elephantEnclosure.addAnimal(&elephant);
    myZoo.acceptVisitors(100);
    myZoo.buyFood(200);
    myZoo.endDay();
    std::cout << "Total days the zoo has been open: " << myZoo.getDays() << std::endl;
    std::cout << "Total visitors today: " << myZoo.getVisitors() << std::endl;
    std::cout << "Total profit today: " << myZoo.getProfit() << std::endl;
    return 0;
}
