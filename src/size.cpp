#include "size.hpp"

using namespace geometry;

size::size(int32_t width, int32_t height) : _width(width), _height(height) {}

size::size(const size &other) : _width(other._width), _height(other._height) {}

void size::set_width(const int32_t width) noexcept { _width = width; }

int32_t size::width() const noexcept { return _width; }

void size::set_height(const int32_t height) noexcept { _height = height; }

int32_t size::height() const noexcept { return _height; }

bool size::operator==(const size &rhs) const noexcept {
  return _width == rhs._width && _height == rhs._height;
}

bool size::operator!=(const size &rhs) const noexcept {
  return !(*this == rhs);
}
