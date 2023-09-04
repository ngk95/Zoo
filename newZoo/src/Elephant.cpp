#include "Elephant.h"

Elephant::Elephant(std::string name, std::shared_ptr<Enclosure> enclosure)
    : Animal(AnimalType::ELEPHANT, name, enclosure, 5, 7) {}

void Elephant::performForVisitors(Zoo& zoo) {
    if (getHappiness() >= 3) {
        std::cout << "The elephant happily performs for the visitors" << std::endl;
        zoo.incrementBudget(zoo.getVisitors());
    } else {
        std::cout << "The elephant is not in the mood to perform right now" << std::endl;
    }
}

void Elephant::paintForVisitors(Zoo& zoo) {
    if (getHappiness() >= 3) {
        std::cout << "The elephant paints a beautiful picture for the visitors" << std::endl;
    } else {
        std::cout << "The elephant is not happy enough to paint right now" << std::endl;
    }
}

void Elephant::update() {
    //TODO
}
