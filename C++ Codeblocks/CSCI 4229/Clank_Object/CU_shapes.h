/*
*   CU_shapes.h
*
*   Some these functions are taken from Professor William's example
*   code from his CSCI 4229 class. Most of this code has been either
*   heavily modified.
*
*   I also added some of my own functions for convenience since I am
*   going to use this header in my final project.
*/

#ifndef CU_SHAPES_H_INCLUDED
#define CU_SHAPES_H_INCLUDED

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include "glWindow_wrapper.h" // Needed for glWindowsPos()
#endif

#define Cos(Glo_th) cos(3.1415927/180*(Glo_th))
#define Sin(Glo_th) sin(3.1415927/180*(Glo_th))

                        //*** Prototypes ***//
// Draws a cube at(x,y,z) dimensions (dx,dy,dz) rotated th about y axis.
static void cube (double x, double y, double z,
                  double dx, double dy, double dz,
                  double th, double saturation);

// Draw a sphere at (x, y, z), radius(r)
static void sphere(double x, double y, double z, double r, double saturation);

// Special function to draw clanks mouth. (Clank function)
static void clank_mouth(double x, double y, double z, double r, double saturation);

// Draw a sphere with specified colors
static void color_sphere(double x, double y, double z, double r,
                         double red, double green, double blue);

// Draws vertex in polar coordinates
static void polar_vertex(double th,double ph);

// Check for OpenGL errors
void ErrCheck(const char* where);
//------------------------------------------------------------------

//------------------------------------------------------------------
                        //*** Implementation ***//
/*  cube  */
static void cube (double x, double y, double z,
                  double dx, double dy, double dz,
                  double th, double saturation)
{
    // Save transformation
    glPushMatrix();
    //Offset
    glTranslated(x,y,z);
    glRotated(th, 0, 1, 0);
    // How big to draw the cube.
    glScaled(dx, dy, dz);

    // Set saturation
    glColor3d(saturation, saturation, saturation);

    // Draw the Cube
    glBegin(GL_QUADS);
    // Front of Z-axis cube
    //glColor3f(1,0,0);
    glVertex3f(-1,-1,+1);
    glVertex3f(+1,-1,+1);
    glVertex3f(+1,+1,+1);
    glVertex3f(-1,+1,+1);
    // Back of Z-axis cube
    //glColor3f(0,0,1);
    glVertex3f(-1,-1,-1);
    glVertex3f(+1,-1,-1);
    glVertex3f(+1,+1,-1);
    glVertex3f(-1,+1,-1);
    //  Right
    //glColor3f(1,1,0);
    glVertex3f(+1,-1,+1);
    glVertex3f(+1,-1,-1);
    glVertex3f(+1,+1,-1);
    glVertex3f(+1,+1,+1);
    //  Left
    //glColor3f(0,1,0);
    glVertex3f(-1,-1,-1);
    glVertex3f(-1,-1,+1);
    glVertex3f(-1,+1,+1);
    glVertex3f(-1,+1,-1);
    //  Top
    //glColor3f(0,1,1);
    glVertex3f(-1,+1,+1);
    glVertex3f(+1,+1,+1);
    glVertex3f(+1,+1,-1);
    glVertex3f(-1,+1,-1);
    //  Bottom
    //glColor3f(1,0,1);
    glVertex3f(-1,-1,-1);
    glVertex3f(+1,-1,-1);
    glVertex3f(+1,-1,+1);
    glVertex3f(-1,-1,+1);
    //  End
    glEnd();
    //  Undo transformations
    glPopMatrix();

}

/*  sphere  */
static void sphere(double x, double y, double z, double r, double saturation)
{
    const int d=5;
    int l_th, l_ph; // local th and local ph

    // Save Transformations
    glPushMatrix();
    // Offset and Scale
    glTranslated(x,y,z);
    glScaled(r,r,r);

    // Sets saturation
    glColor3f(saturation, saturation, saturation);
    // Latitude bands
    for(l_ph=-90; l_ph < 90; l_ph+=d)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for(l_th=0; l_th <= 360; l_th+=d)
        {
            polar_vertex(l_th,l_ph);
            polar_vertex(l_th, l_ph+d);
        }
        glEnd();
    }

    // Undo Transformations
    glPopMatrix();
}

static void clank_mouth(double x, double y, double z, double r, double saturation)
{
    const int d=5;
    const int mouthsize = 10;

    int l_th, l_ph; // local th and local ph

    // Save Transformations
    glPushMatrix();
    // Offset and Scale
    glTranslated(x,y,z);
    glScaled(r,r,r);

    // Sets saturation
    glColor3f(saturation, saturation, saturation);
    // Latitude bands
    for(l_ph=-90; l_ph < mouthsize; l_ph+=d)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for(l_th=0; l_th <= 360; l_th+=d)
        {
            polar_vertex(l_th,l_ph);
            polar_vertex(l_th, l_ph+d);
        }
        glEnd();
    }

    // Undo Transformations
    glPopMatrix();
}

/*  Color sphere  */
static void color_sphere(double x, double y, double z, double r,
                         double red, double green, double blue)
{
    const int d=5;
    int l_th, l_ph; // local th and local ph

    // Save Transformations
    glPushMatrix();
    // Offset and Scale
    glTranslated(x,y,z);
    glScaled(r,r,r);

    // Sets color
    glColor3f(red, green, blue);
    // Latitude bands
    for(l_ph=-90; l_ph < 90; l_ph+=d)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for(l_th=0; l_th <= 360; l_th+=d)
        {
            polar_vertex(l_th,l_ph);
            polar_vertex(l_th, l_ph+d);
        }
        glEnd();
    }

    // Undo Transformations
    glPopMatrix();
}


/*  polar_vertex  */
static void polar_vertex(double th,double ph)
{
   //glColor3f(Cos(th)*Cos(th) , Sin(ph)*Sin(ph) , Sin(th)*Sin(th));
   glVertex3d(Sin(th)*Cos(ph) , Sin(ph) , Cos(th)*Cos(ph));
}

void ErrCheck(const char* where)
{
   int err = glGetError();
   if (err) fprintf(stderr,"ERROR: %s [%s]\n",gluErrorString(err),where);
}
#endif // CU_SHAPES_H_INCLUDED
