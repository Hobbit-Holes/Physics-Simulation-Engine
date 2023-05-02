dragImpulse = 20
dragRotation = 200
numIsles = 50

entities = {
    {
        group = "Player",
        name = "Player",
        components = {
            transform = {
                position = {x = 500, y = 500},
                scale = {x = 1.0, y = 1.0},
                rotation = 0.0
            },
            kinematic = {
                velocity = {x = 0, y = 0},
                acceleration = {x = 0, y = 0},
                angularVelocity = 0,
                angularAcceleration = 0
            },
            collider = {
                render = true,
                resolve = false,
                shape = {
                    type = "rectangle",
                    width = 40,
                    height = 70,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "rectangle",
                    width = 40,
                    height = 70,
                    color = {r = 252, g = 186, b = 3}
                }
            },
            shipMovement = {
                force = {
                    x = 0,
                    y = -1000,
                },
                torque = 1000.0,
                maxVelocity = 75.0,
                maxRotation = 1.0
            },
            sprite = {
                assetId = "Ship",
                width = 96,
                height = 96
            }
        }
    },
    -- {
    --     group = "Island",
    --     name = "Island 1",
    --     components = {
    --         transform = {
    --             position = {x = 201, y = 227}
    --         },
    --         kinematic = {},
    --         collider = {
    --             render = true,
    --             shape = {
    --                 type = "regularPolygon",
    --                 radius = 46,
    --                 vertices = 6,
    --                 color = {r = 144, g = 217, b = 35}
    --             }
    --         },
    --         rigidbody = {
    --             mass = 0,
    --             isStatic = true,
    --             shape = {
    --                 type = "regularPolygon",
    --                 radius = 46,
    --                 vertices = 6,
    --                 color = {r = 144, g = 217, b = 35}
    --             }
    --         },
    --         sprite = {
    --             assetId = "Isle",
    --             width = 96,
    --             height = 96
    --         }
    --     }
    -- }
    -- ,
    -- {
    --     group = "Island",
    --     name = "Island 2",
    --     components = {
    --         transform = {
    --             position = {x = 800, y = 200}
    --         },
    --         kinematic = {},
    --         collider = {
    --             render = true,
    --             shape = {
    --                 type = "regularPolygon",
    --                 radius = 48,
    --                 vertices = 6,
    --                 color = {r = 144, g = 217, b = 35}
    --             }
    --         },
    --         rigidbody = {
    --             mass = 0,
    --             isStatic = true,
    --             shape = {
    --                 type = "regularPolygon",
    --                 radius = 48,
    --                 vertices = 6,
    --                 color = {r = 144, g = 217, b = 35}
    --             }
    --         },
    --         sprite = {
    --             assetId = "Isle",
    --             width = 96,
    --             height = 96
    --         }
    --     }
    -- }
    -- ,
    -- {
    --     group = "Island",
    --     name = "Island 3",
    --     components = {
    --         transform = {
    --             position = {x = 200, y = 800}
    --         },
    --         kinematic = {},
    --         collider = {
    --             render = true,
    --             shape = {
    --                 type = "regularPolygon",
    --                 radius = 40,
    --                 vertices = 6,
    --                 color = {r = 144, g = 217, b = 35}
    --             }
    --         },
    --         rigidbody = {
    --             mass = 0,
    --             isStatic = true,
    --             shape = {
    --                 type = "regularPolygon",
    --                 radius = 40,
    --                 vertices = 6,
    --                 color = {r = 144, g = 217, b = 35}
    --             }
    --         },
    --         sprite = {
    --             assetId = "Isle",
    --             width = 96,
    --             height = 96
    --         }
    --     }
    -- }
    -- ,
    -- {
    --     group = "Island",
    --     name = "Island 4",
    --     components = {
    --         transform = {
    --             position = {x = 800, y = 800}
    --         },
    --         kinematic = {},
    --         collider = {
    --             render = true,
    --             shape = {
    --                 type = "regularPolygon",
    --                 radius = 40,
    --                 vertices = 6,
    --                 color = {r = 144, g = 217, b = 35}
    --             }
    --         },
    --         rigidbody = {
    --             mass = 0,
    --             isStatic = true,
    --             shape = {
    --                 type = "regularPolygon",
    --                 radius = 40,
    --                 vertices = 6,
    --                 color = {r = 144, g = 217, b = 35}
    --             }
    --         },
    --         sprite = {
    --             assetId = "Isle",
    --             width = 96,
    --             height = 96
    --         }
    --     }
    -- },
    {
        group = "Ocean",
        name = "Ocean",
        components = {
            transform = {
                position = {x = 500, y = 500}
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "rectangle",
                    filled = true,
                    width = 1000,
                    height = 1000,
                    color = {r = 144, g = 217, b = 35}
                }
            }
            -- sprite = {
            --     assetId = "Water",
            --     width = 96*6,
            --     height = 96
            -- }
        }
    }
}