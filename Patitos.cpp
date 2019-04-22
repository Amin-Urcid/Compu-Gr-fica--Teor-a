#include <GL/glut.h>
//#include <stdlib.h>

static int year = 0, day = 0;

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
  glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);


   glPushMatrix();
   glColor3f(1.0, 1.0, 1.0);
   glTranslatef(3.0, 2.0, 0.0);
   glutSolidSphere(0.3, 20, 2);
   glPopMatrix();

   glPushMatrix();
   glColor3f(1.0, 0.0, 0.0);
   glTranslatef(2.0, 2.0, 0.0);
   glutSolidSphere(0.3, 20, 2);
   glPopMatrix();




   /*glPushMatrix();
   glColor3f(1.0, 1.0, 1.0);
   glTranslatef(0.0, -2.0, 0.0);//1 cubo central
   glutSolidCube(1);
   glColor3f(1.0, 0.0, 0.0);
   glTranslatef(1.0, 0.0, 0.0);//2
   glutSolidCube(1);
   glColor3f(1.0, 0.0, 0.0);
   glTranslatef(1.0, 0.0, 0.0);//3
   glutSolidCube(1);
   glColor3f(1.0, 0.0, 0.0);
   glTranslatef(1.0, 0.0, 0.0);//4
   glutSolidCube(1);
   glColor3f(1.0, 0.0, 0.0);
   glTranslatef(0.0, 1.0, 0.0);//5
   glutWireCube(1);
   glColor3f(0.0, 1.0, 0.0);
   glTranslatef(0.0, 1.0, 0.0);//6
   glutWireCube(1);
   glTranslatef(0.0, 1.0, 0.0);//7
   glutWireCube(1);
   glTranslatef(0.0, 1.0, 0.0);//8
   glutWireCube(1);
   glTranslatef(-4.0, -4.0, 0.0); //MITAD DERECHA
   glutSolidCube(1);
   glTranslatef(-1.0, 0.0, 0.0);
   glutSolidCube(1);
   glTranslatef(-1.0, 0.0, 0.0);
   glutSolidCube(1);
   glColor3f(1.0, 1.0, 0.0);
   glTranslatef(0.0, 1.0, 0.0);
   glutWireCube(1);
   glColor3f(1.0, 1.0, 0.0);
   glTranslatef(0.0, 1.0, 0.0);
   glutWireCube(1);
   glColor3f(1.0, 1.0, 0.0);
   glTranslatef(0.0, 1.0, 0.0);
   glutWireCube(1);
   glColor3f(1.0, 1.0, 0.0);
   glTranslatef(0.0, 1.0, 0.0);
   glutWireCube(1);

   glPopMatrix();

   glPushMatrix();
   glutWireSphere(1.0, 20, 16);  //draw sun 
   glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
   glTranslatef (2.0, 0.0, 0.0);
   glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
   glutWireSphere(0.2, 10, 8);    // draw smaller planet 
   glPopMatrix();*/

	
   glutSwapBuffers();
}





void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 'd':
         day = (day + 10) % 360;
         glutPostRedisplay();
         break;
      case 'D':
         day = (day - 10) % 360;
         glutPostRedisplay();
         break;
      case 'y':
         year = (year + 5) % 360;
         glutPostRedisplay();
         break;
      case 'Y':
         year = (year - 5) % 360;
         glutPostRedisplay();
         break;
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (700, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}


