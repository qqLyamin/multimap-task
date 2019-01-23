#pragma once
#include <stdexcept>

template<class TKey>
class NotFoundException : public std::exception
{
public:
	virtual const TKey& GetKey() const noexcept = 0;
};