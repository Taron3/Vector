
#include <iostream>
#include <string>

#include "vector.hpp"
#include "vector.cpp"

int main() {

	vector<int> vectInt(10);
	vector<std::string> vectStr;
	vector<std::string> vectFix(4, "ball");
	vectStr.push("c++");
	vectStr.push("c#");
	vectStr.push("java");
	vectStr.push("python");
	vectStr.push("js");
	vectStr.push("swift");

	for (int i = 0; i < vectInt.capacity(); ++i)
	{
		vectInt[i] = i * i;
	}

	std::cout << "front: " << vectInt.front() << "  back: " << vectInt.back() << "\n";

	for (int i = 0; i < vectInt.size(); ++i)
	{
		std::cout << vectInt[i] << " ";
	}
	std::cout << "\n";
	
	for (int i = 0; i < vectStr.size(); ++i)
	{
		std::cout << vectStr[i] << " ";
	}
	std::cout << "\n";
	
	for (int i = 0; i < vectFix.size(); ++i)
	{
		std::cout << vectFix[i] << " ";
	}
	std::cout << "\n";
	
	vector<std::string> temp;
	vector<std::string> tmp;
	temp = move(vectStr);
	tmp = vectStr;
	temp.pop();
	for (int i = 0; i < temp.size(); ++i)
	{	
		std::cout << temp[i] << "  ";
	}
	std::cout << "\n";
	
	vector<std::string> mv(move(temp));
	mv.pop();
	for (int i = 0; i < mv.size(); ++i)
	{
		std::cout << mv[i] << "  ";
	}
	std::cout << "\n";

}
