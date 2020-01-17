#define STB_IMAGE_IMPLEMENTATION

#include "MyRenderer.h"
#include "Core.h"
#include "stb_image.h"
#include <iostream>
#include <fstream>

using namespace rend;

//Shader program
const char* Source =
"#ifdef VERTEX                                 \n" \
"                                              \n" \
"attribute vec3 a_Position;                    \n" \
"attribute vec2 a_TexCoord;                    \n" \
"attribute vec3 a_Normal;                      \n" \
"                                              \n" \
"uniform mat4 u_Projection;                    \n" \
"uniform mat4 u_Model;                         \n" \
"                                              \n" \
"varying vec3 v_Normal;                        \n" \
"varying vec2 v_TexCoord;                      \n" \
"                                              \n" \
"void main()                                   \n" \
"{                                             \n" \
"  gl_Position = u_Projection *                \n" \
"    u_Model * vec4(a_Position, 1);            \n" \
"                                              \n" \
"  v_Normal = a_Normal;                        \n" \
"  v_TexCoord = a_TexCoord;                    \n" \
"}                                             \n" \
"                                              \n" \
"#endif                                        \n" \
"#ifdef FRAGMENT                               \n" \
"                                              \n" \
"uniform sampler2D u_Texture;                  \n" \
"                                              \n" \
"varying vec3 v_Normal;                        \n" \
"varying vec2 v_TexCoord;                      \n" \
"                                              \n" \
"void main()                                   \n" \
"{                                             \n" \
"  gl_FragColor = texture2D(u_Texture, v_TexCoord);      \n" \
"  if(gl_FragColor.x == 9) gl_FragColor.x = v_Normal.x;  \n" \
"}                                             \n" \
"                                              \n" \
"#endif                                        \n";



//Displaying object
void legendaryRenderer::onDisplay()
{
	Shader->setUniform("u_Projection", perspective(radians(65.0f), 1.0f, 0.1f, 100.0f));
	if (rotateConstantly)
	{
		Shader->setUniform("u_Model",
			translate(glm::mat4(1.0f), object_Transform) *
			rotate(glm::mat4(1.0f), rotationAngle += 0.2f, vec3(0, 1, 0))
		);
	}
	else
	{
		Shader->setUniform("u_Model",
			translate(glm::mat4(1.0f), object_Transform) *
			rotate(glm::mat4(1.0f), rotationAngle, vec3(0, 1, 0))
		);
	}
	Shader->setMesh(Mesh);
	Shader->render();
}

//Store object position and rotation, and if it should rotate constantly 
void legendaryRenderer::SetModelSettings(vec3 _mod_Transform, float _rotation)
{
	object_Transform = _mod_Transform;
	rotationAngle = _rotation;
	int r = rand() % 101;
	//Set rotateConstatly to true, if we scored more than 50
	if (r > 66)
		RotateConstantly();

}

//Find a mesh for the object 
void legendaryRenderer::SetModel(std::string  _model_path)
{
	//Store path to mesh file
	model_source_Path = _model_path;
	Context = getCore()->getContext();
	Shader = Context->createShader();
	Shader->parse(Source);
	Mesh = Context->createMesh();

	//Open file for reading 
	std::ifstream f(model_source_Path);
	//Check if we cannot find model route directory
	if (!f.is_open())
	{
		throw Exception("Failed to open model");
	}

	std::string obj;
	std::string line;

	//Reading through mesh file, to get verticies of object
	while (!f.eof())
	{
		std::getline(f, line);
		obj += line + "\n";
	}
	//When file is read, create mesh out of stored verticies 
	Mesh->parse(obj);
}

//Setting texture 
void legendaryRenderer::SetTexture(char const *_texture_path)
{
	texture_source_Path = _texture_path;
	Texture = Context->createTexture();
	int w = 0;
	int h = 0;
	int bpp = 0;
	unsigned char *data = stbi_load(_texture_path,
		&w, &h, &bpp, 3);

	if (!data)
	{
		throw Exception("Failed to open image");
	}

	Texture->setSize(w, h);

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int r = y * w * 3 + x * 3;

			Texture->setPixel(x, y, vec3(
				data[r] / 255.0f,
				data[r + 1] / 255.0f,
				data[r + 2] / 255.0f));
		}
	}
	stbi_image_free(data);
	Mesh->setTexture("u_Texture", Texture);
}


