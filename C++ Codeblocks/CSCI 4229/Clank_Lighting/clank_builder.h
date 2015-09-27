#ifndef CLANK_BUILDER_H_INCLUDED
#define CLANK_BUILDER_H_INCLUDED

/*
*   clank_bulder.h
*
*   Header file that holds a class that allows one to make my clank object.
*   Some these functions are taken from Professor William's example
*   code from his CSCI 4229 class. Most of his code has been either
*   heavily modified, though.
*
*   I also added some of my own functions for convenience since I am
*   going to use this header in my final project.
*
*   Sahle Alturaigi
*
*   Notes to self: 1.) Making movable clank mod function.
*                  2.) Some unnecessary functions need to be taken out later.
*                  3.) Some refactoring is in order.
*/

#include <stdio.h>
#include <stdlib.h>

//  OpenGL with prototypes for glext
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include "glWindow_wrapper.h" // Needed for glWindowsPos()
#endif

// Macros for sin & cos in degrees to radians
#define Cos(Glo_th) cos(3.1415927/180*(Glo_th))
#define Sin(Glo_th) sin(3.1415927/180*(Glo_th))

//------------------ Global Variables ----------------------//
// Lighting variables go here.
int zh          = 90;   // Light azimuth
int emission    = 0;    // Emission intensity (%)
int ambient     = 10;   // Ambient intensity (%)
int diffuse     = 90;   // Diffuse intensity (%)
int specular    = 5;    // Specilar intensity (%)
int shininess   = 128;  // Shininess (power of two)
float shinyvec[1];      // Shininess (value)
float ylight    = 0;    // Elevation of light
//------------------ End Global Variables ------------------//

class Obj_Clank
{
public:

    // Constructor
    Obj_Clank(double Glo_th, double Glo_ph);
    Obj_Clank(double user_dx, double user_dy, double user_dz,
              double Glo_th, double Glo_ph);

    // Destructor (does nothing)
    ~Obj_Clank() {};

    // Update functions
    void update_th(double Glo_th);
    void update_ph(double Glo_ph);
    void set_light(bool Glo_Light);

    // Draws a hard-coded clank object. All the vertex calls are sorted
    // from top to bottom (i.e. head first and feet last) and the function
    // calls are separated by their type (i.e. cube and sphere).
    void simple_draw_clank();

    // Helper lighting functions
    // Draw vertex in polar coordinates with normal
    void Vertex(double tj, double ph);
    // Draw a ball at (x,y,z) with radius (r).
    void ball(double x, double y, double z, double r);

protected:
    // Draws a cube at(x,y,z) dimensions (dx,dy,dz) rotated th about y axis.
    void cube(double x, double y, double z,
              double dx, double dy, double dz,
              double th, double saturation);
    // Draw a sphere at (x, y, z), radius(r)
    void sphere(double x, double y, double z, double r, double saturation);
    // Special function to draw clanks mouth. (Clank function)
    void clank_mouth(double x, double y, double z, double r, double saturation);
    // Draw a sphere with specified colors
    void color_sphere(double x, double y, double z, double r,
                      double red, double green, double blue);
    // Draws a pyramid of size (s) at rotated at (r) at (x,y,z)
    void pyramid(double x, double y, double z, double s, double r);

private:
    bool light_on; // 1 = light on, 0 = light off. Not used so far...
    double dx, dy, dz; // Not used so far...
    double th; // Azimuth view angle
    double ph; // Altitude view angle
};
//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------
Obj_Clank::Obj_Clank(double Glo_th, double Glo_ph)
{
    dx = 0;
    dy = 0;
    dz = 0;
    th = Glo_th;
    ph = Glo_ph;
    light_on = false;
}
//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------
Obj_Clank::Obj_Clank(double user_dx, double user_dy, double user_dz,
                     double Glo_th, double Glo_ph)
{
    dx = user_dx;
    dy = user_dy;
    dz = user_dz;
    th = Glo_th;
    ph = Glo_ph;
    light_on = false;
}
//----------------------------------------------------------------------------
// update_th
//----------------------------------------------------------------------------
void Obj_Clank::update_th(double Glo_th)
{
    th = Glo_th;
}
//----------------------------------------------------------------------------
// update_ph
//----------------------------------------------------------------------------
void Obj_Clank::update_ph(double Glo_ph)
{
    ph = Glo_ph;
}
//----------------------------------------------------------------------------
// Vertex
//----------------------------------------------------------------------------
void Obj_Clank::Vertex(double th, double ph)
{
    double x = Sin(th)*Cos(ph);
    double y = Sin(ph);
    double z = Cos(th)*Cos(ph);

    glNormal3d(x,y,z);
    glVertex3d(x,y,z);
}
//----------------------------------------------------------------------------
// ball
//----------------------------------------------------------------------------
void Obj_Clank::ball(double x, double y, double z, double r)
{
    int l_th, l_ph;
    int inc = 10; // Ball increment
    float yellow[] = {1.0,1.0,0.0,1.0};
    float Emission[] = {0.0,0.0,static_cast<float>(0.01*emission),1.0};

    glPushMatrix();

    glTranslated(x,y,z);
    glScaled(r,r,r);

    // White ball
    glColor3f(1,1,1);
    glMaterialfv(GL_FRONT, GL_SHININESS, shinyvec);
    glMaterialfv(GL_FRONT, GL_SPECULAR, yellow);
    glMaterialfv(GL_FRONT, GL_EMISSION, Emission);
    // Band of latitude
    for(l_ph=-90; l_ph<90; l_ph+=inc)
    {
        glBegin(GL_QUAD_STRIP);
        for(l_th=0; l_th<=360; l_th+=2*inc)
        {
            Vertex(l_th,l_ph);
            Vertex(l_th,l_ph+inc);
        }
        glEnd();
    }

    glPopMatrix();
}
//----------------------------------------------------------------------------
// light_on
//----------------------------------------------------------------------------
void Obj_Clank::set_light(bool Glo_Light)
{
    light_on = Glo_Light;
}
//----------------------------------------------------------------------------
// simple_draw_clank
//----------------------------------------------------------------------------
void Obj_Clank::simple_draw_clank()
{
    glPushMatrix();

    /// Sphere calls
    // Antenna blub
    color_sphere(0.0,2.4,0.0, 0.05, 0.7,0.1,0.0);
    // Head
    sphere(0.0,1.65,0.0, 0.5, 0.7);
    // Eyes
    color_sphere(-0.2,1.75,0.3, 0.2, 0,1,1); // Right eye
    color_sphere(+0.2,1.75,0.3, 0.2, 0,1,1); // Left eye
    // Mouth
    clank_mouth(0.0,1.48,0.07, 0.49, 0.6);
    // Cheek screws
    sphere(+0.5, 1.55,0.0, 0.1, 0.5); // Right cheek
    sphere(-0.5, 1.55,0.0, 0.1, 0.5); // Left cheek
    // Shoulders
    sphere(-0.7,0.9,0.0, 0.15, 0.7); // Right shoulder
    sphere(+0.7,0.9,0.0, 0.15, 0.7); // Left shoulder
    // Elbows
    sphere(-1.3,0.9,0.0, 0.15, 0.7); // Right elbow
    sphere(+1.3,0.9,0.0, 0.15, 0.7); // Left elbow
    // Hip flexors
    sphere(-0.4,-0.3,0.0, 0.15, 0.7); // Right hip
    sphere(+0.4,-0.3,0.0, 0.15, 0.7); // Left hip
    // Knees
    sphere(-0.4,-0.8,0.0, 0.15, 0.7); // Right knee
    sphere(+0.4,-0.8,0.0, 0.15, 0.7); // Left knee


    /// Cube calls
    // Antenna
    cube(0.0,2.2,0.0, 0.01,0.2,0.01, 0.0, 0.25);
    // Torso
    cube(0.0,0.45,0.0, 0.55,0.60,0.25, 0, 0.75);
    // Appendages (Arms)
    cube(-1.1,0.9,0.0, 0.30,0.05,0.05, 0.0, 0.15); // Right bicep
    cube(+1.1,0.9,0.0, 0.30,0.05,0.05, 0.0, 0.15); // Left bicep
    cube(-1.5,0.9,0.0, 0.30,0.05,0.05, 0.0, 0.15); // Right forearm
    cube(+1.5,0.9,0.0, 0.30,0.05,0.05, 0.0, 0.15); // Left forearm
    // Hand
    cube(-1.95,0.9,0.05, 0.15,0.05,0.12, 0.0, 0.7); // Right hand
    cube(+1.95,0.9,0.05, 0.15,0.05,0.12, 0.0, 0.7); // Left hand
    // Right Hand fingers
    cube(-2.15,0.9,-0.02, 0.06,0.05,0.06, 0.0, 0.15); // Index finger (inner)
    cube(-2.28,0.9,-0.02, 0.06,0.05,0.06, 0.0, 0.15); // Index finger (outer)
    cube(-2.15,0.9,0.12, 0.06,0.05,0.06, 0.0, 0.15);  // Middle finger (inner)
    cube(-2.28,0.9,0.12, 0.06,0.05,0.06, 0.0, 0.15);  // Middle finger (outer)
    // Left Hand fingers
    cube(+2.15,0.9,-0.02, 0.06,0.05,0.06, 0.0, 0.15); // Index finger (inner)
    cube(+2.28,0.9,-0.02, 0.06,0.05,0.06, 0.0, 0.15); // Index finger (outer)
    cube(+2.15,0.9,0.12, 0.06,0.05,0.06, 0.0, 0.15);  // Middle finger (inner)
    cube(+2.28,0.9,0.12, 0.06,0.05,0.06, 0.0, 0.15);  // Middle finger (outer)
    // Right thumb
    cube(-1.90,0.9,0.26, 0.06,0.05,0.06, 40, 0.15); // Thumb (inner)
    cube(-2.00,0.9,0.34, 0.06,0.05,0.06, -60, 0.15); // Thumb (outer)
    // Left thumb
    cube(+1.90,0.9,0.26, 0.06,0.05,0.06, 40, 0.15); // Thumb (inner)
    cube(+2.00,0.9,0.34, 0.06,0.05,0.06, 60, 0.15); // Thumb (outer)
    // Appendages (Legs)
    cube(-0.4,-0.7,0.0, 0.05,0.25,0.05, 0.0, 0.15); // Right femur
    cube(+0.4,-0.7,0.0, 0.05,0.25,0.05, 0.0, 0.15); // Left femur
    cube(-0.4,-1.0,0.0, 0.05,0.25,0.05, 0.0, 0.15); // Right tibia
    cube(+0.4,-1.0,0.0, 0.05,0.25,0.05, 0.0, 0.15); // Left tibia
    // Pelvis
    cube(0.0,-0.2,0.0, 0.25,0.10,0.20, 0, 0.1);
    // Feet
    cube(-0.4,-1.3,0.15, 0.1,0.1,0.25, 0.0, 0.7); // Right foot
    cube(+0.4,-1.3,0.15, 0.1,0.1,0.25, 0.0, 0.7); // Left foot
    /// End draw Clank

    // Draw pyramid
    pyramid(3.0, 0.5, -1.0, 0.0, 0.7);
    pyramid(-2.0, 0.5, 1.5, 80, 0.7);
    pyramid(-2.0, 0.5, -1.5, 150, 1.0);


    glEnd();
    glPopMatrix();
}
//----------------------------------------------------------------------------
// cube
//----------------------------------------------------------------------------
void Obj_Clank::cube(double x, double y, double z,
                     double dx, double dy, double dz,
                     double th, double saturation)
{

    // Save transformation
    glPushMatrix();

    // Set specular color to white
    float white[] = {1,1,1,1};
    float black[] = {0,0,0,1};

    // Set saturation
    glColor3d(saturation, saturation, saturation);

    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinyvec);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);


    //Offset
    glTranslated(x,y,z);
    glRotated(th, 0, 1, 0);
    // How big to draw the cube.
    glScaled(dx, dy, dz);

    // Draw the Cube
    glBegin(GL_QUADS);
    // Front of Z-axis cube
    //glColor3f(1,0,0);
    glNormal3f( 0, 0, 1);
    glVertex3f(-1,-1,+1);
    glVertex3f(+1,-1,+1);
    glVertex3f(+1,+1,+1);
    glVertex3f(-1,+1,+1);
    // Back of Z-axis cube
    //glColor3f(0,0,1);
    glNormal3f(0, 0, -1);
    glVertex3f(-1,-1,-1);
    glVertex3f(+1,-1,-1);
    glVertex3f(+1,+1,-1);
    glVertex3f(-1,+1,-1);
    //  Right
    //glColor3f(1,1,0);
    glNormal3f(+1, 0, 0);
    glVertex3f(+1,-1,+1);
    glVertex3f(+1,-1,-1);
    glVertex3f(+1,+1,-1);
    glVertex3f(+1,+1,+1);
    //  Left
    //glColor3f(0,1,0);
    glNormal3f(-1, 0, 0);
    glVertex3f(-1,-1,-1);
    glVertex3f(-1,-1,+1);
    glVertex3f(-1,+1,+1);
    glVertex3f(-1,+1,-1);
    //  Top
    //glColor3f(0,1,1);
    glNormal3f(0, +1, 0);
    glVertex3f(-1,+1,+1);
    glVertex3f(+1,+1,+1);
    glVertex3f(+1,+1,-1);
    glVertex3f(-1,+1,-1);
    //  Bottom
    //glColor3f(1,0,1);
    glNormal3f(0, -1, 0);
    glVertex3f(-1,-1,-1);
    glVertex3f(+1,-1,-1);
    glVertex3f(+1,-1,+1);
    glVertex3f(-1,-1,+1);
    //  End
    glEnd();
    //  Undo transformations
    glPopMatrix();
}
//----------------------------------------------------------------------------
// sphere
//----------------------------------------------------------------------------
void Obj_Clank::sphere(double x, double y, double z, double r, double saturation)
{
    const int d=10;
    int l_th, l_ph; // local th and local ph
    float yellow[] = {1.0,1.0,0.0,1.0};
    float Emission[] = {0.0,0.0,static_cast<float>(0.01*emission),1.0};

    glPushMatrix();
    // Translate and scale
    glTranslated(x,y,z);
    glScaled(r,r,r);

    // Sets saturation
    glColor3f(saturation, saturation, saturation);

    glMaterialfv(GL_FRONT, GL_SHININESS, shinyvec);
    glMaterialfv(GL_FRONT, GL_SPECULAR, yellow);
    glMaterialfv(GL_FRONT, GL_EMISSION, Emission);

    // Latitude bands
    for(l_ph=-90; l_ph < 90; l_ph+=d)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for(l_th=0; l_th <= 360; l_th+=2*d)
        {
            Vertex(l_th,l_ph);
            Vertex(l_th, l_ph+d);
        }
        glEnd();
    }

    // Undo Transformations
    glPopMatrix();
}
//----------------------------------------------------------------------------
// clank_mouth
//----------------------------------------------------------------------------
void Obj_Clank::clank_mouth(double x, double y, double z, double r, double saturation)
{
    const int d=15;
    const int mouthsize = 10;

    int l_th, l_ph; // local th and local ph

    float yellow[] = {1.0,1.0,0.0,1.0};
    float Emission[] = {0.0,0.0,static_cast<float>(0.01*emission),1.0};

    glPushMatrix();
    // Translate and scale
    glTranslated(x,y,z);
    glScaled(r,r,r);

    // Sets saturation
    glColor3f(saturation, saturation, saturation);

    glMaterialfv(GL_FRONT, GL_SHININESS, shinyvec);
    glMaterialfv(GL_FRONT, GL_SPECULAR, yellow);
    glMaterialfv(GL_FRONT, GL_EMISSION, Emission);

    // Latitude bands
    for(l_ph=-90; l_ph < mouthsize; l_ph+=d)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for(l_th=0; l_th <= 360; l_th+=d)
        {
            Vertex(l_th,l_ph);
            Vertex(l_th, l_ph+d);
        }
        glEnd();
    }

    // Undo Transformations
    glPopMatrix();
}
//----------------------------------------------------------------------------
// color_sphere
//----------------------------------------------------------------------------
void Obj_Clank::color_sphere(double x, double y, double z, double r,
                             double red, double green, double blue)
{
    const int d=15;
    int l_th, l_ph; // local th and local ph

    float yellow[] = {1.0,1.0,0.0,1.0};
    float Emission[] = {0.0,0.0,static_cast<float>(0.01*emission),1.0};

    glPushMatrix();
    // Translate and scale
    glTranslated(x,y,z);
    glScaled(r,r,r);

    // Sets color
    glColor3f(red, green, blue);

    glMaterialfv(GL_FRONT, GL_SHININESS, shinyvec);
    glMaterialfv(GL_FRONT, GL_SPECULAR, yellow);
    glMaterialfv(GL_FRONT, GL_EMISSION, Emission);

    // Latitude bands
    for(l_ph=-90; l_ph < 90; l_ph+=d)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for(l_th=0; l_th <= 360; l_th+=d)
        {
            Vertex(l_th,l_ph);
            Vertex(l_th, l_ph+d);
        }
        glEnd();
    }

    // Undo Transformations
    glPopMatrix();
}
//----------------------------------------------------------------------------
// Pyramid
//----------------------------------------------------------------------------
void Obj_Clank::pyramid(double x, double y, double z, double r, double s)
{
    // Save transformation
    glPushMatrix();

    // Set specular color to white
    float white[] = {1,1,1,1};
    float black[] = {0,0,0,1};

    // Set Color to purple
    glColor3d(0.5,0.0,0.5);

    // Offset and scaled and rotated
    glTranslated(x,y,z);
    glScaled(s,s,s);
    glRotated(r, 0, 1, 0);

    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,shinyvec);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,black);

    glBegin(GL_TRIANGLES);

    // Front side
    glNormal3f(0.0,0.2,1.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);

    // Back-right side
    glNormal3f(-0.7,0.2,-0.7);
    glVertex3f(0.0,1.0,0.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(0.0,-1.0,-1.0);

    // Back-left side
    glNormal3f(+0.7,0.2,-0.3);
    glVertex3f(0.0,1.0,0.0);
    glVertex3f(0.0,-1.0,-1.0);
    glVertex3f(1.0,-1.0,1.0);

    // Bottom
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(0.0,-1.0,-1.0);
    glVertex3f(1.0,-1.0,1.0);

    glEnd();

    glColor3d(1,1,1); // So that the rasterized text does not change color
    glPopMatrix();
}

#endif // CLANK_BUILDER_H_INCLUDED
