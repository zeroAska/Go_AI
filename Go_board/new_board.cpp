#include "new_board.h"

#include <cstdlib>
#include <cstring>
#include <list>

using namespace std;

int deltai[4] = { -1, 1, 0, 0 };
int deltaj[4] = { 0, 0, -1, 1 };

block::block()
{
	memset(weight, 0, sizeof(weight));
	freedom = 0;
	influence = 0;
}

block::~block(){}

board_t::board_t()
{
	komi = -3.14;
	board_size = 13;
	memset(main_board, 0, sizeof(main_board));
	memset(next_stone, 0, sizeof(next_stone));
	memset(final_status, 0, sizeof(final_status));
	memset(all_blocks, 0, sizeof(all_blocks));
}

board_t::board_t(int size)
{
	komi = -3.14;
	board_size = size;
	memset(main_board, 0, sizeof(main_board));
	memset(next_stone, 0, sizeof(next_stone));
	memset(final_status, 0, sizeof(final_status));
	memset(all_blocks, 0, sizeof(all_blocks));
}

board_t::board_t(const board_t & old_board)
{
	list<block*>::const_iterator itor;
	list<int>::iterator new_itor;
	block * temp_block;
	komi = -3.14;
	board_size = old_board.board_size;
	memcpy(main_board, old_board.main_board, sizeof(main_board));
	memcpy(next_stone, old_board.next_stone, sizeof(next_stone));
	memcpy(final_status, old_board.final_status, sizeof(final_status));
	for (int i = 0; i < MAX_BOARD*MAX_BOARD; ++i)
		all_blocks[i] = NULL;
	itor = old_board.block_list.begin();
	//new_itor = this->block_list.begin();
	while (itor != old_board.block_list.end())
	{
		temp_block = new block;
		*temp_block = *(*itor);
		this->block_list.push_back(temp_block);
		new_itor = (*itor)->true_eyes.begin();
		while (new_itor != (*itor)->true_eyes.end())
			this->all_blocks[*new_itor++] = temp_block;
		new_itor = (*itor)->fake_eyes.begin();
		while (new_itor != (*itor)->fake_eyes.end())
			this->all_blocks[*new_itor++] = temp_block;
		new_itor = (*itor)->tigers.begin();
		while (new_itor != (*itor)->tigers.end())
			this->all_blocks[*new_itor++] = temp_block;
		new_itor = (*itor)->weaks.begin();
		while (new_itor != (*itor)->weaks.end())
			this->all_blocks[*new_itor++] = temp_block;
		new_itor = (*itor)->empty.begin();
		while (new_itor != (*itor)->empty.end())
			this->all_blocks[*new_itor++] = temp_block;
		new_itor = (*itor)->stones.begin();
		while (new_itor != (*itor)->stones.end())
			this->all_blocks[*new_itor++] = temp_block;
	}
}

const board_t & board_t::operator =(const board_t& old_board)
{
	if (&old_board == this)
	{
		return *this;
	}
	list<block*>::const_iterator itor;
	list<int>::iterator new_itor;
	block * temp_block;
	komi = -3.14;
	board_size = old_board.board_size;
	memcpy(main_board, old_board.main_board, sizeof(main_board));
	memcpy(next_stone, old_board.next_stone, sizeof(next_stone));
	memcpy(final_status, old_board.final_status, sizeof(final_status));
	for (int i = 0; i < MAX_BOARD*MAX_BOARD; ++i)
		all_blocks[i] = NULL;

	itor = this->block_list.end();
	while (itor != this->block_list.begin())
	{
		delete *itor;
		this->block_list.erase(itor--);
	}
	itor = old_board.block_list.begin();
	//new_itor = this->block_list.begin();
	while (itor != old_board.block_list.end())
	{
		temp_block = new block;
		*temp_block = *(*itor);
		this->block_list.push_back(temp_block);
		new_itor = (*itor)->true_eyes.begin();
		while (new_itor != (*itor)->true_eyes.end())
			this->all_blocks[*new_itor++] = temp_block;
		new_itor = (*itor)->fake_eyes.begin();
		while (new_itor != (*itor)->fake_eyes.end())
			this->all_blocks[*new_itor++] = temp_block;
		new_itor = (*itor)->tigers.begin();
		while (new_itor != (*itor)->tigers.end())
			this->all_blocks[*new_itor++] = temp_block;
		new_itor = (*itor)->weaks.begin();
		while (new_itor != (*itor)->weaks.end())
			this->all_blocks[*new_itor++] = temp_block;
		new_itor = (*itor)->empty.begin();
		while (new_itor != (*itor)->empty.end())
			this->all_blocks[*new_itor++] = temp_block;
		new_itor = (*itor)->stones.begin();
		while (new_itor != (*itor)->stones.end())
			this->all_blocks[*new_itor++] = temp_block;
	}
	return *this;
}

board_t::~board_t()
{	
	boardDel();
}

void board_t::boardDel()
{
	list<block*>::iterator itor;
	itor = this->block_list.end();
	while (itor != this->block_list.begin())
	{
		delete *itor;
		this->block_list.erase(itor--);
	}
	memset(main_board, 0, sizeof(main_board));
	memset(next_stone, 0, sizeof(next_stone));
	memset(final_status, 0, sizeof(final_status));
	memset(all_blocks, 0, sizeof(all_blocks));
}