/*
*   clank_bulder.h
*   Header file that holds a class that allows one to make my clank object
*
*   Sahle Alturaigi
*
*   Notes to self: 1.) Making movable clank mod function
*/

#ifndef CLANK_BUILDER_H_INCLUDED
#define CLANK_BUILDER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "CU_shapes.h"

//  OpenGL with prototypes for glext
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include "glWindow_wrapper.h" // Needed for glWindowsPos()
#endif

// Lighting logic will have to go in here.

class Obj_Clank {
public:

    // Constructor
    Obj_Clank();
    Obj_Clank(double user_dx, double user_dy, double user_dz);

    // Destructor (does nothing)
    ~Obj_Clank() {};

    // Draws a hard-coded clank object. All the vertex calls are sorted
    // from top to bottom (i.e. head first and feet last) and the function
    // calls are separated by their type (i.e. cube and sphere).
    void simple_draw_clank();

    /// Implement movable clank here.
private:
    double dx;
    double dy;
    double dz;
};

Obj_Clank::Obj_Clank()
{
    dx = 0;
    dy = 0;
    dz = 0;
}

Obj_Clank::Obj_Clank(double user_dx, double user_dy, double user_dz)
{
    dx = user_dx;
    dy = user_dy;
    dz = user_dz;
}
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

    glEnd();
    glPopMatrix();
}
#endif // CLANK_BUILDER_H_INCLUDED
