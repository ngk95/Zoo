#include "Elephant.h"

Elephant::Elephant()
    : Animal(AnimalType::ELEPHANT, 5, 5) {}

void Elephant::performForVisitors() {
    if (getHappiness() >= 3) {
        std::cout << "The elephant happily performs for the visitors!\n";
    } else {
        std::cout << "The elephant is not in the mood to perform right now.\n";
    }
}

void Elephant::paintForVisitors() {
    if (getHappiness() >= 3) {
        std::cout << "The elephant paints a beautiful picture for the visitors!\n";
    } else {
        std::cout << "The elephant is not happy enough to paint right now.\n";
    }
}
