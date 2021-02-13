#include<glew.h>
#include<freeglut.h>
#include<iostream>
#include "ShaderLoader.h"
#include "object.h"
#include "Camera.h"
#include <string>
#include<vector>



GLuint Indices_Quad[] =
{
   0,1,2,
   0,2,3,
};


GLfloat Vertices_Quad[] =
{
	//Position						//Color						//Texture Coordinates
	-0.4f,	0.4f,	0.0f,			1.0f,0.0f,0.0f,				0.0f,0.0f,
	-0.4f,	-0.4f,	0.0f,			0.0f,1.0f,0.0f,				0.0f,1.0f,
	 0.4f,	-0.4f,	0.0f,			0.0f,0.0f,1.0f,				1.0f,1.0f,
	 0.4f,	 0.4f,	0.0f,			1.0f,1.0f,1.0f,				1.0f,0.0f,
};


void renderCall(object& obj, GLuint& program, glm::mat4 fm, GLuint indices[], GLuint vertices[], int num, std::vector<GLuint> textures, int index)
{
	glUseProgram(program);

	obj.genBuffers(indices, vertices);

	if(obj.textures.size() >= index)
		obj.setActiveTexure(program, 0, "ImageTexture", obj.textures.at(index));


	glUniformMatrix4fv((glGetUniformLocation(program, "finalMat")), 1, GL_FALSE, glm::value_ptr(fm));

	glBindVertexArray(obj.VAO);
	glDrawElements(GL_TRIANGLES, num, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	glUseProgram(0);
}


void Render()
{
	glClear(GL_COLOR_BUFFER_BIT);


	glutSwapBuffers();
}

void Update()
{
	
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(800, 800);
	glutCreateWindow("OpenGL Project");

	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW initialisation has failed. Terminating. ";
		return 0;
	}

	glutDisplayFunc(Render);
	glutIdleFunc(Update);
	glutMainLoop();

	return 0;
}