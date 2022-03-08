// Add support for exporting symbols to be used in DLLs
// This is needed because of how MSVC handles default visibility
// Which is not supported by other compilers, this macro handles the cases

#pragma once

#if defined _WIN32 || defined __CYGWIN__
#define API_IMPORT __declspec(dllimport)
#define API_EXPORT __declspec(dllexport)
#define API_LOCAL
#else
#if __GNUC__ >= 4
#define API_IMPORT __attribute__((visibility("default")))
#define API_EXPORT __attribute__((visibility("default")))
#define API_LOCAL __attribute__((visibility("hidden")))
#else
#define API_IMPORT
#define API_EXPORT
#define API_LOCAL
#endif
#endif

// Source: https://gcc.gnu.org/wiki/Visibility
