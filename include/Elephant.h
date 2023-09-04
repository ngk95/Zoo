#ifndef ELEPHANT_H
#define ELEPHANT_H

#include "Zoo.h"
#include "Animal.h"

class Zoo;
class Enclosure;

class Elephant : public Animal {
public:
    Elephant(std::string name, std::shared_ptr<Enclosure> enclosure);

    void performForVisitors(Zoo& zoo) override;
    void paintForVisitors(Zoo& zoo);
    void update() override;
};

#endif // ELEPHANT_H
