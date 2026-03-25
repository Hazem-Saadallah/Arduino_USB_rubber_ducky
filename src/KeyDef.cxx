#include <KeyDef.hxx>

uint32_t KeyDef::hash_string_runtime(const char str[]) {
  uint32_t seed = KeyDef::hash_seed;
  int32_t c;
  while ((c = *str++)) seed = ((seed << 5) + seed) + c;
  return seed;
}
