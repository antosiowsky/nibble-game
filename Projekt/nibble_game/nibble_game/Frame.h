#ifndef FRAME_H
#define FRAME_H
#include <iostream>
#include "object.h"

class Frame : public Object {
public:
    Frame(float x, float y, float thickness);
    
    sf::Vector2f getCenterPosition() const;
    void draw(sf::RenderWindow& window) const override;

};

#endif
