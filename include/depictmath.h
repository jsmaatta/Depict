
#pragma once

#ifndef DEPICTMATH_H
#define DEPICTMATH_H



//glm
#include <glm/glm.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//glm experimental
//#define GLM_ENABLE_EXPERIMENTAL
//#include <glm/gtx/transform.hpp>
//#include <glm/gtx/string_cast.hpp>


//#include <glm/vec.hpp>
//#include <glm/vec2.hpp>
//#include <glm/vec3.hpp>
//#include <glm/vec4.hpp>

//#include <glm/mat2.hpp>
//#include <glm/mat3.hpp>
//#include <glm/mat3x3.hpp>
//#include <glm/mat4x4.hpp>

typedef  glm::vec1 vec1;
typedef  glm::vec2 vec2;
typedef  glm::vec3 vec3;
typedef  glm::vec4 vec4; 
//typedef  glm::mat1 mat1;
typedef  glm::mat2 mat2;
typedef  glm::mat3 mat3;
typedef  glm::mat4 mat4; 



#endif



//#include "header.h"

/*template<typename... Args> 
inline auto own_vec3(Args&&... args)->decltype(glm::vec3(std::forward<Args>(args)...)){
    return glm::vec3(std::forward<Args>(args)...);
}*/

/*class Bar {
 public:
  Bar(int) {}
};
*/

/*template <typename T>
struct own_vec3 {
  typedef glm::vec3;//<T> type;
};*/

//template <>
//constexpr auto own_vec3() = glm::vec3(1,1,1);

//own_vec3 n = static_cast<own_vec3>(x); 
 //class own_vec3 : public glm::vec1 { };