#include <stdio.h>
#include <math.h>
#include "minilibx_opengl/mlx.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 400
#define FOV_ANGLE (M_PI / 3)
#define NUM_RAYS SCREEN_WIDTH

typedef struct {
    float x;
    float y;
    float angle;
} Player;

typedef struct {
    float x;
    float y;
} Ray;

void draw_ray(int x, int y, int height, void *mlx_ptr, void *win_ptr);

int main() {
    void *mlx_ptr;
    void *win_ptr;
    Player player = {3, 3, M_PI / 2}; // Player starts at position (3, 3) facing upwards

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "Raycasting Demo");

    // Render scene
    for (int ray_index = 0; ray_index < NUM_RAYS; ray_index++) {
        float ray_angle = player.angle - FOV_ANGLE / 2 + (ray_index * FOV_ANGLE / SCREEN_WIDTH);

        Ray ray;
        ray.x = cos(ray_angle);
        ray.y = sin(ray_angle);

        // Find intersection point with walls
        // This is a simplified step; you may need to implement collision detection with walls
        float intersection_x = player.x + ray.x * 5; // Assuming a fixed distance for simplicity
        float intersection_y = player.y + ray.y * 5; // Assuming a fixed distance for simplicity

        // Calculate distance from player to intersection point
        float distance = sqrt(pow(intersection_x - player.x, 2) + pow(intersection_y - player.y, 2));

        // Calculate projected wall height (simplified)
        int wall_height = SCREEN_HEIGHT / distance * 5; // Arbitrary multiplier for height

        // Draw the ray on the screen
        draw_ray(ray_index, SCREEN_HEIGHT / 2 - wall_height / 2, wall_height, mlx_ptr, win_ptr);
    }

    mlx_loop(mlx_ptr);

    return 0;
}

void draw_ray(int x, int y, int height, void *mlx_ptr, void *win_ptr) {
    int color = 0xFFFFFF; // White color for ray (you can change this)
    
    // Draw the ray on the screen
    for (int i = y; i < y + height; i++) {
        mlx_pixel_put(mlx_ptr, win_ptr, x, i, color);
    }
}