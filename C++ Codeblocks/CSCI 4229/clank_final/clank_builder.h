#ifndef CLANK_BUILDER_H_INCLUDED
#define CLANK_BUILDER_H_INCLUDED

/*
*   clank_bulder.h
*
*   This has all the code for making my clank animation
*   This header file takes care of all variables and functions that deal
*   my clank object. There are only two global variable in the main.cpp
*   that this header file is contingent on.
*
*   Sahle Alturaigi
*
*   Animation numbers: 0 = standing, 1 = waving, 2 = "Praise the Sun"
*
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
GLfloat emission    = 0.04;    // Emission intensity (%)
GLfloat ambient     = 0.0;     // Ambient intensity (%)
GLfloat diffuse     = 1.0;     // Diffuse intensity (%)
GLfloat specular    = 1.0;     // Specilar intensity (%)
GLfloat shinyness   = 16;      // Shinyness (power of two)
GLfloat shinyvec[1];           // Shinyness (value)

extern unsigned int Glo_is_animated; // To handle animation resets
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

    // Draw a light_ball of light at (x,y,z) with radius (r).
    void light_ball(double x, double y, double z, double r);

    /*
     * Update methods
     */
    void update_th(double Glo_th);
    void update_ph(double Glo_ph);
    void is_light(bool Glo_Light);

    /*
     *  Helper lighting methods
     */
    // Draw vertex in polar coordinates with normal
    void Vertex(double th, double ph);
    void Vertex2(double th, double ph);

    /*
     *  Draw and Animation methods
     */
    // Draws a hard-coded clank object. All the vertex calls are sorted
    // from top to bottom (i.e. head first and feet last) and the function
    // calls are separated by their type (i.e. cube and sphere).
    void simple_draw_clank();

    /// Code that will check which animation to use and then provide all the necessary
    /// parameters for it to have it work properly
    void compile_clank(int obj_Hand, int obj_RightShoulder, int obj_RightHand2, int obj_LeftShoulder, int obj_LeftHand2,
                       int obj_Body, int obj_Head, double scale);

    // All the methods that handle the animation or standing logic.
    // These are only called within compile_clank method.
    void standing_render(int obj_Hand, int obj_RightShoulder, int obj_LeftShoulder, int obj_Body, int obj_Head, double scale);
    void waving_render(int obj_Hand, int obj_RightShoulder, int obj_LeftShoulder, int obj_Body, int obj_Head, double scale);
    void theSun_render(int obj_RightHand2, int obj_LeftHand2, int obj_RightShoulder, int obj_LeftShoulder, int obj_Body, int obj_Head, double scale);

    // Helper method to signal the compile_clank method which animation to use.
    unsigned int set_animation(unsigned int ani_number);

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

private:
    bool textures_on;   // Sets textures on or off
    bool light_on;      // Sets lights on or off
    double dx, dy, dz;  // Used to move simple clank
    double th;          // Azimuth view angle
    double ph;          // Altitude view angle


    // Animation Control variable
    /** Checks if clank is animated. 0 = none, 1 = wave, 2 = "Praise the sun" **/
    unsigned int is_animated;

    // Texture for whole clank robot. (Not used for this project)
    unsigned int whole_texture;

    /*
    // Textures for clank
    unsigned int joint_tex;
    unsigned int body_tex;
    unsigned int head_tex;
    unsigned int mouth_tex;
    */
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
    textures_on = false;
    is_animated = 0;

    /*
    joint_tex = 0;
    body_tex = 0;
    head_tex = 0;
    mouth_tex = 0;
    */
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
    textures_on = false;
    is_animated = 0;

    /*
    joint_tex = 0;
    body_tex = 0;
    head_tex = 0;
    mouth_tex = 0;
    */
}
//----------------------------------------------------------------------------
// light_ball
//----------------------------------------------------------------------------
void Obj_Clank::light_ball(double x, double y, double z, double r)
{
    int l_th, l_ph;
    int inc = 10; // Ball increment (how many line segments)
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
        glBegin(GL_TRIANGLE_STRIP);
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
// is_light
//----------------------------------------------------------------------------
void Obj_Clank::is_light(bool Glo_Light)
{
    light_on = Glo_Light;
}

//----------------------------------------------------------------------------
// Vertex
//----------------------------------------------------------------------------
void Obj_Clank::Vertex(double th, double ph)
{
    double x = Sin(th)*Cos(ph);
    double y =         Sin(ph);
    double z = Cos(th)*Cos(ph);


    glNormal3d(x,y,z);
    //glTexCoord2f(th/360.0, ph/180.0+0.5);
    glVertex3d(x,y,z);
}
void Obj_Clank::Vertex2(double th, double ph)
{
    double x = -Sin(th)*Cos(ph);
    double y =  Cos(th)*Cos(ph);
    double z =          Sin(ph);

    glNormal3d(x,y,z);
    //glTexCoord2d(th/360.0,ph/180.0+0.5);
    glVertex3d(x,y,z);
}

//----------------------------------------------------------------------------
// simple_draw_clank
//----------------------------------------------------------------------------
void Obj_Clank::simple_draw_clank()
{
    glPushMatrix();

    // So that old clank is at the same height as my new clank.
    glTranslated(0,2,0);

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

//----------------------------------------------------------------------------
// compile_clank
//----------------------------------------------------------------------------
void Obj_Clank::compile_clank(int obj_Hand, int obj_RightShoulder, int obj_RightHand2,
                              int obj_LeftShoulder, int obj_LeftHand2, int obj_Body,
                              int obj_Head, double scale)
{
    // Find which animation to use
    switch(is_animated)
    {
    case 0:
        standing_render(obj_Hand, obj_RightShoulder, obj_LeftShoulder,
                        obj_Body, obj_Head, scale);
        break;
    case 1:
        waving_render(obj_Hand, obj_RightShoulder, obj_LeftShoulder,
                      obj_Body, obj_Head, scale);
        break;
    case 2:
        theSun_render(obj_RightHand2, obj_LeftHand2, obj_RightShoulder,
                      obj_LeftShoulder, obj_Body, obj_Head, scale);
        break;
    default:
        standing_render(obj_Hand, obj_RightShoulder, obj_LeftShoulder,
                        obj_Body, obj_Head, scale);
        break;
    }
}
//----------------------------------------------------------------------------
// standing_render
//----------------------------------------------------------------------------
void Obj_Clank::standing_render(int obj_Hand, int obj_RightShoulder, int obj_LeftShoulder,
                                int obj_Body, int obj_Head, double scale)
{
    /// RENDER resting Right SHOULDER
    glPushMatrix();
    glScaled(scale, scale, scale);
    glTranslated(-0.8, 4, 0); // To set in correct position. (Long story...)
    glCallList(obj_RightShoulder);
    glPopMatrix();

    /// RENDER resting Right HAND
    glPushMatrix();
    glScaled(scale, scale, scale);
    glTranslated(-1.15, 2.3, 0);
    glCallList(obj_Hand);
    glPopMatrix();

    /// RENDER left SHOULDER
    glPushMatrix();
    glScaled(scale, scale, scale);
    glTranslated(+0.8, 4, 0);
    glCallList(obj_LeftShoulder);
    glPopMatrix();

    /// RENDER left HAND
    glPushMatrix();
    glScaled(scale, scale, scale);
    glTranslated(+1.2, 2.3, 0);
    glCallList(obj_Hand);
    glPopMatrix();

    /// RENDER BODY
    glPushMatrix();
    glScaled(scale, scale, scale);
    glCallList(obj_Body);
    glPopMatrix();

    /// RENDER HEAD
    glPushMatrix();
    glScaled(scale, scale, scale);
    glTranslated(0,4.65,0);
    glRotated(22,1,0,0);
    glCallList(obj_Head);
    glPopMatrix();
}
//----------------------------------------------------------------------------
// waving_render
//----------------------------------------------------------------------------
void Obj_Clank::waving_render(int obj_Hand, int obj_RightShoulder, int obj_LeftShoulder,
                              int obj_Body, int obj_Head, double scale)
{
    // The increment value and speed
    static double r_shoul_inc = 0;
    static double wave_speed = 0.60;

    // Time control variables
    double time_elapsed = glutGet(GLUT_ELAPSED_TIME)/1000.0;
    double frame = fmod(time_elapsed, 0.06);

    // Do animation if it is within this time frame.
    if((frame <= 0.06) && (frame >=0.01))
    {
        r_shoul_inc += wave_speed;
        if((r_shoul_inc >= 45) || (r_shoul_inc <= -45))
            wave_speed = -wave_speed;
    }

    /// RENDER raised Right SHOULDER
    glPushMatrix();
    glScaled(scale, scale, scale);
    glTranslated(-0.76, 3.8, 0);
    glRotated(-80,0,0,1);
    glCallList(obj_RightShoulder);
    glPopMatrix();

    /// RENDER waving Right HAND
    glPushMatrix();
    glScaled(scale, scale, scale);
    glTranslated(-2.5, 3.9, 0);
    glRotated(-90, 0,0,1);
    glRotated(-90, 0,1,0);
    glRotated(-90+r_shoul_inc, 1,0,0);
    glCallList(obj_Hand);
    glPopMatrix();

    /// RENDER left SHOULDER
    glPushMatrix();
    glScaled(scale, scale, scale);
    glTranslated(+0.8, 4, 0);
    glCallList(obj_LeftShoulder);
    glPopMatrix();

    /// RENDER left HAND
    glPushMatrix();
    glScaled(scale, scale, scale);
    glTranslated(+1.2, 2.3, 0);
    glCallList(obj_Hand);
    glPopMatrix();

    /// RENDER BODY
    glPushMatrix();
    glScaled(scale, scale, scale);
    glCallList(obj_Body);
    glPopMatrix();

    /// RENDER HEAD
    glPushMatrix();
    glScaled(scale, scale, scale);
    glTranslated(0,4.65,0);
    glRotated(22,1,0,0);
    glCallList(obj_Head);
    glPopMatrix();
}
//----------------------------------------------------------------------------
// theSun_render
//----------------------------------------------------------------------------
void Obj_Clank::theSun_render(int obj_RightHand2, int obj_LeftHand2, int obj_RightShoulder,
                              int obj_LeftShoulder, int obj_Body, int obj_Head, double scale)
{
    // The increment angle and movement speed
    static double z_inc_val = 1;        // rotation for arms (starting value. DON'T MODIFY)
    static double head_inc_val = -40;    // rotation for head (starting value. DON'T MODIFY)
    static double raise_speed = 0.1;

    // Short pause when arms are raised
    static double delay_frame = 0;

    // Time control variables
    double time_elapsed = glutGet(GLUT_ELAPSED_TIME)/1000.0;
    double frame = fmod(time_elapsed, 0.06);

    // Do animation if it is within this time frame.
    if((frame <= 0.06) && (frame >=0.01))
    {
        if(delay_frame <= 0)
        {
            z_inc_val += raise_speed;
            head_inc_val += raise_speed;

            // 115 is the highest I want the arm to go
            if(z_inc_val >= 115)
            {
                raise_speed = -raise_speed;
                delay_frame = 450; // How long the delay should be
            }
            // Reset to standing animation
            else if(z_inc_val <= 0)
            {
                z_inc_val = 1;
                delay_frame = 0;
                raise_speed = -raise_speed;
                Glo_is_animated = set_animation(0);
            }
        }
        else
        {
            --delay_frame;
        }
    }

    /// RENDER Right SHOULDER
    glPushMatrix();
    glScaled(scale, scale, scale);
    glTranslated(-0.8, 4, 0); // To set in correct position. (Long story...)
    glRotated(-z_inc_val, 0, 0, 1);
    glCallList(obj_RightShoulder);
    glPopMatrix();

    /// RENDER Right HAND
    glPushMatrix();
    glScaled(scale, scale, scale);
    glTranslated(-0.8, 4, 0);
    glRotated(-z_inc_val, 0, 0, 1);
    glCallList(obj_RightHand2);
    glPopMatrix();

    /// RENDER Left SHOULDER
    glPushMatrix();
    glScaled(scale, scale, scale);
    glTranslated(+0.8, 4, 0);
    glRotated(+z_inc_val, 0, 0, 1);
    glCallList(obj_LeftShoulder);
    glPopMatrix();

    /// RENDER Left HAND
    glPushMatrix();
    glScaled(scale, scale, scale);
    glTranslated(+0.8, 4, 0);
    glRotated(+z_inc_val, 0, 0, 1);
    glCallList(obj_LeftHand2);
    glPopMatrix();

    /// RENDER BODY
    glPushMatrix();
    glScaled(scale, scale, scale);
    glCallList(obj_Body);
    glPopMatrix();

    /// RENDER HEAD
    glPushMatrix();
    glScaled(scale, scale, scale);
    glTranslated(0,4.65,0);
    glRotated(-head_inc_val/2.6,1,0,0); // Need to divide by 2.6 so it looks right.
    glCallList(obj_Head);
    glPopMatrix();
}
//----------------------------------------------------------------------------
// set_animation
//----------------------------------------------------------------------------
unsigned int Obj_Clank::set_animation(unsigned int ani_number)
{
    switch(ani_number)
    {
    case 0:
        is_animated = 0;
        return 0;
        break;
    case 1:
        is_animated = 1;
        return 1;
        break;
    case 2:
        is_animated = 2;
        return 2;
        break;
    default:
        is_animated = 0;
        return 0;
        break;
    }
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

    if(textures_on)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, whole_texture);
        // Draw the Cube
        glBegin(GL_QUADS);

        // Front of Z-axis cube
        glNormal3f( 0, 0, 1);
        glVertex3f(-1,-1,+1);
        glTexCoord2f(0,0);
        glVertex3f(+1,-1,+1);
        glTexCoord2f(1,0);
        glVertex3f(+1,+1,+1);
        glTexCoord2f(1,1);
        glVertex3f(-1,+1,+1);
        glTexCoord2f(0,1);

        // Back of Z-axis cube
        glNormal3f(0, 0, -1);
        glVertex3f(-1,-1,-1);
        glTexCoord2f(0,0);
        glVertex3f(+1,-1,-1);
        glTexCoord2f(1,0);
        glVertex3f(+1,+1,-1);
        glTexCoord2f(1,1);
        glVertex3f(-1,+1,-1);
        glTexCoord2f(0,1);

        //  Right
        glNormal3f(+1, 0, 0);
        glVertex3f(+1,-1,+1);
        glTexCoord2f(0,0);
        glVertex3f(+1,-1,-1);
        glTexCoord2f(1,0);
        glVertex3f(+1,+1,-1);
        glTexCoord2f(1,1);
        glVertex3f(+1,+1,+1);
        glTexCoord2f(0,1);

        //  Left
        glNormal3f(-1, 0, 0);
        glVertex3f(-1,-1,-1);
        glTexCoord2f(0,0);
        glVertex3f(-1,-1,+1);
        glTexCoord2f(1,0);
        glVertex3f(-1,+1,+1);
        glTexCoord2f(1,1);
        glVertex3f(-1,+1,-1);
        glTexCoord2f(0,1);

        //  Top
        glNormal3f(0, +1, 0);
        glVertex3f(-1,+1,+1);
        glTexCoord2f(0,0);
        glVertex3f(+1,+1,+1);
        glTexCoord2f(1,0);
        glVertex3f(+1,+1,-1);
        glTexCoord2f(1,1);
        glVertex3f(-1,+1,-1);
        glTexCoord2f(0,1);

        //  Bottom
        glNormal3f(0, -1, 0);
        glVertex3f(-1,-1,-1);
        glTexCoord2f(0,0);
        glVertex3f(+1,-1,-1);
        glTexCoord2f(1,0);
        glVertex3f(+1,-1,+1);
        glTexCoord2f(1,1);
        glVertex3f(-1,-1,+1);
        glTexCoord2f(0,1);

        glEnd();
    }
    else
    {
        glBegin(GL_QUADS);

        // Front of Z-axis cube
        glNormal3f( 0, 0, 1);
        glVertex3f(-1,-1,+1);
        glVertex3f(+1,-1,+1);
        glVertex3f(+1,+1,+1);
        glVertex3f(-1,+1,+1);

        // Back of Z-axis cube
        glNormal3f(0, 0, -1);
        glVertex3f(-1,-1,-1);
        glVertex3f(+1,-1,-1);
        glVertex3f(+1,+1,-1);
        glVertex3f(-1,+1,-1);

        //  Right
        glNormal3f(+1, 0, 0);
        glVertex3f(+1,-1,+1);
        glVertex3f(+1,-1,-1);
        glVertex3f(+1,+1,-1);
        glVertex3f(+1,+1,+1);

        //  Left
        glNormal3f(-1, 0, 0);
        glVertex3f(-1,-1,-1);
        glVertex3f(-1,-1,+1);
        glVertex3f(-1,+1,+1);
        glVertex3f(-1,+1,-1);

        //  Top
        glNormal3f(0, +1, 0);
        glVertex3f(-1,+1,+1);
        glVertex3f(+1,+1,+1);
        glVertex3f(+1,+1,-1);
        glVertex3f(-1,+1,-1);

        //  Bottom
        glNormal3f(0, -1, 0);
        glVertex3f(-1,-1,-1);
        glVertex3f(+1,-1,-1);
        glVertex3f(+1,-1,+1);
        glVertex3f(-1,-1,+1);

        glEnd();
    }

    // Disable textures now
    glDisable(GL_TEXTURE_2D);

    //  Undo transformations
    glPopMatrix();
}
//----------------------------------------------------------------------------
// sphere
//----------------------------------------------------------------------------
void Obj_Clank::sphere(double x, double y, double z, double r, double saturation)
{
    const int d = 5;
    int l_th, l_ph; // local th and local ph
    float yellow[] = {1.0,1.0,0.0,1.0};
    float Emission[] = {0.0,0.0,static_cast<float>(0.01*emission),1.0};

    glPushMatrix();

    if(textures_on == true)
    {
        // Enable textures
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, whole_texture);
    }

    // Sets saturation
    glColor3f(saturation, saturation, saturation);

    // Translate and scale
    glTranslated(x,y,z);
    glScaled(r,r,r);

    glMaterialfv(GL_FRONT, GL_SHININESS, shinyvec);
    glMaterialfv(GL_FRONT, GL_SPECULAR, yellow);
    glMaterialfv(GL_FRONT, GL_EMISSION, Emission);


    // This will enable modulation.
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    // Latitude bands
    for(l_ph=-90; l_ph < 90; l_ph+=d)
    {
        glBegin(GL_QUAD_STRIP);
        for(l_th=0; l_th <= 360; l_th+=2*d) // Was 2*d
        {
            Vertex2(l_th,l_ph);
            Vertex2(l_th, l_ph+d);
        }
        glEnd();
    }

    // Disable textures
    glDisable(GL_TEXTURE_2D);

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
#endif // CLANK_BUILDER_H_INCLUDED
