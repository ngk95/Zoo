#ifndef LION_H
#define LION_H

#include "Animal.h"

class Zoo;
class Enclosure;

class Lion : public Animal {
private:
    bool m_isAngry;

public:
    Lion(std::string name, std::shared_ptr<Enclosure> enclosure);
    virtual ~Lion() override = default;

    virtual void performForVisitors(Zoo& zoo) override;
    void update() override;

    bool getIsAngry() const;
    void setIsAngry(bool isAngry);
};

#endif // LION_H
