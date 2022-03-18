#ifndef CircularBuffer_hpp
#define CircularBuffer_hpp

#include <assert.h>

template <typename ttype>
class CircularBuffer
{
public:
  explicit CircularBuffer (const unsigned short a) : elements(new ttype[a]),
                                                     size(a),
                                                     dynAlloc(true),
                                                     readPtr(elements),
                                                     writePtr(elements)
  {
    assert (0 != a);
    reset();
  };

  ~CircularBuffer()
  {
    if (dynAlloc == true)
      delete[] elements;
  }

  void reset()
  {
    for (int i = 0; i < size; i++)
      {
        elements[i] = 0;
      }

    writePtr = readPtr = elements;
  };

  unsigned short getSize() const
  {
    return size;
  }

  void write(const ttype number)
  {
    readPtr = writePtr;
    *writePtr = number;
    writePtr++;

    if (elements + size == writePtr) {
      writePtr = elements;
    }
  }

  ttype lees ()
  {
    auto sample = *readPtr;

    if (readPtr == elements)
      {
        readPtr = elements + size - 1;
      }

    else {
      readPtr--;
    }

    return sample;
  }

  ttype lees (const unsigned int index) const
  {
    auto sampleIndex = index;
    auto * temp = readPtr;

    while (sampleIndex)
      {
        if (temp == elements)
          {
            temp = elements + size - 1;
          }

        else
          {
            temp--;
          }

        sampleIndex--;
      }

    auto sample = *temp;
    return sample;
  }

  ttype operator [](const unsigned int index) const
  {
    if (index < size)
      {
        return elements[index];
      }

    else return elements[size-1];
  }

  ttype sum() const
  {
    auto sum = 0;
    for (int i = 0; i < size; i++)
      {
        sum += elements[i];
      }
    return sum;
  }

  ttype average() const
  {
    return sum()/size;
  }

  ttype average(const ttype number)
  {
    write(number);
    return sum()/size;
  }


  ttype * const elements;

private:
  const unsigned short size;

public:

  const bool dynAlloc;
  ttype *readPtr;
  ttype *writePtr;


};


#endif
