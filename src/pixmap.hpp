#pragma once

#include "common.hpp"

#include "point.hpp"
#include "rect.hpp"
#include "size.hpp"

typedef std::unique_ptr<SDL_Texture, SDL_Deleter> texture_ptr;

namespace graphics {
enum class flip : int32_t {
  none = SDL_FLIP_NONE,
  horizontal = SDL_FLIP_HORIZONTAL,
  vertical = SDL_FLIP_VERTICAL,
  both = SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL
};

class pixmap {
public:
  pixmap() = default;
  pixmap(const std::shared_ptr<renderer> renderer, std::string_view filename);
  ~pixmap() = default;

  void draw(
      const geometry::rect &source,
      const geometry::rect &destination,
      const double angle = 0.0,
      flip flip = flip::none,
      const uint8_t alpha = 255) const noexcept;

  const geometry::size size() const noexcept;

  void set_size(const geometry::size &size) noexcept;

private:
  std::shared_ptr<renderer> _renderer;

  geometry::size _size;
  texture_ptr _texture;
};
}
