#pragma once

/// @brief Általános téglalap-struktúra sablon.
/// @tparam T A koordináták és méretek típusa.
/// @note A téglalap bal-felső sarka az (x, y) koordináta, szélessége w, magassága h.
template<typename T>
struct Rect {
    /// A bal felső sarok X koordinátája.
    T x;
    /// A bal felső sarok Y koordinátája.
    T y;
    /// A téglalap szélessége.
    T w;
    /// A téglalap magassága.
    T h;
};
