#! /bin/bash
gcc -o bin/p main.c libs/player.c libs/enemies.c libs/score.c -lallegro -lallegro_primitives -lallegro_ttf -lallegro_font
echo "compiled succesfully ---- file in bin/"
echo "running..."
bin/p
echo "process terminated."
