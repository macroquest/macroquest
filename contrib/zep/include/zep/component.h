#pragma once

#define ZEP_UNUSED(var) (void)var;

namespace Zep
{
class ZepMessage;
class ZepEditor;

struct IZepComponent
{
    virtual void Notify(std::shared_ptr<ZepMessage> message) { ZEP_UNUSED(message); };
    virtual void DispatchMouseEvent(std::shared_ptr<ZepMessage> message) { ZEP_UNUSED(message); }
    virtual ZepEditor& GetEditor() const = 0;
};

} // namespace Zep
