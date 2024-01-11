#ifdef HELLOIMGUI_HAS_VULKAN
#include "rendering_vulkan.h"
#include "hello_imgui/hello_imgui.h"


namespace HelloImGui
{
    VulkanGlobals& GetVulkanGlobals()
    {
        static VulkanGlobals sVulkanGlobals;
        return sVulkanGlobals;
    }

    //  Impl of RenderingCallbacks_Impl_SwapBuffers
    void SwapVulkanBuffers()
    {
        auto & gVkGlobals = HelloImGui::GetVulkanGlobals();
        ImGui_ImplVulkanH_Window* wd = &gVkGlobals.ImGuiMainWindowData;

        ImDrawData* main_draw_data = ImGui::GetDrawData();
        const bool main_is_minimized = (main_draw_data->DisplaySize.x <= 0.0f || main_draw_data->DisplaySize.y <= 0.0f);

        // Present Main Platform Window
        if (!main_is_minimized)
            HelloImGui::VulkanSetup::FramePresent(wd);
    }

    RenderingCallbacksPtr PrepareBackendCallbacksCommonVulkan()
    {
        auto callbacks = std::make_shared<RenderingCallbacks>();

        callbacks->Impl_NewFrame_3D = [callbacks]
        {
            auto & gVkGlobals = HelloImGui::GetVulkanGlobals();
            auto window = HelloImGui::GetRunnerParams()->backendPointers.glfwWindow;

            // Resize swap chain?
            if (gVkGlobals.SwapChainRebuild)
            {
                ScreenSize screenSize  = callbacks->Impl_GetFrameBufferSize();
                if (screenSize[0] > 0 && screenSize[0] > 0)
                {
                    ImGui_ImplVulkan_SetMinImageCount(gVkGlobals.MinImageCount);
                    ImGui_ImplVulkanH_CreateOrResizeWindow(gVkGlobals.Instance, gVkGlobals.PhysicalDevice,
                                                           gVkGlobals.Device, &gVkGlobals.ImGuiMainWindowData,
                                                           gVkGlobals.QueueFamily, gVkGlobals.Allocator,
                                                           screenSize[0], screenSize[1],
                                                           gVkGlobals.MinImageCount);
                    gVkGlobals.ImGuiMainWindowData.FrameIndex = 0;
                    gVkGlobals.SwapChainRebuild = false;
                }
            }

            // Start the Dear ImGui frame
            ImGui_ImplVulkan_NewFrame();
            // ImGui_ImplGlfw_NewFrame();
        };

        callbacks->Impl_Frame_3D_ClearColor  = [] (ImVec4) {};

        callbacks->Impl_RenderDrawData_To_3D = []
        {
            auto & gVkGlobals = HelloImGui::GetVulkanGlobals();
            ImGui_ImplVulkanH_Window* wd = &gVkGlobals.ImGuiMainWindowData;
            ImVec4 clear_color = HelloImGui::GetRunnerParams()->imGuiWindowParams.backgroundColor;

            ImDrawData* main_draw_data = ImGui::GetDrawData();
            const bool main_is_minimized = (main_draw_data->DisplaySize.x <= 0.0f || main_draw_data->DisplaySize.y <= 0.0f);
            wd->ClearValue.color.float32[0] = clear_color.x * clear_color.w;
            wd->ClearValue.color.float32[1] = clear_color.y * clear_color.w;
            wd->ClearValue.color.float32[2] = clear_color.z * clear_color.w;
            wd->ClearValue.color.float32[3] = clear_color.w;
            if (!main_is_minimized)
                HelloImGui::VulkanSetup::FrameRender(wd, main_draw_data);
        };


        callbacks->Impl_Shutdown_3D = []
        {
            auto & gVkGlobals = HelloImGui::GetVulkanGlobals();
            VkResult err = vkDeviceWaitIdle(gVkGlobals.Device);
            HelloImGui::VulkanSetup::check_vk_result(err);
            ImGui_ImplVulkan_Shutdown();
            HelloImGui::VulkanSetup::CleanupVulkanWindow();
            HelloImGui::VulkanSetup::CleanupVulkan();
        };

        // callbacks->Impl_ScreenshotRgb_3D     = [] { return ImageBuffer{}; };
        // callbacks->Impl_GetFrameBufferSize;   //= [] { return ScreenSize{0, 0}; };


        return callbacks;
    }

}

#endif // HELLOIMGUI_HAS_VULKAN
