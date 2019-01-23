#pragma once
#include "NotFoundException.h"
#include <map>

template<class TKey, class TValue>  //��� ����� � ��� �������� � �������
class Dictionary //�������
{
	std::multimap<TKey, TValue> my_K_V;

public:

	virtual ~Dictionary() = default; //���������� ����������

	virtual const TValue& Get(const TKey& key) const = 0; //����� ���� - ���������� ��������
	virtual void Set(const TKey& key, const TValue& value) = 0; //����� ���� � �������� 
	virtual bool IsSet(const TKey& key) const = 0;
};



//
//https://spb.hh.ru/applicant/vacancy_response?vacancyId=29481375
//
//���������� ����������� ����� ����������, ����������� ��������� Dictionary � ��������� ��������� ����������, ����������� ��������� NotFoundException.
//��� ���������� ����������� ������������ STL. ����� �����, ���������� ���������� ����� �� ����������.
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