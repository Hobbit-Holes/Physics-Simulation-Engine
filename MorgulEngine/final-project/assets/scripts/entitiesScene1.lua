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
                position = {x = 350, y = 400},
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
                assetId = "Ball1",
                width = 25,
                height = 25
            },
            ballMovement = {
                initialVelocity = 250,
                maxVelocity = 450,
                maxDesviation = 0.45,
                sumVelocity = 10,
                sumDesviation = 0.1,
                serve = 1
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
        name = "Bonus Racket",

        components = {
            transform = {
                position = {x = 600, y = 400}
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
                assetId = "BricksRacket",
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
        name = "Brick 01",

        components = {
            transform = {
                position = {x = 600, y = 325}
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
        name = "Brick 02",

        components = {
            transform = {
                position = {x = 600, y = 475}
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
                position = {x = 650, y = 440}
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
                position = {x = 650, y = 360}
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
                position = {x = 550, y = 440}
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
                position = {x = 550, y = 360}
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
                position = {x = 400, y = 200}
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
                position = {x = 800, y = 200}
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
        name = "Brick 08",

        components = {
            transform = {
                position = {x = 400, y = 600}
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
        name = "Brick 09",

        components = {
            transform = {
                position = {x = 800, y = 600}
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