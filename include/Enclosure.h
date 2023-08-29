#ifndef ENCLOSURE_H
#define ENCLOSURE_H

#include "Animal.h"

class Enclosure {
private:
    int m_capacity;
    AnimalType m_animalType;
    bool m_isClean;
    int m_foodCapacity;
    int m_foodStored;

public:
    Enclosure(int capacity, AnimalType animalType, int foodCapacity);

    int getCapacity() const;
    AnimalType getAnimalType() const;
    bool isClean() const;
    int getFoodCapacity() const;
    int getFoodStored() const;

    void setClean(bool cleanStatus);
    void setFoodStored(int amount);

};

#endif // ENCLOSURE_H
