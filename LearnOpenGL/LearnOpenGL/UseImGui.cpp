//
//  UseImGui.cpp
//  LearnOpenGL
//
//  Created by William Clinton on 18/09/2022.
//

#include "LightValues.h"
#include "UseImGui.hpp"
#include "iostream"


void UseImGui::Init(GLFWwindow* window, const char* glsl_version) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    ImGui::StyleColorsDark();
}

void UseImGui::NewFrame() {
    // feed inputs to dear imgui, start new frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}


void render_Light(LightValues lightValues)
{
    //Background Color
    float* lightValue = lightValues.GetBackgroundColor();
    ImGui::ColorEdit3("Background", lightValue);
    lightValues.SetBackgroundColor(lightValue);

    //directional light
    
    float lightIntensity = lightValues.GetDirAmbIntensity();
    ImGui::SliderFloat("Dir Ambient", &lightIntensity, 0, 1 );
    lightValues.SetDirAmbIntensity(lightIntensity);
    
    lightIntensity = lightValues.GetDirDiffIntensity();
    ImGui::SliderFloat("Dir Diffuse", &lightIntensity, 0, 1 );
    lightValues.SetDirDiffIntensity(lightIntensity);

//    for(int i = 0; i < 4; i++){
//        std::string colorName = "Color ";
//        colorName += std::to_string(i);
//
//        ImGui::ColorEdit3(colorName.c_str(), pointLightColorValues[i]);
//        pointLightColors[i] = glm::vec3( pointLightColorValues[i][0],  pointLightColorValues[i][1],  pointLightColorValues[i][2]);
//
//        std::string colorIntensity = colorName + " Intensity";
//        ImGui::SliderFloat(colorIntensity.c_str(), &pointLightIntensity[i], -1, 1);
//    }

    //flash light
    
    lightIntensity = lightValues.GetSpotLightAmbIntensity();
    ImGui::SliderFloat("SpotLight Ambient", &lightIntensity, 0, 1 );
    lightValues.SetSpotLightAmbIntensity(lightIntensity);
    
    lightIntensity = lightValues.GetSpotLightDiffIntensity();
    ImGui::SliderFloat("SpotLight Diffuse", &lightIntensity, 0, 1 );
    lightValues.SetSpotLightDiffIntensity(lightIntensity);
}

void UseImGui::Update(LightValues lightValues) {
    ImGui::Begin("Controls");
    render_Light(lightValues);
    ImGui::End();
}

void UseImGui::Render() {
    // Render dear imgui into screen
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UseImGui::Shutdown() {
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
