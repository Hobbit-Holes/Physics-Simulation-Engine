entities = {
    {
        group = "Enemies",
        name = "Enemy 1",
        components = {
            transform = {
                position = {x = 150, y = 100},
                scale = {x = 1.0, y = 1.0},
                rotation = 0.0
            },
            kinematic = {
                velocity = {x = 0, y = 50},
                acceleration = {x = 0, y = 0},
                angularVelocity = 1,
                angularAcceleration = 0
            },
            collider = {
                render = true,
                shape = {
                    type = "regularPolygon",
                    radius = 40,
                    vertices = 10,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "regularPolygon",
                    radius = 60,
                    vertices = 10,
                    color = {r = 215, g = 189, b = 226}
                }
            },
            on_update_script = {
                function()
                    print("Executing first Lua script")
                end
            }
        }
    },
    {
        group = "Enemies",
        name = "Enemy 2",
        components = {
            transform = {
                position = {x = 400, y = 100},
            },
            kinematic = {
                velocity = {x = 0, y = 30},
                acceleration = {x = 0, y = 100},
            },
            collider = {
                render = false,
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
                    radius = 40,
                    filled = true,
                    color = {r = 36, g = 113, b = 163}
                }
            }
        }
    },
    {
        group = "Enemies",
        name = "Enemy 3",
        components = {
            transform = {
                position = {x = 400, y = 700},
            },
            kinematic = {
                velocity = {x = 0, y = -60},
                acceleration = {x = 0, y = 0},
            },
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = 30,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "circle",
                    radius = 30,
                    filled = true,
                    color = {r = 69, g = 179, b = 157}
                }
            }
        }
    },
    {
        group = "Enemies",
        name = "Enemy 4",
        components = {
            transform = {
                position = {x = 410, y = 400},
            },
            kinematic = {},
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = 20,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 5,
                shape = {
                    type = "circle",
                    radius = 20,
                    filled = true,
                    color = {r = 220, g = 118, b = 51}
                }
            }
        }
    },
    {
        group = "Enemies",
        name = "Enemy 5",
        components = {
            transform = {
                position = {x = 700, y = 650},
            },
            kinematic = {
                velocity = {x = 0, y = -70},
                acceleration = {x = 0, y = 0},
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "star",
                    filled = true,
                    radius = 60,
                    vertices = 8,
                    color = {r = 255, g = 255, b = 255}
                }
            }
        }
    }
}