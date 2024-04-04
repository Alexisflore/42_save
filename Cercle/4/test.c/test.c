#include <stdio.h>
#include <math.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 40
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

void cast_rays(Player *player);

int main() {
    Player player = {3, 3, M_PI / 2}; // Player starts at position (3, 3) facing upwards

    cast_rays(&player);

    return 0;
}

void cast_rays(Player *player) {
    for (int ray_index = 0; ray_index < NUM_RAYS; ray_index++) {
        float ray_angle = player->angle - FOV_ANGLE / 2 + (ray_index * FOV_ANGLE / SCREEN_WIDTH);

        Ray ray;
        ray.x = cos(ray_angle);
        ray.y = sin(ray_angle);

        // Find intersection point with walls
        // This is a simplified step; you may need to implement collision detection with walls
        float intersection_x = player->x + ray.x * 5; // Assuming a fixed distance for simplicity
        float intersection_y = player->y + ray.y * 5; // Assuming a fixed distance for simplicity

        // Calculate distance from player to intersection point
        float distance = sqrt(pow(intersection_x - player->x, 2) + pow(intersection_y - player->y, 2));

        // Calculate projected wall height (simplified)
        int wall_height = SCREEN_HEIGHT / distance * 5; // Arbitrary multiplier for height

        // Render the wall segment
        for (int y = 0; y < SCREEN_HEIGHT; y++) {
            if (y < SCREEN_HEIGHT / 2 - wall_height / 2 || y > SCREEN_HEIGHT / 2 + wall_height / 2) {
                printf(" "); // Empty space
            } else {
                printf("#"); // Wall segment
            }
        }

        printf("\n");
    }
}