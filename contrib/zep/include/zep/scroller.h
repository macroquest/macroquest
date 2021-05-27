
#pragma once

#include "splits.h"
#include "editor.h"
#include "zep/mcommon/animation/timer.h"

namespace Zep
{
class ZepTheme;
class ZepEditor;

class Scroller : public ZepComponent
{
public:
    Scroller(ZepEditor& editor, Region& parent);

    virtual void Display(ZepTheme& theme);
    virtual void Notify(std::shared_ptr<ZepMessage> message) override;
    virtual void DispatchMouseEvent(std::shared_ptr<ZepMessage> message) override;

    std::shared_ptr<Region> GetRegion() const { return m_region; }
    std::shared_ptr<Region> GetTopButtonRegion() const { return m_topButtonRegion; }
    std::shared_ptr<Region> GetBottomButtonRegion() const { return m_bottomButtonRegion; }

    enum class ScrollState
    {
        None,
        ScrollDown,
        ScrollUp,
        PageUp,
        PageDown,
        Drag
    };
    ScrollState GetState() const { return m_scrollState; }
    NRectf ThumbRect() const;

    float vScrollVisiblePercent = 1.0f;
    float vScrollPosition = 0.0f;
    float vScrollLinePercent = 0.0f;
    float vScrollPagePercent = 0.0f;
    bool vertical = true;

private:
    void CheckState();
    void ClickUp();
    void ClickDown();
    void PageUp();
    void PageDown();
    void DoMove(NVec2f pos);

    float ThumbSize() const;
    float ThumbExtra() const;

private:
    std::shared_ptr<Region> m_region;
    std::shared_ptr<Region> m_topButtonRegion;
    std::shared_ptr<Region> m_bottomButtonRegion;
    std::shared_ptr<Region> m_mainRegion;
    timer m_start_delay_timer;
    timer m_reclick_timer;
    ScrollState m_scrollState = ScrollState::None;
    NVec2f m_mouseDownPos;
    float m_mouseDownPercent;
};

}; // namespace Zep
