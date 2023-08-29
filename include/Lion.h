#ifndef LION_H
#define LION_H

#include "Animal.h"

class Lion : public Animal {
private:
    bool m_isAngry;

public:
    Lion();
    virtual ~Lion() override = default;

    virtual void performForVisitors() override;
    void update() override;

    bool getIsAngry() const;
    void setIsAngry(bool isAngry);
};

#endif // LION_H
