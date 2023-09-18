//
//  LightValues.cpp
//  LearnOpenGL
//
//  Created by William Clinton on 24/09/2022.
//

#include "LightValues.h"

#include <iostream>
#include <stdio.h>

LightValues::LightValues(){
    pointLightColorValues = Create2DArrayFloat(4,4);

    for(int i = 0; i < 4; i++){
        backgroundColor[i] = 0.0f;
        for(int j = 0; j < 4; j++){
            pointLightColorValues[i][j] = 1.0f;
        }
        pointLightIntensity[i] = 1.0f;
        
        dirAmbIntensity = 0.05f;
        dirDiffIntensity =  0.1f;
    
        spotLightAmbIntensity = 0.2f;
        spotLightDiffIntensity =  0.8f;
    }
}

float* LightValues::GetBackgroundColor(){
    return backgroundColor;
}

void LightValues::SetBackgroundColor(float color[4]){
    for(int i = 0; i < 4; i++){
        backgroundColor[i] = color[i];
    }
}

float** LightValues::GetPointLightColorValues(){
    float** arr = new float*[4];
    for(int i = 0; i < 4; i++)
        arr[i] = new float[4];

    for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                arr[i][j] = pointLightColorValues[i][j];
            }
        }
    
    return arr;
}

void LightValues::SetPointLightColorValues(float** colors){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            pointLightColorValues[i][j] = colors[i][j];
        }
    }
}

float* LightValues::GetPointLightIntensity(){
    return pointLightIntensity;
}

void LightValues::SetPointLightIntensity(float* intensity){
    for(int i = 0; i < 4; i++){
        pointLightIntensity[i] = intensity[i];
    }
}

float LightValues::GetDirAmbIntensity(){
    return dirAmbIntensity;
}
void LightValues::SetDirAmbIntensity (float value){
    dirAmbIntensity = value;
}

float LightValues::GetDirDiffIntensity (){
    return dirDiffIntensity;
}
void LightValues::SetDirDiffIntensity (float value){
    dirDiffIntensity = value;
}

float LightValues::GetSpotLightAmbIntensity (){
    return spotLightAmbIntensity;
}
void LightValues::SetSpotLightAmbIntensity (float value){
    spotLightAmbIntensity = value;
}

float LightValues::GetSpotLightDiffIntensity (){
    return spotLightDiffIntensity;
}
void LightValues::SetSpotLightDiffIntensity (float value){
    spotLightDiffIntensity = value;
}

float** LightValues::Create2DArrayFloat(int r, int c){
    float** arr = new float*[r];
    for(int i = 0; i < r; i++)
        arr[i] = new float[c];
    return arr;
}
