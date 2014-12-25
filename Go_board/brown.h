/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * This is Brown, a simple go program.                           *
 *                                                               *
 * Copyright 2003 and 2004 by Gunnar Farneb�ck.                  *
 *                                                               *
 * Permission is hereby granted, free of charge, to any person   *
 * obtaining a copy of this file gtp.c, to deal in the Software  *
 * without restriction, including without limitation the rights  *
 * to use, copy, modify, merge, publish, distribute, and/or      *
 * sell copies of the Software, and to permit persons to whom    *
 * the Software is furnished to do so, provided that the above   *
 * copyright notice(s) and this permission notice appear in all  *
 * copies of the Software and that both the above copyright      *
 * notice(s) and this permission notice appear in supporting     *
 * documentation.                                                *
 *                                                               *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY     *
 * KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE    *
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR       *
 * PURPOSE AND NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO      *
 * EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS  *
 * NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT OR    *
 * CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING    *
 * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF    *
 * CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT    *
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS       *
 * SOFTWARE.                                                     *
 *                                                               *
 * Except as contained in this notice, the name of a copyright   *
 * holder shall not be used in advertising or otherwise to       *
 * promote the sale, use or other dealings in this Software      *
 * without prior written authorization of the copyright holder.  *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef __BROWN_H__
#define __BROWN_H__
#define VERSION_STRING "1.0"

#define MIN_BOARD 2
#define MAX_BOARD 19

/* These must agree with the corresponding defines in gtp.c. */
#define EMPTY 0
#define WHITE 1
#define BLACK 2

/* Used in the final_status[] array. */
#define DEAD 0
#define ALIVE 1
#define SEKI 2
#define WHITE_TERRITORY 3
#define BLACK_TERRITORY 4
#define UNKNOWN 5
/*
extern double komi;
extern int board_size;
extern int main_board[MAX_BOARD * MAX_BOARD];

void init_brown(int (&board)[MAX_BOARD*MAX_BOARD]);
void clear_board(int (&board)[MAX_BOARD*MAX_BOARD]);
int board_empty(int (&board)[MAX_BOARD*MAX_BOARD]);
int get_board(int i, int j, int (&board)[MAX_BOARD*MAX_BOARD]);
int get_string(int i, int j, int *stonei, int *stonej);
int legal_move(int i, int j, int color, int (&board)[MAX_BOARD*MAX_BOARD]);
void play_move(int i, int j, int color, int (&board)[MAX_BOARD*MAX_BOARD]);
void generate_move(int *i, int *j, int color, int (&board)[MAX_BOARD*MAX_BOARD]);
void compute_final_status(int (&board)[MAX_BOARD*MAX_BOARD]);
int get_final_status(int i, int j);
void set_final_status(int i, int j, int status);
int valid_fixed_handicap(int handicap);
void place_fixed_handicap(int handicap, int (&board)[MAX_BOARD*MAX_BOARD]);
void place_free_handicap(int handicap, int (&board)[MAX_BOARD*MAX_BOARD]);

// change:
void get_available_moves(int color, int &num_moves, int(&moves)[MAX_BOARD * MAX_BOARD], int(&board)[MAX_BOARD*MAX_BOARD]);
*/

/*
 * Local Variables:
 * tab-width: 8
 * c-basic-offset: 2
 * End:
 */
#endif