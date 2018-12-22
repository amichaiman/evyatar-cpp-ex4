cmake_minimum_required(VERSION 3.10)
project(evyatar_generic_tree)

set(CMAKE_CXX_STANDARD 98)

add_executable(evyatar_generic_tree main.cpp Tree.h Node.h Arena.cpp Arena.h Game.cpp Game.h Group.cpp Group.h Limits.cpp Limits.h Player.h Player.cpp Point.cpp Point.h SpeedVector.cpp SpeedVector.h Spot.cpp Spot.h Forwards.cpp Forwards.h Defencemen.cpp Defencemen.h Goalie.cpp Goalie.h PlayerTree.h)