// ===============================================================
// Computer Graphics Homework Solutions
// Copyright (C) 2019 by George Wolberg
//
// HW1a.cpp - HW1a class
//
// Written by: George Wolberg, 2019
// ===============================================================

#include "HW1a.h"

// init array of 16 vertices for letter 'P'
float Vertices[] = {
    -0.5f , -0.75f,
    -0.5f , -0.5f,
    -0.5f , -0.25f,
    -0.5f ,  0.0f,
    -0.5f ,  0.25f,
    -0.5f ,  0.5f,
    -0.25f,  0.75f,
     0.0f ,  0.75f,
     0.25f,  0.75f,
     0.5f ,  0.75f,
     0.75f,  0.5f,
     0.75f,  0.25f,
     0.5f ,  0.0f,
     0.25f,  0.0f,
     0.0f ,  0.0f,
    -0.25f,  0.0f
};

static int DrawModes[] = {
    GL_POINTS,
    GL_LINES,
    GL_LINE_STRIP,
    GL_LINE_LOOP,
    GL_TRIANGLES,
    GL_TRIANGLE_STRIP,
    GL_TRIANGLE_FAN,
    GL_QUADS,
    GL_POLYGON
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::HW1a:
//
// HW1a constructor.
//
HW1a::HW1a(const QGLFormat &glf, QWidget *parent)
    : HW(glf, parent)
{
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::initializeGL:
//
// Initialization routine before display loop.
// Gets called once before the first time resizeGL() or paintGL() is called.
//
void
HW1a::initializeGL()
{
    // PUT YOUR CODE HERE
    initializeGLFunctions();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glColor3f(1.0F, 1.0f, 1.0f);
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::resizeGL:
//
// Resize event handler.
// The input parameters are the window width (w) and height (h).
//
void
HW1a::resizeGL(int w, int h)
{
    // PUT YOUR CODE HERE
    float xmax, ymax;
    float ar = (float)w / h;
    if (ar > 1.0) {
        xmax = ar;
        ymax = 1.;
    }
    else {
        xmax = 1.;
        ymax = 1 / ar;
    }

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-xmax, xmax, -ymax, ymax, -1.0, 1.0);

}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::paintGL:
//
// Update GL scene.
//
void
HW1a::paintGL()
{
    // PUT YOUR CODE HERE
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

//    float Offset[] = {
//        -0.66f,
//        0,
//        0.66f,
//    };
    
    // define polygon
    GLint vp [4];
    glGetIntegerv (GL_VIEWPORT, vp);
    int pos[] = {0, 0, (int)(vp[2]*.66), vp[3], (int)(QWidget::width()*0.66), 0, vp[2], vp[3],  QWidget::width(), 0, vp[2], vp[3], 0, (int)(QWidget::height()*0.66), vp[2], vp[3], (int)(QWidget::width()*0.66), (int)(QWidget::height()*0.66), vp[2], vp[3],QWidget::width(), (int)(QWidget::height()*0.66), vp[2], vp[3],0, vp[2], (int)(QWidget::width()*0.66), (int)(QWidget::height()*0.66),(int)(QWidget::width()*0.66), vp[3], (int)(QWidget::width()*0.66), (int)(QWidget::height()*0.66),QWidget::width(), vp[3], (int)(QWidget::width()*0.66), (int)(QWidget::height()*0.66)};
    printf("height is %d\n", vp[3]);

    int count = 0;
    for (int i = 0; i < 36; i += 4)
    {
//        float offsetx = Offset[i % 3], offsety = Offset[i / 3];
            glViewport(pos[i], pos[i+1], pos[i+2], pos[i+3]);

        
            printf("Pos ouput is : %d, %d, %d, %d\n", pos[i], pos[i+1], pos[i+2], pos[i+3]);

            glBegin(DrawModes[count]);

            count++;
            for (int j = 0; j < 32; j += 2)
            {
//                float vx = (Vertices[i] / 3) + offsetx, vy = (Vertices[i + 1] / 3) + offsety;
                
//                glLoadIdentity();

                glVertex2f(Vertices[j], Vertices[j+1]);
                glViewport(0, 0, QWidget::width(), QWidget::height());

            }
        glEnd();
    }

}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::controlPanel:
//
// Create control panel groupbox.
//
QGroupBox*
HW1a::controlPanel()
{
    // init group box
    QGroupBox *groupBox = new QGroupBox("Homework 1a");
    groupBox->setStyleSheet(GroupBoxStyle);

    return(groupBox);
}
