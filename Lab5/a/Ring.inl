template<class T>
Ring<T>::~Ring()
{
}

template<class T>
Ring<T>::Ring()
{
}

template<class T>
inline Ring<T>::Ring(const T& data): Set<T>(data)
{
}

template<class T>
Ring<T>::Ring(const Ring<T>& ring): Set<T>((const Set<T>&)ring)
{
}

template<class T>
Ring<T>& Ring<T>::operator=(const Ring<T>& ring)
{
	if (this == &ring)
		return *this;
	Set<T>::operator=(ring);
	return *this;
}

template<class T>
Ring<T>& Ring<T>::operator+=(const Ring<T>& ring)
{
	this->data += ring.data;
	return *this;
}

template<class T>
Ring<T> Ring<T>::operator+(const Ring<T>& ring) const
{
	return Ring<T>(this->data + ring.data);
}

template<class T>
Ring<T>& Ring<T>::operator-=(const Ring<T>& ring)
{
	this->data -= ring.data;
	return *this;
}

template<class T>
Ring<T> Ring<T>::operator-(const Ring<T>& ring) const
{
	return Ring<T>(this->data - ring.data);
}

template<class T>
Ring<T>& Ring<T>::operator*=(const Ring<T>& ring)
{
	this->data *= ring.data;
	return *this;
}

template<class T>
Ring<T> Ring<T>::operator*(const Ring<T>& ring) const
{
	return Ring<T>(this->data * ring.data);
}

template<class P>
std::ostream& operator<<(std::ostream& sstream, const Ring<P>& ring)
{
	sstream << (const Set<P>&)ring;
	return sstream;
}

template<class P>
inline std::istream& operator>>(std::istream& sstream, Ring<P>& ring)
{
	sstream >> (Set<P>&)ring;
	return sstream;
}

template<class T>
void Ring<T>::show()
{
	std::cout << "Кольцо" << std::endl;
}