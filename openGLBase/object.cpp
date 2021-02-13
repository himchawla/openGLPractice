
//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name 	: object.cpp
// Description	: Class to make shapes and add texturing
// Author 		: Himanshu Chawla
// Mail 		: Himanshu.Cha8420
//
//Implementation


#include "object.h"
#define STB_IMAGE_IMPLEMENTATION
#include<stb_image.h>




//generate Buffers, called during setup phase
void object::genBuffers(bool b)
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &EBO);
	glGenBuffers(1, &VBO);


}

//Bind Buffers, called once per frame
void object::genBuffers(GLuint indices[], GLuint vertices[])
{
	
	glBindVertexArray(VAO);

	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (GLvoid*)(3 * sizeof(GL_FLOAT)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (GLvoid*)(6 * sizeof(GL_FLOAT)));
	glEnableVertexAttribArray(2);
}


//Generate Buffers for quad, called in setup mode


//Bind buffers for quad, called once per frame


//Delete buffers, called at end of the code
void object::deleteBuffers()
{
	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &VBO);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

}

object::object()
{

}

//Deconstructor
object::~object()
{
	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &VBO);
}

void object::setActiveTexure(GLuint Program, int x, std::string name, GLuint tex)
{
	glActiveTexture(33984 + x);		// GL_TEXTUR0 = 33984
	glBindTexture(GL_TEXTURE_2D, tex);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glUniform1i(glGetUniformLocation(Program, name.c_str()), x);
}


void object::imageLoader(std::string im, GLuint& TexNum)
{
	glGenTextures(1, &TexNum);
	int ImageWidth;
	int ImageHeight;
	int ImageComponents;


	std::string imageString = "Resources/Texture/" + im;


	unsigned char* ImageData = stbi_load(imageString.c_str(), &ImageWidth, &ImageHeight, &ImageComponents, 0);
	GLint LoadedComponents = (ImageComponents == 4) ? GL_RGBA : GL_RGB;

	glTexImage2D(GL_TEXTURE_2D, 0, LoadedComponents, ImageWidth, ImageHeight, 0, LoadedComponents, GL_UNSIGNED_BYTE, ImageData);

//	textures.push_back(TexNum);

	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(ImageData);

	glBindTexture(GL_TEXTURE_2D, TexNum);
	
	textures.push_back(TexNum);
}
