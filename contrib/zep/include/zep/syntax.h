#pragma once

#include "buffer.h"

#include <atomic>
#include <future>
#include <memory>
#include <unordered_set>
#include <vector>

#include "zep/mcommon/animation/timer.h"
#include "zep/mcommon/math/math.h"

namespace Zep {

enum class ThemeColor;

struct CommentEntry
{
    bool isStart;
    bool isMultiLine;
    uint32_t location;
    uint32_t entries;
};

namespace ZepSyntaxFlags
{
    enum
    {
        CaseInsensitive = (1 << 0),
        IgnoreLineHighlight = (1 << 1),
        LispLike = (1 << 2)
    };
};

struct SyntaxData
{
    ThemeColor foreground = ThemeColor::Normal;
    ThemeColor background = ThemeColor::None;
};

struct SyntaxResult : SyntaxData
{
    uint32_t customBackgroundColor;
    uint32_t customForegroundColor;
};

class ZepSyntax : public ZepComponent
{
public:
    ZepSyntax(ZepBuffer& buffer)
        : ZepComponent(buffer.GetEditor())
        , m_buffer(buffer)
    {
    }

    virtual ~ZepSyntax()
    {
    }

    virtual SyntaxResult GetSyntaxAt(const GlyphIterator& index) const = 0;

    const uint32_t ToBackgroundColor(const SyntaxResult& res) const
    {
        if (res.background == ThemeColor::Custom)
        {
            return res.customBackgroundColor;
        }
        else
        {
            return m_buffer.GetTheme().GetColor(res.background);
        }
    }

    virtual uint32_t ToForegroundColor(const SyntaxResult& res) const
    {
        if (res.foreground == ThemeColor::Custom)
        {
            return res.customForegroundColor;
        }
        else
        {
            return m_buffer.GetTheme().GetColor(res.foreground);
        }
    }

protected:
    ZepBuffer& m_buffer;
};

class ZepSyntaxAdorn;
class ZepBasicSyntax : public ZepSyntax
{
public:
    ZepBasicSyntax(ZepBuffer& buffer,
        const std::unordered_set<std::string>& keywords = std::unordered_set<std::string>{},
        const std::unordered_set<std::string>& identifiers = std::unordered_set<std::string>{},
        uint32_t flags = 0);
    virtual ~ZepBasicSyntax();

    virtual SyntaxResult GetSyntaxAt(const GlyphIterator& index) const override;
    virtual void UpdateSyntax();
    virtual void Interrupt();
    virtual void Wait() const;

    virtual long GetProcessedChar() const
    {
        return m_processedChar;
    }
    virtual void Notify(std::shared_ptr<ZepMessage> payload) override;


    virtual void IgnoreLineHighlight() { m_flags |= ZepSyntaxFlags::IgnoreLineHighlight; }

private:
    virtual void QueueUpdateSyntax(GlyphIterator startLocation, GlyphIterator endLocation);

protected:
    std::vector<CommentEntry> m_commentEntries;
    std::vector<SyntaxData> m_syntax;
    std::future<void> m_syntaxResult;
    std::atomic<long> m_processedChar = { 0 };
    std::atomic<long> m_targetChar = { 0 };
    std::vector<uint32_t> m_multiCommentStarts;
    std::vector<uint32_t> m_multiCommentEnds;
    std::unordered_set<std::string> m_keywords;
    std::unordered_set<std::string> m_identifiers;
    std::atomic<bool> m_stop;
    std::vector<std::shared_ptr<ZepSyntaxAdorn>> m_adornments;
    uint32_t m_flags;

    ByteRange m_activeLineRange = { 0, 0 };
};

class ZepSyntaxAdorn : public ZepComponent
{
public:
    ZepSyntaxAdorn(ZepSyntax& syntax, ZepBuffer& buffer)
        : ZepComponent(syntax.GetEditor())
        , m_buffer(buffer)
        , m_syntax(syntax)
    {
    }

    virtual SyntaxResult GetSyntaxAt(const GlyphIterator& offset, bool& found) const = 0;

protected:
    ZepBuffer& m_buffer;
    ZepSyntax& m_syntax;
};

} // namespace Zep
