# Depict Engine
<p align="center">
    <img src="./logo/logo.png" alt="Depict" width="1000"/>
</p>
<p align="center">
    <img src="./logo/cpp.png" alt="C++" width="50"/>
    <img src="./logo/opengl.svg" alt="OpenGL" width="150"/>
</p>



**Depict** is a  C++ OpenGL Graphics Engine (c) Jukka Maatta

[Latest Version 1.20.6](https://github.com/jsmaatta/DepictEngine)

Features
--------
- Supports **MacOS**
- Made in C++
- GPU support with OpenGL **4.1**
- Supports GPU instancing
- Built as a static library for ease of use

Dependencies
------------
- [SDL2](https://www.libsdl.org/) or [GLFW](https://github.com/glfw/glfw) support
- OpenGL Mathematics ([GLM](https://github.com/g-truc/glm))
- [STB_image](https://github.com/nothings/stb)
- Open Asset Import Library ([ASSIMP](https://github.com/assimp/assimp))

Ease of use
-----------

```
#include "depict.h"
#include "depictmath.h"

using namespace depict;

int main() {

    // Code here

    return 0;
}
```

[//]: # "
int main() {

    unsigned int WIDTH =  800;
    unsigned int HEIGHT = 600;

    init_window(WIDTH, HEIGHT, 'Depict Engine - basic window');
    while (!window_should_close())
    {
			// Code here
    }
    close_window();   
    return 0;
}

"



Made by  **Jukka Maatta** 2018-2020

[//]: # "[www.kuvaus.org](https://www.kuvaus.org)"
