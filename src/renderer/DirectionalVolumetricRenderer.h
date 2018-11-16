#ifndef DIRECTIONALVOLUMETRICRENDERER_H
#define DIRECTIONALVOLUMETRICRENDERER_H

#include "../System.h"
#include "IRenderer.h"

class DirectionalVolumetricRenderer : public IRenderer{

public:
    DirectionalVolumetricRenderer(const char* volumetricVertex, const char* volumetricFragment,
            const char* bilateralBlurVertex, const char* bilateralBlurFragmet);

    virtual void Render(Window* window, RenderTarget* target, Camera* camera, Scene* scene, bool masterRenderer = false);

private:
    void GetVolumetricUniforms();
    void GetBilateralBlurUniforms();

    Framebuffer* framebuffer;

    Shader* volumetricShader;
    Shader* bilateralBlurShader;

    // Volumetric shader uniforms
    Uniform* depthTexture;
    Uniform* shadowTexture;
    Uniform* lightDirection;
    Uniform* inverseProjectionMatrix;
    Uniform* sampleCount;
	Uniform* framebufferResolution;

    Uniform* shadowCascadeCount;

    struct ShadowCascadeUniform {
        Uniform* distance;
        Uniform* lightSpace;
    }cascades[MAX_SHADOW_CASCADE_COUNT];

    // Bilateral blur shader uniforms
    Uniform* diffuseTexture;
    Uniform* blurDirection;
    Uniform* offsets;
    Uniform* weights;
    Uniform* kernelSize;

};

#endif