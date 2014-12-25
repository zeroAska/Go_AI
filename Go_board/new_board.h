#ifndef __NEW_BOARD_H__
#define __NEW_BOARD_H__
#include "brown.h"
#include <list>
#include <cstdio>

#define POS(i, j) ((i) * board.board_size + (j))
#define I(pos) ((pos) / board.board_size)
#define J(pos) ((pos) % board.board_size)

/* three give ups from each side means the chess game finishes */
#define THREE_GIVEUPS 3

/* Macro to find the opposite color. */
#define OTHER_COLOR(color) (WHITE + BLACK - (color))
extern int deltai[4];
extern int deltaj[4];

enum block_attr
{
	TRUE_EYE,
	FAKE_EYE,
	TIGER,
	WEAK,
	FREEDOM,
	MontC
};

enum point_type
{
	TRUE_EYE_P,
	FAKE_EYE_P,
	TIGER_P,
	WEAK_P
};

struct point
{
	int row;
	int col;
	point_type type;
};

class block
{
public:
	int weight[FREEDOM+1];
	std::list<int> true_eyes;
	std::list<int> fake_eyes;
	std::list<int> tigers;
	std::list<int> weaks;
	int freedom;
	int influence;
    std::list<int> stones;
	std::list<int> empty;
	block();
	~block();
};

extern std::list<block> block_list;

class board_t
{
public:
	/* attributes, originally global variables */
	int board_size;
	double komi;
	int main_board[MAX_BOARD * MAX_BOARD];
	int next_stone[MAX_BOARD * MAX_BOARD];
	int final_status[MAX_BOARD * MAX_BOARD];
	int ko_i, ko_j;
	block * all_blocks[MAX_BOARD*MAX_BOARD];
	/* the list for all the blocks */
	std::list<block*> block_list;
	board_t();
	board_t(int size);
	board_t(const board_t & old_board);
	const board_t & operator =(const board_t& old_board);
	~board_t();
	void boardDel();
/* board functions */
	/* original static functions */
	int  pass_move(int i, int j);
	int  on_board(int i, int j);
	int  has_additional_liberty(int i, int j, int libi, int libj);
	int provides_liberty(int ai, int aj, int i, int j, int color);
	int suicide(int i, int j, int color);
	int remove_string(int i, int j);
	int same_string(int pos1, int pos2);
	void get_available_moves(int color, int &num_moves, int(&moves)[MAX_BOARD * MAX_BOARD]);
	void set_final_status_string(int pos, int status);

	/* original public functions */
	void init_brown(int size);
	void clear_board();
	int board_empty();
	int get_board(int i, int j);
	int get_string(int i, int j, int *stonei, int *stonej);
	int legal_move(int i, int j, int color);
	void play_move(int i, int j, int color);
	void generate_move(int *i, int *j, int color);
	void compute_final_status(void);
	int get_final_status(int i, int j);
	void set_final_status(int i, int j, int status);
	int valid_fixed_handicap(int handicap);
	void place_fixed_handicap(int handicap);
	void place_free_handicap(int handicap);
	//void get_available_moves(int color, int &num_moves, int(&moves)[MAX_BOARD * MAX_BOARD]);


};

extern board_t board;

int MtC(int i, int j, int color, int is_forked);


#endif