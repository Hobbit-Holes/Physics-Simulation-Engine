entities = {
    {
        group = "enemies",
        name = "enemy 1",
        components = {
            transform = {
                position = {x = 100, y = 100},
                scale = {x = 1.0, y = 1.0},
                rotation = 0.0
            },
            kinematic = {
                velocity = {x = 0, y = 20},
                acceleration = {x = 0, y = 0},
                angularVelocity = 0,
                angularAcceleration = 0
            },
            collider = {
                render = true,
                shape = {
                    type = "rectangle",
                    width = 100,
                    height = 100,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "rectangle",
                    width = 100,
                    height = 100,
                    color = {r = 252, g = 186, b = 3}
                }
            },
            on_update_script = {
                function(entity, world, delta_time, ellpsed_time)
                    -- Circular movement
                    local new_x = 400 + (math.cos(ellpsed_time * 0.001) * 300)
                    local new_y = 400 + (math.sin(ellpsed_time * 0.001) * 300)
                    set_position(entity, world, new_x, new_y)
                    -- print("Executing first Lua script")
                end
            }
        }
    }
}