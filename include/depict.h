
#pragma once

#ifndef DEPICT_H
#define DEPICT_H 

#define SDL


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





namespace depict {
	
	
	
void init_window(unsigned int width, unsigned int height, std::string title);
void window_should_close();
void close_window();

}

#endif
 
