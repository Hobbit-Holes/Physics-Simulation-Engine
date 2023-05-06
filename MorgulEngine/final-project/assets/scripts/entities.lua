entities = {
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
            }
        }
    },
    {
        group = "Borders",
        name = "Border 1",

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
                resolve = false,
                shape = {
                    type = "rectangle",
                    width = 1,
                    height = 1,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 1,
                    height = 1,
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
        name = "Border 2",

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
                resolve = false,
                shape = {
                    type = "rectangle",
                    width = 1,
                    height = 1,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 1,
                    height = 1,
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
        name = "Border 3",

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
                resolve = false,
                shape = {
                    type = "rectangle",
                    width = 1,
                    height = 1,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 1,
                    height = 1,
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
        name = "Border 4",

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
                resolve = false,
                shape = {
                    type = "rectangle",
                    width = 1,
                    height = 1,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 1,
                    height = 1,
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
        group = "Players",
        name = "Player 1",

        components = {
            transform = {
                position = {x = 300, y = 400},
                scale = {x = 0.25, y = 3},
                rotation = 0
            },
            kinematic = {
                velocity = {x = 0, y = 0}
            },
            collider = {
                render = false,
                resolve = true,
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
                assetId = "White",
                width = 32,
                height = 32
            }
        }
    },
    {
        group = "Players",
        name = "Player 2",

        components = {
            transform = {
                position = {x = 900, y = 400},
                scale = {x = 0.25, y = 3},
                rotation = 0
            },
            kinematic = {
                velocity = {x = 0, y = 0}
            },
            collider = {
                render = false,
                resolve = true,
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
                assetId = "White",
                width = 32,
                height = 32
            }
        }
    },
    {
        group = "Balls",
        name = "Ball 1",

        components = {
            transform = {
                position = {x = 600, y = 400},
                scale = {x = 0.5, y = 0.5},
                rotation = 0
            },
            kinematic = {
                velocity = {x = 0, y = 0}
            },
            collider = {
                render = false,
                resolve = true,
                shape = {
                    type = "rectangle",
                    width = 16,
                    height = 16,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "rectangle",
                    width = 16,
                    height = 16,
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
        group = "Bricks",
        name = "Brick 1",

        components = {
            transform = {
                position = {x = 700, y = 300},
                scale = {x = 1, y = 1},
                rotation = 0
            },
            kinematic = {
                velocity = {x = 0, y = 0}
            },
            collider = {
                render = false,
                resolve = false,
                shape = {
                    type = "rectangle",
                    width = 64,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 64,
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
            }
        }
    },
    {
        group = "Bricks",
        name = "Brick 2",

        components = {
            transform = {
                position = {x = 700, y = 500},
                scale = {x = 1, y = 1},
                rotation = 0
            },
            kinematic = {
                velocity = {x = 0, y = 0}
            },
            collider = {
                render = false,
                resolve = false,
                shape = {
                    type = "rectangle",
                    width = 64,
                    height = 64,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    width = 64,
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
            }
        }
    }
}