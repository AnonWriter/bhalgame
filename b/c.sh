#! /bin/bash
gcc -o bin/p main.c libs/player.c -lallegro -lallegro_primitives -lallegro_ttf -lallegro_font
echo "compiled succefully ---- file in bin/"
