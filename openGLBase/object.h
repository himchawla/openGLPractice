
//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name 	: object.h
// Description	: Class to make shapes and add texturing
// Author 		: Himanshu Chawla
// Mail 		: Himanshu.Cha8420
//
//Local Includes


#pragma once

#include<glew.h>
#include<freeglut.h>
#include<iostream>
#include "ShaderLoader.h"
#include<vector>


class object
{
private:

	

public:
	void setActiveTexure(GLuint Program, int x, std::string name, GLuint tex);
	void genBuffers(bool b);
	void genBuffers(GLuint indices[], GLuint vertices[]);
	std::vector<GLuint> textures;
	void deleteBuffers();
	void imageLoader(std::string im, GLuint& TexNum);

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;


	object();
	~object();
};

