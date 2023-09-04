#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <memory>

class Zoo;
class Enclosure;

enum class AnimalType {
    LION,
    HORSE,
    ELEPHANT
};

class Animal {
private:
    AnimalType m_type;
    const std::string m_name;
    int m_happiness;
    int m_mealsToday;
    std::shared_ptr<Enclosure> enclosure;

protected:
    const int m_foodPerMeal;
    const int m_weight;

public:
    Animal(AnimalType type, std::string m_name, std::shared_ptr<Enclosure> enclosure, int foodPerMeal, int weight);
    virtual ~Animal();

    void eat();
    void play(std::shared_ptr<Animal> other);
    virtual void performForVisitors(Zoo& zoo);
    virtual void update() = 0;

    void increaseHappiness();

    int getHappiness() const;
    int getMealsToday() const;
    AnimalType getType() const;
    int getWeight() const;
    std::string getName() const;

    void setHappiness(int happiness);
    void incrementMealsToday();
    void resetMealsToday();
    void setType(AnimalType type);
    void setWeight(int weight);
};

#endif // ANIMAL_H
