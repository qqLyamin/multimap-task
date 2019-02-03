#pragma once
#include "NotFoundException.h"
#include <map>

template<class TKey, class TValue>  
class Dictionary 
{
public:
	virtual ~Dictionary() = default; 
	virtual const TValue& Get(const TKey& key) const = 0; 
	virtual void Set(const TKey& key, const TValue& value) = 0; 
	virtual bool IsSet(const TKey& key) const = 0;
};

template <class TKey, class TValue>
class myDictionary : public Dictionary<TKey, TValue>
{
	std::map<TKey, TValue> mymap;
public:
	virtual ~myDictionary() = default;
	virtual const TValue& Get(const TKey& key) const override;
	virtual void Set(const TKey& key, const TValue& value);
	virtual bool IsSet(const TKey& key) const;
};

//
//https://spb.hh.ru/applicant/vacancy_response?vacancyId=29481375
//
//Необходимо реализовать класс контейнера, реализующий интерфейс Dictionary и способный выбросить исключение, реализующее интерфейс NotFoundException.
//При разработке допускается использовать STL. Кроме этого, внутренняя реализация ничем не ограничена.
//
//template<class TKey, class TValue>
//class Dictionary
//{
//public:
//	virtual ~Dictionary() = default;
//
//	virtual const TValue& Get(const TKey& key) const = 0;
//	virtual void Set(const TKey& key, const TValue& value) = 0;
//	virtual bool IsSet(const TKey& key) const = 0;
//};
//
//template<class TKey>
//class NotFoundException : public std::exception
//{
//public:
//	virtual const TKey& GetKey() const noexcept = 0;
//};

template<class TKey, class TValue>
inline const TValue & myDictionary<TKey, TValue>::Get(const TKey & key) const
{
	auto a = mymap.find(key);
	if (a != std::end(mymap))
	{
		return (*a).second;
	}
	else
	{
		throw myNotFoundException<TKey>(key);
	}
}

template<class TKey, class TValue>
inline void myDictionary<TKey, TValue>::Set(const TKey & key, const TValue & value)
{
	mymap.emplace(key, value);
}

template<class TKey, class TValue>
inline bool myDictionary<TKey, TValue>::IsSet(const TKey & key) const
{
	auto a = mymap.find(key);
	return a != std::end(mymap);
}
