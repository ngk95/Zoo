#ifndef ZOOKEEPER_H
#define ZOOKEEPER_H

#include <string>
#include <Horse.h>

class Zookeeper {
private:
    std::string m_name;
    int m_workDone;
    int m_daysExperience;

public:
    Zookeeper(const std::string& name, int daysExperience);

    void shoeHorse(Horse& horse);

    std::string getName() const;
    int getWorkDone() const;
    void setWorkDone(int);
    int getDaysExperience() const;

    void incrementWorkDone(int amount);
};

#endif // ZOOKEEPER_H
