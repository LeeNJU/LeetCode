#include<vector>
#include<list>

void wallsAndGates(std::vector<std::vector<int>>& rooms) 
{
    std::vector<int> gates;
	for (int i = 0; i<rooms.size(); i++) 
	{
		for (int j = 0; j<rooms[i].size(); j++) 
		{
			if (rooms[i][j] == 0)
			{
				gates.push_back(i);
				gates.push_back(j);
			}
		}
	}

	for (int i = 0; i < gates.size(); i = i + 2) 
	{
		std::vector<std::pair<int, int>> q1, q2;
		q1.push_back(std::make_pair(gates[i].first, gates[i].second));
		int dist = 1;

		while (!q1.empty()) 
		{
			int row = q1.front().first;
			int col = q1.front().second;
			q1.pop_front();

			if (row > 0 && dist <= rooms[row - 1][col]) {
				rooms[row - 1][col] = dist;
				q2.push_back(std::make_pair(row - 1, col));
			}
			if (row < rooms.size() - 1 && dist <= rooms[row + 1][col]) {
				rooms[row + 1][col] = dist;
				q2.push_back(std::make_pair(row + 1, col));
			}
			if (col > 0 && dist <= rooms[row][col - 1]) {
				rooms[row][col - 1] = dist;
				q2.push_back(std::make_pair(row, col - 1));
			}
			if (col < rooms[0].size() - 1 && dist <= rooms[row][col + 1]) {
				rooms[row][col + 1] = dist;
				q2.push_back(std::make_pair(row, col + 1));
			}

			if (q1.empty()) 
			{
				std::swap(q1, q2);
				dist++;
			}
		}
	}