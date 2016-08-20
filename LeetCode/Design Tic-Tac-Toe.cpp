#include<vector>
//题目描述:设计一个Tic Tac Toe游戏，每一次落子都保证是有效的
//解法描述:简单的方法就是每走一步，就检查每一行，每一列，对角线以及反对角线。高效方法是用row数组和列数组，每当
//        选手1在第i行第j列走一步，那么row[i]和col[j]就加1，如果row数组中某一个值等于n，说明这一行的子都是
//        选手1放的，同理，每列，对角线都是同样的思路，对于选手2，没走一步就在相应的row和col减1，这样如果row
//        或者col的值等于-n，就说明是选手2，作为区分。
class TicTacToe 
{
private:
	std::vector<int> rows, cols;
	int diag;
	int rev_diag;
	int N;

public:
	/** Initialize your data structure here. */
	TicTacToe(int n) : rows(n), cols(n), N(n), diag(0), rev_diag(0) {}

	int move(int row, int col, int player) 
	{
		int add = player == 1 ? 1 : -1;//判断选手1还是选手2，选手1加1，选手2减1
		rows[row] += add;//更新相应的行，列以及对角线的值
		cols[col] += add;
		diag += (row == col ? add : 0);
		rev_diag += (row == N - col - 1 ? add : 0);
		return (abs(rows[row]) == N || abs(cols[col]) == N || //检查行，列和对角线是否有等于n的
			abs(diag) == N || abs(rev_diag) == N) ? player : 0;
	}
};