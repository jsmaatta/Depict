
#pragma once

#ifndef DEPICT_H
#define DEPICT_H 

#define SDL  
//#define NOLIB

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
#include <tuple>
//multithreading
#include <thread>
#include <future>

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

	enum Keys
	{
		KEY_UP,
		KEY_DOWN,
		KEY_LEFT,
		KEY_RIGHT,
		KEY_W,
		KEY_S,
		KEY_A,
		KEY_D,
		KEY_C,
		KEY_ESCAPE
	};

namespace depict {



/////////////////////////////////////////////FUNCTIONS////////////////////////////////////////////////
void init_window(unsigned int width, unsigned int height, std::string title ="");
void clear_window(Color color = BLACK);
void update_window();
bool window_should_close();
void close_window(); 
void copyright();
double get_time(); 
bool is_key_down(Keys KEY);
std::tuple<float,float> get_mouse_position(bool lock_mouse=false);
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
    vec3 position;
    vec3 front;
    vec3 up;
    vec3 right;
    vec3 world_up;
    GLfloat yaw;
    GLfloat pitch;
    GLfloat movement_speed;
    GLfloat mouse_sensitivity;
    GLfloat zoom;

    Camera(vec3 position = vec3(0.0f, 0.0f, 0.0f), vec3 up = vec3(0.0f, 1.0f, 0.0f), GLfloat yaw = YAW, GLfloat pitch = PITCH);
    Camera(GLfloat pos_x, GLfloat pos_y, GLfloat pos_z, GLfloat up_x, GLfloat up_y, GLfloat up_z, GLfloat yaw, GLfloat pitch);
    ~Camera();
    mat4 get_view_matrix();
    void process_keyboard(Camera_Movement direction, GLfloat delta_time);
    void process_mouse_movement(GLfloat xoffset, GLfloat yoffset, GLboolean constrain_pitch = true);
    void process_mouse_scroll(GLfloat yoffset);
private:
    void update_camera_vectors();
};
/////////////////////////////////////////////CAMERA////////////////////////////////////////////////

 

/////////////////////////////////////////////SHADER////////////////////////////////////////////////
struct Shader
{ 
    GLuint ID;
    std::string name;
    Shader();
    Shader(const GLchar* vertex_path, const GLchar* fragment_path, const GLchar* geometry_path = nullptr);
    // Uses the current shader
    void use();
    void un_use();

   // utility uniform functions
    void bind_attribute(GLint attribute, const std::string& variable_name) const;

    void set(const std::string &name, bool value) const;
    void set(const std::string &name, int value) const;
    void set(const std::string &name, float value) const;
    void set(const std::string &name, Color color) const; 
    void set(const std::string &name, vec3 value) const;
    void set(const std::string &name, vec4 value) const;
    void set(const std::string &name, mat4 matrix) const;

private:
    void check_compile_errors(GLuint shader, std::string type);
};

Shader load_shader(std::string name, const GLchar* vertex_path, const GLchar* fragment_path, const GLchar* geometry_path = nullptr);
Shader get_shader(std::string name);
void clear_shaders();
std::map<std::string, Shader> get_shaders();
/////////////////////////////////////////////SHADER////////////////////////////////////////////////



/////////////////////////////////////////////TEXTURE////////////////////////////////////////////////
struct Texture {
    GLuint id;
    std::string type;
    std::string path; 
	//aiString path;

    GLuint width, height; 
    GLuint internal_format;
    GLuint image_format;

    GLuint wrap_s;
    GLuint wrap_t;
    GLuint filter_min;
    GLuint filter_max;
    Texture();
    void generate(GLuint width, GLuint height, unsigned char* image);
    void bind() const;

};

Texture load_texture_from_file(const GLchar *file, GLboolean alpha, GLboolean gamma, GLboolean flip);
GLuint texture_from_file(const char *path, const std::string &directory, bool gamma = false, bool alpha = false, bool flip = false);

static std::map<std::string, Texture> Textures;

Texture load_texture(const GLchar *file, GLboolean alpha, GLboolean flip, std::string name);
Texture get_texture(std::string name);
void clear_textures();
/////////////////////////////////////////////TEXTURE////////////////////////////////////////////////



/////////////////////////////////////////////MODEL////////////////////////////////////////////////
struct Vertex { 
    vec3 position; 
    vec3 normal; 
    vec2 tex_coords; 
    vec3 tangent; 
    vec3 bitangent; 
    vec4 color;
};

struct Mesh { 
    Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures= {Texture()}); 
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<Texture> textures;
    GLuint VAO;

    ~Mesh();

    void draw(Shader our_shader, int number);

    private: 
        GLuint VBO, EBO; 
        void setup_mesh();

};

struct Model 
{ 
    std::vector<Texture> textures_loaded;    
    std::vector<Mesh> meshes;
    std::string directory;
    bool gamma_correction;

    Model(std::string const &file_name, bool gamma = false);// : gamma_correction(gamma);

    ~Model();

    void draw(Shader our_shader, int number);

    private: 
        void load_model(std::string const &file_name);
        template <typename N, typename S>
        void process_node(N *node,    S *scene);
        template <typename M, typename S>
        Mesh process_mesh(M *mesh,    S *scene);
        template <typename MA, typename TT>
        std::vector<Texture> load_material_textures(MA *mat, TT type, std::string type_name);
};
Model* load_model( std::string name, std::string const &file_name, bool gamma = false);
Model* get_model(std::string name);   
void clear_models();
/////////////////////////////////////////////MODEL////////////////////////////////////////////////
    


/////////////////////////////////////////////ENTITY////////////////////////////////////////////////
struct Entity {

	Entity(Model* model, vec3 position = vec3(0.0f, 0.0f, 0.0f), vec3 rotation = vec3(0.0f, 0.0f, 0.0f), vec3 scale = vec3(1.0f, 1.0f, 1.0f));
	Entity(Mesh* mesh, vec3 position = vec3(0.0f, 0.0f, 0.0f), vec3 rotation = vec3(0.0f, 0.0f, 0.0f), vec3 scale = vec3(1.0f, 1.0f, 1.0f));
	Entity(std::string const &file_name, vec3 position = vec3(0.0f, 0.0f, 0.0f), vec3 rotation = vec3(0.0f, 0.0f, 0.0f), vec3 scale = vec3(1.0f, 1.0f, 1.0f));
	~Entity();
	Model* model;
	Mesh* mesh;
	vec3 position;
	vec3 rotation;
	vec3 scale;
    struct  Buffer_Data
      {
        mat4 model_matrix;  
        vec4 model_color;  
        vec3 model_position;        
      };
    void draw(Shader our_shader,  int number = 1);
    void draw(Shader our_shader, mat4 matrix,  int number = 1);
    void create_instances(Buffer_Data* buffer_datas, int amount);
    void create_instances(Buffer_Data* buffer_datas, int amount, unsigned int buffer);
};
/////////////////////////////////////////////ENTITY////////////////////////////////////////////////



/////////////////////////////////////////////SHAPES////////////////////////////////////////////////
enum Shape {CUBE, ICO, SPHERE, QUAD, TRIANGLE, RIGHT_TRIANGLE, TETRA, PYRAMID};
Entity* shape(Shape type,bool flat=true, int recursion_level = 1,
	           vec3 position = vec3(0.0f, 0.0f, 0.0f),
	           vec3 rotation = vec3(0.0f, 0.0f, 0.0f),
	           vec3 scale = vec3(1.0f, 1.0f, 1.0f));
/////////////////////////////////////////////SHAPES////////////////////////////////////////////////










}

#endif
 
