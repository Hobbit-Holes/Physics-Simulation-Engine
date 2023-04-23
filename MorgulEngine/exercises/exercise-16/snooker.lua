Vec2.UnitVector = function(self)
    local normal = math.sqrt(self.x * self.x + self.y * self.y)
    return Vec2(self.x / normal, self.y / normal)
end

Vec2.Normal = function(self)
    return Vec2(-self.y, self.x)
end

Vec2.Normal2 = function(self)
    return Vec2(self.y, -self.x)
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
                    local t = get_position(entity, world)
                    local k = get_velocity(entity, world)
            
                    if t.x < 70 and t.x > 30 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        t.x = t.x + (70 - t.x) + 0.1
                        set_position(t.x + (70 - t.x) + 0.1, t.y)

                    elseif t.x > 730 and t.x < 770 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x - (t.x - 730) + 0.1, t.y)
                    end
            
                    if t.y < 220 and t.y > 180 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x, t.y + (220 - t.y) + 0.1)

                    elseif t.y > 580 and t.y < 620 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end

                        set_position(t.x, t.y - (580 - t.y) + 0.1)
                    end
                    
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
                    local t = get_position(entity, world)
                    local k = get_velocity(entity, world)
            
                    if t.x < 70 and t.x > 30 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        t.x = t.x + (70 - t.x) + 0.1
                        set_position(t.x + (70 - t.x) + 0.1, t.y)

                    elseif t.x > 730 and t.x < 770 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x - (t.x - 730) + 0.1, t.y)
                    end
            
                    if t.y < 220 and t.y > 180 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x, t.y + (220 - t.y) + 0.1)

                    elseif t.y > 580 and t.y < 620 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end

                        set_position(t.x, t.y - (580 - t.y) + 0.1)
                    end
                    
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
                    local t = get_position(entity, world)
                    local k = get_velocity(entity, world)
            
                    if t.x < 70 and t.x > 30 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        t.x = t.x + (70 - t.x) + 0.1
                        set_position(t.x + (70 - t.x) + 0.1, t.y)

                    elseif t.x > 730 and t.x < 770 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x - (t.x - 730) + 0.1, t.y)
                    end
            
                    if t.y < 220 and t.y > 180 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x, t.y + (220 - t.y) + 0.1)

                    elseif t.y > 580 and t.y < 620 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end

                        set_position(t.x, t.y - (580 - t.y) + 0.1)
                    end
                    
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
                    local t = get_position(entity, world)
                    local k = get_velocity(entity, world)
            
                    if t.x < 70 and t.x > 30 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        t.x = t.x + (70 - t.x) + 0.1
                        set_position(t.x + (70 - t.x) + 0.1, t.y)

                    elseif t.x > 730 and t.x < 770 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x - (t.x - 730) + 0.1, t.y)
                    end
            
                    if t.y < 220 and t.y > 180 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x, t.y + (220 - t.y) + 0.1)

                    elseif t.y > 580 and t.y < 620 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end

                        set_position(t.x, t.y - (580 - t.y) + 0.1)
                    end
                    
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
                    local t = get_position(entity, world)
                    local k = get_velocity(entity, world)
            
                    if t.x < 70 and t.x > 30 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        t.x = t.x + (70 - t.x) + 0.1
                        set_position(t.x + (70 - t.x) + 0.1, t.y)

                    elseif t.x > 730 and t.x < 770 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x - (t.x - 730) + 0.1, t.y)
                    end
            
                    if t.y < 220 and t.y > 180 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x, t.y + (220 - t.y) + 0.1)

                    elseif t.y > 580 and t.y < 620 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end

                        set_position(t.x, t.y - (580 - t.y) + 0.1)
                    end
                    
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
                    local t = get_position(entity, world)
                    local k = get_velocity(entity, world)
            
                    if t.x < 70 and t.x > 30 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        t.x = t.x + (70 - t.x) + 0.1
                        set_position(t.x + (70 - t.x) + 0.1, t.y)

                    elseif t.x > 730 and t.x < 770 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x - (t.x - 730) + 0.1, t.y)
                    end
            
                    if t.y < 220 and t.y > 180 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x, t.y + (220 - t.y) + 0.1)

                    elseif t.y > 580 and t.y < 620 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end

                        set_position(t.x, t.y - (580 - t.y) + 0.1)
                    end
                    
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
                    local t = get_position(entity, world)
                    local k = get_velocity(entity, world)
            
                    if t.x < 70 and t.x > 30 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        t.x = t.x + (70 - t.x) + 0.1
                        set_position(t.x + (70 - t.x) + 0.1, t.y)

                    elseif t.x > 730 and t.x < 770 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x - (t.x - 730) + 0.1, t.y)
                    end
            
                    if t.y < 220 and t.y > 180 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x, t.y + (220 - t.y) + 0.1)

                    elseif t.y > 580 and t.y < 620 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end

                        set_position(t.x, t.y - (580 - t.y) + 0.1)
                    end
                    
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
                    local t = get_position(entity, world)
                    local k = get_velocity(entity, world)
            
                    if t.x < 70 and t.x > 30 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        t.x = t.x + (70 - t.x) + 0.1
                        set_position(t.x + (70 - t.x) + 0.1, t.y)

                    elseif t.x > 730 and t.x < 770 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x - (t.x - 730) + 0.1, t.y)
                    end
            
                    if t.y < 220 and t.y > 180 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x, t.y + (220 - t.y) + 0.1)

                    elseif t.y > 580 and t.y < 620 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end

                        set_position(t.x, t.y - (580 - t.y) + 0.1)
                    end
                    
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
                    local t = get_position(entity, world)
                    local k = get_velocity(entity, world)
            
                    if t.x < 70 and t.x > 30 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        t.x = t.x + (70 - t.x) + 0.1
                        set_position(t.x + (70 - t.x) + 0.1, t.y)

                    elseif t.x > 730 and t.x < 770 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x - (t.x - 730) + 0.1, t.y)
                    end
            
                    if t.y < 220 and t.y > 180 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x, t.y + (220 - t.y) + 0.1)

                    elseif t.y > 580 and t.y < 620 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end

                        set_position(t.x, t.y - (580 - t.y) + 0.1)
                    end
                    
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
                    local t = get_position(entity, world)
                    local k = get_velocity(entity, world)
            
                    if t.x < 70 and t.x > 30 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        t.x = t.x + (70 - t.x) + 0.1
                        set_position(t.x + (70 - t.x) + 0.1, t.y)

                    elseif t.x > 730 and t.x < 770 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x - (t.x - 730) + 0.1, t.y)
                    end
            
                    if t.y < 220 and t.y > 180 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x, t.y + (220 - t.y) + 0.1)

                    elseif t.y > 580 and t.y < 620 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end

                        set_position(t.x, t.y - (580 - t.y) + 0.1)
                    end
                    
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
                    local t = get_position(entity, world)
                    local k = get_velocity(entity, world)
            
                    if t.x < 70 and t.x > 30 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        t.x = t.x + (70 - t.x) + 0.1
                        set_position(t.x + (70 - t.x) + 0.1, t.y)

                    elseif t.x > 730 and t.x < 770 then
                        if k.y > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x - (t.x - 730) + 0.1, t.y)
                    end
            
                    if t.y < 220 and t.y > 180 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end
            
                        set_position(entity, world, t.x, t.y + (220 - t.y) + 0.1)

                    elseif t.y > 580 and t.y < 620 then
                        if k.x > 0 then
                            local velocity = k
                            k = k:UnitVector():Normal2()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        else
                            local velocity = k
                            k = k:UnitVector():Normal()
                            set_velocity(entity, world, math.abs(velocity.x) * k.x, math.abs(velocity.y) * k.y)
                        end

                        set_position(t.x, t.y - (580 - t.y) + 0.1)
                    end
                    
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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
            kinematic = {
                velocity = {x = 0, y = 0},
            },
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


