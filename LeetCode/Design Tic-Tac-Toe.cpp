#include<vector>
//��Ŀ����:���һ��Tic Tac Toe��Ϸ��ÿһ�����Ӷ���֤����Ч��
//�ⷨ����:�򵥵ķ�������ÿ��һ�����ͼ��ÿһ�У�ÿһ�У��Խ����Լ����Խ��ߡ���Ч��������row����������飬ÿ��
//        ѡ��1�ڵ�i�е�j����һ������ôrow[i]��col[j]�ͼ�1�����row������ĳһ��ֵ����n��˵����һ�е��Ӷ���
//        ѡ��1�ŵģ�ͬ��ÿ�У��Խ��߶���ͬ����˼·������ѡ��2��û��һ��������Ӧ��row��col��1���������row
//        ����col��ֵ����-n����˵����ѡ��2����Ϊ���֡�
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
		int add = player == 1 ? 1 : -1;//�ж�ѡ��1����ѡ��2��ѡ��1��1��ѡ��2��1
		rows[row] += add;//������Ӧ���У����Լ��Խ��ߵ�ֵ
		cols[col] += add;
		diag += (row == col ? add : 0);
		rev_diag += (row == N - col - 1 ? add : 0);
		return (abs(rows[row]) == N || abs(cols[col]) == N || //����У��кͶԽ����Ƿ��е���n��
			abs(diag) == N || abs(rev_diag) == N) ? player : 0;
	}
};