entities = {
    {
        group = "Balls",
        name = "Ball 1",

        components = {
            transform = {
                position = {x = 400, y = 400}
            },
            sprite = {
                assetId = "balls",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 5,
                frameSpeedRate = 1
            }
        }
    },
    {
        group = "Balls",
        name = "Ball 2",

        components = {
            transform = {
                position = {x = 400, y = 200},
                scale = {x = 2, y = 2}
            },
            sprite = {
                assetId = "more_balls",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 3, 
                frameSpeedRate = 1
            },
            animatedMovement = {
                up = {x = 0, y = 3},
                down = {x = 3, y = 3},
                right = {x = 6, y = 3},
                left = {x = 9, y = 3},
                final = {x = 12, y = 1}
            }
        }
    },
    {
        group = "Arrows",
        name = "Arrow 1",

        components = {
            transform = {
                position = {x = 400, y = 600},
                scale = {x = 3, y = 3}
            },
            sprite = {
                assetId = "arrows",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 3, 
                frameSpeedRate = 1
            },
            animatedMovement = {
                up = {x = 0, y = 3},
                down = {x = 3, y = 3},
                right = {x = 6, y = 3},
                left = {x = 9, y = 3},
                final = {x = 12, y = 1}
            }
        }
    }
}