/*
 * netstream.h
 *
 *  ShowEQ Distributed under GPL
 *  http://www.sourceforge.net/projects/seq
 *
 *  Copyright 2004 Zaphod (dohpaz@users.sourceforge.net). 
 *
 */

#ifndef _NETSTREAM_H_
#define _NETSTREAM_H_

#include <stdint.h>
#include <string>

class NetStream
{
 public:
  NetStream(const uint8_t* data, size_t length);
  ~NetStream();

  const uint8_t* data() { return m_data; }
  size_t length() { return m_length; }
  void reset();
  bool end() { return (m_pos >= m_lastPos); }
  const uint8_t* pos() { return m_pos; }

  uint8_t readUInt8();
  int8_t readInt8();
  uint16_t readUInt16n();
  int16_t readInt16();
  uint32_t readUInt32n();
  int32_t readInt32();
  std::string readText();
  uint16_t readUInt16();
  uint32_t readUInt32();
  void skipBytes(size_t byteCount);

 protected:
  const uint8_t* m_data;
  size_t m_length;
  const uint8_t* m_lastPos;
  const uint8_t* m_pos;
};

/**
 * A network stream that manages data by the bit. This is useful for
 * unpacking non-byte-aligned data.
 */
class BitStream
{
public:
    BitStream(const uint8_t* data, size_t length);
    ~BitStream();

    const uint8_t* data() { return m_data; }
    size_t length() { return m_totalBits >> 3; }
    void reset();
    bool end() { return (m_currentBit >= m_totalBits); }

    bool readBit();
    uint32_t readUInt(size_t bitCount);
    int32_t readInt(size_t bitCount);

protected:
    const uint8_t* m_data;
    size_t m_totalBits;
    size_t m_currentBit;
};

inline uint16_t eqntohuint16(const uint8_t* data)
{
    return (uint16_t)((data[0] << 8) | data[1]);
}

inline int16_t eqntohint16(const uint8_t* data)
{
    return (int16_t)((data[0] << 8) | data[1]);
}

inline  uint32_t eqntohuint32(const uint8_t* data)
{
    return (uint32_t)((data[0] << 24) | (data[1] << 16) |
        (data[2] << 8) | data[3]);
}

inline int32_t eqntohint32(const uint8_t* data)
{
    return (int32_t)((data[0] << 24) | (data[1] << 16) |
        (data[2] << 8) | data[3]);
}

inline uint16_t eqtohuint16(const uint8_t* data)
{
    return *(uint16_t*)data;
}

inline int16_t eqtohint16(const uint8_t* data)
{
    return *(int16_t*)data;
}

inline uint32_t eqtohuint32(const uint8_t* data)
{
    return *(uint32_t*)data;
}

inline int32_t eqtohint32(const uint8_t* data)
{
    return *(int32_t*)data;
}

#endif // _NETSTREAM_H_


