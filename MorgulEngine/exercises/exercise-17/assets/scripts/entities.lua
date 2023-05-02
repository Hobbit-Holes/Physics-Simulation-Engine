velocity = 100

entities = {
    {
        group = "Player",
        name = "Player 1",

        components = {
            transform = {
                position = {x = 400, y = 400},
                scale = {x = 4, y = 4}
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
                final = {x = 16, y = 4}
            },
            sound = {
                assetId = "Pop",
                sound = "Effect",
                play = true
            }
        }
    },
    {
        group = "Texts",
        name = "Title",

        components = {
            transform = {
                position = {x = 400, y = 50},
                rotation = 0
            },
            font = {
                filePath = "./assets/fonts/Bits.ttf",
                text = "DOWN",
                size = 50,
                color = {r = 0, g = 0, b = 0}
            }
        }
    },
    {
        group = "Background",
        name = "Floor",

        components = {
            transform = {
                position = {x = 400, y = 400},
                rotation = 0
            },
            sprite = {
                assetId = "Cesped",
                width = 800,
                height = 800
            }
        }
    },
    {
        group = "Sounds",
        name = "Music",

        components = {
            sound = {
                assetId = "TheShire",
                sound = "Music",
                play = true
            }
        }
    }
}