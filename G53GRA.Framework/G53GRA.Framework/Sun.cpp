//
// Created by Dovydas Ciomenas on 30/04/2018.
// Copyright (c) 2018 w.o.c.ward. All rights reserved.
//

#include "Sun.h"

Sun::Sun() {
    static GLfloat ambient[] =
            {
                    0.1f, 0.1f, 0.1f, 1.0f
            };

    static GLfloat diffuse[] =
            {
                    1.0f, 1.0f, 1.0f, 1.0f
            };

    static GLfloat specular[] =
            {
                    1.0f, 1.0f, 0.0f, 1.0f
            };

    _ambient = ambient;
    _diffuse = diffuse;
    _specular = specular;
}

void Sun::Display() {
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    {
        glDisable(GL_LIGHTING);

        glTranslatef(pos[0], pos[1], pos[2]);

        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glutSolidSphere(100.0, 10, 10);

        glEnable(GL_LIGHTING);
    }
    glPopAttrib();
    glPopMatrix();

    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT, _ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, _diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, _specular);

    GLfloat lightpos[] = { pos[0], pos[1], pos[2], 1.0f };

    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

    glEnable(GL_LIGHT0);

}