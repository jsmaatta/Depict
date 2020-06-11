# Depict Engine 
![Depict](/logo/logo.png)

Depict is a  C++ OpenGL engine (C) Jukka Maatta 2020.

![c++](/logo/cpp.png) ![OpenGL](/logo/opengl.svg)

[Latest Version 1.20.6](https://github.com/jsmaatta/DepictEngine)

Features
--------
	- Supports **MacOS**
	- Made in C++
	- GPU support with OpenGL **4.1**
	- Supports GPU instancing
	- Built in as a static library for ease of use
	
Dependencies
------------
	- [SDL2](https://www.libsdl.org/) or [GLFW](https://github.com/glfw/glfw) support
	- [OpenGL Mathematics (GLM)] (https://github.com/g-truc/glm)
	- [STB_image](https://github.com/nothings/stb)
	- [Open Asset Import Library] (https://github.com/assimp/assimp)
	
Ease of use
-----------

```
#include "depict.h"
#include "depictmath.h"

using namespace depict;

int main() {
	
    unsigned int WIDTH =  800;
    unsigned int HEIGHT = 600;
    
    init_window(WIDTH, HEIGHT, "Depict Engine - basic window");
    
    return 0;
} 
```

Made by  **Jukka Maatta** 2018-2020
[www.kuvaus.org](https://www.kuvaus.org)
