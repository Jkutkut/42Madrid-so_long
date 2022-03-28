## Docs:
- Compi with minilibX:
	- [link](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

## ThingsToDo:
- mlx name based on bonus
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
