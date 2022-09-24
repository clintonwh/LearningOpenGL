//
//  UseImGui.hpp
//  LearnOpenGL
//
//  Created by William Clinton on 18/09/2022.
//

#ifndef UseImGui_hpp
#define UseImGui_hpp

#include <stdio.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include "LightValues.h"

class UseImGui {
public:
  void Init(GLFWwindow* window, const char* glsl_version);
  void NewFrame();
  virtual void Update(LightValues lightValues);
  void Render();
  void Shutdown();
};

#endif /* UseImGui_hpp */
