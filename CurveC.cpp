/*////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
   _____                             
  / ____|                            
 | |         ___ _   _ _ ____   _____ 
 | |        / __| | | | '__\ \ / / _ \
 | |____   | (__| |_| | |   \ V /  __/
  \_____|   \___|\__,_|_|    \_/ \___|
                                    
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////*/



#include <stdio.h>
#include <GL/glut.h>

const double LINE_SIZE = 0.01;

void askForNumber(int &num){
  printf("Please, introduce the size of the C-curve: ");
  scanf("%d", &num);
}

void glDrawLine(double fromX, double fromY, double toX, double toY){
  printf("LINE: %f, %f - %f, %f\n", fromX, fromY, toX, toY);
  glBegin( GL_LINES);
    glVertex3d( fromX, fromY, 0);
    glVertex3d( toX, toY, 0);
  glEnd();
}

/*----------------------------------
Turtle to control the position
----------------------------------*/
enum Direction{Right, Up, Left, Down};

struct Turtle {
  void advance();
  void setPosition(double x, double y, Direction direction);
  void turnClockwise();
  void turnCounterclockwise();

  private:
    double turtleX, turtleY;
    Direction turtleDirection;
};

void Turtle::advance(){
  switch (turtleDirection){
  case Right:
    glDrawLine(turtleX, turtleY, turtleX + LINE_SIZE, turtleY);
    turtleX += LINE_SIZE;
    break;
  case Up:
    glDrawLine(turtleX, turtleY, turtleX, turtleY + LINE_SIZE);
    turtleY += LINE_SIZE;
    break;
  case Left:
    glDrawLine(turtleX, turtleY, turtleX - LINE_SIZE, turtleY);
    turtleX -= LINE_SIZE;
    break;
  case Down:
    glDrawLine(turtleX, turtleY, turtleX, turtleY - LINE_SIZE);
    turtleY -= LINE_SIZE;
    break;
  }
}

void Turtle::setPosition(double x, double y, Direction direction){
  turtleX = x;
  turtleY = y;
  turtleDirection = direction;
}

void Turtle::turnClockwise(){
  int newDirection = (turtleDirection - 1 + 4) % 4;
  turtleDirection = Direction(newDirection);
}

void Turtle::turnCounterclockwise(){
  int newDirection = (turtleDirection +1) % 4;
  turtleDirection = Direction(newDirection);
}


/*----------------------------------
C Curve main drawing method
----------------------------------*/
void drawCurve(int curveSize, Turtle &turtle){
  if(curveSize == 0){
    turtle.advance();
  }
  else if(curveSize > 0){
    drawCurve(curveSize - 1, turtle);
    turtle.turnClockwise();
    drawCurve(curveSize - 1, turtle);
    turtle.turnCounterclockwise();
  }
}


/*----------------------------------
OpenGL starting method
----------------------------------*/
void display(){
  Turtle turtle;
  turtle.setPosition(0, 0, Right);
  int curveSize = 0;
  askForNumber(curveSize);

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
  glClear(GL_COLOR_BUFFER_BIT);         

  drawCurve(curveSize, turtle);
  glFlush();  
}


int main(int argc, char** argv){
  glutInit(&argc, argv);              
  glutCreateWindow("Levy's C-Curve"); 
  glutReshapeWindow(1600, 1000);
  glutDisplayFunc(display); 
  glutMainLoop();           

  return 0;
}
