#pragma once
#ifdef HELLOIMGUI_USE_GLFW
#include "hello_imgui/internal/backend_impls/abstract_runner.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace HelloImGui
{
class RunnerGlfw3 : public AbstractRunner
{
       public:
        RunnerGlfw3(RunnerParams & runnerParams);
        virtual ~RunnerGlfw3() = default;

       protected:
        //
        // Methods related to the platform backend (SDL, Glfw, ...)
        //
        void Impl_InitPlatformBackend() override;
        void Impl_CreateWindow() override;
        void Impl_PollEvents() override;
        void Impl_NewFrame_PlatformBackend() override;
        void Impl_UpdateAndRenderAdditionalPlatformWindows() override;
        void Impl_Cleanup() override;
        void Impl_SwapBuffers() override;
        void Impl_SetWindowIcon() override;

        //
        // Linking the platform backend (SDL, Glfw, ...) to the rendering backend (OpenGL, ...)
        //
        void Impl_LinkPlatformAndRenderBackends() override;
        // Specific to OpenGL
        #ifdef HELLOIMGUI_HAS_OPENGL
            void Impl_Select_Gl_Version() override;
            std::string Impl_GlslVersion() override;
            void Impl_CreateGlContext() override;
            void Impl_InitGlLoader() override;
        #endif

        //
        // Rendering backend (OpenGL, ...): Impl_InitRenderBackendCallbacks will fill the callbacks
        //
        void Impl_InitRenderBackendCallbacks() override;


};

}  // namespace HelloImGui
#endif  // #ifdef HELLOIMGUI_USE_GLFW
