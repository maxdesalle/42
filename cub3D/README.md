# ```cub3D```
The ```cub3D``` project is inspired by the world-famous eponymous 90’s game, whichwas the first FPS ever. The purpose of it is to explore ray-casting, by creating a dynamic view inside a maze.

![](https://media.giphy.com/media/6G9sY8bDUueJKyR0fr/giphy.gif)

## How to use it

Clone the repository and get into the folder:
```bash
cd 42/cub3D/
```
Now compile the files:
```bash
make
```
If you want to play, execute the following command:
```bash
./cub3D maps/map.cub
```
If you want to save a screenshot of the initial in-game view, execute this command:
```bash
./cub3D maps/map.cub --save
```

## What I have learned
```cub3D``` was definitely not an easy project. I have had to rewrite it from scratch as my code was just becoming too messy. In order to fix this situation, I started using much shorter variable names, used a more structured architecture and changed the way the struct is organized.

Additionally, it has obviously introduced me to raycasting, a technology I hadn't heard of before that. 

## Acknowledgments
- Lode's [Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)
- César Claude's [cub3D](https://github.com/cclaude42/cub3d)
- Iciamyplant's [Cub3d-Linux](https://github.com/iciamyplant/Cub3d-Linux)
- Yaroslav Soroko's [Cub3D](https://github.com/Ysoroko/Cub3D)
- Udy Hirawale's [image processing article](https://medium.com/sysf/bits-to-bitmaps-a-simple-walkthrough-of-bmp-image-format-765dc6857393)

## Warning
The structure of this repository does **not** follow the guidelines.
The reason for this is to add some clarity in how the files are structured.

## License
Everything in this repository is released under the [Unlicense](https://github.com/maxdesalle/42/blob/main/LICENSE).
