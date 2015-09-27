
/*
 *  Sahle A. Alturaigi
 *  Sept. 25th, 2013
 *  Finished: Oct. 16th, 2013
 *
 *  CSCI 4229 Hw: objects + projection
 *
 *  Clank Object. This is my attempt of redrawing a character from a game I
 *  like: Clank. This will compose a series of boxes and spheres arranged
 *  in a certain order.
 *
 *  Got some help from the following website:
 *  And from Professor Schreüder, Willam's example code
 *  https://svn.assembla.com/svn/LaspView/src/SpiceRender/glWindowPos.cpp (for help with glWindowPos2i() problem.
 *
 *
 *
 * Self-Notes:
 *  1.) Anything that starts with Glo_ means it is a global variable.
 *  2.) CGlo_ means it is a global constant.
 *  3.)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <string>
#include "clank_builder.h"
//#include "CU_shapes.h"

//  OpenGL with prototypes for glext
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include "glWindow_wrapper.h" // Needed for glWindowsPos()
#endif


//------------------ Global Variables ----------------------//
// View angles
int Glo_th = 27;             // Azimuth of view angle
int Glo_ph = 36;             // Elevation (Altitude) of view angle

// Binary Modes
int Glo_Mode = 2;           // 1 = Orthongonal, 2 = Perspective
int Glo_Show_Axis = 1;      // 1 = show grid, 0 = hide grid.

// Scaling, field of view, Aspect ratio
double Glo_Scale = 3;      // Scale of orthogonal box (scale might not be the best word...)
double Glo_aspect = 1;     // Aspect ratio.
int Glo_FOV = 60;          // Field of view (for perspective)

// Light variables
int Glo_zh = 90;           // Light azimuth

// Other
std::string Glo_Text[2] = {"Orthogonal", "3D Persepctive"}; // Dimension display text
//--------------------END Global Variables------------------//

// Macros for sin & cos in degrees to radians
#define Cos(Glo_th) cos(3.1415927/180*(Glo_th))
#define Sin(Glo_th) sin(3.1415927/180*(Glo_th))

//------------------------------------------------------------
/*  Prototypes  */
// Note that sphere(), cube() and polar_vertex() are in CU_shapes.h

// idle function to pass to glutIdle callback.
void idle();
// Display function to pass to glutDisplayFunc()
void display(); // Need to draw clank ***
// Draws the cartesian plane
void draw_axes();
// Creates the perspective projection
static void Project(double aspect_ratio);
// Reshapes projection of window gets resized
void reshape(int width, int height);
// Button presses
void key(unsigned char ch, int x, int y);
// Arrow key presses
void special_key(int key, int x, int y);
//------------------------------------------------------------

#define LEN 8192 // Maximum length of text string
void Print(const char* format, ...)
{
    char buf[LEN];
    char* ch = buf;
    va_list args;
    // Turn the parameters into a character string
    va_start(args, format);
    vsnprintf(buf, LEN, format, args);
    va_end(args);
    // Display the characters one at a time at the current raster position
    while(*ch)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *ch++);
}

/*
 *  Main
 */
int main(int argc, char *argv[])
{
    // Initialize GLUT and process user parameters
    glutInit(&argc, argv);
    // Request double buffered, true color window
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    // Request 500 x 500 pixel window
    glutInitWindowSize(1000, 1000);
    // Create the window
    glutCreateWindow("Sahle Alturaigi: Object");
    // Tell GLUT to call "display" when the scene should be drawn
    glutDisplayFunc(display);
    // Tell GLUT to call "reshape" when the window is resized
    glutReshapeFunc(reshape);
    // Tell GLUT to call "special_key" when an arrow key is pressed
    glutSpecialFunc(special_key);
    // Tell GLUT to call "key" when a key is pressed
    glutKeyboardFunc(key);
    // Tell GLUT to call idle when the program is not being interacted.
    glutIdleFunc(idle);

    // Checks for any thrown errors
    ErrCheck("init");

    // Pass control to GLUT so it can interact with the user
    glutMainLoop();

    return 0;
}

/*  idle  */
void idle()
{
    // Elapsed time in seconds
    double t;
    t = glutGet(GLUT_ELAPSED_TIME)/1000.0;
    Glo_zh = fmod(90*t, 360.0);

    // Tell GLUT it is necessary to redisplay the scene.
    glutPostRedisplay();
}

/*  display  */
void display()
{
    Obj_Clank myClank;

    // Clear the image
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Enable Z-buffering depth test
    glEnable(GL_DEPTH_TEST);

    // Enable line smoothing (To make it look nicer)
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    // Reset previous transforms
    glLoadIdentity();

    /// Choose how to rotate (For ortho and perspective)
    if(Glo_Mode == 1) // Ortho
    {
        // Sets ortho rotation view
        glRotated(Glo_ph, 1, 0, 0);
        glRotated(Glo_th, 0, 1, 0);
    }
    else if(Glo_Mode == 2) // Perspective
    {
        double Ex = -2*Glo_Scale*Sin(Glo_th)*Cos(Glo_ph);
        double Ey = +2*Glo_Scale*Sin(Glo_ph);
        double Ez = +2*Glo_Scale*Cos(Glo_th)*Cos(Glo_ph);
        gluLookAt(Ex, Ey, Ez, 0, 0, 0, 0, Cos(Glo_ph), 0);
    }

    // Code is in clank_builder.h
    myClank.simple_draw_clank();

    // Draw the cartesian coordinate plane
    draw_axes();

    // Display parameters
    glWindowPos2i(5, 5);
    Print("View Angle=%d, %d Glo_Scale=%.1f Glo_FOV=%d Projection=%s",
          Glo_th, Glo_ph, Glo_Scale, Glo_FOV, Glo_Text[Glo_Mode-1].c_str());

    glFlush();
    glutSwapBuffers();
}

/*  draw_axes  */
void draw_axes()
{
    if(Glo_Show_Axis)
    {
        float scaler = Glo_Scale/1.5;

        // Draw axes in white
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
        glVertex3d(0, 0, 0);
        glVertex3d(scaler, 0, 0);
        glVertex3d(0, 0, 0);
        glVertex3d(0, scaler, 0);
        glVertex3d(0, 0, 0);
        glVertex3d(0, 0, scaler);
        glEnd();

        // Label Axes
        glRasterPos3d(scaler, 0, 0);
        Print("X");
        glRasterPos3d(0, scaler, 0);
        Print("Y");
        glRasterPos3d(0, 0, scaler);
        Print("Z");

    }
}

/*  Project  */
static void Project(double aspect_ratio)
{
    // Maniuplating projection matrix now in lieu of model matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(Glo_Mode  == 1)      // Ortho
        glOrtho(-aspect_ratio*Glo_Scale, +aspect_ratio*Glo_Scale,
                -Glo_Scale, +Glo_Scale, -Glo_Scale, +Glo_Scale);
    else if (Glo_Mode == 2) // Perspec
        gluPerspective(Glo_FOV, aspect_ratio, Glo_Scale/4, 4*Glo_Scale);

    // Going back to model view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/*  reshape  */
void reshape(int width, int height)
{
    // Ratio of the width to the height of the window
    Glo_aspect = (height>0) ? (double)width/height : 1;
    // Set the viewport to the entire window
    glViewport(0, 0, width, height);

    Project(Glo_aspect);
}

/*  key  */
void key(unsigned char ch, int x, int y)
{
    // If ESC, quit program.
    if (ch == 27)
        exit(0);

    // Reset view angle
    else if (ch == '0')
    {
        Glo_th = 0;
        Glo_ph = 0;
        Glo_FOV = 55;
    }
    // Toggles the cartesian coordinate plane
    else if (ch == 'a')
    {
        switch(Glo_Show_Axis)
        {
        case 1:
            Glo_Show_Axis = 0;
            break;
        default:
            Glo_Show_Axis = 1;
            break;
        }
    }
    // Switching between perspective and ortho
    else if ((ch == '1') || (ch == '2'))
    {
        switch(ch)
        {
        case '1':
            Glo_Mode = 1;
            break;
        case '2':
            Glo_Mode = 2;
            break;
        }
    }
    // Zoom in
    else if ((ch == 'w') || (ch == 'W'))
    {
        if(Glo_Mode == 1) // Ortho
            Glo_Scale += 0.5;
        else if(Glo_Mode == 2)
            ++Glo_FOV;
    }
    // Zoom out. Makes sure Glo_FOV and Glo_Scale don't go below 1
    else if (((ch == 'q') || (ch == 'Q')) && ((Glo_FOV > 1) && (Glo_Scale > 1)))
    {
        if(Glo_Mode == 1) // Ortho
            Glo_Scale -= 0.5;
        else if(Glo_Mode == 2)
            --Glo_FOV;
    }
    // Reproject
    Project(Glo_aspect);
    // Tell GLUT it is necessary to redisplay the scene
    glutPostRedisplay();
}

/*  special_key  */
void special_key(int key, int x, int y)
{
    // Right arrow key - increase azimuth by 5 degrees
    if (key == GLUT_KEY_RIGHT)
        Glo_th += 3;
    else if (key == GLUT_KEY_LEFT)
        Glo_th -= 3;
    else if (key == GLUT_KEY_UP)
        Glo_ph += 3;
    else if (key == GLUT_KEY_DOWN)
        Glo_ph -= 3;

    // Keep angles to +/-360 degrees
    Glo_th %= 360;
    Glo_ph %= 360;

    // Tell GLUT it is necessary to redisplay the scene
    glutPostRedisplay();
}
