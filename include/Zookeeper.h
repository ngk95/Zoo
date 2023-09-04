#ifndef ZOOKEEPER_H
#define ZOOKEEPER_H

#include <string>
#include <Horse.h>
#include <Enclosure.h>
class Zoo;

class Zookeeper {
private:
    std::string m_name;
    int m_workDone;
    int m_daysExperience;
    std::shared_ptr<Enclosure> m_assignedEnclosure;

public:
    Zookeeper(const std::string& name);

    void assignToEnclosure(std::shared_ptr<Enclosure> enclosure);
    void removeFromEnclosure();
    bool isAssigned() const;

    void fillFoodStorage();
//    void shoeHorse(std::shared_ptr<Horse> horse);
    std::string getName() const;
    int getWorkDone() const;
    void setWorkDone(int);
    int getDaysExperience() const;

    void incrementWorkDone(int amount);
};

#endif // ZOOKEEPER_H
