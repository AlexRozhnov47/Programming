import pygame, math
from pygame import *
from math import *

WIN_WIDTH = 800
WIN_HEIGHT = 800
SAT_WIDTH = 2
SAT_HEIGHT = 2
DISPLAY = (WIN_WIDTH, WIN_HEIGHT)
SPACE_COLOR = "#000022"
EARTH_COLOR = "blue"
SAT_COLOR = "grey"

#Earth position
X0 = WIN_WIDTH // 2
Y0 = WIN_HEIGHT // 2
#Sat mass
M0 = 2600
#Stop conditions
CRASH_DIST = 10
OUT_DIST = 1000

def main():
    #PyGame init
    pygame.init()
    screen = pygame.display.set_mode(DISPLAY)
    pygame.display.set_caption("Satteite spin mechanics")
    
    #Space init
    bg = Surface((WIN_WIDTH,WIN_HEIGHT))
    bg.fill(Color(SPACE_COLOR))     
    draw.circle (bg, Color(EARTH_COLOR), (X0, Y0), 100)
                    
    #Timer init                     
    timer = pygame.time.Clock()
    
    #Sat init
    sattelite = Surface((SAT_WIDTH, SAT_HEIGHT))
    sattelite.fill(Color(SPACE_COLOR))
    draw.circle (sattelite,
        Color(SAT_COLOR),
        (SAT_WIDTH // 2, SAT_HEIGHT // 2),
        5)

    #Sattelite to Earth distance
    r = 0.0
    #Initial sat pos, speed and accel
    x = WIN_WIDTH // 3
    y = WIN_HEIGHT // 3
    vx = 1.001
    vy = 1.505
    ax = 0.0
    ay = 0.0

    done = False
    while not done:
        timer.tick(50)
        for e in pygame.event.get():
            if e.type == QUIT:
                done = True
                break        

        r = sqrt((x - X0)**2 + (y - Y0)**2)
        
        ax = M0 * (X0 - x) / r**3.1
        ay = M0 * (Y0 - y) / r**3.1

        #New spped based on accel
        vx += ax
        vy += ay

        #New pos based on speed
        x += vx
        y += vy

        screen.blit(bg, (0, 0))      
        screen.blit(sattelite, (int(x), int(y)))
        pygame.display.update()     

        if r < CRASH_DIST:
            done = True
            print("Crashed")
            break
        if r > OUT_DIST:
            done = True
            print("Out of system")
            break

    #Farewell
    print (":-)")

if __name__ == "__main__":
    main()
