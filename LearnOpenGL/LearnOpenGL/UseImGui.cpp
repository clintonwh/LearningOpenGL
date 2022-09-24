//
//  UseImGui.cpp
//  LearnOpenGL
//
//  Created by William Clinton on 18/09/2022.
//

#include "UseImGui.hpp"


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


void render_Light()
{
//    //Background Color
//    ImGui::ColorEdit3("Background", backgroundColor);
//
//    //directional light
//    ImGui::SliderFloat("Dir Ambient", &dirAmbIntensity, 0, 1 );
//    ImGui::SliderFloat("Dir Diffuse", &dirDiffIntensity, 0, 1 );
//
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
//
//    //flash light
//    ImGui::SliderFloat("SpotLight Ambient", &spotLightAmbIntensity, 0, 1 );
//    ImGui::SliderFloat("SpotLight Diffuse", &spotLightDiffIntensity, 0, 1 );
}


void UseImGui::Update() {
    ImGui::Begin("Controls");
    render_Light();
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
