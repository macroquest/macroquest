#ifdef HELLOIMGUI_HAS_METAL
#include "image_metal.h"

#include "imgui.h"
#include "hello_imgui/internal/backend_impls/rendering_metal.h"

namespace HelloImGui
{

    void ImageMetal::_impl_StoreTexture(int width, int height, unsigned char* image_data_rgba)
    {
        auto gMetalGlobals = GetMetalGlobals();

        // Create a MTLTextureDescriptor
        MTLTextureDescriptor* textureDescriptor = [[MTLTextureDescriptor alloc] init];
        textureDescriptor.pixelFormat = MTLPixelFormatRGBA8Unorm; // Adjust as needed
        textureDescriptor.width = width;
        textureDescriptor.height = height;
        textureDescriptor.usage = MTLTextureUsageShaderRead | MTLTextureUsageRenderTarget;

        // Create the texture from the descriptor
        Texture = [gMetalGlobals.mtlDevice newTextureWithDescriptor:textureDescriptor];

        // Upload the image data to the texture
        MTLRegion region = MTLRegionMake2D(0, 0, width, height);
        [Texture replaceRegion:region mipmapLevel:0 withBytes:image_data_rgba bytesPerRow:4 * width];

        [textureDescriptor release];
    }

    ImageMetal::~ImageMetal()
    {
        [Texture release];
    }

    ImTextureID ImageMetal::TextureID()
    {
        return (ImTextureID)Texture;
    }

}

#endif // #ifdef HELLOIMGUI_HAS_VULKAN
