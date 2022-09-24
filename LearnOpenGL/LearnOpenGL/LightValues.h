//
//  LightValues.hpp
//  LearnOpenGL
//
//  Created by William Clinton on 24/09/2022.
//

#ifndef LightValues_h
#define LightValues_h

#include <stdio.h>

class LightValues {
private:
    float backgroundColor[4];
    float** pointLightColorValues;

    float pointLightIntensity[4];

    float dirAmbIntensity;
    float dirDiffIntensity;

    float spotLightAmbIntensity;
    float spotLightDiffIntensity;
    
public:
    LightValues();
    float* GetBackgroundColor();
    void SetBackgroundColor(float color[4]);
    
    float** GetPointLightColorValues();
    void SetPointLightColorValues(float colors[4][4]);
    
    float* GetPointLightIntensity();
    void SetPointLightIntensity(float intensity[4]);
    
    float GetDirAmbIntensity();
    void SetDirAmbIntensity (float value);
    
    float GetDirDiffIntensity();
    void SetDirDiffIntensity (float value);
    
    float GetSpotLightAmbIntensity();
    void SetSpotLightAmbIntensity (float value);
    
    float GetSpotLightDiffIntensity();
    void SetSpotLightDiffIntensity (float value);
};

#endif /* LightValues_hpp */
