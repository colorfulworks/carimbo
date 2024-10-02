#include "entity.hpp"

#include "entitymanager.hpp"
#include "pixmap.hpp"
#include "pixmappool.hpp"
#include "rect.hpp"
#include "resourcemanager.hpp"
#include "soundmanager.hpp"

using namespace framework;

entity::entity(const entityprops &&props)
    : _props(std::move(props)), _fn(nullptr) {
}

entity::~entity() {
  std::cout << "entity::~entity(), id: " << _id << std::endl;
}

std::shared_ptr<entity> entity::create(const entityprops &&props) {
  return std::shared_ptr<entity>(new entity(std::move(props)));
}

uint64_t entity::id() const { return _props.id; }

const entityprops entity::props() const {
  return _props;
}

void entity::set_props(entityprops props) {
  _props = std::move(props);
}

void entity::update() {
  if (_fn) {
    _fn(shared_from_this());
  }
}

static int i = 0;

void entity::draw() const {
  if (_props.spritesheet) {
    const auto source = _props.animations.at("walk")[i].frame;
    i++;
    if (i > 2) {
      i = 0;
    }

    geometry::point position{10, 10};
    geometry::rect destination{position, source.size()};
    destination.scale(4.f);

    _props.spritesheet->draw(
        source,
        destination,
        .0f,
        graphics::flip::none,
        255);
  }
}

void entity::set_entitymanager(std::shared_ptr<entitymanager> entitymanager) {
  _entitymanager = entitymanager;
}

void entity::set_resourcemanager(
    std::shared_ptr<resourcemanager> resourcemanager) {
  _resourcemanager = resourcemanager;
}

void entity::set_onupdate(const std::function<void(std::shared_ptr<entity>)> &fn) {
  _fn = fn;
}

void entity::set_pixmap(const std::string_view) {
  // _pixmap = _resourcemanager->pixmappool()->get(filename);
}
