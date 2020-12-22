template<class T>
Field<T>::~Field()
{
}

template<class T>
Field<T>::Field()
{
}

template<class T>
inline Field<T>::Field(const T& data) : Ring<T>(data)
{
}

template<class T>
Field<T>::Field(const Field<T>& field) : Ring<T>((const Ring<T>&)field)
{
}

template<class T>
Field<T>& Field<T>::operator=(const Field<T>& field)
{
	if (this == &field)
		return *this;
	Ring<T>::operator=(field);
	return *this;
}

template<class T>
Field<T>& Field<T>::operator+=(const Field<T>& field)
{
	this->data += field.data;
	return *this;
}

template<class T>
Field<T> Field<T>::operator+(const Field<T>& field) const
{
	return Field<T>(this->data + field.data);
}

template<class T>
Field<T>& Field<T>::operator-=(const Field<T>& field)
{
	this->data -= field.data;
	return *this;
}

template<class T>
Field<T> Field<T>::operator-(const Field<T>& field) const
{
	return Field<T>(this->data - field.data);
}

template<class T>
Field<T>& Field<T>::operator*=(const Field<T>& field)
{
	this->data *= field.data;
	return *this;
}

template<class T>
Field<T> Field<T>::operator*(const Field<T>& field) const
{
	return Field<T>(this->data * field.data);
}

template<class T>
Field<T>& Field<T>::operator/=(const Field<T>& field)
{
	if (field.data != 0)
		this->data /= field.data;
	return *this;
}

template<class T>
Field<T> Field<T>::operator/(const Field<T>& field) const
{
	if (field.data != 0)
		return Field<T>(this->data / field.data);
	else
		return Field<T>(*this);
}

template<class P>
std::ostream& operator<<(std::ostream& sstream, const Field<P>& field)
{
	sstream << (const Ring<P>&)field;
	return sstream;
}

template<class P>
inline std::istream& operator>>(std::istream& sstream, Field<P>& field)
{
	sstream >> (Ring<P>&)field;
	return sstream;
}

template<class T>
void Field<T>::show()
{
	std::cout << "Поле" << std::endl;
}