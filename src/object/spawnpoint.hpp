//  SuperTux
//  Copyright (C) 2015 Hume2 <teratux.mail@gmail.com>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_OBJECT_SPAWNPOINT_HPP
#define HEADER_SUPERTUX_OBJECT_SPAWNPOINT_HPP

#include "supertux/moving_object.hpp"

#include "video/surface_ptr.hpp"

class ReaderMapping;
class DrawingContext;

class SpawnPointMarker final : public MovingObject
{
public:
  SpawnPointMarker(const std::string& name, const Vector& pos);
  SpawnPointMarker(const ReaderMapping& mapping);

  virtual void update(float dt_sec) override {
    // No updates needed
  }

  virtual void draw(DrawingContext& context) override;

  virtual void collision_solid(const CollisionHit& hit) override {
    // This function wouldn't be called anyway.
  }

  virtual HitResponse collision(GameObject& other, const CollisionHit& hit) override { return FORCE_MOVE; }

  virtual std::string get_class() const override { return "spawnpoint"; }
  virtual std::string get_display_name() const override { return _("Spawnpoint"); }
  virtual ObjectSettings get_settings() override;

private:
  SurfacePtr m_surface;

private:
  SpawnPointMarker(const SpawnPointMarker&) = delete;
  SpawnPointMarker& operator=(const SpawnPointMarker&) = delete;
};

#endif

/* EOF */
