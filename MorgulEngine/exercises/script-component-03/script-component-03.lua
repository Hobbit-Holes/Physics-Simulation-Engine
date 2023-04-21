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
                    -- Wander behaviour
                    local position = get_position(entity, world)
                    local x = position.x
                    local y = position.y
                    local velocity = get_velocity(entity, world)
                    local vx = velocity.x
                    local vy = velocity.y
                    
                    if x < 50 or x > 800 -50 then
                        set_velocity(entity, world, -vx, vy)
                    -- print("Executing first Lua script")
                    end
                end
            }
        }
    }
}