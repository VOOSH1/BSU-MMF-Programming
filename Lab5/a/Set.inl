template<class T>
Set<T>::~Set()
{
}

template<class T>
Set<T>::Set()
{
}

template<class T>
Set<T>::Set(const T& data)
{
	this->data = data;
}

template<class T>
Set<T>::Set(const Set<T>& set)
{
	this->data = set.data;
}

template<class T>
Set<T>& Set<T>::operator=(const Set<T>& set)
{
	if (this == &set)
		return *this;
	this->data = set.data;
	return *this;
}

template<class P>
std::ostream& operator<<(std::ostream& sstream, const Set<P>& set)
{
	sstream << set.data;
	return sstream;
}

template<class P>
inline std::istream& operator>>(std::istream& sstream, Set<P>& set)
{
	sstream >> set.data;
	return sstream;
}