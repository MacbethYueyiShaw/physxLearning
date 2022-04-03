#ifndef RENDER_H
#define RENDER_H

#include <glad/glad.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <imgui.h>
#include <backends/imgui_impl_sdl.h>
#include <backends/imgui_impl_opengl3.h>
#include <stb_image.h>
#include "PxPhysicsAPI.h"
#include <memory>
int testImgui();

namespace Render {
	class SDLRender {
	public:
		SDLRender();
		SDLRender(const char* name);
		~SDLRender();
		int setupDefaultWindow(const char* name);
		void setupDefaultRenderState();

		void startRender(const physx::PxVec3& cameraEye, const physx::PxVec3& cameraDir, physx::PxReal nearClip = 1.f, physx::PxReal farClip = 10000.f);
		void finishRender();
		void renderActors(physx::PxRigidActor** actors, const physx::PxU32 numActors, bool shadows, const physx::PxVec3& color , TriggerRender* cb );
		//	void renderGeoms(const physx::PxU32 nbGeoms, const physx::PxGeometry* geoms, const physx::PxTransform* poses, bool shadows, const physx::PxVec3& color);
		void renderGeoms(const physx::PxU32 nbGeoms, const physx::PxGeometryHolder* geoms, const physx::PxTransform* poses, bool shadows, const physx::PxVec3& color);
	private:
		SDL_Window* window;
		SDL_GLContext context;
	};
	

	class TriggerRender
	{
	public:
		virtual	bool isTrigger(physx::PxShape*)	const = 0;
	};
}
#endif // !RENDER_H
