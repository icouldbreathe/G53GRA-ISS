//
// Created by Dovydas Ciomenas on 27/04/2018.
// Copyright (c) 2018 w.o.c.ward. All rights reserved.
//

#include "SpaceStation.h"
#include "math.h"
const float DEG2RAD = 3.14159/180;

SpaceStation::SpaceStation(GLuint baseTexture, GLuint panelTexture):
baseTexture(baseTexture), panelTexture(panelTexture), _rotation(0.0f), _velocity(0.0f) {
    
}


void rectangle(float x, float y) {
    glDisable(GL_CULL_FACE);
    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);


    glTexCoord2f(0.0, 0.0);
    glVertex2f(0, 0);
    glTexCoord2f(0.0, 1.0);
    glVertex2f(0, y);
    glTexCoord2f(1.0, 1.0);
    glVertex2f(x, y);
    glTexCoord2f(1.0, 0.0);
    glVertex2f(x, 0);




    glEnd();
    glEnable(GL_CULL_FACE);
}

void circle(float radius) {
    glDisable(GL_CULL_FACE);
    glBegin(GL_TRIANGLE_FAN);

    for (int i=0; i < 360; i++) {
        float degInRad = i*DEG2RAD;
        glVertex2f(cos(degInRad) * radius, sin(degInRad) * radius);
    }

    glEnd();
    glEnable(GL_CULL_FACE);
}

void cylinder(float h, float tr, float br) {
    float res = 0.1f * M_PI;
    float x, z;
    float progress;
    float ratio = tr / br;


    glBegin(GL_QUAD_STRIP);
    for (float t = 0.f; t <= 2 * M_PI; t += res)
    {
        progress = t / (2 * M_PI);
        x = br*cos(t);
        z = br*sin(t);

        glNormal3f(x, 0, z);

        glTexCoord2f(progress, 0);
        glVertex3f(x, 0.f, z);
        glTexCoord2f(progress, 1);
        glVertex3f(x * ratio, h, z * ratio);
    }

    glNormal3f(0, 0, -1);
    glTexCoord2f(1, 0);
    glVertex3f(br, 0.f, 0.f);
    glTexCoord2f(1, 1);
    glVertex3f(tr, h, 0.f);
    glEnd();
}

void module(float height, float size) {
    // Main module cylinder
    cylinder(height, size, size);

    // Right end and connection
    glTranslatef(0.0f, -1.0f, 0.0f);
    cylinder(1.0f, size, size/2);
    glTranslatef(0.0f, -1.0f/2, 0.0f);
    cylinder(0.5, size/2, size/2);
    // The end
    glRotatef(90.0, 1.0, 0.0, 0.0);
    circle(size/2);
    glRotatef(-90.0, 1.0, 0.0, 0.0);


    // Left end and connection
    glTranslatef(0.0f, height+1.5f, 0.0f);
    cylinder(1, size/2, size);
    glTranslatef(0.0f, 1.0f, 0.0f);
    cylinder(0.5, size/2, size/2);
    // The end
    glTranslatef(0.0f, 0.5f, 0.0f);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    circle(size/2);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glTranslatef(0.0f, -0.5f, 0.0f);
}


void drawBase() {
    glMatrixMode(GL_MODELVIEW);
    glRotatef(90.0, 0.0, 0.0, 1.0);

    module(5, 2);
    glTranslatef(0.0f, 2.0f , 0.0f);
    module(5, 2);
    glTranslatef(0.0f, -20.0f , 0.0f);
    module(3, 2);

    glRotatef(90.0, 0.0, 0.0, 1.0);
    glTranslatef(-2.5f, 3.0f, 0.0f);
    module(3, 2);

    glTranslatef(2.5f, -3.0f, 0.0f);

    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glTranslatef(-4.0f, 3.0f , -2.0f);
    module(5, 2);

    glTranslatef(0.0f, -13.0f, 0.0f);
    module(1, 2);

    glRotatef(90.0, 1.0, 0.0, 0.0);
    glTranslatef(0.0f, -5.5f , -2.0f);

    //Connection
    cylinder(2, 1, 0.5);

    glTranslatef(0.0f, -1.5f , 0.0f);
    module(0.5, 1);

    glTranslatef(0.0f, -10.0f , 0.0f);

    module(7, 2);

    glTranslatef(0.0f, -10.0f, 0.0f);

    //Connection
    cylinder(0.5, 1, 0.5);

    glTranslatef(0.0f, -2.5f, 0.0f);

    module(1, 1);

    glTranslatef(0.0f, -4.0f, 0.0f);

    //Connection
    cylinder(0.5, 0.5, 1);

    glTranslatef(0.0f, -3.5f, 0.0f);

    module(2, 2);

    //Right far End
    glTranslatef(0.0f, -4.5f, 0.0f);
    cylinder(2, 2, 3);
    glTranslatef(0.0f, -6.0f, 0.0f);
    cylinder(6, 3, 3);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    circle(3);
    glRotatef(-90.0, 1.0, 0.0, 0.0);

    glRotatef(90.0, 0.0, 0.0, 1.0);
    glTranslatef(13.5f, -10.0f, 0.0f);
    module(8, 1.5);

    glTranslatef(0.0f, 3.0f, 0.0f);
    module(1, 1.5);

    glTranslatef(12.5f, -10.0f, 0.0f);
    module(4, 1.2);

    glRotatef(90.0, 1.0, 0.0, 0.0);
    glTranslatef(23.0f, -9.0f, -1.0f);
    module(6, 2);

    glTranslatef(0.0f, 4.5f, 0.0f);
    module(3, 2);

    glTranslatef(0.0f, -4.5f, 0.0f);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glTranslatef(0.0f, -2.5f, 9.0f);
    cylinder(1, 1, 3);

    glTranslatef(0.0f, -2.0f, 0.0f);
    cylinder(2, 3, 3);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    circle(3);
    glRotatef(-90.0, 1.0, 0.0, 0.0);


    glTranslatef(0.0f, -5.0f, 0.0f);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glTranslatef(7.5f, -47.0f, -10.0f);

    // Big abstracted supportive structure for solar panels
    cylinder(80, 1, 1);

    // The ends of the cylinder
    glRotatef(90.0, 1.0, 0.0, 0.0);
    circle(1);
    glRotatef(-90.0, 1.0, 0.0, 0.0);

    glTranslatef(0.0f, 80.0f, 0.0f);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    circle(1);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);

}

void SpaceStation::bigSolarPanel() {
    
    cylinder(5, 0.2, 0.2);

    glRotatef(90.0, 0.0, 1.0, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glTranslatef(-5.0f, 0.0f, 0.0f);
    rectangle(10, 0.5);

    glTranslatef(0.0f, 0.0f, -5.0f);
    rectangle(10, 0.5);

    glTranslatef(0.0f, 0.0f, 47.0f);
    rectangle(10, 0.5);
    glTranslatef(0.0f, 0.0f, -47.0f);

    glTranslatef(0.0f, 0.0f, -42.0f);
    rectangle(10, 0.5);
    glTranslatef(0.0f, 0.0f, 42.0f);

    glRotatef(90.0, 1.0, 0.0, 0.0);
    glTranslatef(0.0f, 6.0f, 0.0f);
    // anim
    glRotatef(_rotation, 0.0, 1.0, 0.0);
    rectangle(4, 40);
    glRotatef(_rotation * (-1), 0.0, 1.0, 0.0);

    glTranslatef(6.0f, 0.0f, 0.0f);
    glRotatef(_rotation, 0.0, 1.0, 0.0);
    rectangle(4, 40);
    glRotatef(_rotation * (-1), 0.0, 1.0, 0.0);

    glTranslatef(0.0f, -47.0f, 0.0f);
    glRotatef(_rotation, 0.0, 1.0, 0.0);
    rectangle(4, 40);
    glRotatef(_rotation * (-1), 0.0, 1.0, 0.0);

    glTranslatef(-6.0f, 0.0f, 0.0f);
    glRotatef(_rotation, 0.0, 1.0, 0.0);
    rectangle(4, 40);
    glRotatef(_rotation * (-1), 0.0, 1.0, 0.0);

    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glRotatef(-90.0, 0.0, 1.0, 0.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glRotatef(-90.0, 0.0, 1.0, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);

    glTranslatef(0.0f, -46.0f, -5.0f);
}

void SpaceStation::drawPanels() {

    glTranslatef(0.0f, -2.5f, 1.0f);

    // The big solar panels
    bigSolarPanel();
    glTranslatef(0.0f, 0.0f, 12.0f);
    bigSolarPanel();
    glTranslatef(0.0f, 0.0f, 50.0f);
    bigSolarPanel();
    glTranslatef(0.0f, 0.0f, 12.0f);
    bigSolarPanel();

    // side solar panels
    glTranslatef(-5.0f, -18.0f, -50.0f);
    rectangle(3, 20);
    glTranslatef(3.2f, 0.0f, 0.0f);
    rectangle(3, 20);
    glTranslatef(3.2f, 0.0f, 0.0f);
    rectangle(3, 20);

    glTranslatef(-6.4f, 0.0f, 27.0f);
    rectangle(3, 20);
    glTranslatef(3.2f, 0.0f, 0.0f);
    rectangle(3, 20);
    glTranslatef(3.2f, 0.0f, 0.0f);
    rectangle(3, 20);

    //base solar panels
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glTranslatef(-6.5f, -11.0f, 0.0f);
    glRotatef(_autoRotation, 0.0f, 1.0f, 0.0f);
    rectangle(2, 15);
    glRotatef(_autoRotation * (-1), 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, -17.0f, 0.0f);
    glRotatef(_autoRotation, 0.0f, 1.0f, 0.0f);
    rectangle(2, 15);
    glRotatef(_autoRotation * (-1), 0.0f, 1.0f, 0.0f);

    glTranslatef(10.0f, 17.0f, 0.0f);
    glRotatef(_autoRotation, 0.0f, 1.0f, 0.0f);
    rectangle(2, 10);
    glRotatef(_autoRotation * (-1), 0.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, -12.0f, 0.0f);
    glRotatef(_autoRotation, 0.0f, 1.0f, 0.0f);
    rectangle(2, 10);
    glRotatef(_autoRotation * (-1), 0.0f, 1.0f, 0.0f);

}

void SpaceStation::Update(const double& deltaTime) {
    _autoRotation += static_cast<float>(deltaTime) * _velocity;
}

void SpaceStation::HandleKey(unsigned char key, int state, int mx, int my) {
    switch (key)
    {
        case '=': 
            _rotation += 1.0f;
            break;
        case '-':
            _rotation -= 1.0f;
            break;
        case '0':
            _velocity += 1.0f;
            break;
        case '9':
            if(_velocity > 0.0f) {
                _velocity -= 1.0f;
            }
            break;
    }
}

void SpaceStation::Display() {
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);

    glRotatef(5.0, 0.0, 0.0, 1.0);


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, baseTexture);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100);

    drawBase();

    glBindTexture(GL_TEXTURE_2D, panelTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100);
    glGenerateMipmap(GL_TEXTURE_2D);

    drawPanels();
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
    glPopAttrib();
}
