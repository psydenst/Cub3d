# Cub3d

## Raycasting

### Introduction

Raycasting is a fundamental technique used in computer graphics to render 3D environments in real-time. It simulates the behavior of light rays to determine what objects or surfaces are visible from a specific point of view. This technique has been widely used in various applications, including video games, architectural visualization, and virtual reality. One of the most notable early examples of raycasting in video games is the iconic game Wolfenstein 3D, released in 1992.

Raycasting gained popularity during the early days of gaming due to its efficient use of computational resources. In 1992, powerful machines were not as readily available, and raycasting provided a clever alternative to more computationally expensive rendering techniques. Compared to methods like ray tracing or polygonal rendering, raycasting consumes considerably less CPU resources, making it well-suited for creating immersive 3D experiences on limited hardware.

### About the Project
This project is a 3D application that utilizes raycasting to render interactive environments. The implementation of raycasting allows for the creation of a realistic first-person perspective, enabling the user to navigate and interact with the virtual world.

### Raycasting Logic
The raycasting algorithm implemented in this project follows the following steps:

0. **Raycaster Loop**: The raycaster_loop function serves as the main loop for the raycasting process. It iterates over each pixel column of the screen and performs the necessary calculations to cast rays and render the 3D environmentent'''
 ```
 void raycaster_loop(t_raycaster *rc, t_data *data, t_frame *frame) {
    rc->screen_x = 0;
    while (rc->screen_x < SCREEN_WIDTH) {
        // Raycasting steps and calculations
        calculate_ray_position(rc);
        calculate_ray_direction(rc, data);
        rc->map_x = (int)data->pos_x;
        rc->map_y = (int)data->pos_y;
        set_delta_dist(rc);
        calculate_ray_step(rc);
        calculate_side_dist(rc, data);
        dda_loop(rc, data);
        set_wall_texture(rc, data, frame);
        calculate_camera_dist(rc);
        calculate_wall_data(rc);
        set_wall_pixel_x(rc, data);
        buffer_ceil_v_line(rc, data, frame);
        buffer_floor_v_line(rc, data, frame);
        set_texture_x(rc, data);
        buffer_wall_v_line(rc, data, frame);
        
        rc->screen_x++;
    }
    return;
}
 ```
1. **Calculate Ray Position**: The position of the ray is determined based on the screen coordinates. This step calculates the x-coordinate of the ray's position in the virtual camera space.
```
void calculate_ray_position(t_raycaster *rc) {
    rc->camera_x = 2 * rc->screen_x / (double)(SCREEN_WIDTH) - 1;
    return;
}
```
Explanation:

The function calculate_ray_position takes a t_raycaster structure pointer (rc) as an input parameter.
rc->screen_x represents the current x-coordinate of the screen pixel being processed.
SCREEN_WIDTH refers to the total width of the screen.
The calculation 2 * rc->screen_x / (double)(SCREEN_WIDTH) - 1 maps the screen coordinates to a range between -1 and 1. This is achieved by dividing rc->screen_x by SCREEN_WIDTH to normalize the value to the range [0, 1], then scaling it by 2 and subtracting 1 to obtain the range [-1, 1].
The resulting value is stored in rc->camera_x, representing the x-coordinate of the ray's position in the virtual camera space.
This calculation is essential for determining the initial position of the ray in the 3D environment and is used as a starting point for the raycasting process.

2. **Calculate Ray Direction**: [Add the description for this step]
After determining the position of the ray in the virtual camera space, we need to calculate the direction in which the ray will be cast. This is essential for accurately rendering the 3D environment. In the calculate_ray_direction function, the ray's direction vector is calculated based on the player's viewing direction and camera position.

```
void calculate_ray_direction(t_raycaster *rc, t_data *data) {
    rc->ray_dir_x = data->dir_x + data->plane_x * rc->camera_x;
    rc->ray_dir_y = data->dir_y + data->plane_y * rc->camera_x;
    return;
}
```
The calculation involves adding the player's viewing direction (data->dir_x and data->dir_y) to the camera plane values (data->plane_x and data->plane_y) scaled by the ray's position in the virtual camera space (rc->camera_x). The resulting values, rc->ray_dir_x and rc->ray_dir_y, represent the x and y components of the ray's direction vector.

This calculation determines the direction in which the ray will be cast from the player's position, enabling us to determine what objects or surfaces the ray will intersect in the 3D environment. The accurate calculation of the ray's direction is crucial for achieving realistic rendering and interaction within the virtual world.

By correctly setting the ray's direction, we ensure that the rays traverse the environment in the desired manner, providing an immersive and visually accurate representation of the 3D scene.

3. **Set Delta Dist**: [Add the description for this step]
In the raycasting algorithm, the "delta distance" (delta_dist) represents the distance that the ray must travel in the x and y directions to move from one grid cell to the next. The set_delta_dist function calculates these delta distances based on the ray's direction vector.

```
void set_delta_dist(t_raycaster *rc) {
    if (rc->ray_dir_x == 0)
        rc->delta_dist_x = INFINITY;
    else
        rc->delta_dist_x = fabs(1 / rc->ray_dir_x);
    if (rc->ray_dir_y == 0)
        rc->delta_dist_y = INFINITY;
    else
        rc->delta_dist_y = fabs(1 / rc->ray_dir_y);
    return;
}
```

The calculation involves taking the reciprocal of the ray's direction components (rc->ray_dir_x and rc->ray_dir_y) and obtaining the absolute value. This is done to ensure that the delta distances are positive.

The purpose of calculating delta distances is to determine how far the ray needs to move in the x and y directions to traverse a single grid cell in the 3D environment. These distances are crucial for implementing the Digital Differential Analyzer (DDA) algorithm, which is responsible for stepping the ray through the environment and finding intersections with walls or other objects.

By setting the delta distances, we ensure that the ray moves incrementally in a consistent manner, allowing it to accurately intersect grid cells and detect objects or walls along its path. The delta distances play a vital role in determining the precise locations where the ray intersects with the virtual environment, contributing to the realistic rendering of the 3D scene.

In summary, the set_delta_dist function calculates and assigns the delta distances for the ray's movement in the x and y directions. These distances are essential for accurately stepping the ray through the environment and determining its intersections with objects or walls.

4. **Calculate Ray Step**: Calculate Ray Step:
In order to traverse the virtual environment grid, the ray needs to determine the step direction for both the x-axis and y-axis. This step direction indicates whether the ray should move in a positive or negative direction along each axis.

The calculate_ray_step function determines the step direction based on the sign of the ray's direction components (ray_dir_x and ray_dir_y). If either component is negative, it means the ray needs to move in the negative direction along the corresponding axis. Otherwise, it moves in the positive direction.

```
void calculate_ray_step(t_raycaster *rc) {
    if (rc->ray_dir_x < 0)
        rc->step_x = -1;
    else
        rc->step_x = 1;
    if (rc->ray_dir_y < 0)
        rc->step_y = -1;
    else
        rc->step_y = 1;
    return;
}
```

By setting the step direction, the raycasting algorithm ensures that the ray moves through the grid in a consistent manner, progressing from one cell to the next. The step direction is used in the subsequent steps of the algorithm to increment or decrement the ray's position in each axis.

This calculation is crucial for maintaining the ray's trajectory and correctly traversing the virtual environment grid, allowing for accurate detection of intersections with walls and objects.

By determining the step direction, the raycasting algorithm ensures that the ray follows a straight path through the grid, moving from one cell to the next in a predictable manner. This is an essential component of the algorithm to accurately render the 3D environment and detect collisions with objects.

5. **Calculate Side Dist**:
In the raycasting process, it is necessary to determine the initial side distances from the ray's starting position to the next x-side and y-side in the virtual environment grid. These side distances help track the distance the ray needs to travel to reach the next x-side or y-side.

The calculate_side_dist function calculates the side distances (side_dist_x and side_dist_y) based on the ray's direction and its relative position within the current grid cell.

```
void calculate_side_dist(t_raycaster *rc, t_data *data) {
    if (rc->ray_dir_x < 0)
        rc->side_dist_x = (data->pos_x - rc->map_x) * rc->delta_dist_x;
    else
        rc->side_dist_x = (rc->map_x + 1.0 - data->pos_x) * rc->delta_dist_x;
    if (rc->ray_dir_y < 0)
        rc->side_dist_y = (data->pos_y - rc->map_y) * rc->delta_dist_y;
    else
        rc->side_dist_y = (rc->map_y + 1.0 - data->pos_y) * rc->delta_dist_y;
    return;
}
```

The side distances are calculated by considering the ray's direction along the x-axis and y-axis. If the ray's direction along a specific axis is negative, it means the ray is moving in the negative direction along that axis. In this case, the side distance is calculated as the difference between the current position (pos_x or pos_y) and the current grid cell position (map_x or map_y), multiplied by the corresponding delta distance (delta_dist_x or delta_dist_y).

On the other hand, if the ray's direction along a specific axis is positive, it means the ray is moving in the positive direction along that axis. In this case, the side distance is calculated as the difference between the next grid cell position and the current position, multiplied by the corresponding delta distance.

The calculated side distances are important for determining the distance the ray needs to travel to reach the next x-side or y-side in the grid. This information is used in the subsequent steps of the algorithm, such as the Digital Differential Analyzer (DDA) loop, to determine which side (x-side or y-side) the ray encounters first and to perform accurate wall intersection calculations.

I hope this explanation, along with the provided code snippet, clarifies the purpose and role of the Calculate Side Dist step in the raycasting algorithm.

6. **DDA Loop**:
The DDA (Digital Differential Analyzer) loop is a crucial part of the raycasting algorithm. DDA is used to step through the grid and check for collisions with walls. Here's an explanation of how it works:

The DDA loop continues until a collision with a wall is detected. The variable rc->hit is initially set to 0, indicating no collision.

In each iteration of the loop, the distances to the next potential intersections along the x and y axes are compared: rc->side_dist_x and rc->side_dist_y, respectively. If rc->side_dist_x is smaller, it means the next intersection is along the x axis, so the ray moves to the next grid cell horizontally.

When moving horizontally, rc->side_dist_x is incremented by rc->delta_dist_x to update the distance to the next intersection along the x axis. rc->map_x is also updated by rc->step_x, which is either -1 or 1 depending on the ray direction, to move to the next grid cell horizontally. The variable rc->side is set to 0 to indicate a horizontal intersection.

If rc->side_dist_y is smaller, it means the next intersection is along the y axis, so the ray moves to the next grid cell vertically.

When moving vertically, rc->side_dist_y is incremented by rc->delta_dist_y to update the distance to the next intersection along the y axis. rc->map_y is updated by rc->step_y, which is either -1 or 1 depending on the ray direction, to move to the next grid cell vertically. The variable rc->side is set to 1 to indicate a vertical intersection.

After updating the distances and grid positions, the code checks if the current grid cell contains a wall. If data->map.world_map[rc->map_x][rc->map_y] is equal to '1', it means there is a wall in that location, and rc->hit is set to 1 to indicate a collision.

This process continues until a wall is hit, and the DDA loop terminates.

The DDA loop plays a crucial role in tracing the ray's path through the grid and identifying the exact point of collision with walls. It allows for precise rendering of the walls and determines the intersection points required for further calculations, such as calculating the distance to the wall and applying textures

```
void dda_loop(t_raycaster *rc, t_data *data)
{
    rc->hit = 0;
    while (rc->hit == 0)
    {
        if (rc->side_dist_x < rc->side_dist_y)
        {
            rc->side_dist_x += rc->delta_dist_x;
            rc->map_x += rc->step_x;
            rc->side = 0;
        }
        else
        {
            rc->side_dist_y += rc->delta_dist_y;
            rc->map_y += rc->step_y;
            rc->side = 1;
        }
        if (data->map.world_map[rc->map_x][rc->map_y] == '1')
            rc->hit = 1;
    }
    return;
}
```

The DDA loop ensures that the ray correctly traverses the grid and stops at the first wall it encounters, allowing for accurate rendering of the 3D environment.

If you have any more questions or need further clarification, feel free to ask.

### Getting Started

To run the Cub3d project on your local machine, please follow these steps:

Download and configure the Minilibx library by following the installation instructions provided in the official Minilibx documentation. You can find the installation guide at: Minilibx Installation Guide. Make sure to choose the appropriate instructions for your operating system.

Once you have successfully installed and configured the Minilibx library, you can proceed with the Cub3d project setup.

Clone the Cub3d repository to your local machine using the following command:

```
git clone https://github.com/algacyr-melo/cub3d.git
```
Then navigate to the repository directory. Then run:

```
make
```

This will compile all the necessary source files and generate the executable file cub3d.

To launch the application with a specific map, use the following command:

```
./cub3d maps/chose_a_map
```

Then enjoy the 3D rendering :)
