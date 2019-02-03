#pragma once
#include <stdexcept>

template<class TKey>
class NotFoundException : public std::exception
{
public:
	virtual const TKey& GetKey() const noexcept = 0;
};


template<class TKey>
class myNotFoundException : public NotFoundException<TKey>
{
	TKey mykey;
public:

	myNotFoundException(const TKey & mykey): mykey(mykey)
	{
	};

	virtual const TKey& GetKey() const noexcept
	{
		return mykey;
	};
};