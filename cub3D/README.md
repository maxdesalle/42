# ```cub3D```
The ```cub3D``` project is inspired by the world-famous eponymous 90’s game, which was the first FPS ever. The purpose of it is to explore ray-casting, by creating a dynamic view inside a maze.

The way ray-casting works is that, from the player's perspective, rays are sent to each pixel column in order to calculate the distance at which these columns are from the player. This forces every game leveraging ray-casting to be in 2D, as it's essentially just bringing perspective in an image. Additionally, this makes it impossiblet to have vertical levels, so you can't have stairs, or jump in these types of games.

Most available maps (except the first one) were created by [Yaroslav Soroko](https://github.com/ysoroko).

<p align="center">
	<img src="https://media.giphy.com/media/6G9sY8bDUueJKyR0fr/giphy.gif" width="50%" />
</p>

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
```cub3D``` was definitely not an easy project. I had to rewrite it from scratch near the end as my code was just becoming too messy. In order to fix this situation, I started using much shorter variable names, used a more structured architecture and changed the way the main struct is organized.

But most importantly, it taught me the importance of clean code, and planning the architecture before starting to code, instead of doing it while coding. This was my big mistake. I hadn't really planned how to do things beforehand, which made me lose a lot of valuable time.

Additionally, it has obviously introduced me to raycasting, a technology I hadn't heard of before that. 

## Acknowledgments
- Lode's [Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)
- César Claude's [cub3D](https://github.com/cclaude42/cub3d)
- Iciamyplant's [Cub3d-Linux](https://github.com/iciamyplant/Cub3d-Linux)
- Yaroslav Soroko's [Cub3D](https://github.com/Ysoroko/Cub3D)
- Udy Hirawale's [image processing article](https://medium.com/sysf/bits-to-bitmaps-a-simple-walkthrough-of-bmp-image-format-765dc6857393)
- Dustin Krecisz's [cub3d_destroyer](https://github.com/Dustin42Codam/cub3d_destroyer)

## Warning
The structure of this repository does **not** follow the guidelines.
The reason for this is to add some clarity in how the files are structured.

## License
Everything in this repository is released under the [Unlicense](https://github.com/maxdesalle/42/blob/main/LICENSE).
