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

drag = 100

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

player = {
    x = table.position.x + 150,
    y = table.position.y,
    radius = ballsRadius,
    color = {
        r = 255,
        g = 255,
        b = 255
    }
}

enemies = {
    {
        x = table.position.x - 100,
        y = table.position.y,
        radius = ballsRadius,
        color = {
            r = 255,
            g = 255,
            b = 255
        }
    },
    {
        x = table.position.x - 130,
        y = table.position.y - 15,
        radius = ballsRadius,
        color = {
            r = 255,
            g = 255,
            b = 255
        }
    },
    {
        x = table.position.x - 130,
        y = table.position.y + 15,
        radius = ballsRadius,
        color = {
            r = 255,
            g = 255,
            b = 255
        }
    },
    {
        x = table.position.x - 160,
        y = table.position.y - 30,
        radius = ballsRadius,
        color = {
            r = 255,
            g = 255,
            b = 255
        }
    },
    {
        x = table.position.x - 160,
        y = table.position.y,
        radius = ballsRadius,
        color = {
            r = 255,
            g = 255,
            b = 255
        }
    },
    {
        x = table.position.x - 160,
        y = table.position.y + 30,
        radius = ballsRadius,
        color = {
            r = 255,
            g = 255,
            b = 255
        }
    },
    {
        x = table.position.x - 190,
        y = table.position.y - 45,
        radius = ballsRadius,
        color = {
            r = 255,
            g = 255,
            b = 255
        }
    },
    {
        x = table.position.x - 190,
        y = table.position.y - 15,
        radius = ballsRadius,
        color = {
            r = 255,
            g = 255,
            b = 255
        }
    },
    {
        x = table.position.x - 190,
        y = table.position.y + 15,
        radius = ballsRadius,
        color = {
            r = 255,
            g = 255,
            b = 255
        }
    },
    {
        x = table.position.x - 190,
        y = table.position.y + 45,
        radius = ballsRadius,
        color = {
            r = 255,
            g = 255,
            b = 255
        }
    }
}

holes = {
    {
        x = table.position.x - table.width/2,
        y = table.position.y - table.heigth/2,
        radius = holeRadius,
        color = holeColor
    },
    {
        x = table.position.x,
        y = table.position.y - table.heigth/2,
        radius = holeRadius,
        color = holeColor
    },
    {
        x = table.position.x + table.width/2,
        y = table.position.y - table.heigth/2,
        radius = holeRadius,
        color = holeColor
    },
    {
        x = table.position.x - table.width/2,
        y = table.position.y + table.heigth/2,
        radius = holeRadius,
        color = holeColor
    },
    {
        x = table.position.x,
        y = table.position.y + table.heigth/2,
        radius = holeRadius,
        color = holeColor
    },
    {
        x = table.position.x + table.width/2,
        y = table.position.y + table.heigth/2,
        radius = holeRadius,
        color = holeColor
    }
}

floor = {
    x = table.position.x,
    y = table.position.y,
    width = table.width,
    heigth = table.heigth,
    color = {
        r = 0,
        g = 143,
        b = 57
    }
}

walls = {
    {
        x = table.position.x,
        y = table.position.y - table.heigth/2,
        width = table.width,
        heigth = wallDeep,
        color = wallColor
    },
    {
        x = table.position.x,
        y = table.position.y + table.heigth/2,
        width = table.width,
        heigth = wallDeep,
        color = wallColor
    },
    {
        x = table.position.x - table.width/2,
        y = table.position.y,
        width = wallDeep,
        heigth = table.heigth,
        color = wallColor
    },
    {
        x = table.position.x + table.width/2,
        y = table.position.y,
        width = wallDeep,
        heigth = table.heigth,
        color = wallColor
    }
}