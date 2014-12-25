#include "new_board.h"

#define SIMULATION_TIMES 10000


static int count_stones(int color, int(&final_status)[MAX_BOARD*MAX_BOARD])
{
	int count = 0;
	for (int i = 0; i < MAX_BOARD*MAX_BOARD; i++)
	{
		if (final_status[i] == color + 2) count++;
	}
	return count;
}


/* place the stone in (i,j), and then start   MonteCarlo
* return -1 if the stone cannot be placed there, else return the total number of ways to win the game starting from (i,j)
*/
int MC(int i, int j, int color, int is_forked)
{
	
	int win_times = 0;
	int index = POS(i, j);
	// the guess place for MC
	int i_new, j_new, num_moves = 0, wins = 0;

	// save the board, and copy back after the MC simulation
	board_t board_save(board);
	int moves[MAX_BOARD*MAX_BOARD];

	// return -1 if POS(i,j) is illegal 
	if (!board.legal_move(i, j, color))
		return -1;

	board.play_move(i, j, color);

	for (int i = 0; i < SIMULATION_TIMES; i++)
	{
		int temp_color = color;
		int is_final = 0;
		while (true)
		{
			board.generate_move(&i_new, &j_new, temp_color);
			if (i_new == -1 && j_new == -1)
			{
				is_final++;
				if (is_final == THREE_GIVEUPS * 2) break;
				temp_color = OTHER_COLOR(temp_color);
				continue;
			}
			board.play_move(i_new, j_new, temp_color);
			temp_color = OTHER_COLOR(temp_color);
		}
		board.compute_final_status();

		if (count_stones(color, board.final_status)> board.board_size*board.board_size / 2)
			wins++;

		// re-init the chess board 
		board = board_save;
	}

	/* copy back the saved board */
	if (!is_forked)
		board = board_save;

	return wins;
}
