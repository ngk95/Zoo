#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "Animal.h"

class Elephant : public Animal {
public:
    Elephant();

    virtual void performForVisitors() override;
    void paintForVisitors();
};

#endif // ELEPHANT_H
