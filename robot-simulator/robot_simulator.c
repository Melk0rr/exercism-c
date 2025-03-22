#include "robot_simulator.h"

static robot_position_t movements[] = {
    [DIRECTION_NORTH] = {0, 1},
    [DIRECTION_SOUTH] = {0, -1},
    [DIRECTION_EAST] = {1, 0},
    [DIRECTION_WEST] = {-1, 0},
};

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
  robot_status_t new_robot = {direction, {x, y}};
  return new_robot;
}

void robot_move(robot_status_t *robot, const char *commands)
{
  for (unsigned int i = 0; commands[i] != '\0'; i++)
  {
    if (commands[i] != 'A')
      robot->direction = commands[i] == 'R' ? (robot->direction + 1) % 4
                                            : (robot->direction + 3) % 4;
    else
      robot->position = (robot_position_t){
          .x = robot->position.x + movements[robot->direction].x,
          .y = robot->position.y + movements[robot->direction].y};
  }
}
