#include<string>

//题目描述:给定一个字符串，判断这个字符串是不是表示合法的数字， 正负，小数，指数（3e10）等等
//解法描述:利用有限状态机，state = 0是起始状态，state = -1是无效状态，随着输入不同的input，状态有所变化，
//         得到状态转移表

bool isNumber(std::string s)
{
	enum InputType  //有限状态机中的节点
	{
		INVALID, // 0
		SPACE, // 1
		SIGN, // 2
		DIGIT, // 3
		DOT, // 4
		EXPONENT, // 5
		NUM_INPUTS // 6
	};
	const int transitionTable[][NUM_INPUTS] =  //各个状态转换
	{
		-1, 0, 3, 1, 2, -1, // next states for state 0
		-1, 8, -1, 1, 4, 5, // next states for state 1
		-1, -1, -1, 4, -1, -1, // next states for state 2
		-1, -1, -1, 1, 2, -1, // next states for state 3
		-1, 8, -1, 4, -1, 5, // next states for state 4
		-1, -1, 6, 7, -1, -1, // next states for state 5
		-1, -1, -1, 7, -1, -1, // next states for state 6
		-1, 8, -1, 7, -1, -1, // next states for state 7
		-1, 8, -1, -1, -1, -1, // next states for state 8
	};

	int state = 0;
	for (int i = 0; i < s.size(); ++i) {
		InputType inputType = INVALID;
		if (isspace(s[i]))
			inputType = SPACE;
		else if (s[i] == '+' || s[i] == '-')
			inputType = SIGN;
		else if (isdigit(s[i]))
			inputType = DIGIT;
		else if (s[i] == '.')
			inputType = DOT;
		else if (s[i] == 'e' || s[i] == 'E')
			inputType = EXPONENT;
		// Get next state from current state and input symbol
		state = transitionTable[state][inputType];
		// Invalid input
		if (state == -1) 
			return false;
	}
	// If the current state belongs to one of the accepting (final) states,
	// then the number is valid
	return state == 1 || state == 4 || state == 7 || state == 8;
}