valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/mi_mapa.ber


Reviewing so_long!!

Example map:

Matrix
          01234 --> Columns
        0 11111
        1 1P001
        2 10C01
        3 10E01
Row <-- 4 11111

'P' Personaje
'C' Collectable
'E' Exit
'1' Wall
'0' Floor

Player input right
Call hanle_key(KEY_D, &game)
find_player(game) --> // Finds the 'P' at position (1,1)
move_player(game, 1, 2): since the tile is not '1', the player can move in
  handle_tile_interaction is '0' (simple movement)
    Clears (1,1), updates to (1,2), and places 'P' at the new coordinate
    Increases with move_count and print the steps
    render_map redraws

Current state of the map:
11111
10P01
10C01
10E01
11111

Player input below:
handle_key(KEY_S, &game);
find_player → (1,2)
	move_player(game, 2,2):
		Box is 'C' → entra
		handle_tile_interaction:
			Cambia (2,2) a 'P', (1,2) a '0'
		Increases with move_count and print the steps
    render_map redraws

Current state of the map:
11111
10001
10P01
10E01
11111

Player input below:
handle_key(KEY_S, &game);
find_player → (2,2)
move_player(game, 3,2):
  Box 'E' → entra
  handle_tile_interaction:
		Llama a count_collectibles → ya no hay 'C' → check
  Increases with move_count and print the steps
	Llama a close_game
			internal_close_game
			free_resources, mlx_destroy_window
			Libera mapas, cierra display
			Print "game cerrado.\n" y hace exit(0)

✅ Juego finalizado con éxito tras 4 movimientos.
