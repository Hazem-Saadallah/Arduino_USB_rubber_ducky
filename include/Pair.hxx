#pragma once

template <typename T1, typename T2> class Pair {
private:
  T1 m_First;
  T2 m_Second;

public:
  constexpr Pair() = default;
  constexpr Pair(T1 first, T2 second) : m_First(first), m_Second(second) { }
  constexpr ~Pair() = default;
  constexpr Pair(Pair &&) noexcept = default;
  constexpr Pair &operator=(Pair &&) noexcept = default;
  constexpr Pair(const Pair &) = default;
  constexpr Pair &operator=(const Pair &) = default;

  constexpr T1 get_first() const { return m_First; }
  constexpr T2 get_second() const { return m_Second; }

  constexpr void set_first(T1 value) { m_First = value; }
  constexpr void set_second(T2 value) { m_Second = value; }
};
