#include "Vector.h"

#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;


template<typename Type>
Vector<Type>::Vector(size_t capacity)
	: m_capacity(capacity)
	, m_lastIndex(0)
{
	if (m_capacity <= 0)
		throw logic_error("Vector must have possitive size");

	cout << "Constructor\n";
	values = new Type[m_capacity];
	for (size_t i = 0; i < m_capacity; i++)
	{
		values[i] = 0;
	}
}


template<typename Type>
Vector<Type>::~Vector()
{
	cout << "Destructor\n";
	delete[] values;
}


template<typename Type>
Type& Vector<Type>::operator[](size_t index)
{
	std::cout << "[" << index << "]\n";
	return values[index];
}


template<typename Type>
void Vector<Type>::push_back(Type value)
{
	const int reservation = 2;

	if (m_lastIndex >= m_capacity)
	{
		Type* values_tmp = new Type[m_capacity + reservation];
		std::copy(values, values + m_capacity, values_tmp);

		values_tmp[m_capacity] = value;

		memset(values_tmp + m_capacity + 1, 0, (reservation - 1) * sizeof(Type));

		m_lastIndex = m_capacity;
		m_lastIndex++;


		m_capacity += reservation;

		delete[] values;
		values = values_tmp;
	}
	else
	{
		values[m_lastIndex++] = value;
	}

}

template<typename Type>
void Vector<Type>::remove(Type * value)
{
	cout << "Borro el elemnto " << *value << endl;
	Type* values_tmp = new Type[m_capacity - 1];
	auto index = value - values;
	if (values != value)
	{
		std::copy(values, value, values_tmp);
		std::copy(value + 1, values + m_capacity - 1, values_tmp + index);
	}

	m_capacity--;
	m_lastIndex--;
	delete[] values;
	values = values_tmp;
}

template<typename Type>
void Vector<Type>::remove(int index)
{
	Type* values_tmp = new Type[m_capacity - 1];
	Type* value = &values[index];
	cout << "Borro el elemnto " << *value << endl;
	if (values != value)
	{
		std::copy(values, value, values_tmp);
		std::copy(value + 1, values + m_capacity - 1, values_tmp + index);
	}

	m_capacity--;
	m_lastIndex--;
	delete[] values;
	values = values_tmp;
}

template<typename Type>
void Vector<Type>::printVector()
{
	for (int i = 0; i < m_capacity; i++) {
		cout << "Elemento n " << i << " es: " << endl;
		cout << values[i] << endl;
	}
}
