#ifndef HORSE_H
#define HORSE_H

#include "Animal.h"

class Horse : public Animal {
private:
    bool m_isShoed;
    int m_daysSinceLastShoed;

public:
    Horse();

    void incrementShoeing();

    bool getIsShoed() const;
    int getDaysSinceLastShoed() const;
    void update() override;

    void setIsShoed(bool isShoed);
    void setDaysSinceLastShoed(int days);

};

#endif // HORSE_H
