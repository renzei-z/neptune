#ifdef __linux__
#include <stdlib.h>
#include <string.h>
#endif
#include <Types.h>

#pragma once

template<typename Item>
class Vector {
  static constexpr size_t start_capacity = 4;
  static constexpr size_t extend_factor = 2;
public:
  Vector() {
    m_first = (Item*)malloc(sizeof(Item) * start_capacity);

    if (m_first == nullptr) {
      // TODO: Propagate errors   
    }

    m_size = 0;
    m_capacity = start_capacity;
  }

  ~Vector() {
    if (m_first != nullptr) free(m_first);
  }

  Item *get(size_t idx) {
    if (m_size == 0) return nullptr;

    // Index must be less than size.
    // For example, to get element 4, 
    // due to 0 indexing, the vector must
    // have a size 5.
    if (idx >= m_size) {
      
      // Out of bounds!
      return nullptr;
    }

    return m_first + idx;
  }

  inline Item *last() { return get(m_size - 1); }

  Item* append(Item item){ 
    if (m_size == m_capacity) {
      
      if (extend() == m_capacity) {
        // TODO: Propagate errors
        return nullptr; 
      }
    }
    
    // We can't use get(m_size) here,
    // as that errors when the vector
    // is full.
    Item *next = m_first + m_size;
    m_size += 1;
    *next = item;
    return next;
  }
private:
  size_t extend() {
    size_t new_capacity = m_capacity * extend_factor; 
    Item *new_loc = (Item*)malloc(sizeof(Item) * new_capacity);
    if (new_loc == nullptr) return m_capacity;

    memcpy(new_loc, m_first, m_capacity * sizeof(Item));
    free(m_first);
    m_first = new_loc;
    return new_capacity;
  }
protected:
  Item *m_first;
  size_t m_size;
  size_t m_capacity;
};
