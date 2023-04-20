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
                angularVelocity = 1,
                angularAcceleration = 0
            },
            collider = {
                render = true,
                shape = {
                    type = "circle",
                    radius = 40,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "circle",
                    radius = 60,
                    color = {r = 252, g = 186, b = 3}
                }
            },
            on_update_script = {
                function()
                    print("Executing first Lua script")
                end
            }
        }
    }
}