#include "robot_simulator.h"

static robot_position_t movements[] = {
    [DIRECTION_NORTH] = {0, 1},
    [DIRECTION_SOUTH] = {0, -1},
    [DIRECTION_EAST] = {1, 0},
    [DIRECTION_WEST] = {-1, 0},
};

robot_direction_t get_next_direction(robot_direction_t current, char command)
{
  switch (current)
  {
  case DIRECTION_NORTH:
    return command = 'R' ? DIRECTION_EAST : DIRECTION_WEST;
    break;

  case DIRECTION_EAST:
    return command = 'R' ? DIRECTION_SOUTH : DIRECTION_NORTH;
    break;

  case DIRECTION_SOUTH:
    return command = 'R' ? DIRECTION_WEST : DIRECTION_EAST;
    break;

  case DIRECTION_WEST:
    return command = 'R' ? DIRECTION_NORTH : DIRECTION_SOUTH;
    break;

  default:
    return DIRECTION_MAX;
    break;
  }
}

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
  robot_status_t new_robot = {direction, {x, y}};
  return new_robot;
}

void robot_move(robot_status_t *robot, const char *commands)
{
  for (int i = 0; commands[i] != '\0'; i++)
  {
    if (commands[i] != 'A')
      robot->direction = get_next_direction(robot->direction, commands[i]);

    else
    {
      robot->position.x += movements[robot->direction].x;
      robot->position.y += movements[robot->direction].y;
    }
  }
}
