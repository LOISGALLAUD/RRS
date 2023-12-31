# CMAKE_BINARY_DIR est le répertoire d’où sera lancée la commande cmake, à savoir build
# S’assure que la version de make est suffisamment récente
cmake_minimum_required(VERSION 2.6)
# Indique le nom du projet
project(demo_cpp)
# Impose le répertoire de création du fichier exécutable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Impose le répertoire des fichiers source
set(CMAKE_CURRENT_SOURCE_DIR ${CMAKE_BINARY_DIR}/../src)
# Ajoute le répertoire include des fichiers .h au chemin de recherche des #include "xx.h"
include_directories(${CMAKE_BINARY_DIR}/../include)
# Impose certaines options de compilation
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Wextra -Wpedantic")
# Génère la liste des fichiers .cpp devant être compilés
file(
   GLOB_RECURSE
   srcFiles
   ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)
add_executable(
   rrs
   ${srcFiles}
)
