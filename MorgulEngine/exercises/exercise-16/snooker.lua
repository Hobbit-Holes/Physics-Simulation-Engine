Vec2.UnitVector = function(self)
    local normal = math.sqrt(self.x * self.x + self.y * self.y)
    local res = self
    res.x = self.x / normal
    res.y =  self.y / normal
    return res
end

Vec2.Normal = function(self)
    local x = self.x
    local y = self.y
    self.x = -y
    self.y = x
    return self
end

Vec2.Normal2 = function(self)
    local x = self.x
    local y = self.y
    self.x = y
    self.y = -x
    return self
end

function Boundaries(entity, world, delta_time, ellpsed_time)
    local t = get_position(entity, world)
    local k = get_velocity(entity, world)

    if t.x < 70 and t.x > 30 then
        local velocity = get_velocity(entity, world)
        k = k:UnitVector()

        if k.y > 0 then
            k = k:Normal2()
        else
            k = k:Normal()
        end

        set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
        set_position(entity, world, t.x + (70 - t.x) + 0.1, t.y)

    elseif t.x > 730 and t.x < 770 then
        local velocity = get_velocity(entity, world)
        k = k:UnitVector()

        if k.y > 0 then
            k = k:Normal()
        else
            k = k:Normal2()
        end

        set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
        set_position(entity, world, t.x - (t.x - 730) + 0.1, t.y)
    end

    if t.y < 220 and t.y > 180 then
        local velocity = get_velocity(entity, world)
        k = k:UnitVector()

        if k.x > 0 then
            k = k:Normal()
        else
            k = k:Normal2()
        end

        set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
        set_position(entity, world, t.x, t.y + (220 - t.y) + 0.1)

    elseif t.y > 580 and t.y < 620 then
        local velocity = get_velocity(entity, world)
        k = k:UnitVector()

        if k.x > 0 then
            k = k:Normal2()
        else
            k = k:Normal()
        end

        set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
        set_position(entity, world, t.x, t.y - (t.y - 580) + 0.1)
    end
end

dragImpulse = 100

ballsRadius = 12

holeRadius = 30
holeColor = {
    r = 155,
    g = 155,
    b = 155
}

wallDeep = 1.25 * ballsRadius
wallColor = {
    r = 125,
    g = 85,
    b = 0
}

table = {
    position = {
        x = 400,
        y = 400
    },
    width = 700,
    heigth = 400,
    color = {
        r = 24,
        g = 87,
        b = 41
    }
}

entities = {
    {
        group = "Player",
        name = "Player",
        components = {
            transform = {
                position = {x = table.position.x + 150, y = table.position.y},
            },
            kinematic = {},
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 255, g = 255, b = 255}
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 255, g = 255, b = 255},
                    filled = true
                }
            },
            damage = {
                position = {x = 500, y = 400}
            },
            on_update_script = {
                function(entity, world, delta_time, ellpsed_time)
                    Boundaries(entity, world, delta_time, ellpsed_time)
                end
            }
        }
    },
    {
        group = "Enemy",
        name = "Enemy 1",
        components = {
            transform = {
                position = {x = table.position.x - 100, y = table.position.y},
            },
            kinematic = {},
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 255, g = 215, b = 0}
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 255, g = 215, b = 0},
                    filled = true
                }
            },
            damage = {
                position = {x = 100, y = 100}
            },
            on_update_script = {
                function(entity, world, delta_time, ellpsed_time)
                    Boundaries(entity, world, delta_time, ellpsed_time)
                end
            }
        }
    },
    {
        group = "Enemy",
        name = "Enemy 2",
        components = {
            transform = {
                position = {x = table.position.x - 130, y = table.position.y - 15},
            },
            kinematic = {},
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 205, g = 92, b = 92}
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 205, g = 92, b = 92},
                    filled = true
                }
            },
            damage = {
                position = {x = 150, y = 100}
            },
            on_update_script = {
                function(entity, world, delta_time, ellpsed_time)
                    Boundaries(entity, world, delta_time, ellpsed_time)
                end
            }
        }
    },
    {
        group = "Enemy",
        name = "Enemy 3",
        components = {
            transform = {
                position = {x = table.position.x - 130, y = table.position.y + 15},
            },
            kinematic = {},
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 72, g = 61, b = 139}
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 72, g = 61, b = 139},
                    filled = true
                }
            },
            damage = {
                position = {x = 200, y = 100}
            },
            on_update_script = {
                function(entity, world, delta_time, ellpsed_time)
                    Boundaries(entity, world, delta_time, ellpsed_time)
                end
            }
        }
    },
    {
        group = "Enemy",
        name = "Enemy 4",
        components = {
            transform = {
                position = {x = table.position.x - 160, y = table.position.y - 30},
            },
            kinematic = {},
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 0, g = 191, b = 255}
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 0, g = 191, b = 255},
                    filled = true
                }
            },
            damage = {
                position = {x = 250, y = 100}
            },
            on_update_script = {
                function(entity, world, delta_time, ellpsed_time)
                    Boundaries(entity, world, delta_time, ellpsed_time)
                end
            }
        }
    },
    {
        group = "Enemy",
        name = "Enemy 5",
        components = {
            transform = {
                position = {x = table.position.x - 160, y = table.position.y},
            },
            kinematic = {},
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 105, g = 105, b = 105}
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 105, g = 105, b = 105},
                    filled = true
                }
            },
            damage = {
                position = {x = 300, y = 100}
            },
            on_update_script = {
                function(entity, world, delta_time, ellpsed_time)
                    Boundaries(entity, world, delta_time, ellpsed_time)
                end
            }
        }
    },
    {
        group = "Enemy",
        name = "Enemy 6",
        components = {
            transform = {
                position = {x = table.position.x - 160, y = table.position.y + 30},
            },
            kinematic = {},
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 128, g = 0, b = 0}
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 128, g = 0, b = 0},
                    filled = true
                }
            },
            damage = {
                position = {x = 350, y = 100}
            },
            on_update_script = {
                function(entity, world, delta_time, ellpsed_time)
                    Boundaries(entity, world, delta_time, ellpsed_time)
                end
            }
        }
    },
    {
        group = "Enemy",
        name = "Enemy 7",
        components = {
            transform = {
                position = {x = table.position.x - 190, y = table.position.y - 45},
            },
            kinematic = {},
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 186, g = 85, b = 211}
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 186, g = 85, b = 211},
                    filled = true
                }
            },
            damage = {
                position = {x = 400, y = 100}
            },
            on_update_script = {
                function(entity, world, delta_time, ellpsed_time)
                    Boundaries(entity, world, delta_time, ellpsed_time)
                end
            }
        }
    },
    {
        group = "Enemy",
        name = "Enemy 8",
        components = {
            transform = {
                position = {x = table.position.x - 190, y = table.position.y - 15},
            },
            kinematic = {},
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 255, g = 69, b = 0}
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 255, g = 69, b = 0},
                    filled = true
                }
            },
            damage = {
                position = {x = 450, y = 100}
            },
            on_update_script = {
                function(entity, world, delta_time, ellpsed_time)
                    Boundaries(entity, world, delta_time, ellpsed_time)
                end
            }
        }
    },
    {
        group = "Enemy",
        name = "Enemy 9",
        components = {
            transform = {
                position = {x = table.position.x - 190, y = table.position.y + 15},
            },
            kinematic = {},
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 255, g = 0, b = 0}
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 255, g = 0, b = 0},
                    filled = true
                }
            },
            damage = {
                position = {x = 500, y = 100}
            },
            on_update_script = {
                function(entity, world, delta_time, ellpsed_time)
                    Boundaries(entity, world, delta_time, ellpsed_time)
                end
            }
        }
    },
    {
        group = "Enemy",
        name = "Enemy 10",
        components = {
            transform = {
                position = {x = table.position.x - 190, y = table.position.y + 45},
            },
            kinematic = {},
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 255, g = 200, b = 80}
                }
            },
            rigidbody = {
                mass = 1,
                shape = {
                    type = "circle",
                    radius = ballsRadius,
                    color = {r = 255, g = 200, b = 80},
                    filled = true
                }
            },
            damage = {
                position = {x = 550, y = 100}
            },
            on_update_script = {
                function(entity, world, delta_time, ellpsed_time)
                    Boundaries(entity, world, delta_time, ellpsed_time)
                end
            }
        }
    },
    {
        group = "Hole",
        name = "Hole 1",
        components = {
            transform = {
                position = {x = table.position.x - table.width/2, y = table.position.y - table.heigth/2},
            },
            kinematic = {},
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = holeRadius,
                    color = holeColor
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "circle",
                    radius = holeRadius,
                    color = holeColor,
                    filled = true
                }
            }
        }
    },
    {
        group = "Hole",
        name = "Hole 2",
        components = {
            transform = {
                position = {x = table.position.x, y = table.position.y - table.heigth/2},
            },
            kinematic = {},
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = holeRadius,
                    color = holeColor
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "circle",
                    radius = holeRadius,
                    color = holeColor,
                    filled = true
                }
            }
        }
    },
    {
        group = "Hole",
        name = "Hole 3",
        components = {
            transform = {
                position = {x = table.position.x + table.width/2, y = table.position.y - table.heigth/2},
            },
            kinematic = {},
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = holeRadius,
                    color = holeColor
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "circle",
                    radius = holeRadius,
                    color = holeColor,
                    filled = true
                }
            }
        }
    },
    {
        group = "Hole",
        name = "Hole 4",
        components = {
            transform = {
                position = {x = table.position.x - table.width/2, y = table.position.y + table.heigth/2},
            },
            kinematic = {},
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = holeRadius,
                    color = holeColor
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "circle",
                    radius = holeRadius,
                    color = holeColor,
                    filled = true
                }
            }
        }
    },
    {
        group = "Hole",
        name = "Hole 5",
        components = {
            transform = {
                position = {x = table.position.x, y = table.position.y + table.heigth/2},
            },
            kinematic = {},
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = holeRadius,
                    color = holeColor
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "circle",
                    radius = holeRadius,
                    color = holeColor,
                    filled = true
                }
            }
        }
    },
    {
        group = "Hole",
        name = "Hole 6",
        components = {
            transform = {
                position = {x = table.position.x + table.width/2, y = table.position.y + table.heigth/2},
            },
            kinematic = {},
            collider = {
                render = false,
                shape = {
                    type = "circle",
                    radius = holeRadius,
                    color = holeColor
                }
            },
            rigidbody = {
                mass = 0,
                isStatic = true,
                shape = {
                    type = "circle",
                    radius = holeRadius,
                    color = holeColor,
                    filled = true
                }
            }
        }
    },
    {
        group = "Wall",
        name = "Wall 1",
        components = {
            transform = {
                position = {x = table.position.x, y = table.position.y - table.heigth/2},
            },
            kinematic = {},
            rigidbody = {
                mass = 1,
                shape = {
                    type = "rectangle",
                    width = table.width,
                    height = wallDeep,
                    color = wallColor,
                    filled = true
                }
            }
        }
    },
    {
        group = "Wall",
        name = "Wall 2",
        components = {
            transform = {
                position = {x = table.position.x, y = table.position.y + table.heigth/2},
            },
            kinematic = {},
            rigidbody = {
                mass = 1,
                shape = {
                    type = "rectangle",
                    width = table.width,
                    height = wallDeep,
                    color = wallColor,
                    filled = true
                }
            }
        }
    },
    {
        group = "Wall",
        name = "Wall 3",
        components = {
            transform = {
                position = {x = table.position.x - table.width/2, y = table.position.y},
            },
            kinematic = {},
            rigidbody = {
                mass = 1,
                shape = {
                    type = "rectangle",
                    width = wallDeep,
                    height = table.heigth,
                    color = wallColor,
                    filled = true
                }
            }
        }
    },
    {
        group = "Wall",
        name = "Wall 4",
        components = {
            transform = {
                position = {x = table.position.x + table.width/2, y = table.position.y},
            },
            kinematic = {},
            rigidbody = {
                mass = 1,
                shape = {
                    type = "rectangle",
                    width = wallDeep,
                    height = table.heigth,
                    color = wallColor,
                    filled = true
                }
            }
        }
    },
    {
        group = "Floor",
        name = "Floor",
        components = {
            transform = {
                position = {x = table.position.x, y = table.position.y},
            },
            kinematic = {},
            rigidbody = {
                mass = 1,
                shape = {
                    type = "rectangle",
                    width = 700,
                    height = 400,
                    color = {r = 0, g = 143, b = 57},
                    filled = true
                }
            }
        }
    }
}
