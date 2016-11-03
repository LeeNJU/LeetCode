#include<vector>
#include<string>
#include<stack>
//��Ŀ����:����һ���ַ�����Ҫ��ȥ�������ظ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ��������Ľ�����ֵ�������С�ģ�����
//        "bcabc"�õ�"abc"
//�ⷨ����:��һ��ջ���浱ǰ�����Ž⣬�����ǰԪ�ر�ջ��Ԫ��С������ջ��Ԫ�ز��������һ�γ��֣����ҵ�ǰԪ�ز���
//        ջ�У���ô����ջ��Ԫ�أ����뵱ǰԪ��
std::string removeDuplicateLetters(std::string s) 
{
	std::vector<bool> exist(26, false);//��ջ���Ƿ����
	std::vector<int> vec(26, 0); //ͳ��ÿ���ַ��Ĵ������Ѿ����ֵĴ���
	for (int i = 0; i < s.length(); ++i)
		++vec[s[i] - 'a'];

	std::stack<char> stack;//ջ���浱ǰ�����Ž�
	for (int i = 0; i < s.length(); ++i)
	{
		while (!stack.empty() && stack.top() > s[i] && vec[stack.top() - 'a']
			&& !exist[s[i] - 'a'])//��ǰ�ַ���ջ���ַ�ҪС������ջ���ַ����������һ�γ��֣����ҵ�ǰ�ַ�����ջ��
		{
			exist[stack.top() - 'a'] = false;
			stack.pop();
		}

		if (!exist[s[i] - 'a'])
		{
			stack.push(s[i]);
			exist[s[i] - 'a'] = true;
		}
		--vec[s[i] - 'a'];
	}

	std::string result;
	while (!stack.empty())//ȡ��ջ��Ԫ���ٷ�ת
	{
		result += stack.top();
		stack.pop();
	}
	std::reverse(result.begin(), result.end());
	return result;
}