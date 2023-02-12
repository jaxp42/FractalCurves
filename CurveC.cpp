/*////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

   _____                             
  / ____|                            
 | |        ___ _   _ _ ____   _____ 
 | |       / __| | | | '__\ \ / / _ \
 | |____  | (__| |_| | |   \ V /  __/
  \_____|  \___|\__,_|_|    \_/ \___|
                                    

//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <GL/glut.h>

const double LINE_SIZE = 0.01;

void askForNumber(int &num){
  printf("Please, introduce the size of the C-curve: ");
  scanf("%d", &num);
}

void display(){
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background color to black
  glClear(GL_COLOR_BUFFER_BIT);         
 

  glBegin( GL_LINES);
    glVertex3d( 0, 0, 0);
    glVertex3d( 0.01, 0, 0);
    glVertex3d( 0.01, 0, 0);
    glVertex3d( 0.01, 0.01, 0);
    glVertex3d( 0.01, 0.01, 0);
    glVertex3d( 0.02, 0.01, 0);
  glEnd();




 
   glFlush();  
}


/*----------------------------------
Surface to print the Curve
----------------------------------*/
struct Paper {
  void wipePaper();
  void printPaper();
  void writeInPaper(char charToWrite, int x, int y);
};

//Removes all content from the paper
void Paper::wipePaper(){

}

//Prints the paper's content
void Paper::printPaper(){

}

//Writes charToWrite in the (x,y) position
void Paper::writeInPaper(char charToWrite, int x, int y){
  
}


/*----------------------------------
Turtle to walk the paper
----------------------------------*/
enum Direction{Right, Up, Left, Down};

struct Turtle {
  void advance();
  void setPosition(double x, double y);

  private:
    double turtleX, turtleY;
    Direction direction;
};

void Turtle::advance(){
  switch (direction){
  case Right:
    glBegin( GL_LINES);
      glVertex3d( turtleX, turtleY, 0);
      glVertex3d( turtleX + LINE_SIZE, turtleY, 0);
    glEnd();
    turtleX += LINE_SIZE;
    break;
  case Up:
    glBegin( GL_LINES);
      glVertex3d( turtleX, turtleY, 0);
      glVertex3d( turtleX, turtleY + LINE_SIZE, 0);
    glEnd();
    turtleY += LINE_SIZE;
    break;
  case Left:
    glBegin( GL_LINES);
      glVertex3d( turtleX, turtleY, 0);
      glVertex3d( turtleX - LINE_SIZE, turtleY, 0);
    glEnd();
    turtleX += LINE_SIZE;
    break;
  case Down:
    glBegin( GL_LINES);
      glVertex3d( turtleX, turtleY, 0);
      glVertex3d( turtleX, turtleY - LINE_SIZE, 0);
    glEnd();
    turtleY += LINE_SIZE;
    break;
  }
}

void Turtle::setPosition(double x, double y){
  turtleX = x;
  turtleY = y;
}


/*----------------------------------
C Curve main drawing method
----------------------------------*/
void drawCurve(int curveSize){
  if(curveSize == 0){

  }
}

int main(int argc, char** argv){
  int curveSize = 0;
  askForNumber(curveSize);

   glutInit(&argc, argv);                 // Initialize GLUT
   glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
   glutInitWindowSize(320, 320);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutMainLoop();           // Enter the infinitely event-processing loop
   return 0;



  // return 0;
}
