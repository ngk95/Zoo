#ifndef HORSE_H
#define HORSE_H

#include "Zoo.h"
#include "Animal.h"

class Zoo;
class Enclosure;

class Horse : public Animal {
private:
    bool m_isShoed;
    int m_daysSinceLastShoed;

public:
    Horse(std::string name, std::shared_ptr<Enclosure> enclosure);

    void incrementShoeing();

    bool getIsShoed() const;
    int getDaysSinceLastShoed() const;
    virtual void performForVisitors(Zoo& zoo) override;
    void update() override;

    void setIsShoed(bool isShoed);
    void setDaysSinceLastShoed(int days);

};

#endif // HORSE_H
