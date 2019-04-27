//
//  Skybox.hpp
//  G53GRA.Framework
//
//  Created by Dovydas Ciomenas on 27/04/2018.
//  Copyright © 2018 w.o.c.ward. All rights reserved.
//

#pragma once

#include "DisplayableObject.h"

class Skybox : public DisplayableObject {
public:
    Skybox(GLuint texTop, GLuint texBottom, GLuint texLeft, GLuint texRight, GLuint texNear, GLuint texFar);
    ~Skybox() {};
    void Display();
private:
    GLuint _texTop, _texBottom, _texLeft, _texRight, _texNear, _texFar;
};
