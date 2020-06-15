
#pragma once

#ifndef DEPICT_H
#define DEPICT_H 

#define SDL  

#include <SDL.h>
#include <imgui.h> //optional imgui.h and imconfig.h

#include "depictmath.h"


#include <iostream> 

//c includes just in case
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip> 
#include <memory>
#include <vector> 
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <unordered_map>
#include <cassert> 
#include <ctype.h>
#include <chrono>

#include <utility>
#include <math.h>
#include <algorithm>





/*

STRUCTS:

Color

Camera
Shader

Texture

Vertex
Mesh
Model
Entity

MATH:
vec1, vec2, vec3, vec4
mat2, mat3, mat4
GL float, int, uint, boolean, char

*/

struct Color
{
	float w, x, y, z;
	Color() { x = y = z = w = 0.0f; }
	template<typename A , typename B , typename C , typename D = float >
	Color(A const &_x, B const &_y, C const &_z, D const &_w=255.0f) { x = (float)_x; y = (float)_y; z = (float)_z; w = (float)_w; };

};
  



//color definitions
    #define LIGHTGRAY   Color(200.0f, 200.0f, 200.0f, 255.0f)         // Light Gray
    #define GRAY        Color(130.0f, 130.0f, 130.0f, 255.0f)         // Gray
    #define DARKGRAY    Color(80.0f, 80.0f, 80.0f, 255.0f)            // Dark Gray
    #define YELLOW      Color(253.0f, 249.0f, 0.0f, 255.0f)           // Yellow
    #define RGBYELLOW   Color(255.0f, 255.0f, 0.0f, 255.0f)           // RGB Yellow
    #define GOLD        Color(255.0f, 203.0f, 0.0f, 255.0f)           // Gold
    #define ORANGE      Color(255.0f, 161.0f, 0.0f, 255.0f)           // Orange
    #define PINK        Color(255.0f, 109.0f, 194.0f, 255.0f)         // Pink
    #define RGBRED      Color(255.0f,  0.0f,  0.0f, 255.0f)           // RGB Red
    #define RED         Color(230.0f, 41.0f, 55.0f, 255.0f)           // Red
    #define MAROON      Color(190.0f, 33.0f, 55.0f, 255.0f)           // Maroon
    #define RGBGREEN    Color(0.0f, 255.0f,  0.0f, 255.0f)            // RGB Green
    #define GREEN       Color(0.0f, 228.0f, 48.0f, 255.0f)            // Green
    #define LIME        Color(0.0f, 158.0f, 47.0f, 255.0f)            // Lime
    #define DARKGREEN   Color(0.0f, 117.0f, 44.0f, 255.0f)            // Dark Green
    #define SKYBLUE     Color(102.0f, 191.0f, 255.0f, 255.0f)         // Sky Blue
    #define RGBBLUE     Color(0.0f,   0.0f, 255.0f, 255.0f)           // RGB Blue
    #define BLUE        Color(0.0f, 121.0f, 241.0f, 255.0f)           // Blue
    #define DARKBLUE    Color(0.0f,  82.0f, 172.0f, 255.0f)            // Dark Blue
    #define CYAN        Color(0.0f, 255.0f, 255.0f, 255.0f)           // Cyan
    #define PURPLE      Color(200.0f, 122.0f, 255.0f, 255.0f)         // Purple
    #define MAGENTA     Color(255.0f, 0.0f, 255.0f, 255.0f)           // Magenta
    #define VIOLET      Color(135.0f, 60.0f, 190.0f, 255.0f)          // Violet
    #define DARKPURPLE  Color(112.0f, 31.0f, 126.0f, 255.0f)          // Dark Purple
    #define BEIGE       Color(211.0f, 176.0f, 131.0f, 255.0f)         // Beige
    #define BROWN       Color(127.0f, 106.0f, 79.0f, 255.0f)          // Brown
    #define DARKBROWN   Color(76.0f, 63.0f, 47.0f, 255.0f)            // Dark Brown

    #define WHITE       Color(255.0f, 255.0f, 255.0f, 255.0f)         // White
    #define BLACK       Color(0.0f, 0.0f, 0.0f, 255.0f)               // Black
    #define TRANSPARENT Color(0.0f, 0.0f, 0.0f, 0.0f)                 // Transparent
    #define OFFWHITE    Color(245.0f, 245.0f, 245.0f, 255.0f)         // Off White
    #define LOGOGRAY    Color(55.0f, 55.0f, 55.0f, 255.0f)            // Logo gray
    #define BACKGROUND  Color(50.0f, 62.0f, 80.0f, 255.0f)            // Background



namespace depict {

/////////////////////////////////////////////FUNCTIONS////////////////////////////////////////////////
void init_window(unsigned int width, unsigned int height, std::string title ="");
void clear_window(Color color = BLACK);
void update_window();
bool window_should_close();
void close_window(); 
void copyright();
double get_time(); 
/////////////////////////////////////////////FUNCTIONS////////////////////////////////////////////////



/////////////////////////////////////////////OPENGL////////////////////////////////////////////////
void opengl_gen_buffers(GLuint* buffer);
void opengl_bind_buffers(GLuint buffer);
void opengl_buffer_data(int32_t size, const void * data);
/////////////////////////////////////////////OPENGL////////////////////////////////////////////////



enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// Default camera values
const GLfloat YAW        = -90.0f;
const GLfloat PITCH      =  0.0f;
const GLfloat SPEED      =  3.0f;
const GLfloat SENSITIVITY =  0.25f;
const GLfloat ZOOM       =  45.0f;



/////////////////////////////////////////////CAMERA////////////////////////////////////////////////
struct Camera
{ 
    vec3 Position;
    vec3 Front;
    vec3 Up;
    vec3 Right;
    vec3 WorldUp;
    GLfloat Yaw;
    GLfloat Pitch;
    GLfloat MovementSpeed;
    GLfloat MouseSensitivity;
    GLfloat Zoom;

    Camera(vec3 position = vec3(0.0f, 0.0f, 0.0f), vec3 up = vec3(0.0f, 1.0f, 0.0f), GLfloat yaw = YAW, GLfloat pitch = PITCH);
    Camera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch);
    ~Camera();
    mat4 GetViewMatrix();
    void ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime);
    void ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch = true);
    void ProcessMouseScroll(GLfloat yoffset);
private:
    void updateCameraVectors();
};
/////////////////////////////////////////////CAMERA////////////////////////////////////////////////

 

/////////////////////////////////////////////SHADER////////////////////////////////////////////////
struct Shader
{ 
    GLuint ID;
    std::string name;
    Shader();
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath, const GLchar* geometryPath = nullptr);
    // Uses the current shader
    void use();
    void unUse();

   // utility uniform functions
    void bindAttribute(GLint attribute, const std::string& variableName) const;

    void set(const std::string &name, bool value) const;
    void set(const std::string &name, int value) const;
    void set(const std::string &name, float value) const;
    void set(const std::string &name, Color color) const; 
    void set(const std::string &name, vec3 value) const;
    void set(const std::string &name, vec4 value) const;
    void set(const std::string &name, mat4 matrix) const;

private:
    void checkCompileErrors(GLuint shader, std::string type);
};

Shader LoadShader(std::string name, const GLchar* vertexPath, const GLchar* fragmentPath, const GLchar* geometryPath = nullptr);
Shader GetShader(std::string name);
void ClearShaders();
std::map<std::string, Shader> get_shaders();
/////////////////////////////////////////////SHADER////////////////////////////////////////////////



/////////////////////////////////////////////TEXTURE////////////////////////////////////////////////
struct Texture {
    GLuint id;
    std::string type;
    std::string path; 
	//aiString path;

    GLuint width, height; 
    GLuint internalFormat;
    GLuint imageFormat;

    GLuint wrapS;
    GLuint wrapT;
    GLuint filterMin;
    GLuint filterMax;
    Texture();
    void generate(GLuint width, GLuint height, unsigned char* image);
    void Bind() const;

};

Texture loadTextureFromFile(const GLchar *file, GLboolean alpha, GLboolean gamma, GLboolean flip);
GLuint TextureFromFile(const char *path, const std::string &directory, bool gamma = false, bool alpha = false, bool flip = false);

static std::map<std::string, Texture> Textures;

Texture LoadTexture(const GLchar *file, GLboolean alpha, GLboolean flip, std::string name);
Texture GetTexture(std::string name);
void ClearTextures();
/////////////////////////////////////////////TEXTURE////////////////////////////////////////////////



/////////////////////////////////////////////MODEL////////////////////////////////////////////////
struct Vertex { 
    vec3 Position; 
    vec3 Normal; 
    vec2 TexCoords; 
    vec3 Tangent; 
    vec3 Bitangent; 
    vec4 Color;
};

struct Mesh { 
    Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures= {Texture()}); 
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<Texture> textures;
    GLuint VAO;

    ~Mesh();

    void Draw(Shader ourShader, int number);

    private: 
        GLuint VBO, EBO; 
        void setupMesh();

};

struct Model 
{ 
    std::vector<Texture> textures_loaded;    
    std::vector<Mesh> meshes;
    std::string directory;
    bool gammaCorrection;

    Model(std::string const &fileName, bool gamma = false);// : gammaCorrection(gamma);

    ~Model();

    void Draw(Shader ourShader, int number);

    private: 
        void loadModel(std::string const &fileName);
        template <typename N, typename S>
        void processNode(N *node,    S *scene);
        template <typename M, typename S>
        Mesh processMesh(M *mesh,    S *scene);
        template <typename MA, typename TT>
        std::vector<Texture> loadMaterialTextures(MA *mat, TT type, std::string typeName);
};
Model* LoadModel( std::string name, std::string const &fileName, bool gamma = false);
Model* GetModel(std::string name);   
void ClearModels();
/////////////////////////////////////////////MODEL////////////////////////////////////////////////
    


/////////////////////////////////////////////ENTITY////////////////////////////////////////////////
struct Entity {

	Entity(Model* model, vec3 position = vec3(0.0f, 0.0f, 0.0f), vec3 rotation = vec3(0.0f, 0.0f, 0.0f), vec3 scale = vec3(1.0f, 1.0f, 1.0f));
	Entity(Mesh* mesh, vec3 position = vec3(0.0f, 0.0f, 0.0f), vec3 rotation = vec3(0.0f, 0.0f, 0.0f), vec3 scale = vec3(1.0f, 1.0f, 1.0f));
	Entity(std::string const &fileName, vec3 position = vec3(0.0f, 0.0f, 0.0f), vec3 rotation = vec3(0.0f, 0.0f, 0.0f), vec3 scale = vec3(1.0f, 1.0f, 1.0f));
	~Entity();
	Model* model;
	Mesh* mesh;
	vec3 position;
	vec3 rotation;
	vec3 scale;
    struct  BufferData
      {
        mat4 modelMatrix;  
        vec4 modelColor;  
        vec3 modelPosition;        
      };
    void Draw(Shader ourShader,  int number = 1);
    void Draw(Shader ourShader, mat4 matrix,  int number = 1);
    void CreateInstances(BufferData* bufferdatas, int amount);
    void CreateInstances(BufferData* bufferdatas, int amount, unsigned int buffer);
};
/////////////////////////////////////////////ENTITY////////////////////////////////////////////////



/////////////////////////////////////////////SHAPES////////////////////////////////////////////////
enum Shape {Cube, Ico, Sphere};
Entity* shape(Shape type,bool flat=true, int recursionLevel = 1,
	           vec3 position = vec3(0.0f, 0.0f, 0.0f),
	           vec3 rotation = vec3(0.0f, 0.0f, 0.0f),
	           vec3 scale = vec3(1.0f, 1.0f, 1.0f));
/////////////////////////////////////////////SHAPES////////////////////////////////////////////////










}

#endif
 
