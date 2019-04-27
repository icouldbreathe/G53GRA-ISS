#include "MyScene.h"
#include "Skybox.h"
#include "SpaceStation.h"
#include "Sun.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

    // Load textures for the base and the solar panels
	GLuint baseTexture = Scene::GetTexture("aluminium.bmp");
	GLuint panelTexture = Scene::GetTexture("solar2.bmp");

    // Add SpaceStation object to the scene
	SpaceStation* station = new SpaceStation(baseTexture, panelTexture);
	station->size(10);
	station->position(0.0f, -300.0f, 0.0f);
	//station->position()
	AddObjectToScene(station);

    // Load skybox textures
	GLuint tf = Scene::GetTexture("drakeq_up.bmp");
	GLuint bf = Scene::GetTexture("drakeq_dn.bmp");
	GLuint lf = Scene::GetTexture("drakeq_lf.bmp");
	GLuint rf = Scene::GetTexture("drakeq_rt.bmp");
	GLuint nf = Scene::GetTexture("drakeq_bk.bmp");
	GLuint ff = Scene::GetTexture("drakeq_ft.bmp");
    
    // Add Skybox object to the scene
    Skybox* skybox = new Skybox(tf, bf, lf, rf, nf, ff);
    skybox->size(10000.0f, 10000.0f, 10000.0f);
	skybox->position(0.0f, -5000.0f, 0.0f);
    AddObjectToScene(skybox);

    // Add sun object to the scene
	Sun* sun = new Sun();
	sun->position(-10000.0f, 2000.0f, 0.0f);
    sun->size(2000);
	AddObjectToScene(sun);

}

void MyScene::Projection()
{
	GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
    gluPerspective(80.0, aspect, 1.0, 30000.0);
}
