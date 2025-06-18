import pygame
import random

# Initialize pygame
pygame.init()

# Set up display
screen = pygame.display.set_mode((400, 400))
pygame.display.set_caption("Pac-Man")

# Define colors
BLACK = (0, 0, 0)
YELLOW = (255, 255, 0)

# Set up Pac-Man properties
pacman_pos = [50, 50]
pacman_size = 20
pacman_speed = 20

# Main game loop
running = True
while running:
    screen.fill(BLACK)
   
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
   
    keys = pygame.key.get_pressed()
   
    # Move Pac-Man with arrow keys
    if keys[pygame.K_LEFT]:
        pacman_pos[0] -= pacman_speed
    if keys[pygame.K_RIGHT]:
        pacman_pos[0] += pacman_speed
    if keys[pygame.K_UP]:
        pacman_pos[1] -= pacman_speed
    if keys[pygame.K_DOWN]:
        pacman_pos[1] += pacman_speed
   
    # Draw Pac-Man (as a yellow circle)
    pygame.draw.circle(screen, YELLOW, pacman_pos, pacman_size)
   
    pygame.display.flip()
    pygame.time.wait(100)

# Quit the game
pygame.quit()