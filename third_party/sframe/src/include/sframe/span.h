#pragma once



#if defined(__has_include)
#if __has_include(<version>)
#include <version>
#endif
#endif

#if defined(__cpp_lib_span) && __cpp_lib_span >= 202002L
#include <span>
namespace sframe {
using std::span;
} // namespace sframe
#elif ((defined(__cplusplus) && __cplusplus >= 202002L) ||                     \
       (defined(_MSVC_LANG) && _MSVC_LANG >= 202002L)) &&                      \
  defined(__has_include) && __has_include(<span>)
#include <span>
namespace sframe {
using std::span;
} // namespace sframe
#else
#include "third_party/sframe/src/include/gsl-lite/gsl-lite.hpp"
namespace sframe {
using gsl_lite::span;
} // namespace sframe
#endif
