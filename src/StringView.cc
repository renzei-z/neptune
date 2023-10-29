#include <StringView.h>

StringView operator""_sv(const char *str, size_t len)
{
  return StringView(str, len);
}
