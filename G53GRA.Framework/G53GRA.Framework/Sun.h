//
// Created by Dovydas Ciomenas on 30/04/2018.
// Copyright (c) 2018 w.o.c.ward. All rights reserved.
//

#ifndef G53GRA_FRAMEWORK_SUN_H
#define G53GRA_FRAMEWORK_SUN_H


#include "DisplayableObject.h"

class Sun : public DisplayableObject {
public:
    Sun();
    ~Sun() {};
    void Display();
private:
    GLfloat *_ambient, *_diffuse, *_specular;
};


#endif //G53GRA_FRAMEWORK_SUN_H
