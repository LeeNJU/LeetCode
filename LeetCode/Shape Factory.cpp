#include<string>
#include<iostream>

//题目描述:实现工厂模式，输出正确的图形
//解法描述:每个形状类实现draw方法，在工厂类中进行if判断

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