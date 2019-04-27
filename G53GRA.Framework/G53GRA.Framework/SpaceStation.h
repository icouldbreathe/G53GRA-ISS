//
// Created by Dovydas Ciomenas on 27/04/2018.
// Copyright (c) 2018 w.o.c.ward. All rights reserved.
//

#ifndef G53GRA_FRAMEWORK_SPACESTATION_H
#define G53GRA_FRAMEWORK_SPACESTATION_H

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"


class SpaceStation :
    public DisplayableObject,
    public Animation,
    public Input
{
public:
    SpaceStation(GLuint baseTexture, GLuint panelTexture);
    ~SpaceStation() {};
    void Display();
    void Update(const double& deltaTime);
    void HandleKey(unsigned char key, int state, int mx, int my);
private:
    GLuint baseTexture, panelTexture;
protected:
    void drawPanels();
    void bigSolarPanel();
    float _rotation, _velocity, _autoRotation;
};


#endif //G53GRA_FRAMEWORK_SPACESTATION_H
