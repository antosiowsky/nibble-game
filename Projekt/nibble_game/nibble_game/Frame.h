#ifndef FRAME_H
#define FRAME_H

#include "object.h"

class Frame : public Object {
public:
    Frame(float x, float y, float lenght, float thickness);
    ~Frame();
    

    void draw(sf::RenderWindow& window) const override;

private:
    float lenght;
    float thickness;
};

#endif // FRAME_H
