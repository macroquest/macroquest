/*
 * netstream.h
 *
 *  ShowEQ Distributed under GPL
 *  http://www.sourceforge.net/projects/seq
 *
 *  Copyright 2004 Zaphod (dohpaz@users.sourceforge.net). 
 *
 */


#include "netstream.h"


NetStream::NetStream(const uint8_t* data, size_t length)
  : m_data(data),
    m_length(length)
{
  m_lastPos = &m_data[m_length];

  reset();
}

NetStream::~NetStream()
{
}

void NetStream::reset()
{
  // reset position to the end of the string
  m_pos = m_data;
}

uint8_t NetStream::readUInt8()
{
  uint8_t val;

  // make sure there is enough data left
  if ((m_lastPos - m_pos) >= 1)
  {
    // convert the data and increment past it
    val = *m_pos;
    m_pos++;
  }
  else 
    val = 0; // just return 0 if no data left

  return val;
}

int8_t NetStream::readInt8()
{
  int8_t val;

  // make sure there is enough data left
  if ((m_lastPos - m_pos) >= 1)
  {
    // convert the data and increment past it
    val = *(int8_t*)m_pos;
    m_pos++;
  }
  else 
    val = 0; // just return 0 if no data left

  return val;
}

uint16_t NetStream::readUInt16n()
{
  uint16_t val;

  // make sure there is enough data left
  if ((m_lastPos - m_pos) >= 2)
  {
    // convert the data and increment past it
    val = eqntohuint16(m_pos);
    m_pos += 2;
  }
  else 
    val = 0; // just return 0 if no data left

  return val;
}

int16_t NetStream::readInt16()
{
  int16_t val;

  // make sure there is enough data left
  if ((m_lastPos - m_pos) >= 2)
  {
    // convert the data and increment past it
    val = eqntohint16(m_pos);
    m_pos += 2;
  }
  else
    val = 0; // just return 0 if no data left

  return val;
}

uint32_t NetStream::readUInt32n()
{
  uint32_t val;

  // make sure there is enough data left
  if ((m_lastPos - m_pos) >= 4)
  {
    // convert the data and increment past it
    val = eqntohuint32(m_pos);
    m_pos += 4;
  }
  else 
    val = 0; // just return 0 if no data left

  return val;
}

int32_t NetStream::readInt32()
{
  uint32_t val;

  // make sure there is enough data left
  if ((m_lastPos - m_pos) >= 4)
  {
    // convert the data and increment past it
    val = eqntohint32(m_pos);
    m_pos += 4;
  }
  else
    val = 0; // just return 0 if no data left

  return val;
}

std::string NetStream::readText()
{
  // make sure there is data left
  if (m_pos < m_lastPos)
  {
    // note the starting positino
    const uint8_t* startPos = m_pos;
    
    // search for the end of the NULL terminated string
    while ((*m_pos != '\0') && (m_pos < m_lastPos))
      m_pos++;
    
    size_t len = m_pos - startPos;

    // skip over trailing null
    if (m_pos < m_lastPos)
      m_pos++;
    
    // return the result as a QString
    return std::string((const char*)startPos, len);
  }
  else
    return std::string();
}

uint16_t NetStream::readUInt16()
{
    uint16_t val;

  // make sure there is enough data left
    if ((m_lastPos - m_pos) >= 2)
    {
    // convert the data and increment past it
        val = eqtohuint16(m_pos);
        m_pos += 2;
    }
    else 
        val = 0; // just return 0 if no data left

    return val;
}

uint32_t NetStream::readUInt32()
{
  uint32_t val;

  // make sure there is enough data left
  if ((m_lastPos - m_pos) >= 4)
  {
    // convert the data and increment past it
    val = eqtohuint32(m_pos);
    m_pos += 4;
  }
  else 
    val = 0; // just return 0 if no data left

  return val;
}

void NetStream::skipBytes(size_t byteCount)
{
  if (uint32_t(m_lastPos - m_pos) >= byteCount)
  {
    m_pos += byteCount;
  }
}

BitStream::BitStream(const uint8_t* data, size_t length)
  : m_data(data)
{
    // Length in bits.
    m_totalBits = length * 8;

    reset();
}

BitStream::~BitStream()
{
}

void BitStream::reset()
{
    m_currentBit = 0;
}

uint32_t BitStream::readUInt(size_t bitCount)
{
    // Make sure we have the bits first.
    if (m_currentBit + bitCount > m_totalBits)
    {
        return 0;
    }

    const uint8_t* currentByte = m_data + (m_currentBit >> 3);
    uint32_t out = 0;

    // Partial bytes in the lead and end. Full bytes in the middle.
    size_t leadPartialBitCount = 8 - (m_currentBit % 8);
    size_t middleByteCount;
    size_t tailPartialBitCount;

    if (leadPartialBitCount == 8)
    {
        // Lead partial is a byte. So just put it in the middle.
        leadPartialBitCount = 0;
    }

    if (leadPartialBitCount > bitCount)
    {
        // All the bits we need are in the lead partial. Note that when
        // the lead partial is byte aligned, this won't process it. Instead
        // it will be handled by the tailPartialBitCount.
        out = *currentByte & ((1 << leadPartialBitCount) - 1);
        m_currentBit += bitCount;

        return out >> (leadPartialBitCount - bitCount);
    }
    else
    {
        // Spanning multiple bytes. leadPartialBitCount is correct.
        // Calculate middle and tail.
        middleByteCount = (bitCount - leadPartialBitCount) / 8;
        tailPartialBitCount = 
            bitCount - (leadPartialBitCount + middleByteCount*8);
    }

    if (leadPartialBitCount > 0)
    {
        // Pull in partial from the lead byte
        out |= *currentByte & ((1 << leadPartialBitCount) - 1);
        currentByte++;
    }

    // Middle
    for (size_t i=0; i<middleByteCount; i++)
    {
        out = (out << 8) | *currentByte;
        currentByte++;
    }

    // And the end.
    if (tailPartialBitCount > 0)
    {
        out = (out << tailPartialBitCount) | 
            (*currentByte >> (8 - tailPartialBitCount));
    }

    // Update the current bit
    m_currentBit += bitCount;

    return out;
}

int32_t BitStream::readInt(size_t bitCount)
{
    // Sign
    uint32_t sign = readUInt(1);
    uint32_t retval = readUInt(bitCount - 1);

    return retval * (sign ? -1 : 1);
}

