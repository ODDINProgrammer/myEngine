#include <rend/rend.h>
#include <string>
#include <SDL2/SDL.h>
#include <sr1/memory>

#include "Component.h"
/**
  * Renderer Class
  * This class has an access to public members of Component.
  * It handles the openGL for creating a shape out of mesh data and puting textures on that object.
  * Also has functions for setting rotation and object possition.
  */
class legendaryRenderer : public Component
{
private:
	std::string model_source_Path;///< A string that stores path to mesh 
	char const * texture_source_Path;///< A string that stores path to texture 
	glm::vec3 object_Transform;///< Vector for storing object' position
	float rotationAngle;/// < float for storing object' rotation angle
	bool rotateConstantly;/// < boolea, which is used to determine, if object is spinning or not

	std::sr1::shared_ptr<rend::Context> Context; ///< Context pointer
	std::sr1::shared_ptr<rend::Mesh> Mesh;///< Mesh pointer
	std::sr1::shared_ptr<rend::Shader> Shader;///< Shader pointer
	std::sr1::shared_ptr<rend::Texture> Texture; ///< Texture pointer
public:
	void onDisplay();
	/**
	  * \breif Defines an object using path to the mesh file.
	  */
	void SetModel(std::string _model_source_path);
	/**
	  * \breif Puts texture on object using path to the texture file.
	  */
	void SetTexture(char const * _texture_source_path);
	/**
	  * \breif Sets position and rotation, and defines if object is spinning or not.
	  */
	void SetModelSettings(glm::vec3 _mod_Transform, float _rotation);
	/**
	  * \breif Sets corresponsible boolean to determine spinning.
	  */
	void RotateConstantly() { rotateConstantly = true; }
};