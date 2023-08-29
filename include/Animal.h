#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

enum class AnimalType {
    LION,
    HORSE,
    ELEPHANT
};

class Animal {
private:
    const int m_foodPerMeal;
    int m_happiness;
    int m_mealsToday;
    AnimalType m_type;
    int m_weight;

public:
    Animal(AnimalType type, int foodPerMeal, int weight);
    virtual ~Animal();

    void eat();
    void play(Animal& other);
    virtual void performForVisitors() = 0;
    virtual void update();

    void increaseHappiness();

    int getHappiness() const;
    int getMealsToday() const;
    AnimalType getType() const;
    int getWeight() const;

    void setHappiness(int happiness);
    void incrementMealsToday();
    void setType(AnimalType type);
    void setWeight(int weight);
};

#endif // ANIMAL_H
