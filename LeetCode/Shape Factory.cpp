#include<string>
#include<iostream>

//��Ŀ����:ʵ�ֹ���ģʽ�������ȷ��ͼ��
//�ⷨ����:ÿ����״��ʵ��draw�������ڹ������н���if�ж�

class Shape 
{
public:
	virtual void draw() const = 0;
};

class Rectangle : public Shape 
{
	void draw() const 
	{
		std::cout << " ---- " << std::endl;
		std::cout << "|    |" << std::endl;
		std::cout << " ---- " << std::endl;
	}
};

class Square : public Shape 
{
	void draw() const
	{
		std::cout << " ---- " << std::endl;
		std::cout << "|    |" << std::endl;
		std::cout << "|    |" << std::endl;
		std::cout << " ---- " << std::endl;
	}
};

class Triangle : public Shape 
{
	void draw() const 
	{
		std::cout << "  /\\ " << std::endl;
		std::cout << " /  \\ " << std::endl;
		std::cout << "/____\\ " << std::endl;
	}
};

class ShapeFactory 
{
public:
	/**
	* @param shapeType a string
	* @return Get object of type Shape
	*/
	Shape* getShape(std::string& shapeType) 
	{
		if (shapeType == "Square") 
			return new Square();
		else if (shapeType == "Triangle") 
			return new Triangle();
		else if (shapeType == "Rectangle") 
			return new Rectangle();
		else 
			return nullptr;
	}
};