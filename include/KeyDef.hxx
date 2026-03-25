#pragma once

#include <stdint.h>

class KeyDef {
private:
  static constexpr uint32_t hash_seed{5381};
  static constexpr uint32_t hash_string(const char str[], uint32_t seed=hash_seed) {
    return (*str == '\0') ? seed : hash_string(str + 1, ((seed << 5) + seed) + *str);
  }

private:
  uint8_t m_ID;
  const char *m_Name;
  uint32_t m_Hash;

public:
  constexpr KeyDef() : m_ID(0), m_Name(nullptr), m_Hash(hash_seed) {}
  constexpr KeyDef(uint8_t id, const char *name) : m_ID(id), m_Name(name), m_Hash(hash_string(name)) {}
  constexpr ~KeyDef() = default;
  constexpr KeyDef(KeyDef &&) noexcept = default;
  constexpr KeyDef &operator=(KeyDef &&) noexcept = default;
  constexpr KeyDef(const KeyDef &) = default;
  constexpr KeyDef &operator=(const KeyDef &) = default;

  constexpr uint8_t get_id() const { return m_ID; }
  constexpr const char *get_name() const { return m_Name; }
  constexpr uint32_t get_hash() const { return m_Hash; }

  constexpr void set_first(uint8_t id) { m_ID = id; }
  constexpr void set_second(const char *name) { m_Name = name; }

  static uint32_t hash_string_runtime(const char str[]);
};
