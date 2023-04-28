# 42Madrid-so_long:

The so_long project is a simple 2D game that we must implement at 42School. The game consists of a player, an exit point and a number of collectible objects, which the player must gather before reaching the exit.

![Bonus example](./res/result/bonus_example.gif)

## Playing the Game
To play the so_long game, run the following command:

```bash
./so_long [map_path]
```
`map_path` is the path to the game map file that you want to play.
The game map file must be a valid `.ber` file containing the game map.

The player can move around the game map using the arrow keys or WASD. The game ends when the player reaches the exit point after collecting all the collectible objects.

## Compiling the Program
The so_long program comes with a Makefile that includes the following rules:

- `all`: compiles the program
- `re`: recompiles the program
- `bonus`: compiles with animations and enemies
- `fclean`: removes all object files and the program
- `clean`: removes all object files

**Note**: Keep in mind that this project uses the *Codam's MLX* library.

## Special thanks:
- Codam MLX: [link](https://github.com/codam-coding-college/MLX42)
- Cat: [link](https://itch.io/profile/elthen)
- Environment and enemy: [link](https://pixel-poem.itch.io/dungeon-assetpuck)
