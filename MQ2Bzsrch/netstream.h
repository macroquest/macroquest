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

#include <string>

class NetStream
{
 public:
  NetStream(const unsigned char* data, unsigned int length);
  ~NetStream();

  const unsigned char* data() { return m_data; }
  unsigned int length() { return m_length; }
  void reset();
  bool end() { return (m_pos >= m_lastPos); }
  const unsigned char* pos() { return m_pos; }

  unsigned char readUInt8();
  signed char readInt8();
  unsigned short readUInt16n();
  short readInt16();
  unsigned int readUInt32n();
  int readInt32();
  std::string readText();
  unsigned short readUInt16();
  unsigned int readUInt32();
  void skipBytes(unsigned int byteCount);

 protected:
  const unsigned char* m_data;
  unsigned int m_length;
  const unsigned char* m_lastPos;
  const unsigned char* m_pos;
};

/**
 * A network stream that manages data by the bit. This is useful for
 * unpacking non-byte-aligned data.
 */
class BitStream
{
public:
    BitStream(const unsigned char* data, unsigned int length);
    ~BitStream();

    const unsigned char* data() { return m_data; }
    unsigned int length() { return m_totalBits >> 3; }
    void reset();
    bool end() { return (m_currentBit >= m_totalBits); }

    bool readBit();
    unsigned int readUInt(unsigned int bitCount);
    int readInt(unsigned int bitCount);

protected:
    const unsigned char* m_data;
    unsigned int m_totalBits;
    unsigned int m_currentBit;
};

inline unsigned short eqntohuint16(const unsigned char* data)
{
    return (unsigned short)((data[0] << 8) | data[1]);
}

inline short eqntohint16(const unsigned char* data)
{
    return (short)((data[0] << 8) | data[1]);
}

inline  unsigned int eqntohuint32(const unsigned char* data)
{
    return (unsigned int)((data[0] << 24) | (data[1] << 16) |
        (data[2] << 8) | data[3]);
}

inline int eqntohint32(const unsigned char* data)
{
    return (int)((data[0] << 24) | (data[1] << 16) |
        (data[2] << 8) | data[3]);
}

inline unsigned short eqtohuint16(const unsigned char* data)
{
    return *(unsigned short*)data;
}

inline short eqtohint16(const unsigned char* data)
{
    return *(short*)data;
}

inline unsigned int eqtohuint32(const unsigned char* data)
{
    return *(unsigned int*)data;
}

inline int eqtohint32(const unsigned char* data)
{
    return *(int*)data;
}

#endif // _NETSTREAM_H_


