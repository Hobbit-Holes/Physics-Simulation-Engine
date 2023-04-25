velocity = 75

entities = {
    {
        group = "Player",
        name = "Player 1",

        components = {
            transform = {
                position = {x = 400, y = 400},
                scale = {x = 3, y = 3}
            },
            kinematic = {
                velocity = {x = 0, y = 50}
            },
            sprite = {
                assetId = "Marquitos",
                width = 32,
                height = 32
            },
            animation = {
                numFrames = 4,
                frameSpeedRate = 5
            },
            animatedMovement = {
                up = {x = 4, y = 4},
                down = {x = 0, y = 4},
                right = {x = 8, y = 4},
                left = {x = 12, y = 4},
                final = {x = 1, y = 1}
            }
        }
    }
}