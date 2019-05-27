#ifndef AE_GPURAYTRACINGRENDERER_H
#define AE_GPURAYTRACINGRENDERER_H

#include "../System.h"
#include "Renderer.h"

#include <unordered_map>

namespace Atlas {

	namespace Renderer {

		class GPURayTracingRenderer : public Renderer {

		public:
			GPURayTracingRenderer();

			virtual void Render(Viewport* viewport, RenderTarget* target, Camera* camera, Scene::Scene* scene);

			void Render(Viewport* viewport, Texture::Texture2D* texture, Camera* camera, Scene::Scene* scene);

			static std::string vertexUpdateComputePath;
			static std::string BVHComputePath;
			static std::string rayCasterComputePath;

		private:
			void GetVertexUpdateUniforms();
			void GetBVHUniforms();
			void GetRayCasterUniforms();

			bool UpdateGPUData(Scene::Scene* scene);

			struct GPUTriangle {
				vec4 v0;
				vec4 v1;
				vec4 v2;
				vec4 n0;
				vec4 n1;
				vec4 n2;
			};

			struct GPUMaterial {
				vec4 diffuseColor;

				float specularHardness;
				float specularIntensity;
			};

			int32_t workGroupLimit;
			int32_t shaderStorageLimit;

			Buffer::Buffer triangleBuffer;
			Buffer::Buffer materialBuffer;
			Buffer::Buffer materialIndicesBuffer;

			Shader::Shader vertexUpdateShader;

			Shader::Uniform* modelMatrixVertexUpdateUniform = nullptr;
			Shader::Uniform* triangleOffsetVertexUpdateUniform = nullptr;
			Shader::Uniform* triangleCountVertexUpdateUniform = nullptr;
			Shader::Uniform* xInvocationsVertexUpdateUniform = nullptr;

			Shader::Shader BVHShader;


			Shader::Shader rayCasterShader;

			Shader::Uniform* widthRayCasterUniform = nullptr;
			Shader::Uniform* heightRayCasterUniform = nullptr;
			Shader::Uniform* originRayCasterUniform = nullptr;
			Shader::Uniform* rightRayCasterUniform = nullptr;
			Shader::Uniform* bottomRayCasterUniform = nullptr;
			Shader::Uniform* cameraLocationRayCasterUniform = nullptr;
			Shader::Uniform* cameraFarPlaneRayCasterUniform = nullptr;
			Shader::Uniform* cameraNearPlaneRayCasterUniform = nullptr;
			Shader::Uniform* triangleCountRayCasterUniform = nullptr;
			Shader::Uniform* lightDirectionRayCasterUniform = nullptr;
			Shader::Uniform* lightColorRayCasterUniform = nullptr;
			Shader::Uniform* lightAmbientRayCasterUniform = nullptr;

		};

	}

}

#endif