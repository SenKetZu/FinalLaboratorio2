#pragma once
#include <iostream>
class Configuracion
{

private:
	Configuracion();

public:
	static Configuracion& getInstance()
	{
		static Configuracion instance;
		return instance;
	}

	std::string getName();


};

