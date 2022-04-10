## Docs:
- Compi with minilibX:
	- [link](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
- Check latest version of mlx

## ThingsToDo:
- Freeend on create_game
- mandatory with only one img
- End without leaks -> clean_end
  - Invalid map
  - Inconsistent map

  - loop_hook:

			#include <mlx.h>

			int	render_next_frame(void *YourStruct);

			int	main(void)
			{
				void	*mlx;

				mlx = mlx_init();
				mlx_loop_hook(mlx, render_next_frame, YourStruct);
				mlx_loop(mlx);
			}
