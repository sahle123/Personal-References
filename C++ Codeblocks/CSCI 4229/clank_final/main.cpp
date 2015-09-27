
/*
 *  Sahle A. Alturaigi
 *  Nov 14, 2013
 *  Finished: ***
 *
 *  CSCI 4229 Hw: Final Projects
 *
 *
 *  Notes on this project can be found in CSCI 4229 notes.txt
 *
 * Self-Notes:
 *  1.) Anything that starts with Glo_ means it is a global variable.
 *  2.) CGlo_ means it is a global constant.
 *  3.) The FOV is no longer mutable by the user
 *  4.) This project is coming out amazingly
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <string>
#include "clank_builder.h"
#include "ObjTex_loader.h"

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
int Glo_th = 27;            // Azimuth of view angle
int Glo_ph = 36;            // Elevation (Altitude) of view angle
double Glo_y  = 1.5;        // Y coordinate view angle

// Binary Modes
int Glo_Mode = 2;           // 1 = Orthongonal, 2 = Perspective.
int Glo_Show_Axis = 0;      // 1 = show grid, 0 = hide grid.
bool Glo_Light = true;      // Control variable for Lighting. (Orbiting or circling)

// Scaling, field of view, Aspect ratio
double Glo_Scale = 0.7;     // Scale of orthogonal box
double Glo_aspect = 1.0;    // Aspect ratio.
double Glo_dim = 3.0;       // Size of the world
int Glo_FOV = 60;           // Field of view (for perspective)

// Lighting variables go here.
int Glo_zh      = 90;       // Light azimuth
int local       = 0;        // Local Viewer model

// Object files
int OBJ_RightShoulder;      /// Object file: Right Shoulder
int OBJ_LeftShoulder;       /// Object file: Left Shoulder
int OBJ_Hand;               /// Object file: Hand (Both L and R)
int OBJ_Right_hand2;        /// Object file: Right Hand (for "Sun" animation)
int OBJ_Left_hand2;         /// Object file: Left Hand (for "Sun" animation)
int OBJ_Body;               /// Object file: Body
int OBJ_Head;               /// Object file: Head

// Control variable for animation 0 = stand, 1 = wave, 2 = the Sun.
unsigned int Glo_is_animated = 0;

// Shows my first model of clank.
bool Glo_oldClank = false;

// Other
std::string Glo_Text[2] = {"Orthogonal", "3D Persepctive"}; // Dimension display text
//--------------------END Global Variables------------------//

// Macros for sin & cos in degrees to radians
#define Cos(Glo_th) cos(3.1415927/180*(Glo_th))
#define Sin(Glo_th) sin(3.1415927/180*(Glo_th))

/*  Prototypes  */
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
// Check for OpenGL errors (Moved to CSCIx229_modded header file.
//void ErrCheck(const char* where);
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
    glutInitWindowSize(800, 800);
    // Create the window
    glutCreateWindow("Sahle Alturaigi: \"Say HELLO, Clank!\"");
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

    // *** Loading objects here *** //
    OBJ_Head = LoadOBJ("blender_obj//Head.obj");
    OBJ_Hand = LoadOBJ("blender_obj//Hand.obj");
    OBJ_Body = LoadOBJ("blender_obj//Body.obj");
    OBJ_RightShoulder = LoadOBJ("blender_obj//Right_Shoulder_hinge.obj");
    OBJ_LeftShoulder = LoadOBJ("blender_obj//Left_Shoulder_hinge.obj");
    OBJ_Right_hand2 = LoadOBJ("blender_obj//Right_hand2.obj");
    OBJ_Left_hand2 = LoadOBJ("blender_obj//Left_hand2.obj");
    // *** End loading objects *** //

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
    glutPostRedisplay();
}

/*  display  */
void display()
{
    // Light emitter variables
    int light_distance  = 3;    // How far away the light is from the object
    GLfloat light_size  = 0.1;  // The size of the ball of light
    GLfloat ylight      = 2.0;    // y coordinate of light ball.
    // Light variables. (These values can be found in clank_builder.h)
    GLfloat Emission[]  = {emission,emission,emission, 1.0};
    GLfloat Ambient[]   = {ambient,ambient,ambient, 1.0};
    GLfloat Diffuse[]   = {diffuse,diffuse,diffuse, 1.0};
    GLfloat Specular[]  = {specular,specular,specular, 1.0};
    GLfloat Shinyness[] = {shinyness};

    // Position of the ball light and emanating light (Orbit)
    GLfloat Position[]  = {static_cast<GLfloat>(light_distance*Cos(Glo_zh)), ylight,
                           static_cast<GLfloat>(light_distance*Sin(Glo_zh)), 1.0};
    // Position of the ball light and emanating light (Circle)
    GLfloat Position2[] = {static_cast<GLfloat>(Cos(Glo_zh)), static_cast<GLfloat>(ylight + Sin(Glo_zh)), 2, 1};


    // Instantiate myClank object
    Obj_Clank myClank(Glo_th, Glo_ph);

    // Check which animation to use for clank object.
    Glo_is_animated = myClank.set_animation(Glo_is_animated);


    // Clear the image
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // Enable Z-buffering depth test
    glEnable(GL_DEPTH_TEST);
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
        double Ex = -2*Glo_dim*Sin(Glo_th)*Cos(Glo_ph);
        double Ey = +2*Glo_dim*Sin(Glo_ph);
        double Ez = +2*Glo_dim*Cos(Glo_th)*Cos(Glo_ph);
        gluLookAt(Ex, Ey+Glo_y, Ez, 0, Glo_y, 0, 0, Cos(Glo_ph), 0);
    }

    // *** Lighting section ***//
    myClank.is_light(Glo_Light);

    // Draw a orbiting light
    if(Glo_Light)
        myClank.light_ball(Position[0],Position[1],Position[2] , light_size);
    // Else draw a circling light
    else
        myClank.light_ball(Position2[0],Position2[1],Position2[2] , light_size);

    //  OpenGL should normalize normal vectors
    glEnable(GL_NORMALIZE);
    //  Enable lighting
    glEnable(GL_LIGHTING);
    //  Enable light 0
    glEnable(GL_LIGHT0);
    //  Set ambient, diffuse, specular components and position of light 0
    glLightfv(GL_LIGHT0,GL_AMBIENT ,Ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE ,Diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);

    // Set the correct lighting according to light ball's position
    if(Glo_Light)
        glLightfv(GL_LIGHT0,GL_POSITION,Position);
    else
        glLightfv(GL_LIGHT0,GL_POSITION,Position2);

    // Set material properties
    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,Shinyness);
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,  Ambient);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,  Diffuse);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR, Specular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION, Emission);
    // *** End of Lighting **//

    // Decide whether to draw Old Clank or New Clank
    if(Glo_oldClank)
    {
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
        glEnable(GL_COLOR_MATERIAL);
        myClank.simple_draw_clank();
    }
    else
    {
        // Disable lighting from Old Clank, otherwise render looks bad.
        glDisable(GL_COLOR_MATERIAL);

        // Compile the object file (Important step!!!)
        myClank.compile_clank(OBJ_Hand, OBJ_RightShoulder, OBJ_Right_hand2, OBJ_LeftShoulder,
                              OBJ_Left_hand2, OBJ_Body, OBJ_Head, Glo_Scale);
    }

    // Disable lighting
    glDisable(GL_LIGHTING);

    // Draw the cartesian coordinate plane
    draw_axes();

    // Display parameters
    switch(Glo_is_animated)
    {
    case 0:
        glWindowPos2i(5, 5);
        Print("Animation:   Standing");
        break;
    case 1:
        glWindowPos2i(5, 5);
        Print("Animation:   Waving");
        break;
    case 2:
        glColor3f(0.8,0.8,0);
        glWindowPos2i(5, 5);
        Print("Animation:   Praise the Sun!");
        glColor3f(1,1,1);
        break;
    }
    //Print("View Angle=%d, %d Glo_dim=%.1f Glo_FOV=%d Projection=%s",
    //      Glo_th, Glo_ph, Glo_dim, Glo_FOV, Glo_Text[Glo_Mode-1].c_str());

    glColor3f(1,1,1);
    // Displays Status
    glWindowPos2i(5,25);
    Print("Light Mode: %s",Glo_Light?"Orbiting":"Circling");

    // Rasterized "Hi" text for wave animation
    if(Glo_is_animated == 1)
    {
        glRasterPos3d(1, 4, 0);
        Print("Hi :)");
    }

    glFlush();
    glutSwapBuffers();
}

/*  draw_axes  */
void draw_axes()
{
    if(Glo_Show_Axis)
    {
        static float scaler = Glo_dim;

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

    if(Glo_Mode == 1)      // Ortho
        glOrtho(-aspect_ratio*Glo_dim, +aspect_ratio*Glo_dim,
                -Glo_dim, +Glo_dim, -Glo_dim, +Glo_dim);
    else if (Glo_Mode == 2) // Perspec
        gluPerspective(Glo_FOV, aspect_ratio, Glo_dim/16, 16*Glo_dim);

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
/*
 *   S/s = Toggle Lights
 */
void key(unsigned char ch, int x, int y)
{
    // If ESC, quit program.
    if (ch == 27)
        exit(0);

    // Reset view angle
    else if (ch == '0')
    {
        Glo_th = 6;
        Glo_ph = 12;
        Glo_FOV = 60;
        Glo_y = 2.5;
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
            Glo_dim = 5.0;
            break;
        case '2':
            Glo_Mode = 2;
            Glo_dim = 2.5;
            break;
        }
    }
    // Zoom in
    else if ((ch == 'w') || (ch == 'W'))
    {
        Glo_dim += 0.1;
        /*if(Glo_Mode == 1) // Ortho
            Glo_dim += 0.1;
        else if(Glo_Mode == 2)
            ++Glo_FOV;*/
    }
    // Zoom out.
    else if (((ch == 'q') || (ch == 'Q')) && ((Glo_FOV >= 1)))
    {
        Glo_dim -= 0.1;
        /*if(Glo_Mode == 1) // Ortho
            Glo_dim -= 0.1;
        else if(Glo_Mode == 2)
            --Glo_FOV;*/
    }
    else if ((ch == 's') ||(ch == 'S'))
    {
        Glo_Light = !Glo_Light;
    }
    else if ((ch == 'd') || (ch == 'D'))
    {
        Glo_is_animated = 0;
        Glo_oldClank = false;
    }
    else if ((ch == 'f') || (ch == 'F'))
    {
        Glo_is_animated = 1;
        Glo_oldClank = false;
    }
    else if ((ch == 'g') || (ch == 'G'))
    {
        Glo_is_animated = 2;
        Glo_oldClank = false;
    }
    else if ((ch == 'z') || (ch == 'Z'))
    {
        Glo_oldClank = !Glo_oldClank;
        Glo_is_animated = 0;
    }

    // Translate shinyness power to value (-1 => 0)
    shinyvec[0] = shinyness<0 ? 0 : pow(2.0,shinyness);
    // Reproject
    Project(Glo_aspect);
    // Animate scene
    glutIdleFunc(idle);
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
    {
        int mod = glutGetModifiers();// To get shift press
        if ((mod == GLUT_ACTIVE_SHIFT) || (Glo_Mode == 1))
            Glo_ph += 3;
        else
            Glo_y += 0.1;
    }
    else if (key == GLUT_KEY_DOWN)
    {
        int mod = glutGetModifiers(); // To get shift press
        if ((mod == GLUT_ACTIVE_SHIFT) || (Glo_Mode == 1))
            Glo_ph -= 3;
        else
            Glo_y -= 0.1;
    }

    // Keep angles to +/-360 degrees
    Glo_th %= 360;
    Glo_ph %= 360;

    // Tell GLUT it is necessary to redisplay the scene
    glutPostRedisplay();
}
