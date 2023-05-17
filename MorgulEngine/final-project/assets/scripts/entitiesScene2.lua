entities = {
    {
        group = "Sounds",
        name = "Music",

        components = {
            sound = {
                assetId = "Music",
                sound = "Music",
                play = true
            }
        }
    },
    {
        group = "Texts",
        name = "Text Player 1",

        components = {
            transform = {
                position = {x = 100, y = 400},
                scale = {x = 4, y = 4},
                rotation = -90
            },
            font = {
                filePath = "./assets/fonts/bit5x3.ttf",
                text = "PLAYER 1",
                size = 20,
                color = {r = 255, g = 255, b = 255}
            }
        }
    },
    {
        group = "Texts",
        name = "Text Player 2",

        components = {
            transform = {
                position = {x = 1100, y = 400},
                scale = {x = 4, y = 4},
                rotation = 90
            },
            font = {
                filePath = "./assets/fonts/bit5x3.ttf",
                text = "PLAYER 2",
                size = 20,
                color = {r = 255, g = 255, b = 255}
            }
        }
    },
    {
        group = "Texts",
        name = "Text Punctuation",

        components = {
            transform = {
                position = {x = 600, y = 75},
                scale = {x = 4, y = 4},
                rotation = 0
            },
            font = {
                filePath = "./assets/fonts/bit5x3.ttf",
                text = "0 - 0",
                size = 20,
                color = {r = 255, g = 255, b = 255}
            },
            textPunctuation = {}
        }
    },
    {
        group = "Borders",
        name = "Border Top",

        components = {
            transform = {
                position = {x = 600, y = 150},
                scale = {x = 25, y = 0.5},
                rotation = 0
            },
            kinematic = {
                velocity = {x = 0, y = 0}
            },
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32 * 25,
                    height = 32 * 0.5,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32 * 25,
                    height = 32 * 0.5,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "White",
                width = 32,
                height = 32
            }
        }
    },
    {
        group = "Borders",
        name = "Border Bottom",

        components = {
            transform = {
                position = {x = 600, y = 650},
                scale = {x = 25, y = 0.5},
                rotation = 0
            },
            kinematic = {
                velocity = {x = 0, y = 0}
            },
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32 * 25,
                    height = 32 * 0.5,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32 * 25,
                    height = 32 * 0.5,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "White",
                width = 32,
                height = 32
            }
        }
    },
    {
        group = "Borders",
        name = "Border Left",

        components = {
            transform = {
                position = {x = 208, y = 400},
                scale = {x = 0.5, y = 16},
                rotation = 0
            },
            kinematic = {
                velocity = {x = 0, y = 0}
            },
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32 * 0.5,
                    height = 32 * 15,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32 * 0.5,
                    height = 32 * 15,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "White",
                width = 32,
                height = 32
            }
        }
    },
    {
        group = "Borders",
        name = "Border Right",

        components = {
            transform = {
                position = {x = 992, y = 400},
                scale = {x = 0.5, y = 16},
                rotation = 0
            },
            kinematic = {
                velocity = {x = 0, y = 0}
            },
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32 * 0.5,
                    height = 32 * 15,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32 * 0.5,
                    height = 32 * 15,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "White",
                width = 32,
                height = 32
            }
        }
    },
    {
        group = "Goals",
        name = "Goal Player 1",

        components = {
            transform = {
                position = {x = 215, y = 400},
                scale = {x = 0.5, y = 16},
                rotation = 0
            },
            kinematic = {
                velocity = {x = 0, y = 0}
            },
            collider = {
                render = false,
                resolve = false,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32 * 0.5,
                    height = 32 * 15,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32 * 0.5,
                    height = 32 * 15,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Goal",
                width = 32,
                height = 32
            },
            sound = {
                assetId = "Score",
                sound = "Effect",
                play = false
            }
        }
    },
    {
        group = "Goals",
        name = "Goal Player 2",

        components = {
            transform = {
                position = {x = 985, y = 400},
                scale = {x = 0.5, y = 16},
                rotation = 0
            },
            kinematic = {
                velocity = {x = 0, y = 0}
            },
            collider = {
                render = false,
                resolve = false,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32 * 0.5,
                    height = 32 * 15,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32 * 0.5,
                    height = 32 * 15,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Goal",
                width = 32,
                height = 32
            },
            sound = {
                assetId = "Score",
                sound = "Effect",
                play = false
            }
        }
    },
    {
        group = "Players",
        name = "Player 1",

        components = {
            transform = {
                position = {x = 300, y = 400},
                scale = {x = 1, y = 1},
                rotation = 0
            },
            kinematic = {
                velocity = {x = 0, y = 0}
            },
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 8,
                    height = 96,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 8,
                    height = 96,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Player",
                width = 16,
                height = 96
            },
            racketController = {
                control = 1,
                limitUp = 225,
                limitDown = 575,
                speed = 200
            }
        }
    },
    {
        group = "Players",
        name = "Player 2",

        components = {
            transform = {
                position = {x = 900, y = 400},
                scale = {x = 1, y = 1},
                rotation = 0
            },
            kinematic = {
                velocity = {x = 0, y = 0}
            },
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 8,
                    height = 96,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 8,
                    height = 96,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Player",
                width = 16,
                height = 96
            },
            racketController = {
                control = 0,
                limitUp = 225,
                limitDown = 575,
                speed = 200
            }
        }
    },
    {
        group = "Balls",
        name = "Ball 1",

        components = {
            transform = {
                position = {x = 850, y = 400},
                scale = {x = 1, y = 1},
                rotation = 0
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = false,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 25,
                    height = 25,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "rectangle",
                    width = 25,
                    height = 25,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Ball2",
                width = 25,
                height = 25
            },
            ballMovement = {
                initialVelocity = 250,
                maxVelocity = 500,
                maxDesviation = 0.45,
                sumVelocity = 10,
                sumDesviation = 0.1,
                serve = 2
            },
            sound = {
                assetId = "Hit",
                sound = "Effect",
                play = false
            }
        }
    },
    {
        group = "Bonus",
        name = "Bonus Restart",

        components = {
            transform = {
                position = {x = 600, y = 200}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "BricksRestart",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 1
            }
        }
    },
    {
        group = "Bonus",
        name = "Bonus Speed",

        components = {
            transform = {
                position = {x = 600, y = 600}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "BricksSpeed",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 1
            }
        }
    },
    {
        group = "Bricks",
        name = "Brick 02",

        components = {
            transform = {
                position = {x = 600, y = 525}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Bricks",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 3
            }
        }
    },
    {
        group = "Bricks",
        name = "Brick 03",

        components = {
            transform = {
                position = {x = 550, y = 575}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Bricks",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 3
            }
        }
    },
    {
        group = "Bricks",
        name = "Brick 04",

        components = {
            transform = {
                position = {x = 650, y = 575}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Bricks",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 3
            }
        }
    },
    {
        group = "Bricks",
        name = "Brick 05",

        components = {
            transform = {
                position = {x = 600, y = 275}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Bricks",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 3
            }
        }
    },
    {
        group = "Bricks",
        name = "Brick 06",

        components = {
            transform = {
                position = {x = 550, y = 225}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Bricks",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 3
            }
        }
    },
    {
        group = "Bricks",
        name = "Brick 07",

        components = {
            transform = {
                position = {x = 650, y = 225}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Bricks",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 3
            }
        }
    },
    {
        group = "Bricks",
        name = "Defense 1_01",

        components = {
            transform = {
                position = {x = 260, y = 200}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Bricks",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 3,
                restingLifes = 1
            }
        }
    },
    {
        group = "Bricks",
        name = "Defense 1_02",

        components = {
            transform = {
                position = {x = 260, y = 275}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Bricks",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 3,
                restingLifes = 1
            }
        }
    },
    {
        group = "Bricks",
        name = "Defense 1_03",

        components = {
            transform = {
                position = {x = 260, y = 350}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Bricks",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 3,
                restingLifes = 1
            }
        }
    },
    {
        group = "Bricks",
        name = "Defense 1_04",

        components = {
            transform = {
                position = {x = 260, y = 450}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Bricks",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 3,
                restingLifes = 1
            }
        }
    },
    {
        group = "Bricks",
        name = "Defense 1_05",

        components = {
            transform = {
                position = {x = 260, y = 525}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Bricks",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 3,
                restingLifes = 1
            }
        }
    },
    {
        group = "Bricks",
        name = "Defense 1_06",

        components = {
            transform = {
                position = {x = 260, y = 600}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Bricks",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 3,
                restingLifes = 1
            }
        }
    },
    {
        group = "Bricks",
        name = "Defense 2_01",

        components = {
            transform = {
                position = {x = 940, y = 200}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Bricks",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 3,
                restingLifes = 1
            }
        }
    },
    {
        group = "Bricks",
        name = "Defense 2_02",

        components = {
            transform = {
                position = {x = 940, y = 275}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Bricks",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 3,
                restingLifes = 1
            }
        }
    },
    {
        group = "Bricks",
        name = "Defense 2_03",

        components = {
            transform = {
                position = {x = 940, y = 350}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Bricks",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 3,
                restingLifes = 1
            }
        }
    },
    {
        group = "Bricks",
        name = "Defense 2_04",

        components = {
            transform = {
                position = {x = 940, y = 450}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Bricks",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 3,
                restingLifes = 1
            }
        }
    },
    {
        group = "Bricks",
        name = "Defense 2_05",

        components = {
            transform = {
                position = {x = 940, y = 525}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Bricks",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 3,
                restingLifes = 1
            }
        }
    },
    {
        group = "Bricks",
        name = "Defense 2_06",

        components = {
            transform = {
                position = {x = 940, y = 600}
            },
            kinematic = {},
            collider = {
                render = false,
                resolve = true,
                aabb = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 32,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            sprite = {
                assetId = "Bricks",
                width = 64,
                height = 64
            },
            animation = {
                numFrames = 1,
                frameSpeedRate = 1
            },
            brick = {
                numLifes = 3,
                restingLifes = 1
            }
        }
    },
    {
        group = "World",
        name = "Center Line",

        components = {
            transform = {
                position = {x = 600, y = 400},
                scale = {x = 0.05, y = 16},
            },
            sprite = {
                assetId = "White",
                width = 32,
                height = 32
            }
        }
    }
}