print("Hola")

ballsRadius = 15
holeSize = 40
holeColor = {
    r = 66,
    g = 66,
    b = 66
}

wallDeep = 2 * ballsRadius
wallColor = {
    r = 87,
    g = 48,
    b = 24
}

drag = 100

table = {
    position = {
        x = 500,
        y = 400
    },
    width = 850,
    height = 450,
    color = {
        r = 24,
        g = 87,
        b = 41
    }
}

walls = {
    {
        x = table.position.x - table.width/4,
        y = table.position.y - table.height/2,
        width = table.width/2 - 2.5 * holeSize,
        height = wallDeep,
        color = wallColor
    },
    {
        x = table.position.x - table.width/2,
        y = table.position.y - table.height/4,
        width = table.width/2 - 2.5 * holeSize,
        height = wallDeep,
        color = wallColor
    }
}