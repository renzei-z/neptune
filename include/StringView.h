#include <Types.h>

#pragma once

class StringView {
public:
  StringView(const char *data, size_t len)
    : m_data(data)
    , m_len(len) {}

protected:
  const char *m_data;
  size_t m_len;
};

StringView operator""_sv(const char *str, size_t len);
